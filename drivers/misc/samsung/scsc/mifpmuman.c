/****************************************************************************
 *
 * Copyright (c) 2014 - 2021 Samsung Electronics Co., Ltd. All rights reserved
 *
 ****************************************************************************/

/* uses */
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <linux/slab.h>
#include <linux/mutex.h>
#include <scsc/scsc_logring.h>
#include "scsc_mif_abs.h"
#include <linux/module.h>

#define PMU_MSG_TIMEOUT (HZ)

static uint pmu_cmd_timeout = 1;
module_param(pmu_cmd_timeout, uint, S_IRUGO | S_IWUSR);
MODULE_PARM_DESC(pmu_cmd_timeout, "PMU command timeout in seconds, default 1");

/* Implements */
#include "mifpmuman.h"

static void mifpmu_isr(int irq, void *data)
{
	struct mifpmuman *pmu = (struct mifpmuman *)data;
	struct scsc_mif_abs *mif;
	/* Get abs implementation */
	mif = pmu->mif;
	pmu->last_msg = (enum pmu_msg)(mif->get_mbox_pmu(mif));
	SCSC_TAG_INFO(MXMAN, "Received PMU IRQ\n");

	complete(&pmu->msg_ack);
}

int mifpmuman_init(struct mifpmuman *pmu, struct scsc_mif_abs *mif,
		   mifpmuisr_handler handler, void *irq_data)
{
	if (pmu->in_use)
		return -EBUSY;

	mutex_init(&pmu->lock);
	pmu->in_use = true;
	pmu->pmu_irq_handler = handler;
	pmu->irq_data = irq_data;

	/* register isr with mif abstraction */
	mif->irq_reg_pmu_handler(mif, mifpmu_isr, (void *)pmu);

	/* cache mif */
	pmu->mif = mif;

	init_completion(&pmu->msg_ack);
	return 0;
}

int mifpmuman_load_fw(struct mifpmuman *pmu, int *ka_patch, size_t ka_patch_len)
{
	struct scsc_mif_abs *mif;
	int ret;

	mutex_lock(&pmu->lock);
	if (!pmu->in_use) {
		SCSC_TAG_ERR(MXMAN, "PMU not initialized\n");
		mutex_unlock(&pmu->lock);
		return -ENODEV;
	}
	/* Get abs implementation */
	SCSC_TAG_INFO(MXMAN, "ka_patch : 0x%x\n", ka_patch);
	SCSC_TAG_INFO(MXMAN, "ka_patch_len : 0x%x\n", ka_patch_len);
	mif = pmu->mif;

	ret = mif->load_pmu_fw(mif, ka_patch, ka_patch_len);

	mutex_unlock(&pmu->lock);

	return ret;
}

int mifpmuman_send_msg(struct mifpmuman *pmu, enum pmu_msg msg)
{
	struct scsc_mif_abs *mif;
	int ret;

	SCSC_TAG_INFO(MXMAN, "Send PMU message %s\n", pmu_msg_string[msg]);

	mutex_lock(&pmu->lock);
	if (!pmu->in_use) {
		mutex_unlock(&pmu->lock);
		return -ENODEV;
	}
	/* Get abs implementation */
	mif = pmu->mif;

	ret = mif->set_mbox_pmu(mif, msg);

	if (wait_for_completion_timeout(&pmu->msg_ack, pmu_cmd_timeout * PMU_MSG_TIMEOUT) == 0) {
		SCSC_TAG_ERR(MXMAN, "Timeout waiting for msg ACK\n");
		mutex_unlock(&pmu->lock);
		return -ETIMEDOUT;
	}

	SCSC_TAG_INFO(MXMAN, "Received PMU message %s\n",
		      pmu_msg_string[pmu->last_msg]);
	/* reinit so completion can be re-used */
	reinit_completion(&pmu->msg_ack);

	mutex_unlock(&pmu->lock);

	return ret;
}

int mifpmuman_deinit(struct mifpmuman *pmu)
{
	mutex_lock(&pmu->lock);
	if (!pmu->in_use) {
		mutex_unlock(&pmu->lock);
		return -ENODEV;
	}
	pmu->in_use = false;
	mutex_unlock(&pmu->lock);
	return 0;
}

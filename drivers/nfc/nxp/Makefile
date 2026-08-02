# SPDX-License-Identifier: GPL-2.0
#
# Makefile for nfc devices
#
ifneq ($(SEC_BUILD_CONF_USE_ESE_TZ), false)
	ccflags-y += -DENABLE_ESE_SPI_SECURED
endif

# for combined driver
ifeq ($(CONFIG_NFC_NXP_COMBINED),y)
ifeq ($(CONFIG_NXP_NFC),m)
obj-$(CONFIG_NXP_NFC)		+= nfc_nxp_sec.o
nfc_nxp_sec-$(CONFIG_NFC_SN2XX_ESE_SUPPORT)	+= p73.o ese_reset.o
nfc_nxp_sec-$(CONFIG_SEC_NFC_LOGGER_NXP)		+= ../nfc_logger/nfc_logger.o
nfc_nxp_sec-$(CONFIG_NFC_SN2XX)		+= common.o common_ese.o i2c_drv.o
else
obj-$(CONFIG_NFC_SN2XX)	+= nfc.o
nfc-objs			+= common.o common_ese.o i2c_drv.o
obj-$(CONFIG_NFC_SN2XX_ESE_SUPPORT)	+= p73.o ese_reset.o
obj-$(CONFIG_SEC_NFC_LOGGER_NXP)	+= ../nfc_logger/nfc_logger.o
endif # CONFIG_NXP_NFC

else # !CONFIG_NFC_NXP_COMBINED
# for sn2xx only
ifeq ($(CONFIG_NXP_NFC),m)
obj-$(CONFIG_NXP_NFC)		+= nfc_sec_nxp.o
nfc_sec_nxp-$(CONFIG_NFC_SN2XX_ESE_SUPPORT)	+= p73.o ese_reset.o
nfc_sec_nxp-$(CONFIG_SEC_NFC_LOGGER_NXP)		+= ../nfc_logger/nfc_logger.o
nfc_sec_nxp-$(CONFIG_NFC_SN2XX)		+= common.o common_ese.o i2c_drv.o
else
obj-$(CONFIG_NFC_SN2XX)	+= nfc.o
nfc-objs			+= common.o common_ese.o i2c_drv.o
obj-$(CONFIG_NFC_SN2XX_ESE_SUPPORT)	+= p73.o ese_reset.o
obj-$(CONFIG_SEC_NFC_LOGGER_NXP)	+= ../nfc_logger/nfc_logger.o
endif # CONFIG_NXP_NFC
endif # CONFIG_NFC_NXP_COMBINED

ccflags-y 			+= -DRECOVERY_ENABLE -UDEBUG

# SPDX-License-Identifier: GPL-2.0
dtb-$(CONFIG_ARCH_EXYNOS) += exynos/s5e9925.dtb

dtbo-$(CONFIG_MODEL_R0S) += samsung/r0s/r0s_eur_openx_w01_r19.dtbo
dtbo-$(CONFIG_MODEL_R0S) += samsung/r0s/r0s_eur_openx_w01_r20.dtbo
dtbo-$(CONFIG_MODEL_R0S) += samsung/r0s/r0s_eur_openx_w01_r21.dtbo
dtbo-$(CONFIG_MODEL_R0S) += samsung/r0s/r0s_eur_openx_w01_r23.dtbo
dtbo-$(CONFIG_MODEL_R0S) += samsung/r0s/r0s_eur_openx_w01_r24.dtbo
dtbo-$(CONFIG_MODEL_R0S) += samsung/r0s/r0s_eur_openx_w01_r25.dtbo
dtbo-$(CONFIG_MODEL_R0S) += samsung/r0s/r0s_eur_openx_w01_r26.dtbo
dtbo-$(CONFIG_MODEL_R0S) += samsung/r0s/r0s_eur_openx_w01_r27.dtbo

dtbo-$(CONFIG_MODEL_G0S) += samsung/g0s/g0s_eur_openx_w01_r19.dtbo
dtbo-$(CONFIG_MODEL_G0S) += samsung/g0s/g0s_eur_openx_w01_r20.dtbo
dtbo-$(CONFIG_MODEL_G0S) += samsung/g0s/g0s_eur_openx_w01_r21.dtbo
dtbo-$(CONFIG_MODEL_G0S) += samsung/g0s/g0s_eur_openx_w01_r23.dtbo
dtbo-$(CONFIG_MODEL_G0S) += samsung/g0s/g0s_eur_openx_w01_r24.dtbo
dtbo-$(CONFIG_MODEL_G0S) += samsung/g0s/g0s_eur_openx_w01_r25.dtbo
dtbo-$(CONFIG_MODEL_G0S) += samsung/g0s/g0s_eur_openx_w01_r26.dtbo
dtbo-$(CONFIG_MODEL_G0S) += samsung/g0s/g0s_eur_openx_w01_r27.dtbo

dtbo-$(CONFIG_MODEL_B0S) += samsung/b0s/b0s_eur_openx_w01_r19.dtbo
dtbo-$(CONFIG_MODEL_B0S) += samsung/b0s/b0s_eur_openx_w01_r21.dtbo
dtbo-$(CONFIG_MODEL_B0S) += samsung/b0s/b0s_eur_openx_w01_r24.dtbo
dtbo-$(CONFIG_MODEL_B0S) += samsung/b0s/b0s_eur_openx_w01_r26.dtbo
dtbo-$(CONFIG_MODEL_B0S) += samsung/b0s/b0s_eur_openx_w01_r27.dtbo
dtbo-$(CONFIG_MODEL_B0S) += samsung/b0s/b0s_eur_openx_w01_r28.dtbo

targets += dtbs
DTB_LIST  := $(dtb-y) $(dtbo-y)
always    := $(DTB_LIST)

dtbs: $(addprefix $(obj)/, $(DTB_LIST))

clean-files := *.dtb*

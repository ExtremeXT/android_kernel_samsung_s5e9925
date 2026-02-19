# SPDX-License-Identifier: GPL-2.0
dtbo-$(CONFIG_MODEL_R0S) += r0s/r0s_eur_openx_w01_r19.dtbo
dtbo-$(CONFIG_MODEL_R0S) += r0s/r0s_eur_openx_w01_r20.dtbo
dtbo-$(CONFIG_MODEL_R0S) += r0s/r0s_eur_openx_w01_r21.dtbo
dtbo-$(CONFIG_MODEL_R0S) += r0s/r0s_eur_openx_w01_r23.dtbo
dtbo-$(CONFIG_MODEL_R0S) += r0s/r0s_eur_openx_w01_r24.dtbo
dtbo-$(CONFIG_MODEL_R0S) += r0s/r0s_eur_openx_w01_r25.dtbo
dtbo-$(CONFIG_MODEL_R0S) += r0s/r0s_eur_openx_w01_r26.dtbo
dtbo-$(CONFIG_MODEL_R0S) += r0s/r0s_eur_openx_w01_r27.dtbo

dtbo-$(CONFIG_MODEL_G0S) += g0s/g0s_eur_openx_w01_r19.dtbo
dtbo-$(CONFIG_MODEL_G0S) += g0s/g0s_eur_openx_w01_r20.dtbo
dtbo-$(CONFIG_MODEL_G0S) += g0s/g0s_eur_openx_w01_r21.dtbo
dtbo-$(CONFIG_MODEL_G0S) += g0s/g0s_eur_openx_w01_r23.dtbo
dtbo-$(CONFIG_MODEL_G0S) += g0s/g0s_eur_openx_w01_r24.dtbo
dtbo-$(CONFIG_MODEL_G0S) += g0s/g0s_eur_openx_w01_r25.dtbo
dtbo-$(CONFIG_MODEL_G0S) += g0s/g0s_eur_openx_w01_r26.dtbo
dtbo-$(CONFIG_MODEL_G0S) += g0s/g0s_eur_openx_w01_r27.dtbo

dtbo-$(CONFIG_MODEL_B0S) += b0s/b0s_eur_openx_w01_r19.dtbo
dtbo-$(CONFIG_MODEL_B0S) += b0s/b0s_eur_openx_w01_r21.dtbo
dtbo-$(CONFIG_MODEL_B0S) += b0s/b0s_eur_openx_w01_r24.dtbo
dtbo-$(CONFIG_MODEL_B0S) += b0s/b0s_eur_openx_w01_r26.dtbo
dtbo-$(CONFIG_MODEL_B0S) += b0s/b0s_eur_openx_w01_r27.dtbo
dtbo-$(CONFIG_MODEL_B0S) += b0s/b0s_eur_openx_w01_r28.dtbo

targets += dtbs
DTB_LIST  := $(dtb-y) $(dtbo-y)
always-y    := $(DTB_LIST)

dtbs: $(addprefix $(obj)/, $(DTB_LIST))

clean-files := *.dtb*

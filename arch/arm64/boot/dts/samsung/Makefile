# SPDX-License-Identifier: GPL-2.0
# Galaxy S22 - SM-S901B
dtbo-$(CONFIG_MACH_R0S_EUR_OPENX) += \
	r0s/r0s_eur_openx_w01_r19.dtbo \
	r0s/r0s_eur_openx_w01_r20.dtbo \
	r0s/r0s_eur_openx_w01_r21.dtbo \
	r0s/r0s_eur_openx_w01_r23.dtbo \
	r0s/r0s_eur_openx_w01_r24.dtbo \
	r0s/r0s_eur_openx_w01_r25.dtbo \
	r0s/r0s_eur_openx_w01_r26.dtbo \
	r0s/r0s_eur_openx_w01_r27.dtbo

# Galaxy S22+ - SM-S906B
dtbo-$(CONFIG_MACH_G0S_EUR_OPENX) += \
	g0s/g0s_eur_openx_w01_r19.dtbo \
	g0s/g0s_eur_openx_w01_r20.dtbo \
	g0s/g0s_eur_openx_w01_r21.dtbo \
	g0s/g0s_eur_openx_w01_r23.dtbo \
	g0s/g0s_eur_openx_w01_r24.dtbo \
	g0s/g0s_eur_openx_w01_r25.dtbo \
	g0s/g0s_eur_openx_w01_r26.dtbo \
	g0s/g0s_eur_openx_w01_r27.dtbo

# Galaxy S22 Ultra - SM-S908B
dtbo-$(CONFIG_MACH_B0S_EUR_OPENX) += \
	b0s/b0s_eur_openx_w01_r19.dtbo \
	b0s/b0s_eur_openx_w01_r21.dtbo \
	b0s/b0s_eur_openx_w01_r24.dtbo \
	b0s/b0s_eur_openx_w01_r26.dtbo \
	b0s/b0s_eur_openx_w01_r27.dtbo \
	b0s/b0s_eur_openx_w01_r28.dtbo

# Galaxy S23 FE (eur_openx) - SM-S711B
dtbo-$(CONFIG_MACH_R11S_EUR_OPENX) += \
	r11s/r11s_eur_openx_w01_r00.dtbo \
	r11s/r11s_eur_openx_w01_r01.dtbo \
	r11s/r11s_eur_openx_w01_r02.dtbo \
	r11s/r11s_eur_openx_w01_r03.dtbo \
	r11s/r11s_eur_openx_w01_r05.dtbo

# Galaxy S23 FE (kor_singlex) - SM-S711N
dtbo-$(CONFIG_MACH_R11S_KOR_SINGLEX) += r11s/r11s_kor_singlex_w01_r05.dtbo

targets += dtbs
DTB_LIST  := $(dtb-y) $(dtbo-y)
always-y    := $(DTB_LIST)

dtbs: $(addprefix $(obj)/, $(DTB_LIST))

clean-files := *.dtb*

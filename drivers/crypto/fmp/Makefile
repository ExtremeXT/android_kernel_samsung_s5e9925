# Exynos FMP makefile
ccflags-y += -I$(srctree)/drivers/scsi/ufs/$(TARGET_SOC)

ifeq ($(CONFIG_EXYNOS_FMP_INTEGRITY_TEST), y)
FIPS_PR = fipsed_
endif

fmp-core-y += fmp.o

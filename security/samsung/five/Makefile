
obj-$(CONFIG_FIVE) += five.o
obj-$(CONFIG_FIVE_PA_FEATURE) += five_pa.o

EXTRA_CFLAGS += -I$(src)
asflags-y += -Isecurity/integrity/five
asflags-y += -Isecurity/samsung/five
ccflags-y += -I$(srctree)
ccflags-y += -Wformat

five-y := five_lv.o five_cert.o five_keyring.o five_init.o  \
	  five_cert_builtin.o five_cache.o \
	  five_dmverity.o
five-$(CONFIG_FIVE_DSMS) += five_dsms.o

ifdef CONFIG_FIVE_GKI_20
  FILES := five_main.o five_appraise.o five_crypto.o five_audit.o \
           five_hooks.o task_integrity.o five_state.o five_vfs.o \
           five_tint_dev.o five_tee_interface.o
  five-y += $(addprefix gki/,$(FILES))
else
  five-y +=  five_crypto.o five_audit.o \
              five_hooks.o task_integrity.o five_state.o
    five-y += five_main.o five_appraise.o five_tee_interface.o
endif

# kunit tests options:
ENABLED_TARGETS_LIST = b0s g0s
ifeq ($(CONFIG_SEC_KUNIT), y)
  GCOV_PROFILE := y
  EXTRA_CFLAGS += -DFIVE_KUNIT_ENABLED
  five-$(CONFIG_FIVE) += five_dsms.o
  ifeq ($(CONFIG_UML), y)
  else
    ifneq ($(filter $(TARGET_DEVICE),$(ENABLED_TARGETS_LIST)),)
      ifeq ($(CONFIG_FIVE_PA_FEATURE), y)
      endif
    else
      $(warning security/five: TARGET_DEVICE: $(TARGET_DEVICE). skip on-device kunit test)
    endif
  endif
endif

# SPDX-License-Identifier: GPL-2.0
CFLAGS_REMOVE_core.o	= -pg
KASAN_SANITIZE_core.o	:= n
CFLAGS_core.o		+= -fno-stack-protector

obj-y += core.o

obj-$(CONFIG_INTEL_TDX_GUEST)	+= tdx/
obj-$(CONFIG_AMD_MEM_ENCRYPT)   += sev/

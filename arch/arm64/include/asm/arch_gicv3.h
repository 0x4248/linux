/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * arch/arm64/include/asm/arch_gicv3.h
 *
 * Copyright (C) 2015 ARM Ltd.
 */
#ifndef __ASM_ARCH_GICV3_H
#define __ASM_ARCH_GICV3_H

#include <asm/sysreg.h>

#ifndef __ASSEMBLY__

#include <linux/irqchip/arm-gic-common.h>
#include <linux/stringify.h>
#include <asm/barrier.h>
#include <asm/cacheflush.h>

#define read_gicreg(r)			read_sysreg_s(SYS_ ## r)
#define write_gicreg(v, r)		write_sysreg_s(v, SYS_ ## r)

/*
 * Low-level accessors
 *
 * These system registers are 32 bits, but we make sure that the compiler
 * sets the GP register's most significant bits to 0 with an explicit cast.
 */

static __always_inline void gic_write_dir(u32 irq)
{
	write_sysreg_s(irq, SYS_ICC_DIR_EL1);
	isb();
}

static inline u64 gic_read_iar_common(void)
{
	u64 irqstat;

	irqstat = read_sysreg_s(SYS_ICC_IAR1_EL1);
	dsb(sy);
	return irqstat;
}

/*
 * Cavium ThunderX erratum 23154
 *
 * The gicv3 of ThunderX requires a modified version for reading the
 * IAR status to ensure data synchronization (access to icc_iar1_el1
 * is not sync'ed before and after).
 *
 * Erratum 38545
 *
 * When a IAR register read races with a GIC interrupt RELEASE event,
 * GIC-CPU interface could wrongly return a valid INTID to the CPU
 * for an interrupt that is already released(non activated) instead of 0x3ff.
 *
 * To workaround this, return a valid interrupt ID only if there is a change
 * in the active priority list after the IAR read.
 *
 * Common function used for both the workarounds since,
 * 1. On Thunderx 88xx 1.x both erratas are applicable.
 * 2. Having extra nops doesn't add any side effects for Silicons where
 *    erratum 23154 is not applicable.
 */
static inline u64 gic_read_iar_cavium_thunderx(void)
{
	u64 irqstat, apr;

	apr = read_sysreg_s(SYS_ICC_AP1R0_EL1);
	nops(8);
	irqstat = read_sysreg_s(SYS_ICC_IAR1_EL1);
	nops(4);
	mb();

	/* Max priority groups implemented is only 32 */
	if (likely(apr != read_sysreg_s(SYS_ICC_AP1R0_EL1)))
		return irqstat;

	return 0x3ff;
}

static u64 __maybe_unused gic_read_iar(void)
{
	if (alternative_has_cap_unlikely(ARM64_WORKAROUND_CAVIUM_23154))
		return gic_read_iar_cavium_thunderx();
	else
		return gic_read_iar_common();
}

static inline void gic_write_ctlr(u32 val)
{
	write_sysreg_s(val, SYS_ICC_CTLR_EL1);
	isb();
}

static inline u32 gic_read_ctlr(void)
{
	return read_sysreg_s(SYS_ICC_CTLR_EL1);
}

static inline void gic_write_grpen1(u32 val)
{
	write_sysreg_s(val, SYS_ICC_IGRPEN1_EL1);
	isb();
}

static inline void gic_write_sgi1r(u64 val)
{
	write_sysreg_s(val, SYS_ICC_SGI1R_EL1);
}

static inline u32 gic_read_sre(void)
{
	return read_sysreg_s(SYS_ICC_SRE_EL1);
}

static inline void gic_write_sre(u32 val)
{
	write_sysreg_s(val, SYS_ICC_SRE_EL1);
	isb();
}

static inline void gic_write_bpr1(u32 val)
{
	write_sysreg_s(val, SYS_ICC_BPR1_EL1);
}

static inline u32 gic_read_pmr(void)
{
	return read_sysreg_s(SYS_ICC_PMR_EL1);
}

static __always_inline void gic_write_pmr(u32 val)
{
	write_sysreg_s(val, SYS_ICC_PMR_EL1);
}

static inline u32 gic_read_rpr(void)
{
	return read_sysreg_s(SYS_ICC_RPR_EL1);
}

#define gic_read_typer(c)		readq_relaxed(c)
#define gic_write_irouter(v, c)		writeq_relaxed(v, c)
#define gic_read_lpir(c)		readq_relaxed(c)
#define gic_write_lpir(v, c)		writeq_relaxed(v, c)

#define gic_flush_dcache_to_poc(a,l)	\
	dcache_clean_inval_poc((unsigned long)(a), (unsigned long)(a)+(l))

#define gits_read_baser(c)		readq_relaxed(c)
#define gits_write_baser(v, c)		writeq_relaxed(v, c)

#define gits_read_cbaser(c)		readq_relaxed(c)
#define gits_write_cbaser(v, c)		writeq_relaxed(v, c)

#define gits_write_cwriter(v, c)	writeq_relaxed(v, c)

#define gicr_read_propbaser(c)		readq_relaxed(c)
#define gicr_write_propbaser(v, c)	writeq_relaxed(v, c)

#define gicr_write_pendbaser(v, c)	writeq_relaxed(v, c)
#define gicr_read_pendbaser(c)		readq_relaxed(c)

#define gicr_write_vpropbaser(v, c)	writeq_relaxed(v, c)
#define gicr_read_vpropbaser(c)		readq_relaxed(c)

#define gicr_write_vpendbaser(v, c)	writeq_relaxed(v, c)
#define gicr_read_vpendbaser(c)		readq_relaxed(c)

static inline bool gic_prio_masking_enabled(void)
{
	return system_uses_irq_prio_masking();
}

static inline void gic_pmr_mask_irqs(void)
{
	gic_write_pmr(GIC_PRIO_IRQOFF);
}

static inline void gic_arch_enable_irqs(void)
{
	asm volatile ("msr daifclr, #3" : : : "memory");
}

static inline bool gic_has_relaxed_pmr_sync(void)
{
	return cpus_have_cap(ARM64_HAS_GIC_PRIO_RELAXED_SYNC);
}

#endif /* __ASSEMBLY__ */
#endif /* __ASM_ARCH_GICV3_H */
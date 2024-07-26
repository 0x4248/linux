/* SPDX-License-Identifier: MIT */
/*
 * Copyright © 2023 Intel Corporation
 */
#ifndef _XE_REGS_H_
#define _XE_REGS_H_

#include "regs/xe_reg_defs.h"

#define TIMESTAMP_OVERRIDE					XE_REG(0x44074)
#define   TIMESTAMP_OVERRIDE_US_COUNTER_DENOMINATOR_MASK	REG_GENMASK(15, 12)
#define   TIMESTAMP_OVERRIDE_US_COUNTER_DIVIDER_MASK		REG_GENMASK(9, 0)

#define PCU_IRQ_OFFSET				0x444e0
#define GU_MISC_IRQ_OFFSET			0x444f0
#define   GU_MISC_GSE				REG_BIT(27)

#define SOFTWARE_FLAGS_SPR33			XE_REG(0x4f084)

#define GU_CNTL_PROTECTED			XE_REG(0x10100C)
#define   DRIVERINT_FLR_DIS			REG_BIT(31)

#define GU_CNTL					XE_REG(0x101010)
#define   LMEM_INIT				REG_BIT(7)
#define   DRIVERFLR				REG_BIT(31)

#define GU_DEBUG				XE_REG(0x101018)
#define   DRIVERFLR_STATUS			REG_BIT(31)

#define XEHP_CLOCK_GATE_DIS			XE_REG(0x101014)
#define   SGSI_SIDECLK_DIS			REG_BIT(17)

#define XEHP_MTCFG_ADDR				XE_REG(0x101800)
#define   TILE_COUNT				REG_GENMASK(15, 8)

#define GGC					XE_REG(0x108040)
#define   GMS_MASK				REG_GENMASK(15, 8)
#define   GGMS_MASK				REG_GENMASK(7, 6)

#define DSMBASE					XE_REG(0x1080C0)
#define   BDSM_MASK				REG_GENMASK64(63, 20)

#define GSMBASE					XE_REG(0x108100)

#define STOLEN_RESERVED				XE_REG(0x1082c0)
#define   WOPCM_SIZE_MASK			REG_GENMASK64(9, 7)

#define MTL_RP_STATE_CAP			XE_REG(0x138000)

#define MTL_GT_RPE_FREQUENCY			XE_REG(0x13800c)

#define MTL_MEDIAP_STATE_CAP			XE_REG(0x138020)
#define   MTL_RPN_CAP_MASK			REG_GENMASK(24, 16)
#define   MTL_RP0_CAP_MASK			REG_GENMASK(8, 0)

#define MTL_MPE_FREQUENCY			XE_REG(0x13802c)
#define   MTL_RPE_MASK				REG_GENMASK(8, 0)

#define DG1_MSTR_TILE_INTR			XE_REG(0x190008)
#define   DG1_MSTR_IRQ				REG_BIT(31)
#define   DG1_MSTR_TILE(t)			REG_BIT(t)

#define GFX_MSTR_IRQ				XE_REG(0x190010, XE_REG_OPTION_VF)
#define   MASTER_IRQ				REG_BIT(31)
#define   GU_MISC_IRQ				REG_BIT(29)
#define   DISPLAY_IRQ				REG_BIT(16)
#define   GT_DW_IRQ(x)				REG_BIT(x)

#define PVC_RP_STATE_CAP			XE_REG(0x281014)

#endif

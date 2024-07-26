/* SPDX-License-Identifier: GPL-2.0-or-later */
/*
 * sma1303.h -- sma1303 ALSA SoC Audio driver
 *
 * Copyright 2023 Iron Device Corporation
 *
 * Author: Kiseok Jo <kiseok.jo@irondevice.com>
 *
 */

#ifndef _SMA1303_H
#define _SMA1303_H

#define  SMA1303_I2C_ADDR_00		0x1e
#define  SMA1303_I2C_ADDR_01		0x3e
#define  SMA1303_I2C_ADDR_10		0x5e
#define  SMA1303_I2C_ADDR_11		0x7e

#define  SMA1303_EXTERNAL_CLOCK_19_2	0x00
#define  SMA1303_EXTERNAL_CLOCK_24_576	0x01
#define  SMA1303_PLL_CLKIN_MCLK		0x02
#define  SMA1303_PLL_CLKIN_BCLK		0x03

#define  SMA1303_MONO			0x00
#define  SMA1303_STEREO			0x01

#define  SMA1303_I2C_RETRY_COUNT	3

/*
 * SMA1303 Register Definition
 */

/* SMA1303 Register Addresses */
#define  SMA1303_00_SYSTEM_CTRL		0x00
#define  SMA1303_01_INPUT1_CTRL1	0x01
#define  SMA1303_02_INPUT1_CTRL2	0x02
#define  SMA1303_03_INPUT1_CTRL3	0x03
#define  SMA1303_04_INPUT1_CTRL4	0x04
/* 0x05 ~ 0x08 : Reserved */
#define  SMA1303_09_OUTPUT_CTRL		0x09
#define  SMA1303_0A_SPK_VOL		0x0a
#define  SMA1303_0B_BST_TEST		0x0b
#define  SMA1303_0C_BST_TEST1		0x0c
#define  SMA1303_0D_SPK_TEST		0x0d
#define  SMA1303_0E_MUTE_VOL_CTRL	0x0e
/* 0x0F : Reserved */
#define  SMA1303_10_SYSTEM_CTRL1	0x10
#define  SMA1303_11_SYSTEM_CTRL2	0x11
#define  SMA1303_12_SYSTEM_CTRL3	0x12
/* 0x13 : Reserved */
#define  SMA1303_14_MODULATOR		0x14
#define  SMA1303_15_BASS_SPK1		0x15
#define  SMA1303_16_BASS_SPK2		0x16
#define  SMA1303_17_BASS_SPK3		0x17
#define  SMA1303_18_BASS_SPK4		0x18
#define  SMA1303_19_BASS_SPK5		0x19
#define  SMA1303_1A_BASS_SPK6		0x1a
#define  SMA1303_1B_BASS_SPK7		0x1b
/* 0x1C ~ 0x22 : Reserved */
#define  SMA1303_23_COMP_LIM1		0x23
#define  SMA1303_24_COMP_LIM2		0x24
#define  SMA1303_25_COMP_LIM3		0x25
#define  SMA1303_26_COMP_LIM4		0x26
/* 0x27 ~ 0x32 : Reserved */
#define  SMA1303_33_SDM_CTRL		0x33
#define  SMA1303_34_OTP_DATA1		0x34
/* 0x35 : Reserved */
#define  SMA1303_36_PROTECTION		0x36
#define  SMA1303_37_SLOPE_CTRL		0x37
#define  SMA1303_38_OTP_TRM0		0x38
/* 0x39 ~ 0x3A : Reserved */
#define  SMA1303_3B_TEST1		0x3b
#define  SMA1303_3C_TEST2		0x3c
#define  SMA1303_3D_TEST3		0x3d
#define  SMA1303_3E_ATEST1		0x3e
#define  SMA1303_3F_ATEST2		0x3f
/* 0x40 ~ 0x8A : Reserved */
#define	 SMA1303_8B_PLL_POST_N		0x8b
#define	 SMA1303_8C_PLL_N		0x8c
#define	 SMA1303_8D_PLL_A_SETTING	0x8d
#define	 SMA1303_8E_PLL_CTRL		0x8e
#define	 SMA1303_8F_PLL_P_CP		0x8f
#define  SMA1303_90_POSTSCALER		0x90
#define  SMA1303_91_CLASS_G_CTRL	0x91
#define  SMA1303_92_FDPEC_CTRL		0x92
/* 0x93 : Reserved */
#define  SMA1303_94_BOOST_CTRL1		0x94
#define  SMA1303_95_BOOST_CTRL2		0x95
#define  SMA1303_96_BOOST_CTRL3		0x96
#define  SMA1303_97_BOOST_CTRL4		0x97
/* 0x98 ~ 0x9F : Reserved */
#define  SMA1303_A0_PAD_CTRL0		0xa0
#define  SMA1303_A1_PAD_CTRL1		0xa1
#define	 SMA1303_A2_TOP_MAN1		0xa2
#define	 SMA1303_A3_TOP_MAN2		0xa3
#define	 SMA1303_A4_TOP_MAN3		0xa4
#define  SMA1303_A5_TDM1		0xa5
#define  SMA1303_A6_TDM2		0xa6
#define  SMA1303_A7_CLK_MON		0xa7
/* 0xA8 ~ 0xF9 : Reserved */
#define	 SMA1303_FA_STATUS1		0xfa
#define	 SMA1303_FB_STATUS2		0xfb
/* 0xFC ~ 0xFE : Reserved */
#define	 SMA1303_FF_DEVICE_INDEX	0xff

/* SMA1303 Registers Bit Fields */

/* SYSTEM_CTRL : 0x00 */
#define SMA1303_RESETBYI2C_MASK (1<<1)
#define SMA1303_RESETBYI2C_NORMAL (0<<1)
#define SMA1303_RESETBYI2C_RESET (1<<1)

#define SMA1303_POWER_MASK (1<<0)
#define SMA1303_POWER_OFF (0<<0)
#define SMA1303_POWER_ON (1<<0)

/* INTPUT CTRL1 : 0x01 */
#define SMA1303_CONTROLLER_DEVICE_MASK (1<<7)
#define SMA1303_DEVICE_MODE	(0<<7)
#define SMA1303_CONTROLLER_MODE	(1<<7)

#define SMA1303_I2S_MODE_MASK	(7<<4)
#define SMA1303_STANDARD_I2S	(0<<4)
#define SMA1303_LJ		(1<<4)
#define SMA1303_RJ_16BIT	(4<<4)
#define SMA1303_RJ_18BIT	(5<<4)
#define SMA1303_RJ_20BIT	(6<<4)
#define SMA1303_RJ_24BIT	(7<<4)

#define SMA1303_LEFTPOL_MASK	(1<<3)
#define SMA1303_LOW_FIRST_CH	(0<<3)
#define SMA1303_HIGH_FIRST_CH	(1<<3)

#define SMA1303_SCK_RISING_MASK	(1<<2)
#define SMA1303_SCK_FALLING_EDGE	(0<<2)
#define SMA1303_SCK_RISING_EDGE	(1<<2)

/* INTPUT CTRL2 : 0x02 */
#define SMA1303_IMODE_MASK (3<<6)
#define SMA1303_I2S	(0<<6)
#define SMA1303_PCM_SHORT (1<<6)
#define SMA1303_PCM_LONG (2<<6)

#define RSMA1303_IGHT_FIRST_MASK (1<<5)
#define SMA1303_LEFT_NORMAL (0<<5)
#define SMA1303_RIGHT_INVERTED (1<<5)

#define SMA1303_PCM_ALAW_MASK (1<<4)
#define SMA1303_PCM_U_DECODING (0<<4)
#define SMA1303_PCM_A_DECODING (1<<4)

#define SMA1303_PCM_COMP_MASK (1<<3)
#define SMA1303_PCM_LINEAR (0<<3)
#define SMA1303_PCM_COMPANDING (1<<3)

#define SMA1303_INPUTSEL_MASK (1<<2)
#define SMA1303_PCM_8KHZ (0<<2)
#define SMA1303_PCM_16KHZ (1<<2)

#define SMA1303_PCM_STEREO_MASK (1<<1)
#define SMA1303_PCM_MONO (0<<1)
#define SMA1303_PCM_STEREO (1<<1)

#define SMA1303_PCM_DL_MASK (1<<0)
#define SMA1303_PCM_8BIT (0<<0)
#define SMA1303_PCM_16BIT (1<<0)

/* INTPUT CTRL3 : 0x03 */
#define SMA1303_PCM_N_SLOT_MASK (15<<0)
#define SMA1303_PCM_N_SLOT1 (0<<0)
#define SMA1303_PCM_N_SLOT2 (1<<0)
#define SMA1303_PCM_N_SLOT3 (2<<0)
#define SMA1303_PCM_N_SLOT4 (3<<0)
#define SMA1303_PCM_N_SLOT5 (4<<0)
#define SMA1303_PCM_N_SLOT6 (5<<0)
#define SMA1303_PCM_N_SLOT7 (6<<0)
#define SMA1303_PCM_N_SLOT8 (7<<0)
#define SMA1303_PCM_N_SLOT9 (8<<0)
#define SMA1303_PCM_N_SLOT10 (9<<0)
#define SMA1303_PCM_N_SLOT11 (10<<0)
#define SMA1303_PCM_N_SLOT12 (11<<0)
#define SMA1303_PCM_N_SLOT13 (12<<0)
#define SMA1303_PCM_N_SLOT14 (13<<0)
#define SMA1303_PCM_N_SLOT15 (14<<0)
#define SMA1303_PCM_N_SLOT16 (15<<0)

/* INTPUT CTRL4 : 0x04 */
#define SMA1303_PCM1_SLOT_MASK (15<<4)
#define SMA1303_PCM1_SLOT1 (0<<4)
#define SMA1303_PCM1_SLOT2 (1<<4)
#define SMA1303_PCM1_SLOT3 (2<<4)
#define SMA1303_PCM1_SLOT4 (3<<4)
#define SMA1303_PCM1_SLOT5 (4<<4)
#define SMA1303_PCM1_SLOT6 (5<<4)
#define SMA1303_PCM1_SLOT7 (6<<4)
#define SMA1303_PCM1_SLOT8 (7<<4)
#define SMA1303_PCM1_SLOT9 (8<<4)
#define SMA1303_PCM1_SLOT10 (9<<4)
#define SMA1303_PCM1_SLOT11 (10<<4)
#define SMA1303_PCM1_SLOT12 (11<<4)
#define SMA1303_PCM1_SLOT13 (12<<4)
#define SMA1303_PCM1_SLOT14 (13<<4)
#define SMA1303_PCM1_SLOT15 (14<<4)
#define SMA1303_PCM1_SLOT16 (15<<4)

#define SMA1303_PCM2_SLOT_MASK (15<<0)
#define SMA1303_PCM2_SLOT1 (0<<0)
#define SMA1303_PCM2_SLOT2 (1<<0)
#define SMA1303_PCM2_SLOT3 (2<<0)
#define SMA1303_PCM2_SLOT4 (3<<0)
#define SMA1303_PCM2_SLOT5 (4<<0)
#define SMA1303_PCM2_SLOT6 (5<<0)
#define SMA1303_PCM2_SLOT7 (6<<0)
#define SMA1303_PCM2_SLOT8 (7<<0)
#define SMA1303_PCM2_SLOT9 (8<<0)
#define SMA1303_PCM2_SLOT10 (9<<0)
#define SMA1303_PCM2_SLOT11 (10<<0)
#define SMA1303_PCM2_SLOT12 (11<<0)
#define SMA1303_PCM2_SLOT13 (12<<0)
#define SMA1303_PCM2_SLOT14 (13<<0)
#define SMA1303_PCM2_SLOT15 (14<<0)
#define SMA1303_PCM2_SLOT16 (15<<0)

/* OUTPUT CTRL : 0x09 */
#define SMA1303_PORT_CONFIG_MASK (3<<5)
#define SMA1303_INPUT_PORT_ONLY (0<<5)
#define SMA1303_OUTPUT_PORT_ENABLE (2<<5)

#define SMA1303_PORT_OUT_SEL_MASK (7<<0)
#define SMA1303_OUT_SEL_DISABLE (0<<0)
#define SMA1303_FORMAT_CONVERTER (1<<0)
#define SMA1303_MIXER_OUTPUT (2<<0)
#define SMA1303_SPEAKER_PATH (3<<0)
#define SMA1303_POSTSCALER_OUTPUT (4<<0)

/* BST_TEST : 0x0B */
#define SMA1303_BST_OFF_SLOPE_MASK (3<<6)
#define SMA1303_BST_OFF_SLOPE_6_7ns (0<<6)
#define SMA1303_BST_OFF_SLOPE_4_8ns (1<<6)
#define SMA1303_BST_OFF_SLOPE_2_6ns (2<<6)
#define SMA1303_BST_OFF_SLOPE_1_2ns (3<<6)

#define SMA1303_OCP_TEST_MASK (1<<5)
#define SMA1303_OCP_NORMAL_MODE (0<<5)
#define SMA1303_OCP_TEST_MODE (1<<5)

#define SMA1303_BST_FAST_LEBN_MASK (1<<4)
#define SMA1303_BST_SHORT_LEB (0<<4)
#define SMA1303_BST_LONG_LEB (1<<4)

#define SMA1303_HIGH_PGAIN_MASK (1<<3)
#define SMA1303_NORMAL_P_GAIN (0<<3)
#define SMA1303_HIGH_P_GAIN (1<<3)

#define SMA1303_VCOMP_MASK (1<<2)
#define SMA1303_VCOMP_NORMAL_MODE (0<<2)
#define SMA1303_VCOMP_V_MON_MODE (1<<2)

#define SMA1303_PMOS_ON_MASK (1<<1)
#define SMA1303_PMOS_NORMAL_MODE (0<<1)
#define SMA1303_PMOS_TEST_MODE (1<<1)

#define SMA1303_NMOS_ON_MASK (1<<0)
#define SMA1303_NMOS_NORMAL_MODE (0<<0)
#define SMA1303_NMOS_TEST_MODE (1<<0)

/* BST_TEST1 : 0x0C */
#define SMA1303_SET_OCP_H_MASK (3<<6)
#define SMA1303_HIGH_OCP_4_5_LVL (0<<6)
#define SMA1303_HIGH_OCP_3_2_LVL (1<<6)
#define SMA1303_HIGH_OCP_2_1_LVL (2<<6)
#define SMA1303_HIGH_OCP_0_9_LVL (3<<6)

#define SMA1303_OCL_TEST_MASK (1<<5)
#define SMA1303_OCL_NORMAL_MODE (0<<5)
#define SMA1303_OCL_TEST_MODE (1<<5)

#define SMA1303_LOOP_CHECK_MASK (1<<4)
#define SMA1303_BST_LOOP_NORMAL_MODE (0<<4)
#define SMA1303_BST_LOOP_CHECK_MODE (1<<4)

#define SMA1303_EN_SH_PRT_MASK (1<<3)
#define SMA1303_EN_SH_PRT_DISABLE (0<<3)
#define SMA1303_EN_SH_PRT_ENABLE (1<<3)

/* SPK_TEST : 0x0D */
#define SMA1303_VREF_MON_MASK (1<<3)
#define SMA1303_VREF_NORMAL_MODE (0<<3)
#define SMA1303_VREF_V_MON_MODE (1<<3)

#define SMA1303_SPK_OCP_DLYN_MASK (1<<2)
#define SMA1303_SPK_OCP_LONG_DELAY (0<<2)
#define SMA1303_SPK_OCP_NORMAL (1<<2)

#define SMA1303_SPK_OFF_SLOPE_MASK (3<<0)
#define SMA1303_SPK_OFF_SLOPE_SLOW (0<<0)
#define SMA1303_SPK_OFF_SLOPE_FAST (3<<0)

/* MUTE_VOL_CTRL : 0x0E */
#define SMA1303_VOL_SLOPE_MASK (3<<6)
#define SMA1303_VOL_SLOPE_OFF (0<<6)
#define SMA1303_VOL_SLOPE_SLOW (1<<6)
#define SMA1303_VOL_SLOPE_MID (2<<6)
#define SMA1303_VOL_SLOPE_FAST (3<<6)

#define SMA1303_MUTE_SLOPE_MASK (3<<4)
#define SMA1303_MUTE_SLOPE_OFF (0<<4)
#define SMA1303_MUTE_SLOPE_SLOW (1<<4)
#define SMA1303_MUTE_SLOPE_MID (2<<4)
#define SMA1303_MUTE_SLOPE_FAST (3<<4)

#define SMA1303_SPK_MUTE_MASK (1<<0)
#define SMA1303_SPK_UNMUTE (0<<0)
#define SMA1303_SPK_MUTE (1<<0)

/* SYSTEM_CTRL1 :0x10 */
#define SMA1303_SPK_MODE_MASK (7<<2)
#define SMA1303_SPK_OFF (0<<2)
#define SMA1303_SPK_MONO (1<<2)
#define SMA1303_SPK_STEREO (4<<2)

/* SYSTEM_CTRL2 : 0x11 */
#define SMA1303_SPK_BS_MASK (1<<6)
#define SMA1303_SPK_BS_BYP (0<<6)
#define SMA1303_SPK_BS_EN (1<<6)
#define SMA1303_SPK_LIM_MASK (1<<5)
#define SMA1303_SPK_LIM_BYP (0<<5)
#define SMA1303_SPK_LIM_EN (1<<5)

#define SMA1303_LR_DATA_SW_MASK (1<<4)
#define SMA1303_LR_DATA_SW_NORMAL (0<<4)
#define SMA1303_LR_DATA_SW_SWAP (1<<4)

#define SMA1303_MONOMIX_MASK (1<<0)
#define SMA1303_MONOMIX_OFF (0<<0)
#define SMA1303_MONOMIX_ON (1<<0)

/* SYSTEM_CTRL3 : 0x12 */
#define SMA1303_INPUT_MASK (3<<6)
#define SMA1303_INPUT_0_DB (0<<6)
#define SMA1303_INPUT_M6_DB (1<<6)
#define SMA1303_INPUT_M12_DB (2<<6)
#define SMA1303_INPUT_INFI_DB (3<<6)
#define SMA1303_INPUT_R_MASK (3<<4)
#define SMA1303_INPUT_R_0_DB (0<<4)
#define SMA1303_INPUT_R_M6_DB (1<<4)
#define SMA1303_INPUT_R_M12_DB (2<<4)
#define SMA1303_INPUT_R_INFI_DB (3<<4)

/* Modulator : 0x14 */
#define SMA1303_SPK_HYSFB_MASK (3<<6)
#define SMA1303_HYSFB_625K (0<<6)
#define SMA1303_HYSFB_414K (1<<6)
#define SMA1303_HYSFB_297K (2<<6)
#define SMA1303_HYSFB_226K (3<<6)
#define SMA1303_SPK_BDELAY_MASK (63<<0)

/* SDM CONTROL : 0x33 */
#define SMA1303_SDM_Q_SEL_MASK (1<<2)
#define SMA1303_QUART_SEL_1_DIV_4 (0<<2)
#define SMA1303_QUART_SEL_1_DIV_8 (1<<2)

/* OTP_DATA1 : 0x34 */
#define SMA1303_OTP_LVL_MASK (1<<5)
#define SMA1303_OTP_LVL_NORMAL (0<<5)
#define SMA1303_OTP_LVL_LOW (1<<5)

/* PROTECTION : 0x36 */
#define SMA1303_EDGE_DIS_MASK (1<<7)
#define SMA1303_EDGE_DIS_ENABLE (0<<7)
#define SMA1303_EDGE_DIS_DISABLE (1<<7)

#define SMA1303_SPK_OCP_DIS_MASK (1<<3)
#define SMA1303_SPK_OCP_ENABLE (0<<3)
#define SMA1303_SPK_OCP_DISABLE (1<<3)

#define SMA1303_OCP_MODE_MASK (1<<2)
#define SMA1303_AUTO_RECOVER (0<<2)
#define SMA1303_SHUT_DOWN_PERMANENT (1<<2)

#define SMA1303_OTP_MODE_MASK (3<<0)
#define SMA1303_OTP_MODE_DISABLE (0<<0)
#define SMA1303_IG_THR1_SHUT_THR2 (1<<0)
#define SMA1303_REC_THR1_SHUT_THR2 (2<<0)
#define SMA1303_SHUT_THR1_SHUT_THR2 (3<<0)

/* TEST2 : 0x3C */
#define SMA1303_SPK_HSDM_BP_MASK (1<<4)
#define SMA1303_SPK_HSDM_ENABLE (0<<4)
#define SMA1303_SPK_HSDM_BYPASS (1<<4)

#define SMA1303_SDM_SYNC_DIS_MASK (1<<5)
#define SMA1303_SDM_SYNC_NORMAL (0<<5)
#define SMA1303_SDM_SYNC_DISABLE (1<<5)

/* ATEST2 : 0x3F */
#define SMA1303_SPK_OUT_FREQ_MASK (1<<2)
#define SMA1303_SPK_OUT_FREQ_360K (0<<2)
#define SMA1303_SPK_OUT_FREQ_410K (1<<2)

#define SMA1303_LOW_POWER_MODE_MASK (1<<3)
#define SMA1303_LOW_POWER_MODE_DISABLE (0<<3)
#define SMA1303_LOW_POWER_MODE_ENABLE (1<<3)

#define SMA1303_THERMAL_ADJUST_MASK (3<<5)
#define SMA1303_THERMAL_150_110 (0<<5)
#define SMA1303_THERMAL_160_120 (1<<5)
#define SMA1303_THERMAL_140_100 (2<<5)

#define SMA1303_FAST_OFF_DRIVE_SPK_MASK (1<<0)
#define SMA1303_FAST_OFF_DRIVE_SPK_DISABLE (0<<0)
#define SMA1303_FAST_OFF_DRIVE_SPK_ENABLE (1<<0)

/* PLL_CTRL : 0x8E */
#define SMA1303_TRM_LVL_MASK (1<<4)
#define SMA1303_TRM_LVL_NORMAL (0<<4)
#define SMA1303_TRM_LVL_LOW (1<<4)

#define SMA1303_LOW_OCL_MODE_MASK (1<<3)
#define SMA1303_LOW_OCL_MODE (0<<3)
#define SMA1303_NORMAL_OCL_MODE (1<<3)

#define SMA1303_PLL_PD2_MASK (7<<0)
#define SMA1303_PLL_PD2 (7<<0)
#define SMA1303_PLL_OPERATION2 (0<<0)

/* POSTSCALER : 0x90 */
#define SMA1303_BYP_POST_MASK (1<<0)
#define SMA1303_EN_POST_SCALER (0<<0)
#define SMA1303_BYP_POST_SCALER (1<<0)

/* FDPEC CONTROL : 0x92 */
#define SMA1303_FLT_VDD_GAIN_MASK (15<<4)
#define SMA1303_FLT_VDD_GAIN_2P40 (0<<4)
#define SMA1303_FLT_VDD_GAIN_2P45 (1<<4)
#define SMA1303_FLT_VDD_GAIN_2P50 (2<<4)
#define SMA1303_FLT_VDD_GAIN_2P55 (3<<4)
#define SMA1303_FLT_VDD_GAIN_2P60 (4<<4)
#define SMA1303_FLT_VDD_GAIN_2P65 (5<<4)
#define SMA1303_FLT_VDD_GAIN_2P70 (6<<4)
#define SMA1303_FLT_VDD_GAIN_2P75 (7<<4)
#define SMA1303_FLT_VDD_GAIN_2P80 (8<<4)
#define SMA1303_FLT_VDD_GAIN_2P85 (9<<4)
#define SMA1303_FLT_VDD_GAIN_2P90 (10<<4)
#define SMA1303_FLT_VDD_GAIN_2P95 (11<<4)
#define SMA1303_FLT_VDD_GAIN_3P00 (12<<4)
#define SMA1303_FLT_VDD_GAIN_3P05 (13<<4)
#define SMA1303_FLT_VDD_GAIN_3P10 (14<<4)
#define SMA1303_FLT_VDD_GAIN_3P15 (15<<4)

#define SMA1303_DIS_FCHG_MASK (1<<2)
#define SMA1303_EN_FAST_CHARGE (0<<2)
#define SMA1303_DIS_FAST_CHARGE (1<<2)

/* BOOST_CONTROL4 : 0x97 */
#define SMA1303_TRM_VBST_MASK (7<<2)
#define SMA1303_TRM_VBST_5P5 (0<<2)
#define SMA1303_TRM_VBST_5P6 (1<<2)
#define SMA1303_TRM_VBST_5P7 (2<<2)
#define SMA1303_TRM_VBST_5P8 (3<<2)
#define SMA1303_TRM_VBST_5P9 (4<<2)
#define SMA1303_TRM_VBST_6P0 (5<<2)
#define SMA1303_TRM_VBST_6P1 (6<<2)
#define SMA1303_TRM_VBST_6P2 (7<<2)

/* TOP_MAN1 : 0xA2 */
#define SMA1303_PLL_LOCK_SKIP_MASK (1<<7)
#define SMA1303_PLL_LOCK_ENABLE (0<<7)
#define SMA1303_PLL_LOCK_DISABLE (1<<7)

#define SMA1303_PLL_PD_MASK (1<<6)
#define SMA1303_PLL_OPERATION (0<<6)
#define SMA1303_PLL_PD (1<<6)

#define SMA1303_PLL_DIV_MASK (3<<4)
#define SMA1303_PLL_OUT (0<<4)
#define SMA1303_PLL_OUT_2 (1<<4)
#define SMA1303_PLL_OUT_4 (2<<4)
#define SMA1303_PLL_OUT_8 (3<<4)

#define SMA1303_PLL_REF_CLK_MASK (1<<3)
#define SMA1303_PLL_REF_CLK1 (0<<3)
#define SMA1303_PLL_SCK (1<<3)

#define SMA1303_DAC_DN_CONV_MASK (1<<2)
#define SMA1303_DAC_DN_CONV_DISABLE (0<<2)
#define SMA1303_DAC_DN_CONV_ENABLE (1<<2)

#define SMA1303_SDO_IO_MASK (1<<1)
#define SMA1303_HIGH_Z_LRCK_H (0<<1)
#define SMA1303_HIGH_Z_LRCK_L (1<<1)

#define SMA1303_SDO_OUTPUT2_MASK (1<<0)
#define SMA1303_SDO_NORMAL (0<<0)
#define SMA1303_SDO_OUTPUT_ONLY (1<<0)

/* TOP_MAN2 : 0xA3 */
#define SMA1303_MON_OSC_PLL_MASK (1<<7)
#define SMA1303_PLL_SDO (0<<7)
#define SMA1303_OSC_SDO (1<<7)

#define SMA1303_TEST_CLKO_EN_MASK (1<<6)
#define SMA1303_NORMAL_SDO (0<<6)
#define SMA1303_CLK_OUT_SDO (1<<6)

#define SMA1303_SDO_OUTPUT_MASK (1<<3)
#define SMA1303_NORMAL_OUT (0<<3)
#define SMA1303_HIGH_Z_OUT (1<<3)

#define SMA1303_CLOCK_MON_MASK (1<<1)
#define SMA1303_CLOCK_MON (0<<1)
#define SMA1303_CLOCK_NOT_MON (1<<1)

#define SMA1303_OSC_PD_MASK (1<<0)
#define SMA1303_NORMAL_OPERATION_OSC (0<<0)
#define SMA1303_POWER_DOWN_OSC (1<<0)

/* TOP_MAN3 0xA4 */
#define SMA1303_O_FORMAT_MASK (7<<5)
#define SMA1303_O_FMT_LJ (1<<5)
#define SMA1303_O_FMT_I2S (2<<5)
#define SMA1303_O_FMT_TDM (4<<5)

#define SMA1303_SCK_RATE_MASK (1<<3)
#define SMA1303_SCK_64FS (0<<3)
#define SMA1303_SCK_32FS (2<<3)

#define SMA1303_LRCK_POL_MASK (1<<0)
#define SMA1303_L_VALID (0<<0)
#define SMA1303_R_VALID (1<<0)

/* TDM1 FORMAT : 0xA5 */
#define SMA1303_TDM_CLK_POL_MASK (1<<7)
#define SMA1303_TDM_CLK_POL_RISE (0<<7)
#define SMA1303_TDM_CLK_POL_FALL (1<<7)

#define SMA1303_TDM_TX_MODE_MASK (1<<6)
#define SMA1303_TDM_TX_MONO (0<<6)
#define SMA1303_TDM_TX_STEREO (1<<6)

#define SMA1303_TDM_SLOT1_RX_POS_MASK (7<<3)
#define SMA1303_TDM_SLOT1_RX_POS_0 (0<<3)
#define SMA1303_TDM_SLOT1_RX_POS_1 (1<<3)
#define SMA1303_TDM_SLOT1_RX_POS_2 (2<<3)
#define SMA1303_TDM_SLOT1_RX_POS_3 (3<<3)
#define SMA1303_TDM_SLOT1_RX_POS_4 (4<<3)
#define SMA1303_TDM_SLOT1_RX_POS_5 (5<<3)
#define SMA1303_TDM_SLOT1_RX_POS_6 (6<<3)
#define SMA1303_TDM_SLOT1_RX_POS_7 (7<<3)

#define SMA1303_TDM_SLOT2_RX_POS_MASK (7<<0)
#define SMA1303_TDM_SLOT2_RX_POS_0 (0<<0)
#define SMA1303_TDM_SLOT2_RX_POS_1 (1<<0)
#define SMA1303_TDM_SLOT2_RX_POS_2 (2<<0)
#define SMA1303_TDM_SLOT2_RX_POS_3 (3<<0)
#define SMA1303_TDM_SLOT2_RX_POS_4 (4<<0)
#define SMA1303_TDM_SLOT2_RX_POS_5 (5<<0)
#define SMA1303_TDM_SLOT2_RX_POS_6 (6<<0)
#define SMA1303_TDM_SLOT2_RX_POS_7 (7<<0)

/* TDM2 FORMAT : 0xA6 */
#define SMA1303_TDM_DL_MASK (1<<7)
#define SMA1303_TDM_DL_16 (0<<7)
#define SMA1303_TDM_DL_32 (1<<7)

#define SMA1303_TDM_N_SLOT_MASK (1<<6)
#define SMA1303_TDM_N_SLOT_4 (0<<6)
#define SMA1303_TDM_N_SLOT_8 (1<<6)

#define SMA1303_TDM_SLOT1_TX_POS_MASK (7<<3)
#define SMA1303_TDM_SLOT1_TX_POS_0 (0<<3)
#define SMA1303_TDM_SLOT1_TX_POS_1 (1<<3)
#define SMA1303_TDM_SLOT1_TX_POS_2 (2<<3)
#define SMA1303_TDM_SLOT1_TX_POS_3 (3<<3)
#define SMA1303_TDM_SLOT1_TX_POS_4 (4<<3)
#define SMA1303_TDM_SLOT1_TX_POS_5 (5<<3)
#define SMA1303_TDM_SLOT1_TX_POS_6 (6<<3)
#define SMA1303_TDM_SLOT1_TX_POS_7 (7<<3)

#define SMA1303_TDM_SLOT2_TX_POS_MASK (7<<0)
#define SMA1303_TDM_SLOT2_TX_POS_0 (0<<0)
#define SMA1303_TDM_SLOT2_TX_POS_1 (1<<0)
#define SMA1303_TDM_SLOT2_TX_POS_2 (2<<0)
#define SMA1303_TDM_SLOT2_TX_POS_3 (3<<0)
#define SMA1303_TDM_SLOT2_TX_POS_4 (4<<0)
#define SMA1303_TDM_SLOT2_TX_POS_5 (5<<0)
#define SMA1303_TDM_SLOT2_TX_POS_6 (6<<0)
#define SMA1303_TDM_SLOT2_TX_POS_7 (7<<0)

/* STATUS1 : 0xFA */
#define SMA1303_OT1_OK_STATUS (1<<7)
#define SMA1303_OT2_OK_STATUS (1<<6)

/* STATUS2 : 0xFB */
#define SMA1303_OCP_SPK_STATUS (1<<5)
#define SMA1303_OCP_BST_STATUS (1<<4)
#define SMA1303_OTP_STAT_OK_0 (5<<1)
#define SMA1303_OTP_STAT_OK_1 (2<<2)

#define SMA1303_CLK_MON_STATUS (1<<0)

/* DEVICE_INFO : 0xFF */
#define SMA1303_DEVICE_ID (2<<3)
#define SMA1303_UVLO_BST_STATUS (1<<2)
#define SMA1303_REV_NUM_STATUS (3<<0)
#define SMA1303_REV_NUM_TV0 (0<<0)
#define SMA1303_REV_NUM_TV1 (1<<0)

#endif

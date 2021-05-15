/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Samsung Exynos SoC series dsp driver
 *
 * Copyright (c) 2019 Samsung Electronics Co., Ltd.
 *              http://www.samsung.com/
 */

#ifndef __HW_O3_DSP_HW_O3_CTRL_H__
#define __HW_O3_DSP_HW_O3_CTRL_H__

#include "hardware/dsp-ctrl.h"

#define ENABLE_DSP_O3_REG_IAC_S
#define ENABLE_DSP_O3_REG_AAREG_S
#define ENABLE_DSP_O3_REG_IAC_NS
#define ENABLE_DSP_O3_REG_AAREG_NS
//#define ENABLE_DSP_O3_REG_C2A0
//#define ENABLE_DSP_O3_REG_C2A1
#define ENABLE_DSP_O3_REG_GIC
#define ENABLE_DSP_O3_REG_NPUS
#define ENABLE_DSP_O3_REG_SDMA
//#define ENABLE_DSP_O3_REG_FLC00
//#define ENABLE_DSP_O3_REG_BAAW0
//#define ENABLE_DSP_O3_REG_PWM_NS
//#define ENABLE_DSP_O3_REG_PWM_S
#define ENABLE_DSP_O3_REG_MBOX_EXT_NS
//#define ENABLE_DSP_O3_REG_MBOX_EXT_S
//#define ENABLE_DSP_O3_REG_MBOX_INT_NS
//#define ENABLE_DSP_O3_REG_MBOX_INT_S
#define ENABLE_DSP_O3_REG_VPD0_CTRL

enum dsp_o3_reg_id {
#ifdef ENABLE_DSP_O3_REG_IAC_S
	DSP_O3_IAC_S_IAC_CTRL,
	DSP_O3_IAC_S_IAC_IRQ,
	DSP_O3_IAC_S_IAC_STACK_ADDR,
	DSP_O3_IAC_S_IAC_STATUS,
	DSP_O3_IAC_S_IAC_IRQ_CNT,
	DSP_O3_IAC_S_IRQ_SWI_STATUS_TO_CC,
	DSP_O3_IAC_S_IRQ_SWI_MSTATUS_TO_CC,
	DSP_O3_IAC_S_IRQ_SWI_ENABLE_TO_CC,
	DSP_O3_IAC_S_IRQ_SWI_SET_TO_CC,
	DSP_O3_IAC_S_IRQ_SWI_CLR_TO_CC,
	DSP_O3_IAC_S_IRQ_SWI_STATUS_TO_IAC,
	DSP_O3_IAC_S_IRQ_SWI_MSTATUS_TO_IAC,
	DSP_O3_IAC_S_IRQ_SWI_ENABLE_TO_IAC,
	DSP_O3_IAC_S_IRQ_SWI_SET_TO_IAC,
	DSP_O3_IAC_S_IRQ_SWI_CLR_TO_IAC,
	DSP_O3_IAC_S_IRQ_MBOX_ENABLE_TO_CC,
	DSP_O3_IAC_S_IRQ_MBOX_STATUS_TO_CC,
	DSP_O3_IAC_S_IRQ_MBOX_MSTATUS_TO_CC,
	DSP_O3_IAC_S_MBOX_IAC_TO_CC_INTR,
	DSP_O3_IAC_S_MBOX_IAC_TO_CC$,
	DSP_O3_IAC_S_MBOX_IVP0_TH0_TO_CC_INTR,
	DSP_O3_IAC_S_MBOX_IVP0_TH0_TO_CC$,
	DSP_O3_IAC_S_MBOX_IVP0_TH1_TO_CC_INTR,
	DSP_O3_IAC_S_MBOX_IVP0_TH1_TO_CC$,
	DSP_O3_IAC_S_MBOX_IVP1_TH0_TO_CC_INTR,
	DSP_O3_IAC_S_MBOX_IVP1_TH0_TO_CC$,
	DSP_O3_IAC_S_MBOX_IVP1_TH1_TO_CC_INTR,
	DSP_O3_IAC_S_MBOX_IVP1_TH1_TO_CC$,
#endif // ENABLE_DSP_O3_REG_IAC_S,
#ifdef ENABLE_DSP_O3_REG_AAREG_S
	DSP_O3_AAREG_S_SEMAPHORE_REG$,
#endif // ENABLE_DSP_O3_REG_AAREG_S
#ifdef ENABLE_DSP_O3_REG_IAC_NS
	DSP_O3_IAC_NS_SRESET,
	DSP_O3_IAC_NS_IAC_CTRL,
	DSP_O3_IAC_NS_IAC_IRQ,
	DSP_O3_IAC_NS_IAC_STACK_ADDR,
	DSP_O3_IAC_NS_IAC_STATUS,
	DSP_O3_IAC_NS_IAC_IRQ_CNT,
	DSP_O3_IAC_NS_IAC_SLVERRORADDR_PM,
	DSP_O3_IAC_NS_IAC_SLVERRORADDR_DM,
	DSP_O3_IAC_NS_IAC_PC,
	DSP_O3_IAC_NS_IAC_EPC0,
	DSP_O3_IAC_NS_IAC_EPC1,
	DSP_O3_IAC_NS_IAC_EPC2,
	DSP_O3_IAC_NS_IAC_EPC3,
	DSP_O3_IAC_NS_DBG_ENABLE,
	DSP_O3_IAC_NS_IRQ_DBG_STATUS_FR_PBOX,
	DSP_O3_IAC_NS_IRQ_DBG_MSTATUS_FR_PBOX,
	DSP_O3_IAC_NS_IRQ_DBG_ENABLE_FR_PBOX,
	DSP_O3_IAC_NS_IRQ_DBG_CLR_FR_PBOX,
	DSP_O3_IAC_NS_IRQ_SWI_STATUS_TO_CC,
	DSP_O3_IAC_NS_IRQ_SWI_MSTATUS_TO_CC,
	DSP_O3_IAC_NS_IRQ_SWI_ENABLE_TO_CC,
	DSP_O3_IAC_NS_IRQ_SWI_SET_TO_CC,
	DSP_O3_IAC_NS_IRQ_SWI_CLR_TO_CC,
	DSP_O3_IAC_NS_IRQ_SWI_STATUS_TO_IAC,
	DSP_O3_IAC_NS_IRQ_SWI_MSTATUS_TO_IAC,
	DSP_O3_IAC_NS_IRQ_SWI_ENABLE_TO_IAC,
	DSP_O3_IAC_NS_IRQ_SWI_SET_TO_IAC,
	DSP_O3_IAC_NS_IRQ_SWI_CLR_TO_IAC,
	DSP_O3_IAC_NS_IRQ_MBOX_ENABLE_TO_CC,
	DSP_O3_IAC_NS_IRQ_MBOX_STATUS_TO_CC,
	DSP_O3_IAC_NS_IRQ_MBOX_MSTATUS_TO_CC,
	DSP_O3_IAC_NS_MBOX_IAC_TO_CC_INTR,
	DSP_O3_IAC_NS_MBOX_IAC_TO_CC$,
	DSP_O3_IAC_NS_MBOX_IVP0_TH0_TO_CC_INTR,
	DSP_O3_IAC_NS_MBOX_IVP0_TH0_TO_CC$,
	DSP_O3_IAC_NS_MBOX_IVP0_TH1_TO_CC_INTR,
	DSP_O3_IAC_NS_MBOX_IVP0_TH1_TO_CC$,
	DSP_O3_IAC_NS_MBOX_IVP1_TH0_TO_CC_INTR,
	DSP_O3_IAC_NS_MBOX_IVP1_TH0_TO_CC$,
	DSP_O3_IAC_NS_MBOX_IVP1_TH1_TO_CC_INTR,
	DSP_O3_IAC_NS_MBOX_IVP1_TH1_TO_CC$,
#endif // ENABLE_DSP_O3_REG_IAC_NS
#ifdef ENABLE_DSP_O3_REG_AAREG_NS
	DSP_O3_AAREG_NS_SEMAPHORE_REG$,
#endif // ENABLE_DSP_O3_REG_AAREG_NS
#ifdef ENABLE_DSP_O3_REG_C2A0
#endif // ENABLE_DSP_O3_REG_C2A0
#ifdef ENABLE_DSP_O3_REG_C2A1
#endif // ENABLE_DSP_O3_REG_C2A1
#ifdef ENABLE_DSP_O3_REG_GIC
	DSP_O3_GICD_CTLR,
	DSP_O3_GICD_TYPER,
	DSP_O3_GICD_IIDR,
	DSP_O3_GICD_IGROUPR0,
	DSP_O3_GICD_IGROUPR$,
	DSP_O3_GICD_ISENABLER0,
	DSP_O3_GICD_ISENABLER$,
	DSP_O3_GICD_ICENABLER0,
	DSP_O3_GICD_ICENABLER$,
	DSP_O3_GICD_ISPENDR0,
	DSP_O3_GICD_ISPENDR$,
	DSP_O3_GICD_ICPENDR0,
	DSP_O3_GICD_ICPENDR$,
	DSP_O3_GICD_ISACTIVER0,
	DSP_O3_GICD_ISACTIVER$,
	DSP_O3_GICD_ICACTIVER0,
	DSP_O3_GICD_ICACTIVER$,
	DSP_O3_GICD_IPRIORITYR_SGI$,
	DSP_O3_GICD_IPRIORITYR_PPI0,
	DSP_O3_GICD_IPRIORITYR_PPI1,
	DSP_O3_GICD_IPRIORITYR_SPI$,
	DSP_O3_GICD_ITARGETSR_SGI$,
	DSP_O3_GICD_ITARGETSR_PPI0,
	DSP_O3_GICD_ITARGETSR_PPI1,
	DSP_O3_GICD_ITARGETSR_SPI$,
	DSP_O3_GICD_ICFGR_SGI,
	DSP_O3_GICD_ICFGR_PPI,
	DSP_O3_GICD_ICFGR_SPI$,
	DSP_O3_GICD_PPISR,
	DSP_O3_GICD_SPISRn$,
	DSP_O3_GICD_SGIR,
	DSP_O3_GICD_CPENDSGIR$,
	DSP_O3_GICD_SPENDSGIR$,
	DSP_O3_GICC_CTLR,
	DSP_O3_GICC_PMR,
	DSP_O3_GICC_BPR,
	DSP_O3_GICC_IAR,
	DSP_O3_GICC_EOIR,
	DSP_O3_GICC_RPR,
	DSP_O3_GICC_HPPIR,
	DSP_O3_GICC_ABPR,
	DSP_O3_GICC_AIAR,
	DSP_O3_GICC_AEOIR,
	DSP_O3_GICC_AHPPIR,
	DSP_O3_GICC_APR0,
	DSP_O3_GICC_NSAPR0,
	DSP_O3_GICC_IIDR,
	DSP_O3_GICC_DIR,
#endif // ENABLE_DSP_O3_REG_GIC
#ifdef ENABLE_DSP_O3_REG_NPUS
	DSP_O3_NPUS_USER_REG0,
	DSP_O3_NPUS_USER_REG1,
	DSP_O3_NPUS_USER_REG2,
	DSP_O3_NPUS_USER_REG3,
	DSP_O3_NPUS_USER_REG4,
	DSP_O3_NPUS_SFR_APB,
	DSP_O3_NPUS_DBGL1RST_DISABLE,
	DSP_O3_NPUS_CFGTE0,
	DSP_O3_NPUS_CFGTE1,
	DSP_O3_NPUS_VINITHI0,
	DSP_O3_NPUS_VINITHI1,
	DSP_O3_NPUS_CFGEND0,
	DSP_O3_NPUS_CFGEND1,
	DSP_O3_NPUS_PMUEVENT0,
	DSP_O3_NPUS_PMUEVENT1,
	DSP_O3_NPUS_EDBGRQ0,
	DSP_O3_NPUS_EDBGRQ1,
	DSP_O3_NPUS_EVENTI,
	DSP_O3_NPUS_STANDBY_WFI0,
	DSP_O3_NPUS_STANDBY_WFI1,
	DSP_O3_NPUS_STANDBY_WFE0,
	DSP_O3_NPUS_STANDBY_WFE1,
	DSP_O3_NPUS_STANDBY_WFIL2,
	DSP_O3_NPUS_CP15S_DISABLE20,
	DSP_O3_NPUS_CP15S_DISABLE21,
	DSP_O3_NPUS_PRESETDBG_CTRL,
	DSP_O3_NPUS_PRESETDBG,
	DSP_O3_NPUS_L2RESET_CTRL,
	DSP_O3_NPUS_L2RESET,
	DSP_O3_NPUS_CFGS_DISABLE,
	DSP_O3_NPUS_CORE0_S,
	DSP_O3_NPUS_CORE1_S,
	DSP_O3_NPUS_CORE2_S,
	DSP_O3_NPUS_CORE3_S,
	DSP_O3_NPUS_SHR_SRAM0_S,
	DSP_O3_NPUS_SHR_SRAM1_S,
	DSP_O3_NPUS_SHR_SRAM2_S,
	DSP_O3_NPUS_SHR_SRAM3_S,
	DSP_O3_NPUS_SDMA_TOTAL_S,
	DSP_O3_NPUS_RQGL_S,
	DSP_O3_NPUS_SDMA_CM_S,
	DSP_O3_NPUS_VC0_S,
	DSP_O3_NPUS_VC1_S,
	DSP_O3_NPUS_VC2_S,
	DSP_O3_NPUS_VC3_S,
	DSP_O3_NPUS_VC4_S,
	DSP_O3_NPUS_VC5_S,
	DSP_O3_NPUS_VC6_S,
	DSP_O3_NPUS_VC7_S,
	DSP_O3_NPUS_VC8_S,
	DSP_O3_NPUS_VC9_S,
	DSP_O3_NPUS_VC10_S,
	DSP_O3_NPUS_VC11_S,
	DSP_O3_NPUS_VC12_S,
	DSP_O3_NPUS_VC13_S,
	DSP_O3_NPUS_VC14_S,
	DSP_O3_NPUS_VC15_S,
	DSP_O3_NPUS_VC16_S,
	DSP_O3_NPUS_VC17_S,
	DSP_O3_NPUS_VC18_S,
	DSP_O3_NPUS_VC19_S,
	DSP_O3_NPUS_VC20_S,
	DSP_O3_NPUS_VC21_S,
	DSP_O3_NPUS_VC22_S,
	DSP_O3_NPUS_VC23_S,
	DSP_O3_NPUS_C2A0_S_GATING,
	DSP_O3_NPUS_C2A1_S_GATING,
	DSP_O3_NPUS_C2A0_S_IP_AXI,
	DSP_O3_NPUS_C2A1_S_IP_AXI,
	DSP_O3_NPUS_C2A0_S_OVERRIDE,
	DSP_O3_NPUS_C2A1_S_OVERRIDE,
	DSP_O3_NPUS_C2A0_S_OVERRIDE_SEL,
	DSP_O3_NPUS_C2A1_S_OVERRIDE_SEL,
	DSP_O3_NPUS_C2A0_SWRESET,
	DSP_O3_NPUS_C2A1_SWRESET,
	DSP_O3_NPUS_SSRAM_DEBUG_EN,
	DSP_O3_NPUS_SSRAM_CLK_GATE_DISABLE,
	DSP_O3_NPUS_STM_ENABLE,
	DSP_O3_NPUS_CPU_PC_VALUE0,
	DSP_O3_NPUS_PDMA_BOOT_FROM_PC,
	DSP_O3_NPUS_PDMA_BOOT_ADDR,
	DSP_O3_NPUS_PDMA_BOOT_MGR_NS,
	DSP_O3_NPUS_PDMA_BOOT_IRQ_NS,
	DSP_O3_NPUS_PDMA_BOOT_PERI_NS,
	DSP_O3_NPUS_QOS_CPU,
	DSP_O3_NPUS_QOS_CMDQ,
	DSP_O3_NPUS_QOS_SDMA_TCM,
	DSP_O3_NPUS_QOS_C2A,
	DSP_O3_NPUS_AXI_DSP,
	DSP_O3_NPUS_CPU_REMAP_EN,
	DSP_O3_NPUS_CPU_REMAP_SRC,
	DSP_O3_NPUS_CPU_REMAP_DEST,
	DSP_O3_NPUS_CPU_PC_VALUE1,
	DSP_O3_NPUS_INTC_CONTROL,
	DSP_O3_NPUS_INTC0_IGROUP,
	DSP_O3_NPUS_INTC0_IEN_SET,
	DSP_O3_NPUS_INTC0_IEN_CLR,
	DSP_O3_NPUS_INTC0_IPEND,
	DSP_O3_NPUS_INTC0_IPRIO_PEND,
	DSP_O3_NPUS_INTC0_IPRIORITY0,
	DSP_O3_NPUS_INTC0_IPRIORITY1,
	DSP_O3_NPUS_INTC0_IPRIORITY2,
	DSP_O3_NPUS_INTC0_IPRIORITY3,
	DSP_O3_NPUS_INTC0_IPRIO_S_PEND,
	DSP_O3_NPUS_INTC0_IPRIO_NS_PEND,
	DSP_O3_NPUS_INTC1_IGROUP,
	DSP_O3_NPUS_INTC1_IEN_SET,
	DSP_O3_NPUS_INTC1_IEN_CLR,
	DSP_O3_NPUS_INTC1_IPEND,
	DSP_O3_NPUS_INTC1_IPRIO_PEND,
	DSP_O3_NPUS_INTC1_IPRIORITY0,
	DSP_O3_NPUS_INTC1_IPRIORITY1,
	DSP_O3_NPUS_INTC1_IPRIORITY2,
	DSP_O3_NPUS_INTC1_IPRIORITY3,
	DSP_O3_NPUS_INTC1_IPRIO_S_PEND,
	DSP_O3_NPUS_INTC1_IPRIO_NS_PEND,
#endif // ENABLE_DSP_O3_REG_NPUS
#ifdef ENABLE_DSP_O3_REG_SDMA
	DSP_O3_SDMA_VERSION,
	DSP_O3_SDMA_SRESET,
	DSP_O3_SDMA_CLOCK_GATE_EN,
	DSP_O3_SDMA_CLOCK_GATE_SE_SET_0,
	DSP_O3_SDMA_CLOCK_GATE_SE_SET_1,
	DSP_O3_SDMA_MO_CTRL_EXT,
	DSP_O3_SDMA_MO_CTRL_INT_RD,
	DSP_O3_SDMA_MO_CTRL_INT_WR,
	DSP_O3_SDMA_ARQOS_LUT,
	DSP_O3_SDMA_AWQOS_LUT,
	DSP_O3_SDMA_DESCRIPTOR_QUEUE_CFG_VC0,
	DSP_O3_SDMA_DESCRIPTOR_QUEUE_CFG_VC1,
	DSP_O3_SDMA_DESCRIPTOR_QUEUE_CFG_VC2,
	DSP_O3_SDMA_DESCRIPTOR_QUEUE_CFG_VC3,
	DSP_O3_SDMA_DESCRIPTOR_QUEUE_CFG_VC4,
	DSP_O3_SDMA_DESCRIPTOR_QUEUE_CFG_VC5,
	DSP_O3_SDMA_DESCRIPTOR_QUEUE_CFG_VC6,
	DSP_O3_SDMA_DESCRIPTOR_QUEUE_CFG_VC7,
	DSP_O3_SDMA_DESCRIPTOR_QUEUE_CFG_VC8,
	DSP_O3_SDMA_DESCRIPTOR_QUEUE_CFG_VC9,
	DSP_O3_SDMA_DESCRIPTOR_QUEUE_CFG_VC10,
	DSP_O3_SDMA_DESCRIPTOR_QUEUE_CFG_VC11,
	DSP_O3_SDMA_DESCRIPTOR_QUEUE_CFG_VC12,
	DSP_O3_SDMA_DESCRIPTOR_QUEUE_CFG_VC13,
	DSP_O3_SDMA_DESCRIPTOR_QUEUE_CFG_VC14,
	DSP_O3_SDMA_DESCRIPTOR_QUEUE_CFG_VC15,
	DSP_O3_SDMA_DESCRIPTOR_QUEUE_CFG_VC16,
	DSP_O3_SDMA_DESCRIPTOR_QUEUE_CFG_VC17,
	DSP_O3_SDMA_DESCRIPTOR_QUEUE_CFG_VC18,
	DSP_O3_SDMA_DESCRIPTOR_QUEUE_CFG_VC19,
	DSP_O3_SDMA_DESCRIPTOR_QUEUE_CFG_VC20,
	DSP_O3_SDMA_DESCRIPTOR_QUEUE_CFG_VC21,
	DSP_O3_SDMA_DESCRIPTOR_QUEUE_CFG_VC22,
	DSP_O3_SDMA_DESCRIPTOR_QUEUE_CFG_VC23,
	DSP_O3_SDMA_ERR_CODES,
	DSP_O3_SDMA_ERR_MASK,
	DSP_O3_SDMA_INTERRUPT_CM,
	DSP_O3_SDMA_INTERRUPT_MASK_CM,
	DSP_O3_SDMA_INTERRUPT_DONE_NS,
	DSP_O3_SDMA_INTERRUPT_BLK_DONE_NS,
	DSP_O3_SDMA_INTERRUPT_FORCE_NS,
	DSP_O3_SDMA_INTERRUPT_GROUP_NS,
	DSP_O3_SDMA_INTERRUPT_QUEUE_NS_VC0,
	DSP_O3_SDMA_INTERRUPT_QUEUE_NS_VC1,
	DSP_O3_SDMA_INTERRUPT_QUEUE_NS_VC2,
	DSP_O3_SDMA_INTERRUPT_QUEUE_NS_VC3,
	DSP_O3_SDMA_INTERRUPT_QUEUE_NS_VC4,
	DSP_O3_SDMA_INTERRUPT_QUEUE_NS_VC5,
	DSP_O3_SDMA_INTERRUPT_QUEUE_NS_VC6,
	DSP_O3_SDMA_INTERRUPT_QUEUE_NS_VC7,
	DSP_O3_SDMA_INTERRUPT_QUEUE_NS_VC8,
	DSP_O3_SDMA_INTERRUPT_QUEUE_NS_VC9,
	DSP_O3_SDMA_INTERRUPT_QUEUE_NS_VC10,
	DSP_O3_SDMA_INTERRUPT_QUEUE_NS_VC11,
	DSP_O3_SDMA_INTERRUPT_QUEUE_NS_VC12,
	DSP_O3_SDMA_INTERRUPT_QUEUE_NS_VC13,
	DSP_O3_SDMA_INTERRUPT_QUEUE_NS_VC14,
	DSP_O3_SDMA_INTERRUPT_QUEUE_NS_VC15,
	DSP_O3_SDMA_INTERRUPT_QUEUE_NS_VC16,
	DSP_O3_SDMA_INTERRUPT_QUEUE_NS_VC17,
	DSP_O3_SDMA_INTERRUPT_QUEUE_NS_VC18,
	DSP_O3_SDMA_INTERRUPT_QUEUE_NS_VC19,
	DSP_O3_SDMA_INTERRUPT_QUEUE_NS_VC20,
	DSP_O3_SDMA_INTERRUPT_QUEUE_NS_VC21,
	DSP_O3_SDMA_INTERRUPT_QUEUE_NS_VC22,
	DSP_O3_SDMA_INTERRUPT_QUEUE_NS_VC23,
	DSP_O3_SDMA_INTERRUPT_DONE_S,
	DSP_O3_SDMA_INTERRUPT_BLK_DONE_S,
	DSP_O3_SDMA_INTERRUPT_FORCE_S,
	DSP_O3_SDMA_INTERRUPT_GROUP_S,
	DSP_O3_SDMA_INTERRUPT_QUEUE_S_VC0,
	DSP_O3_SDMA_INTERRUPT_QUEUE_S_VC1,
	DSP_O3_SDMA_INTERRUPT_QUEUE_S_VC2,
	DSP_O3_SDMA_INTERRUPT_QUEUE_S_VC3,
	DSP_O3_SDMA_INTERRUPT_QUEUE_S_VC4,
	DSP_O3_SDMA_INTERRUPT_QUEUE_S_VC5,
	DSP_O3_SDMA_INTERRUPT_QUEUE_S_VC6,
	DSP_O3_SDMA_INTERRUPT_QUEUE_S_VC7,
	DSP_O3_SDMA_INTERRUPT_QUEUE_S_VC8,
	DSP_O3_SDMA_INTERRUPT_QUEUE_S_VC9,
	DSP_O3_SDMA_INTERRUPT_QUEUE_S_VC10,
	DSP_O3_SDMA_INTERRUPT_QUEUE_S_VC11,
	DSP_O3_SDMA_INTERRUPT_QUEUE_S_VC12,
	DSP_O3_SDMA_INTERRUPT_QUEUE_S_VC13,
	DSP_O3_SDMA_INTERRUPT_QUEUE_S_VC14,
	DSP_O3_SDMA_INTERRUPT_QUEUE_S_VC15,
	DSP_O3_SDMA_INTERRUPT_QUEUE_S_VC16,
	DSP_O3_SDMA_INTERRUPT_QUEUE_S_VC17,
	DSP_O3_SDMA_INTERRUPT_QUEUE_S_VC18,
	DSP_O3_SDMA_INTERRUPT_QUEUE_S_VC19,
	DSP_O3_SDMA_INTERRUPT_QUEUE_S_VC20,
	DSP_O3_SDMA_INTERRUPT_QUEUE_S_VC21,
	DSP_O3_SDMA_INTERRUPT_QUEUE_S_VC22,
	DSP_O3_SDMA_INTERRUPT_QUEUE_S_VC23,
	DSP_O3_SDMA_TCM0_TRANSFER_ON_VC0,
	DSP_O3_SDMA_TCM1_TRANSFER_ON_VC0,
	DSP_O3_SDMA_TCM0_TRANSFER_ON_VC1,
	DSP_O3_SDMA_TCM1_TRANSFER_ON_VC1,
	DSP_O3_SDMA_TCM0_TRANSFER_ON_VC2,
	DSP_O3_SDMA_TCM1_TRANSFER_ON_VC2,
	DSP_O3_SDMA_TCM0_TRANSFER_ON_VC3,
	DSP_O3_SDMA_TCM1_TRANSFER_ON_VC3,
	DSP_O3_SDMA_TCM0_TRANSFER_ON_VC4,
	DSP_O3_SDMA_TCM1_TRANSFER_ON_VC4,
	DSP_O3_SDMA_TCM0_TRANSFER_ON_VC5,
	DSP_O3_SDMA_TCM1_TRANSFER_ON_VC5,
	DSP_O3_SDMA_TCM0_TRANSFER_ON_VC6,
	DSP_O3_SDMA_TCM1_TRANSFER_ON_VC6,
	DSP_O3_SDMA_TCM0_TRANSFER_ON_VC7,
	DSP_O3_SDMA_TCM1_TRANSFER_ON_VC7,
	DSP_O3_SDMA_TCM0_TRANSFER_ON_VC8,
	DSP_O3_SDMA_TCM1_TRANSFER_ON_VC8,
	DSP_O3_SDMA_TCM0_TRANSFER_ON_VC9,
	DSP_O3_SDMA_TCM1_TRANSFER_ON_VC9,
	DSP_O3_SDMA_TCM0_TRANSFER_ON_VC10,
	DSP_O3_SDMA_TCM1_TRANSFER_ON_VC10,
	DSP_O3_SDMA_TCM0_TRANSFER_ON_VC11,
	DSP_O3_SDMA_TCM1_TRANSFER_ON_VC11,
	DSP_O3_SDMA_TCM0_TRANSFER_ON_VC12,
	DSP_O3_SDMA_TCM1_TRANSFER_ON_VC12,
	DSP_O3_SDMA_TCM0_TRANSFER_ON_VC13,
	DSP_O3_SDMA_TCM1_TRANSFER_ON_VC13,
	DSP_O3_SDMA_TCM0_TRANSFER_ON_VC14,
	DSP_O3_SDMA_TCM1_TRANSFER_ON_VC14,
	DSP_O3_SDMA_TCM0_TRANSFER_ON_VC15,
	DSP_O3_SDMA_TCM1_TRANSFER_ON_VC15,
	DSP_O3_SDMA_TCM0_TRANSFER_ON_VC16,
	DSP_O3_SDMA_TCM1_TRANSFER_ON_VC16,
	DSP_O3_SDMA_TCM0_TRANSFER_ON_VC17,
	DSP_O3_SDMA_TCM1_TRANSFER_ON_VC17,
	DSP_O3_SDMA_TCM0_TRANSFER_ON_VC18,
	DSP_O3_SDMA_TCM1_TRANSFER_ON_VC18,
	DSP_O3_SDMA_TCM0_TRANSFER_ON_VC19,
	DSP_O3_SDMA_TCM1_TRANSFER_ON_VC19,
	DSP_O3_SDMA_TCM0_TRANSFER_ON_VC20,
	DSP_O3_SDMA_TCM1_TRANSFER_ON_VC20,
	DSP_O3_SDMA_TCM0_TRANSFER_ON_VC21,
	DSP_O3_SDMA_TCM1_TRANSFER_ON_VC21,
	DSP_O3_SDMA_TCM0_TRANSFER_ON_VC22,
	DSP_O3_SDMA_TCM1_TRANSFER_ON_VC22,
	DSP_O3_SDMA_TCM0_TRANSFER_ON_VC23,
	DSP_O3_SDMA_TCM1_TRANSFER_ON_VC23,
	DSP_O3_SDMA_FLT_INFO_SET_CFG,
	DSP_O3_SDMA_FLT_INFO_MAX_SET0,
	DSP_O3_SDMA_FLT_INFO_MIN_SET0,
	DSP_O3_SDMA_FLT_INFO_SUM_SET0,
	DSP_O3_SDMA_FLT_INFO_SUM2_SET0,
	DSP_O3_SDMA_FLT_INFO_MAX_SET1,
	DSP_O3_SDMA_FLT_INFO_MIN_SET1,
	DSP_O3_SDMA_FLT_INFO_SUM_SET1,
	DSP_O3_SDMA_FLT_INFO_SUM2_SET1,
	DSP_O3_SDMA_FLT_INFO_MAX_SET2,
	DSP_O3_SDMA_FLT_INFO_MIN_SET2,
	DSP_O3_SDMA_FLT_INFO_SUM_SET2,
	DSP_O3_SDMA_FLT_INFO_SUM2_SET2,
	DSP_O3_SDMA_FLT_INFO_MAX_SET3,
	DSP_O3_SDMA_FLT_INFO_MIN_SET3,
	DSP_O3_SDMA_FLT_INFO_SUM_SET3,
	DSP_O3_SDMA_FLT_INFO_SUM2_SET3,
	DSP_O3_SDMA_STATUS_SE_0,
	DSP_O3_SDMA_STATUS_SE_1,
	DSP_O3_SDMA_STATUS_INT_SOURCE_ERR,
	DSP_O3_SDMA_STATUS_INT_SOURCE_DONE,
	DSP_O3_SDMA_STATUS_INT_SOURCE_BLK_DONE,
	DSP_O3_SDMA_STATUS_INT_SOURCE_GROUP,
	DSP_O3_SDMA_STATUS_VC_INFO_VC0_7,
	DSP_O3_SDMA_STATUS_VC_INFO_VC8_15,
	DSP_O3_SDMA_STATUS_VC_INFO_VC16_23,
	DSP_O3_SDMA_STATUS_TCM0_SDMA_MUTEX,
	DSP_O3_SDMA_STATUS_TCM1_SDMA_MUTEX,
	DSP_O3_SDMA_TCM0_TRANSFER_ON_UPDATE_VC,
	DSP_O3_SDMA_TCM1_TRANSFER_ON_UPDATE_VC,
	DSP_O3_SDMA_NSECURE,
	DSP_O3_SDMA_DEBUG_ADDR,
	DSP_O3_SDMA_DEBUG_REG0,
	/* More Detail INFO each VC$ below */
#endif // ENABLE_DSP_O3_REG_SDMA
#ifdef ENABLE_DSP_O3_REG_FLC00
#endif // ENABLE_DSP_O3_REG_FLC00
#ifdef ENABLE_DSP_O3_REG_BAAW0
#endif // ENABLE_DSP_O3_REG_BAAW0
#ifdef ENABLE_DSP_O3_REG_PWM_NS
#endif // ENABLE_DSP_O3_REG_PWM_NS
#ifdef ENABLE_DSP_O3_REG_PWM_S
#endif // ENABLE_DSP_O3_REG_PWM_S
#ifdef ENABLE_DSP_O3_REG_MBOX_EXT_NS
	DSP_O3_MBOX_EXT_NS_MCUCTRL,
	DSP_O3_MBOX_EXT_NS_IS_VERSION,
	DSP_O3_MBOX_EXT_NS_INT_0_GR,
	DSP_O3_MBOX_EXT_NS_INT_0_CR,
	DSP_O3_MBOX_EXT_NS_INT_0_MR,
	DSP_O3_MBOX_EXT_NS_INT_0_SR,
	DSP_O3_MBOX_EXT_NS_INT_0_MSR,
#endif // ENABLE_DSP_O3_REG_MBOX_EXT_NS
#ifdef ENABLE_DSP_O3_REG_MBOX_EXT_S
#endif // ENABLE_DSP_O3_REG_MBOX_EXT_S
#ifdef ENABLE_DSP_O3_REG_MBOX_INT_NS
#endif // ENABLE_DSP_O3_REG_MBOX_INT_NS
#ifdef ENABLE_DSP_O3_REG_MBOX_INT_S
#endif // ENABLE_DSP_O3_REG_MBOX_INT_S
#ifdef ENABLE_DSP_O3_REG_VPD0_CTRL
	DSP_O3_VPD0_MCGEN,
	DSP_O3_VPD0_IVP_SWRESET,
	DSP_O3_VPD0_PERF_MON_ENABLE,
	DSP_O3_VPD0_PERF_MON_CLEAR,
	DSP_O3_VPD0_DBG_MON_ENABLE,
	DSP_O3_VPD0_DBG_INTR_STATUS,
	DSP_O3_VPD0_DBG_INTR_ENABLE,
	DSP_O3_VPD0_DBG_INTR_CLEAR,
	DSP_O3_VPD0_DBG_INTR_MSTATUS,
	DSP_O3_VPD0_IVP_SFR2AXI_SGMO,
	DSP_O3_VPD0_CLOCK_CONFIG,
	DSP_O3_VPD0_VM_STACK_START$,
	DSP_O3_VPD0_VM_STACK_END$,
	DSP_O3_VPD0_VM_MODE,
	DSP_O3_VPD0_PERF_IVP0_TH0_PC,
	DSP_O3_VPD0_PERF_IVP0_TH0_VALID_CNTL,
	DSP_O3_VPD0_PERF_IVP0_TH0_VALID_CNTH,
	DSP_O3_VPD0_PERF_IVP0_TH0_STALL_CNT,
	DSP_O3_VPD0_PERF_IVP0_TH1_PC,
	DSP_O3_VPD0_PERF_IVP0_TH1_VALID_CNTL,
	DSP_O3_VPD0_PERF_IVP0_TH1_VALID_CNTH,
	DSP_O3_VPD0_PERF_IVP0_TH1_STALL_CNT,
	DSP_O3_VPD0_PERF_IVP0_IC_REQL,
	DSP_O3_VPD0_PERF_IVP0_IC_REQH,
	DSP_O3_VPD0_PERF_IVP0_IC_MISS,
	DSP_O3_VPD0_PERF_IVP0_INST_CNTL$,
	DSP_O3_VPD0_PERF_IVP0_INST_CNTH$,
	DSP_O3_VPD0_PERF_IVP1_TH0_PC,
	DSP_O3_VPD0_PERF_IVP1_TH0_VALID_CNTL,
	DSP_O3_VPD0_PERF_IVP1_TH0_VALID_CNTH,
	DSP_O3_VPD0_PERF_IVP1_TH0_STALL_CNT,
	DSP_O3_VPD0_PERF_IVP1_TH1_PC,
	DSP_O3_VPD0_PERF_IVP1_TH1_VALID_CNTL,
	DSP_O3_VPD0_PERF_IVP1_TH1_VALID_CNTH,
	DSP_O3_VPD0_PERF_IVP1_TH1_STALL_CNT,
	DSP_O3_VPD0_PERF_IVP1_IC_REQL,
	DSP_O3_VPD0_PERF_IVP1_IC_REQH,
	DSP_O3_VPD0_PERF_IVP1_IC_MISS,
	DSP_O3_VPD0_PERF_IVP1_INST_CNTL$,
	DSP_O3_VPD0_PERF_IVP1_INST_CNTH$,
	DSP_O3_VPD0_DBG_IVP0_ADDR_PM,
	DSP_O3_VPD0_DBG_IVP0_ADDR_DM,
	DSP_O3_VPD0_DBG_IVP0_ERROR_INFO,
	DSP_O3_VPD0_DBG_IVP0_TH0_ERROR_PC$,
	DSP_O3_VPD0_DBG_IVP0_TH1_ERROR_PC$,
	DSP_O3_VPD0_DBG_IVP1_ADDR_PM,
	DSP_O3_VPD0_DBG_IVP1_ADDR_DM,
	DSP_O3_VPD0_DBG_IVP1_ERROR_INFO,
	DSP_O3_VPD0_DBG_IVP1_TH0_ERROR_PC$,
	DSP_O3_VPD0_DBG_IVP1_TH1_ERROR_PC$,
	DSP_O3_VPD0_DBG_MPU_SMONITOR$,
	DSP_O3_VPD0_DBG_MPU_EMONITOR$,
	DSP_O3_VPD0_AXI_ERROR_RD,
	DSP_O3_VPD0_AXI_ERROR_WR,
	DSP_O3_VPD0_RD_MOCNT$,
	DSP_O3_VPD0_WR_MOCNT$,
	DSP_O3_VPD0_IVP0_WAKEUP,
	DSP_O3_VPD0_IVP0_INTR_STATUS_TH$,
	DSP_O3_VPD0_IVP0_INTR_ENABLE_TH$,
	DSP_O3_VPD0_IVP0_SWI_SET_TH$,
	DSP_O3_VPD0_IVP0_SWI_CLEAR_TH$,
	DSP_O3_VPD0_IVP0_MASKED_STATUS_TH$,
	DSP_O3_VPD0_IVP0_IC_BASE_ADDR,
	DSP_O3_VPD0_IVP0_IC_CODE_SIZE,
	DSP_O3_VPD0_IVP0_IC_INVALID_REQ,
	DSP_O3_VPD0_IVP0_IC_INVALID_STATUS,
	DSP_O3_VPD0_IVP0_DM_STACK_START$,
	DSP_O3_VPD0_IVP0_DM_STACK_END$,
	DSP_O3_VPD0_IVP0_STATUS,
	DSP_O3_VPD0_IVP1_WAKEUP,
	DSP_O3_VPD0_IVP1_INTR_STATUS_TH$,
	DSP_O3_VPD0_IVP1_INTR_ENABLE_TH$,
	DSP_O3_VPD0_IVP1_SWI_SET_TH$,
	DSP_O3_VPD0_IVP1_SWI_CLEAR_TH$,
	DSP_O3_VPD0_IVP1_MASKED_STATUS_TH$,
	DSP_O3_VPD0_IVP1_IC_BASE_ADDR,
	DSP_O3_VPD0_IVP1_IC_CODE_SIZE,
	DSP_O3_VPD0_IVP1_IC_INVALID_REQ,
	DSP_O3_VPD0_IVP1_IC_INVALID_STATUS,
	DSP_O3_VPD0_IVP1_DM_STACK_START$,
	DSP_O3_VPD0_IVP1_DM_STACK_END$,
	DSP_O3_VPD0_IVP1_STATUS,
	DSP_O3_VPD0_IVP0_MAILBOX_INTR_TH0,
	DSP_O3_VPD0_IVP0_MAILBOX_TH0_$,
	DSP_O3_VPD0_IVP0_MAILBOX_INTR_TH1,
	DSP_O3_VPD0_IVP0_MAILBOX_TH1_$,
	DSP_O3_VPD0_IVP1_MAILBOX_INTR_TH0,
	DSP_O3_VPD0_IVP1_MAILBOX_TH0_$,
	DSP_O3_VPD0_IVP1_MAILBOX_INTR_TH1,
	DSP_O3_VPD0_IVP1_MAILBOX_TH1_$,
	DSP_O3_VPD0_IVP0_MSG_TH0_$,
	DSP_O3_VPD0_IVP0_MSG_TH1_$,
	DSP_O3_VPD0_IVP1_MSG_TH0_$,
	DSP_O3_VPD0_IVP1_MSG_TH1_$,
#endif // ENABLE_DSP_O3_REG_VPD0_CTRL

	DSP_O3_REG_END,
};

int dsp_hw_o3_ctrl_init(void);

#endif

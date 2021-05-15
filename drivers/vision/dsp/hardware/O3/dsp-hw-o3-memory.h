/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Samsung Exynos SoC series dsp driver
 *
 * Copyright (c) 2019 Samsung Electronics Co., Ltd.
 *              http://www.samsung.com/
 */

#ifndef __HW_O3_DSP_HW_O3_MEMORY_H__
#define __HW_O3_DSP_HW_O3_MEMORY_H__

#include "hardware/dsp-memory.h"

#define DSP_O3_MEMORY_MAX_SIZE	(SZ_16M)

#define DSP_O3_FW_EXTENSION	"bin"

#define DSP_O3_MASTER_FW_NAME	"dsp_master"	// master boot + stack
#define DSP_O3_MASTER_FW_IOVA	(0x20000000)
#define DSP_O3_MASTER_FW_SIZE	(SZ_1M)

#define DSP_O3_FW_NAME		"dsp"
#define DSP_O3_FW_IOVA		(0x20100000)
#define DSP_O3_FW_SIZE		(SZ_1M * 3)

#define DSP_O3_DHCP_MEM_IOVA	(0x21000000)
#define DSP_O3_DHCP_MEM_SIZE	(SZ_4K)

#define DSP_O3_FW_LOG_IOVA	(DSP_O3_DHCP_MEM_IOVA + DSP_O3_MEMORY_MAX_SIZE)
#define DSP_O3_FW_LOG_SIZE	(SZ_1M)

#define DSP_O3_IVP_PM_NAME	"dsp_ivp_pm"
#define DSP_O3_IVP_PM_IOVA	(DSP_O3_FW_LOG_IOVA + DSP_O3_MEMORY_MAX_SIZE)
#define DSP_O3_IVP_PM_SIZE	(SZ_16M)

#define DSP_O3_IVP_DM_NAME	"dsp_ivp_dm"
#define DSP_O3_IVP_DM_IOVA	(DSP_O3_IVP_PM_IOVA + DSP_O3_MEMORY_MAX_SIZE)
#define DSP_O3_IVP_DM_SIZE	(SZ_128K)

#define DSP_O3_IAC_PM_NAME	"dsp_iac_pm"
#define DSP_O3_IAC_PM_IOVA	(DSP_O3_IVP_DM_IOVA + DSP_O3_MEMORY_MAX_SIZE)
#define DSP_O3_IAC_PM_SIZE	(SZ_32K)

#define DSP_O3_IAC_DM_NAME	"dsp_iac_dm"
#define DSP_O3_IAC_DM_IOVA	(DSP_O3_IAC_PM_IOVA + DSP_O3_MEMORY_MAX_SIZE)
#define DSP_O3_IAC_DM_SIZE	(SZ_32K)

#define DSP_O3_MBOX_MEMORY_IOVA	(DSP_O3_IAC_DM_IOVA + DSP_O3_MEMORY_MAX_SIZE)
#define DSP_O3_MBOX_MEMORY_SIZE	(SZ_8K)

#define DSP_O3_MBOX_POOL_IOVA	(DSP_O3_MBOX_MEMORY_IOVA + \
		DSP_O3_MEMORY_MAX_SIZE)
#define DSP_O3_MBOX_POOL_SIZE	(SZ_128K)

#define DSP_O3_DL_OUT_IOVA	(DSP_O3_MBOX_POOL_IOVA + DSP_O3_MEMORY_MAX_SIZE)
#define DSP_O3_DL_OUT_SIZE	(SZ_1M)

#define DSP_O3_SM_BASE_ADDR		(0x5A0000)
#define DSP_O3_SM(n)			(DSP_O3_SM_BASE_ADDR + (n) * 4)

#define DSP_O3_DHCP_IDX(n)		(0x4 * (n))

#define DSP_O3_SM_USERDEFINED_COUNT	(64)
#define DSP_O3_SM_USERDEFINED_SIZE	(SZ_4 * DSP_O3_SM_USERDEFINED_COUNT)
#define DSP_O3_SM_USERDEFINED_BASE	(DSP_O3_SM(0))
#define DSP_O3_SM_USERDEFINED(n)	(DSP_O3_SM_USERDEFINED_BASE + 0x4 * (n))

#define DSP_O3_SM_FW_INFO_COUNT		(192)
#define DSP_O3_SM_FW_INFO_SIZE		(SZ_4 * DSP_O3_SM_FW_INFO_COUNT)
#define DSP_O3_SM_FW_INFO_BASE		(DSP_O3_SM(DSP_O3_SM_USERDEFINED_COUNT))
#define DSP_O3_SM_FW_INFO(n)		(DSP_O3_SM_FW_INFO_BASE + 0x4 * (n))

enum dsp_o3_dhcp_used_count {
	DSP_O3_DHCP_TO_CC_MBOX		= 0,
	DSP_O3_DHCP_TO_HOST_MBOX	= 8,
	DSP_O3_DHCP_LOG_QUEUE		= 16,
	DSP_O3_DHCP_TO_CC_INT_STATUS	= 24,
	DSP_O3_DHCP_TO_HOST_INT_STATUS,
	DSP_O3_DHCP_FW_RESERVED_SIZE,
	DSP_O3_DHCP_IVP_PM_IOVA,
	DSP_O3_DHCP_RESERVED0,
	DSP_O3_DHCP_IVP_PM_SIZE,
	DSP_O3_DHCP_IVP_DM_IOVA,
	DSP_O3_DHCP_IVP_DM_SIZE,
	DSP_O3_DHCP_IAC_PM_IOVA,
	DSP_O3_DHCP_IAC_PM_SIZE,
	DSP_O3_DHCP_IAC_DM_IOVA,
	DSP_O3_DHCP_IAC_DM_SIZE,
	DSP_O3_DHCP_RESERVED1,
	DSP_O3_DHCP_RESERVED2,
	DSP_O3_DHCP_MAILBOX_VERSION,
	DSP_O3_DHCP_MESSAGE_VERSION,
	DSP_O3_DHCP_FW_LOG_MEMORY_IOVA,
	DSP_O3_DHCP_FW_LOG_MEMORY_SIZE,
	DSP_O3_DHCP_TO_CC_MBOX_MEMORY_IOVA,
	DSP_O3_DHCP_TO_CC_MBOX_MEMORY_SIZE,
	DSP_O3_DHCP_TO_CC_MBOX_POOL_IOVA,
	DSP_O3_DHCP_TO_CC_MBOX_POOL_SIZE,
	DSP_O3_DHCP_RESERVED3,
	DSP_O3_DHCP_KERNEL_MODE,
	DSP_O3_DHCP_DL_OUT_IOVA,
	DSP_O3_DHCP_DL_OUT_SIZE,
	DSP_O3_DHCP_DEBUG_LAYER_START,
	DSP_O3_DHCP_DEBUG_LAYER_END,
	DSP_O3_DHCP_CHIPID_REV,
	DSP_O3_DHCP_PRODUCT_ID,
	DSP_O3_DHCP_NPUS_FREQUENCY,
	DSP_O3_DHCP_VPD_FREQUENCY,
	DSP_O3_DHCP_RESERVED4,
	DSP_O3_DHCP_RESERVED5,
	DSP_O3_DHCP_INTERRUPT_MODE,
	DSP_O3_DHCP_DRIVER_VERSION,
	DSP_O3_DHCP_FIRMWARE_VERSION,
	DSP_O3_DHCP_USED_COUNT,
};

enum dsp_o3_priv_mem_id {
	DSP_O3_PRIV_MEM_FW,
	DSP_O3_PRIV_MEM_DHCP,
	DSP_O3_PRIV_MEM_FW_LOG,
	DSP_O3_PRIV_MEM_IVP_PM,
	DSP_O3_PRIV_MEM_IVP_DM,
	DSP_O3_PRIV_MEM_IAC_PM,
	DSP_O3_PRIV_MEM_IAC_DM,
	DSP_O3_PRIV_MEM_MBOX_MEMORY,
	DSP_O3_PRIV_MEM_MBOX_POOL,
	DSP_O3_PRIV_MEM_DL_OUT,
	DSP_O3_PRIV_MEM_COUNT,
};

enum dsp_o3_reserved_mem_id {
	DSP_O3_RESERVED_MEM_FW_MASTER,
	DSP_O3_RESERVED_MEM_COUNT,
};

int dsp_hw_o3_memory_init(void);

#endif

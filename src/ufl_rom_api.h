/*
 * Copyright 2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _UFL_ROM_API_H_
#define _UFL_ROM_API_H_

#include "ufl_flexspi_nor_flash.h"
#include "ufl_rom_api_imxrt5xx.h"
#include "ufl_rom_api_imxrt6xx.h"
#include "ufl_rom_api_imxrt106x.h"
#include "ufl_rom_api_imxrt117x.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/

//!@brief FLEXSPI Flash driver API Interface
typedef struct _flexspi_nor_flash_driver
{
    status_t (*init)(uint32_t instance, flexspi_nor_config_t *config);
    status_t (*page_program)(uint32_t instance, flexspi_nor_config_t *config, uint32_t dst_addr, const uint32_t *src);
    status_t (*erase_all)(uint32_t instance, flexspi_nor_config_t *config);
    status_t (*erase)(uint32_t instance, flexspi_nor_config_t *config, uint32_t start, uint32_t lengthInBytes);
    status_t (*read)(uint32_t instance, flexspi_nor_config_t *config, uint32_t *dst, uint32_t addr, uint32_t lengthInBytes);
    status_t (*set_clock_source)(uint32_t clockSrc);
    status_t (*get_config)(uint32_t instance, flexspi_nor_config_t *config, serial_nor_config_option_t *option);
} flexspi_nor_flash_driver_t;

typedef struct _tool_cfg_iar
{
    bool enablePageSizeOverride;
} ufl_tool_cfg_iar;

typedef struct _target_desc
{
    uint32_t imxrtChipId;
    uint32_t flexspiInstance;
    uint32_t flexspiBaseAddr;
    uint32_t flashBaseAddr;
    serial_nor_config_option_t configOption;
    flexspi_nor_flash_driver_t flashDriver;
    bool isFlashPageProgram;
    ufl_tool_cfg_iar iarCfg;
} ufl_target_desc_t;

#if defined(UFL_USE_CONST_VAR)
const
#endif
extern ufl_target_desc_t g_uflTargetDesc;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /*_cplusplus*/

status_t flexspi_nor_flash_init(uint32_t instance, flexspi_nor_config_t *config);

status_t flexspi_nor_flash_page_program(uint32_t instance,
                                        flexspi_nor_config_t *config,
                                        uint32_t dstAddr,
                                        const uint32_t *src);

status_t flexspi_nor_flash_erase_all(uint32_t instance, flexspi_nor_config_t *config);

status_t flexspi_nor_get_config(uint32_t instance, flexspi_nor_config_t *config, serial_nor_config_option_t *option);

status_t flexspi_nor_flash_erase(uint32_t instance, flexspi_nor_config_t *config, uint32_t start, uint32_t length);

status_t flexspi_nor_flash_read(uint32_t instance, flexspi_nor_config_t *config, uint32_t *dst, uint32_t start, uint32_t bytes);

status_t flexspi_nor_set_clock_source(uint32_t clockSrc);

status_t flexspi_nor_auto_config(uint32_t instance, flexspi_nor_config_t *config, serial_nor_config_option_t *option);

#if defined(__cplusplus)
}
#endif /*_cplusplus*/

#endif /* _UFL_ROM_API_H_ */

/*
* The Clear BSD License
* Copyright (c) 2015-2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2018 NXP
* All rights reserved.
*/

#include <stdio.h>
#include "ufl_rom_api.h"
/***********************************************************************************************************************
 *  Definitions
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  Variables
 **********************************************************************************************************************/

flexspi_nor_config_t flashConfig = {.pageSize = 0x400};

/***********************************************************************************************************************
 *  Prototypes
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Codes
 **********************************************************************************************************************/

int main()
{
    status_t status = ufl_full_setup();
    uint32_t instance = g_uflTargetDesc.flexspiInstance;

    if (!status)
    {
        status = flexspi_nor_flash_erase(instance, &flashConfig, 0x1000, flashConfig.sectorSize);
        if (!status)
        {
            while (1);
        }
    }

    while (1);
}
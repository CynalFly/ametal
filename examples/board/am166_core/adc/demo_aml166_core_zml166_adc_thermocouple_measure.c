/*******************************************************************************
*                                 AMetal
*                       ----------------------------
*                       innovating embedded platform
*
* Copyright (c) 2001-2018 Guangzhou ZHIYUAN Electronics Co., Ltd.
* All rights reserved.
*
* Contact information:
* web site:    http://www.zlg.cn/
*******************************************************************************/

/**
 * \file
 * \brief ZML166核心板 24位adc测热点偶温度
 *
 * - 操作步骤：
 *   1. 连接好设定的热电偶之后，打开串口 PA9 PA10。
 *
 * - 实验现象：
 *   1. 串口将会打印测量温度。
 *
 * \par 源代码
 * \snippet demo_aml166_core_adc24_thermistor_measure.c src_aml166_core_adc24_thermistor_measure
 *
 * \internal
 * \par Modification history
 * - 1.00 19-01-17  htf, first implementation.
 * \endinternal
 */

/**
 * \addtogroup demo_aml166_core_adc24_thermistor_measure
 * \copydoc demo_aml166_core_adc24_thermistor_measure.c
 */

/** [src_aml166_core_adc24_thermistor_measure] */

#include <am_aml166_inst_init.h>
#include "am_hwconf_zml166_adc.h"
#include "am_zml166_adc.h"
#include "string.h"
#include "am_zlg_flash.h"
#include "am_thermocouple.h"
#include "zlg116_periph_map.h"
#include "demo_components_entries.h"
#include "demo_aml166_core_entries.h"
#include "demo_zlg_entries.h"

/**
 * \brief 热电偶测温例程
 */
void demo_aml166_core_zml166_adc_thermocouple_measure (void)
{
    int   i  = 0;
    float para[16];
    am_zml166_adc_handle_t  handle = am_zml166_adc_inst_init();

    /* 热电偶计算以及电压校准参数初始化 */
    am_thermocouplie_init();
    am_zlg_flash_init(ZLG116_FLASH);
    memcpy((void *)para, (uint32_t *)((FLASH_BLOCK_NUM * 1024)), 4 * 16);

    if(!(para[0] < 1.1 && para[0] > 0.9)){
        for(i = 0; i < 8; i++){
            para[2 * i + 0] = 1;
            para[2 * i + 1] = 0;
        }
    }
    dome_zml166_adc_thermocouple_measure_entry((void *)handle,
                                                       para,
                                                       AM_THERMOCOUPLIE_K);
}

/** [src_aml166_core_adc24_thermistor_measure] */

/* end of file */

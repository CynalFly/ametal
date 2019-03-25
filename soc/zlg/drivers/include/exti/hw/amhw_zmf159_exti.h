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
 * \brief EXTI �ӿ�
 *
 * \internal
 * \par Modification history
 * - 1.00 17-08-23  lqy, first implementation
 * \endinternal
 */

#ifndef __AMHW_ZMF159_EXTI_H
#define __AMHW_ZMF159_EXTI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "am_types.h"
#include "hw/amhw_zlg_exti.h"

/*
 * \brief �����ṹ��εĿ�ʼ
 */
#if defined(__CC_ARM)
  #pragma push
  #pragma anon_unions
#elif defined(__ICCARM__)
  #pragma language=extended
#elif defined(__GNUC__)
#elif defined(__TMS470__)
#elif defined(__TASKING__)
  #pragma warning 586
#else
  #warning Not supported compiler t
#endif

/**
 * \addtogroup amhw_zmf159_if_exti
 * \copydoc amhw_zmf159_exti.h
 * @{
 */

/**
 * \brief EXTI�Ĵ�����ṹ��
 */
typedef amhw_zlg_exti_t amhw_zmf159_exti_t;

/**
 * \brief �߱��ö��
 */
typedef enum {
    AMHW_ZMF159_LINE_NUM0  = (1ul << 0),    /**< \brief ��0 */
    AMHW_ZMF159_LINE_NUM1  = (1ul << 1),    /**< \brief ��1 */
    AMHW_ZMF159_LINE_NUM2  = (1ul << 2),    /**< \brief ��2 */
    AMHW_ZMF159_LINE_NUM3  = (1ul << 3),    /**< \brief ��3 */
    AMHW_ZMF159_LINE_NUM4  = (1ul << 4),    /**< \brief ��4 */
    AMHW_ZMF159_LINE_NUM5  = (1ul << 5),    /**< \brief ��5 */
    AMHW_ZMF159_LINE_NUM6  = (1ul << 6),    /**< \brief ��6 */
    AMHW_ZMF159_LINE_NUM7  = (1ul << 7),    /**< \brief ��7 */
    AMHW_ZMF159_LINE_NUM8  = (1ul << 8),    /**< \brief ��8 */
    AMHW_ZMF159_LINE_NUM9  = (1ul << 9),    /**< \brief ��9 */
    AMHW_ZMF159_LINE_NUM10 = (1ul << 10),   /**< \brief ��10 */
    AMHW_ZMF159_LINE_NUM11 = (1ul << 11),   /**< \brief ��11 */
    AMHW_ZMF159_LINE_NUM12 = (1ul << 12),   /**< \brief ��12 */
    AMHW_ZMF159_LINE_NUM13 = (1ul << 13),   /**< \brief ��13 */
    AMHW_ZMF159_LINE_NUM14 = (1ul << 14),   /**< \brief ��14 */
    AMHW_ZMF159_LINE_NUM15 = (1ul << 15),   /**< \brief ��15 */
    AMHW_ZMF159_LINE_NUM16 = (1ul << 16),   /**< \brief ��16���ӵ� PVD ��� */
    AMHW_ZMF159_LINE_NUM17 = (1ul << 17),   /**< \brief ��17���ӵ�RTC�����¼� */
    AMHW_ZMF159_LINE_NUM18 = (1ul << 18),   /**< \brief ��18���ӵ�USB�����¼� */
    AMHW_ZMF159_LINE_NUM19 = (1ul << 19),   /**< \brief ��19���ӵ��Ƚ���1��� */
    AMHW_ZMF159_LINE_NUM20 = (1ul << 20),   /**< \brief ��20���ӵ��Ƚ���2��� */
    AMHW_ZMF159_LINE_NUM21 = (1ul << 21),   /**< \brief ��21���ӵ�IWDG�ж� */

}amhw_zmf159_exti_line_num_t;

/**
 * \brief �ж�/�¼�����ö��
 */
typedef enum
{
    AMHW_ZMF159_EXTI_TRIGGER_RISING         = 0x08,
    AMHW_ZMF159_EXTI_TRIGGER_FALLING        = 0x0C,
    AMHW_ZMF159_EXTI_TRIGGER_RISING_FALLING = 0x10
}amwh_zmf159_extitrigger_type_t;

/**
 * \brief ���������� x�ϵ��ж�����
 *
 * \param[in]   p_hw_exti : ָ���ⲿ�ж�/�¼����ƿ��ָ��
 * \param[in]   num : �߱��
 *              AMHW_ZMF159_LINE_NUM* ��ֵ��
 *              ���AMHW_ZMF159_LINE_NUM*��Ļ�ֵ
 *              ��:
 *               - AMHW_ZMF159_LINE_NUM0
 *               - AMHW_ZMF159_LINE_NUM0 | AMHW_ZMF159_LINE_NUM1
 *
 * \return ��
 */
am_static_inline
void amhw_zmf159_exti_imr_set(amhw_zmf159_exti_t     *p_hw_exti,
                              amhw_zmf159_exti_line_num_t  num)
{
    p_hw_exti->imr |= (num & 0x3fffff);
}

/**
 * \brief ���������� x�ϵ��ж�����
 *
 * \param[in]   p_hw_exti : ָ���ⲿ�ж�/�¼����ƿ��ָ��
 * \param[in]   num : �߱��
 *              AMHW_ZMF159_LINE_NUM* ��ֵ��
 *              ���AMHW_ZMF159_LINE_NUM*��Ļ�ֵ
 *              ��:
 *               - AMHW_ZMF159_LINE_NUM0
 *               - AMHW_ZMF159_LINE_NUM0 | AMHW_ZMF159_LINE_NUM1
 *
 * \return ��
 */
am_static_inline
void amhw_zmf159_exti_imr_clear(amhw_zmf159_exti_t     *p_hw_exti,
                                amhw_zmf159_exti_line_num_t  num)
{
    p_hw_exti->imr &= ~(num & 0x3fffff);
}

/**
 * \brief ���������� x�ϵ��¼�����
 *
 * \param[in]   p_hw_exti : ָ���ⲿ�ж�/�¼����ƿ��ָ��
 * \param[in]    num : �߱��
 *              AMHW_ZMF159_LINE_NUM* ��ֵ��
 *              ���AMHW_ZMF159_LINE_NUM*��Ļ�ֵ
 *              ��:
 *               - AMHW_ZMF159_LINE_NUM0
 *               - AMHW_ZMF159_LINE_NUM0 | AMHW_ZMF159_LINE_NUM1
 *
 * \return ��
 */
am_static_inline
void amhw_zmf159_exti_emr_set(amhw_zmf159_exti_t    *p_hw_exti,
                              amhw_zmf159_exti_line_num_t num)
{
    p_hw_exti->emr |= (num & 0x3fffff);
}

/**
 * \brief ���������� x�ϵ��¼�����
 *
 * \param[in]   p_hw_exti : ָ���ⲿ�ж�/�¼����ƿ��ָ��
 * \param[in]   num : �߱��
 *              AMHW_ZMF159_LINE_NUM* ��ֵ��
 *              ���AMHW_ZMF159_LINE_NUM*��Ļ�ֵ
 *              ��:
 *               - AMHW_ZMF159_LINE_NUM0
 *               - AMHW_ZMF159_LINE_NUM0 | AMHW_ZMF159_LINE_NUM1
 *
 * \return ��
 */
am_static_inline
void amhw_zmf159_exti_emr_clear(amhw_zmf159_exti_t     *p_hw_exti,
                                amhw_zmf159_exti_line_num_t  num)
{
    p_hw_exti->emr &= ~(num & 0x3fffff);
}

/**
 * \brief ���������� x�ϵ������ش������жϺ��¼���
 *
 * \param[in]   p_hw_exti : ָ���ⲿ�ж�/�¼����ƿ��ָ��
 * \param[in]   num : �߱��
 *              AMHW_ZMF159_LINE_NUM* ��ֵ��
 *              ���AMHW_ZMF159_LINE_NUM*��Ļ�ֵ
 *              ��:
 *               - AMHW_ZMF159_LINE_NUM0
 *               - AMHW_ZMF159_LINE_NUM0 | AMHW_ZMF159_LINE_NUM1
 *
 * \return ��
 */
am_static_inline
void amhw_zmf159_exti_rtsr_set(amhw_zmf159_exti_t     *p_hw_exti,
                               amhw_zmf159_exti_line_num_t  num)
{
    p_hw_exti->rtsr |= (num & 0x3fffff);
}

/**
 * \brief ��ֹ������ x�ϵ������ش������жϺ��¼���
 *
 * \param[in]   p_hw_exti : ָ���ⲿ�ж�/�¼����ƿ��ָ��
 * \param[in]   num : �߱��
 *              AMHW_ZMF159_LINE_NUM* ��ֵ��
 *              ���AMHW_ZMF159_LINE_NUM*��Ļ�ֵ
 *              ��:
 *               - AMHW_ZMF159_LINE_NUM0
 *               - AMHW_ZMF159_LINE_NUM0 | AMHW_ZMF159_LINE_NUM1
 *
 * \return ��
 */
am_static_inline
void amhw_zmf159_exti_rtsr_clear(amhw_zmf159_exti_t     *p_hw_exti,
                                 amhw_zmf159_exti_line_num_t  num)
{
    p_hw_exti->rtsr &= ~(num & 0x3fffff);
}

/**
 * \brief ���������� x�ϵ��½��ش������жϺ��¼���
 *
 * \param[in]   p_hw_exti : ָ���ⲿ�ж�/�¼����ƿ��ָ��
 * \param[in]   num : �߱��
 *              AMHW_ZMF159_LINE_NUM* ��ֵ��
 *              ���AMHW_ZMF159_LINE_NUM*��Ļ�ֵ
 *              ��:
 *               - AMHW_ZMF159_LINE_NUM0
 *               - AMHW_ZMF159_LINE_NUM0 | AMHW_ZMF159_LINE_NUM1
 *
 * \return ��
 */
am_static_inline
void amhw_zmf159_exti_ftsr_set(amhw_zmf159_exti_t     *p_hw_exti,
                               amhw_zmf159_exti_line_num_t  num)
{
    p_hw_exti->ftsr |= (num & 0x3fffff);
}

/**
 * \brief ��ֹ������ x�ϵ��½��ش������жϺ��¼���
 *
 * \param[in]   p_hw_exti : ָ���ⲿ�ж�/�¼����ƿ��ָ��
 * \param[in]   num : �߱��
 *              AMHW_ZMF159_LINE_NUM* ��ֵ��
 *              ���AMHW_ZMF159_LINE_NUM*��Ļ�ֵ
 *              ��:
 *               - AMHW_ZMF159_LINE_NUM0
 *               - AMHW_ZMF159_LINE_NUM0 | AMHW_ZMF159_LINE_NUM1
 *
 * \return ��
 */
am_static_inline
void amhw_zmf159_exti_ftsr_clear(amhw_zmf159_exti_t     *p_hw_exti,
                                 amhw_zmf159_exti_line_num_t  num)
{
    p_hw_exti->ftsr &= ~(num & 0x3fffff);
}

/**
 * \brief ������ x�ϵ������ж�
 *
 * \param[in]   p_hw_exti : ָ���ⲿ�ж�/�¼����ƿ��ָ��
 * \param[in]   num : �߱��
 *              AMHW_ZMF159_LINE_NUM* ��ֵ��
 *              ���AMHW_ZMF159_LINE_NUM*��Ļ�ֵ
 *              ��:
 *               - AMHW_ZMF159_LINE_NUM0
 *               - AMHW_ZMF159_LINE_NUM0 | AMHW_ZMF159_LINE_NUM1
 *
 * \return ��
 */
am_static_inline
void amhw_zmf159_exti_swier_set(amhw_zmf159_exti_t     *p_hw_exti,
                                amhw_zmf159_exti_line_num_t  num)
{
    p_hw_exti->swier |= (num & 0x3fffff);
}

/**
 * \brief ����жϱ�־
 *
 * \param[in]   p_hw_exti : ָ���ⲿ�ж�/�¼����ƿ��ָ��
 * \param[in]   num : �߱��
 *              AMHW_ZMF159_LINE_NUM* ��ֵ��
 *              ���AMHW_ZMF159_LINE_NUM*��Ļ�ֵ
 *              ��:
 *               - AMHW_ZMF159_LINE_NUM0
 *               - AMHW_ZMF159_LINE_NUM0 | AMHW_ZMF159_LINE_NUM1
 *
 * \return ��
 */
am_static_inline
void amhw_zmf159_exti_pending_clear(amhw_zmf159_exti_t     *p_hw_exti,
                                    amhw_zmf159_exti_line_num_t  num)
{
    p_hw_exti->pr |= (num & 0x3fffff);
}

/**
 * \brief ��ȡ�ⲿ�жϱ�־
 *
 * \param[in]   p_hw_exti : ָ���ⲿ�ж�/�¼����ƿ��ָ��
 * \param[in]   num : �߱��
 *
 * \return �������жϱ�־
 *              AMHW_ZMF159_LINE_NUM* ��ֵ��
 *              ���AMHW_ZMF159_LINE_NUM*��Ļ�ֵ
 *              ��:
 *               - AMHW_ZMF159_LINE_NUM0
 *               - AMHW_ZMF159_LINE_NUM0 | AMHW_ZMF159_LINE_NUM1
 *
 */
am_static_inline
uint32_t amhw_zmf159_exti_pr_read(amhw_zmf159_exti_t     *p_hw_exti,
                                  amhw_zmf159_exti_line_num_t  num)
{
    return (p_hw_exti->pr & num);
}
/**
 * @}
 */
/*
 * \brief �����ṹ��εĽ���
 */

#if defined(__CC_ARM)
  #pragma pop
#elif defined(__ICCARM__)
#elif defined(__GNUC__)
#elif defined(__TMS470__)
#elif defined(__TASKING__)
  #pragma warning restore
#else
  #warning Not supported compiler t
#endif

#ifdef __cplusplus
}
#endif /* __AMHW_ZMF159_EXTI_H */

#endif

/* end of file */
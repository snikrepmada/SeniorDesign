/*******************************************************************************
 * File Name   : File Name
 * Author      : Author
 * Version     : Version
 * Date        : Date
 * Description : Description
 *******************************************************************************
 *
 * Information
 *
 ******************************************************************************/

#ifndef __gpio_H
#define __gpio_H
#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f4xx_hal.h"

void MX_GPIO_Init(void);

/* LED Calls */
void LED_GRN_ON(void);
void LED_GRN_OFF(void);
void LED_GRN_TGL(void);
void LED_ORG_ON(void);
void LED_ORG_OFF(void);
void LED_ORG_TGL(void);
void LED_RED_ON(void);
void LED_RED_OFF(void);
void LED_RED_TGL(void);
void LED_BLU_ON(void);
void LED_BLU_OFF(void);
void LED_BLU_TGL(void);

/* DMCI Power and Reset Calls */
void DCMI_PWRDN_HIGH(void);
void DCMI_PWRDN_LOW(void);
void DCMI_PWRDN_TGL(void);
void DCMI_RST_HIGH(void);
void DCMI_RST_LOW(void);
void DCMI_RST_TGL(void);

/* User Input Push Button Status */
int USER_PB_STATUS(void);

#ifdef __cplusplus
}
#endif
#endif

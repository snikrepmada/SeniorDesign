/*
  ******************************************************************************
  * File Name          : DCMI.h
  * Description        : This file provides code for the configuration
  *                      of the DCMI instances.
  ******************************************************************************
  *
  *
  ******************************************************************************
  */

#ifndef __dcmi_H
#define __dcmi_H
#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f4xx_hal.h"

extern DCMI_HandleTypeDef hdcmi;

void MX_DCMI_Init(void);

#ifdef __cplusplus
}
#endif
#endif

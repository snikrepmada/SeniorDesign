/*
  ******************************************************************************
  * File Name          : I2C.h
  * Description        : This file provides code for the configuration
  *                      of the I2C instances.
  ******************************************************************************
  *
  *
  ******************************************************************************
  */

#ifndef __i2c_H
#define __i2c_H
#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f4xx_hal.h"

extern I2C_HandleTypeDef hi2c1;

void MX_I2C1_Init(void);

uint8_t SCCB_Write(uint8_t addr, uint8_t data);
uint8_t SCCB_Read(uint8_t addr);

#ifdef __cplusplus
}
#endif
#endif

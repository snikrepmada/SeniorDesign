/*
  ******************************************************************************
  * File Name          : I2C.c
  * Description        : This file provides code for the configuration
  *                      of the I2C instances.
  ******************************************************************************
  *
  *
  ******************************************************************************
  */

#include "i2c.h"
#include "gpio.h"

#define TIMEOUT 10000
#define SLAVE_ADDR 0x60

#define BREAK() __asm__ volatile ("BKPT")

I2C_HandleTypeDef hi2c1;

void MX_I2C1_Init(void)
{
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLED;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLED;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLED;
  HAL_I2C_Init(&hi2c1);
}

void HAL_I2C_MspInit(I2C_HandleTypeDef* hi2c)
{
  GPIO_InitTypeDef GPIO_InitStruct;
  if(hi2c->Instance==I2C1)
  {
    GPIO_InitStruct.Pin = SCCB_SCL_Pin|SCCB_SDA_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF4_I2C1;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    __I2C1_CLK_ENABLE();
  }
}

void HAL_I2C_MspDeInit(I2C_HandleTypeDef* hi2c)
{
  if(hi2c->Instance==I2C1)
  {
    __I2C1_CLK_DISABLE();
    HAL_GPIO_DeInit(GPIOB, SCCB_SCL_Pin|SCCB_SDA_Pin);
  }
}

uint8_t SCCB_Write(uint8_t addr, uint8_t data)
{
  uint8_t ret = 0;
  uint8_t buf[] = { addr, data };

  __disable_irq();
  if (HAL_I2C_Master_Transmit(&hi2c1, SLAVE_ADDR, buf, 2, TIMEOUT) != HAL_OK) {
    ret = 0xFF;
  }
  __enable_irq();
  return ret;
}

uint8_t SCCB_Read(uint8_t addr)
{
  uint8_t data = 0;

  __disable_irq();
  if (HAL_I2C_Master_Transmit(&hi2c1, SLAVE_ADDR, &addr, 1, TIMEOUT) != HAL_OK) {
    data = 0xFF;
    goto error_w;
  }
  if (HAL_I2C_Master_Receive(&hi2c1, SLAVE_ADDR, &data, 1, TIMEOUT) != HAL_OK) {
    data = 0xFF;
  }
error_w:
  __enable_irq();
  return data;
}

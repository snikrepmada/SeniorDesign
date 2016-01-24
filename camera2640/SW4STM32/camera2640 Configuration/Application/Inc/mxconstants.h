/*
  ******************************************************************************
  * File Name          : mxconstants.h
  * Description        : This file contains the common defines of the application
  ******************************************************************************
  *
  *
  ******************************************************************************
  */

#define USER_PB_Pin GPIO_PIN_0
#define USER_PB_GPIO_Port GPIOA
#define SPI_CS_Pin GPIO_PIN_4
#define SPI_CS_GPIO_Port GPIOC
#define DCMI_PWRDN_Pin GPIO_PIN_8
#define DCMI_PWRDN_GPIO_Port GPIOD
#define DCMI_RST_Pin GPIO_PIN_9
#define DCMI_RST_GPIO_Port GPIOD
#define LED_GRN_Pin GPIO_PIN_12
#define LED_GRN_GPIO_Port GPIOD
#define LED_ORG_Pin GPIO_PIN_13
#define LED_ORG_GPIO_Port GPIOD
#define LED_RED_Pin GPIO_PIN_14
#define LED_RED_GPIO_Port GPIOD
#define LED_BLU_Pin GPIO_PIN_15
#define LED_BLU_GPIO_Port GPIOD
#define DCMI_XCLK_Pin GPIO_PIN_8
#define DCMI_XCLK_GPIO_Port GPIOA
#define SCCB_SCL_Pin GPIO_PIN_8
#define SCCB_SCL_GPIO_Port GPIOB
#define SCCB_SDA_Pin GPIO_PIN_9
#define SCCB_SDA_GPIO_Port GPIOB

#define BREAK() __asm__ volatile ("BKPT");

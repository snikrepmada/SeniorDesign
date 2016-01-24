/*
  ******************************************************************************
  * File Name          : main.c
  * Description        : Main program body
  ******************************************************************************
  *
  *
  ******************************************************************************
  */

#include "stm32f4xx_hal.h"
#include "dcmi.h"
#include "i2c.h"
#include "spi.h"
#include "usart.h"
#include "usb_device.h"
#include "gpio.h"
#include "usbd_cdc_if.h"

void SystemClock_Config(void);

int main(void)
{
   HAL_Init();

  SystemClock_Config();

  MX_GPIO_Init();
  MX_DCMI_Init();
  //MX_SPI1_Init();
  //MX_USART2_UART_Init();
  MX_USB_DEVICE_Init();

  //LED_BLU_ON();

  //HAL_Delay(5000);
  uint8_t USBStartMsg[]="USB Communications has started.\n\r";
  CDC_Transmit_FS(USBStartMsg,strlen(USBStartMsg));

  LED_GRN_ON();

  OV2640_Init();

  int status;

  HAL_Delay(1000);

  uint8_t *image;

  image = malloc(800*sizeof(uint8_t));

  //Sensor_Snapshot(image);

  LED_BLU_ON();

  int i;

  while (1)
  {
    status = USER_PB_STATUS();
    if(status == 1)
    {
      for(i = 0; i < 0xFFFC; i++)
      {
        //CDC_Transmit_FS(image[i], 1);
      }
      //CDC_Transmit_FS("PRESSED\n\r", 9);
    }
    LED_GRN_TGL();
    HAL_Delay(500);
  }
}

void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

  __PWR_CLK_ENABLE();

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 192;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  HAL_RCC_OscConfig(&RCC_OscInitStruct);

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_SYSCLK|RCC_CLOCKTYPE_PCLK1
                              |RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV4;
  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3);

  HAL_RCC_MCOConfig(RCC_MCO1, RCC_MCO1SOURCE_PLLCLK, RCC_MCODIV_4);

  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

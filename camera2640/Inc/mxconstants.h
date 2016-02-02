/**
  ******************************************************************************
  * File Name          : mxconstants.h
  * Description        : This file contains the common defines of the application
  ******************************************************************************
  *
  * COPYRIGHT(c) 2016 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/

#define USR_PB_Pin GPIO_PIN_0
#define USR_PB_GPIO_Port GPIOA
#define USR_TX_Pin GPIO_PIN_2
#define USR_TX_GPIO_Port GPIOA
#define USR_RX_Pin GPIO_PIN_3
#define USR_RX_GPIO_Port GPIOA
#define USR_SCK_Pin GPIO_PIN_5
#define USR_SCK_GPIO_Port GPIOA
#define USR_MOSI_Pin GPIO_PIN_7
#define USR_MOSI_GPIO_Port GPIOA
#define USR_CS_Pin GPIO_PIN_4
#define USR_CS_GPIO_Port GPIOC
#define USR_SCL_Pin GPIO_PIN_10
#define USR_SCL_GPIO_Port GPIOB
#define USR_SDA_Pin GPIO_PIN_11
#define USR_SDA_GPIO_Port GPIOB
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
#define USR_MISO_Pin GPIO_PIN_4
#define USR_MISO_GPIO_Port GPIOB
#define DCMI_SCL_Pin GPIO_PIN_8
#define DCMI_SCL_GPIO_Port GPIOB
#define DCMI_SDA_Pin GPIO_PIN_9
#define DCMI_SDA_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */
#define BREAK() __asm__ volatile ("BKPT")
/* USER CODE END Private defines */

/**
  * @}
  */

/**
  * @}
*/

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

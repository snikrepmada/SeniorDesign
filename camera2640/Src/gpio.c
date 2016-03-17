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

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __GPIOE_CLK_ENABLE();
  __GPIOH_CLK_ENABLE();
  __GPIOA_CLK_ENABLE();
  __GPIOB_CLK_ENABLE();
  __GPIOD_CLK_ENABLE();
  __GPIOC_CLK_ENABLE();

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = USR_PB_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(USR_PB_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PDPin PDPin PDPin PDPin
                           PDPin PDPin */
  GPIO_InitStruct.Pin = DCMI_PWRDN_Pin|DCMI_RST_Pin|LED_GRN_Pin|LED_ORG_Pin
                          |LED_RED_Pin|LED_BLU_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = DCMI_XCLK_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF0_MCO;
  HAL_GPIO_Init(DCMI_XCLK_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = USR_CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
  HAL_GPIO_Init(USR_CS_GPIO_Port, &GPIO_InitStruct);

}

/* LED Calls */
void LED_GRN_ON(void)
{
  HAL_GPIO_WritePin(LED_GRN_GPIO_Port, LED_GRN_Pin, GPIO_PIN_SET);
}
void LED_GRN_OFF(void)
{
  HAL_GPIO_WritePin(LED_GRN_GPIO_Port, LED_GRN_Pin, GPIO_PIN_RESET);
}
void LED_GRN_TGL(void)
{
  HAL_GPIO_TogglePin(LED_GRN_GPIO_Port, LED_GRN_Pin);
}
void LED_ORG_ON(void)
{
  HAL_GPIO_WritePin(LED_ORG_GPIO_Port, LED_ORG_Pin, GPIO_PIN_SET);
}
void LED_ORG_OFF(void)
{
  HAL_GPIO_WritePin(LED_ORG_GPIO_Port, LED_ORG_Pin, GPIO_PIN_RESET);
}
void LED_ORG_TGL(void)
{
  HAL_GPIO_TogglePin(LED_ORG_GPIO_Port, LED_ORG_Pin);
}
void LED_RED_ON(void)
{
  HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
}
void LED_RED_OFF(void)
{
  HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);
}
void LED_RED_TGL(void)
{
  HAL_GPIO_TogglePin(LED_GRN_GPIO_Port, LED_GRN_Pin);
}
void LED_BLU_ON(void)
{
  HAL_GPIO_WritePin(LED_BLU_GPIO_Port, LED_BLU_Pin, GPIO_PIN_SET);
}
void LED_BLU_OFF(void)
{
  HAL_GPIO_WritePin(LED_BLU_GPIO_Port, LED_BLU_Pin, GPIO_PIN_RESET);
}
void LED_BLU_TGL(void)
{
  HAL_GPIO_TogglePin(LED_GRN_GPIO_Port, LED_GRN_Pin);
}

/* DMCI Power and Reset Calls */
void DCMI_PWRDN_HIGH(void)
{
  HAL_GPIO_WritePin(DCMI_PWRDN_GPIO_Port, DCMI_PWRDN_Pin, GPIO_PIN_SET);
}
void DCMI_PWRDN_LOW(void)
{
  HAL_GPIO_WritePin(DCMI_PWRDN_GPIO_Port, DCMI_PWRDN_Pin, GPIO_PIN_RESET);
}
void DCMI_PWRDN_TGL(void)
{
  HAL_GPIO_TogglePin(DCMI_PWRDN_GPIO_Port, DCMI_PWRDN_Pin);
}
void DCMI_RST_HIGH(void)
{
  HAL_GPIO_WritePin(DCMI_RST_GPIO_Port, DCMI_RST_Pin, GPIO_PIN_SET);
}
void DCMI_RST_LOW(void)
{
  HAL_GPIO_WritePin(DCMI_RST_GPIO_Port, DCMI_RST_Pin, GPIO_PIN_RESET);
}
void DCMI_RST_TGL(void)
{
  HAL_GPIO_TogglePin(DCMI_RST_GPIO_Port, DCMI_RST_Pin);
}

/* User Input Push Button Status */
int USER_PB_STATUS(void)
{
  return HAL_GPIO_ReadPin(USR_PB_GPIO_Port, USR_PB_Pin);
}

/* ****************************** END OF FILE ******************************* */

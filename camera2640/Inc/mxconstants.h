/* Includes ------------------------------------------------------------------*/


/* Private define ------------------------------------------------------------*/
#define USR_PB_Pin GPIO_PIN_0
#define USR_PB_GPIO_Port GPIOA
#define USR_SCK_Pin GPIO_PIN_5
#define USR_SCK_GPIO_Port GPIOA
#define USR_MOSI_Pin GPIO_PIN_7
#define USR_MOSI_GPIO_Port GPIOA
#define USR_SCL_Pin GPIO_PIN_10
#define USR_SCL_GPIO_Port GPIOB
#define USR_SDA_Pin GPIO_PIN_11
#define USR_SDA_GPIO_Port GPIOB
#define DCMI_PWRDN_Pin GPIO_PIN_10
#define DCMI_PWRDN_GPIO_Port GPIOD
#define DCMI_RST_Pin GPIO_PIN_11
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
#define USR_TX_Pin GPIO_PIN_12
#define USR_TX_GPIO_Port GPIOC
#define USR_RX_Pin GPIO_PIN_2
#define USR_RX_GPIO_Port GPIOD
#define USR_CS_Pin GPIO_PIN_3
#define USR_CS_GPIO_Port GPIOB
#define USR_MISO_Pin GPIO_PIN_4
#define USR_MISO_GPIO_Port GPIOB
#define DCMI_SCL_Pin GPIO_PIN_8
#define DCMI_SCL_GPIO_Port GPIOB
#define DCMI_SDA_Pin GPIO_PIN_9
#define DCMI_SDA_GPIO_Port GPIOB

#define BREAK() __asm__ volatile ("BKPT")

/* ****************************** END OF FILE ******************************* */

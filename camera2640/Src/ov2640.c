/*******************************************************************************
 * File Name   : ov2640.c
 * Author      : Adam Perkins
 * Version     : 0.1.0
 * Date        : 30-January-2016
 * Description : OV2640 camera module
 *******************************************************************************
 *
 * Used to initialize and access the OV2640 camera module
 *
 ******************************************************************************/

/* Includes ----------------------------------------------------------------- */
#include "ov2640.h"
#include "i2c.h"

/* Private typedef ---------------------------------------------------------- */
/* Private define ----------------------------------------------------------- */
#define DELAY 2
#define TIMEOUT 10000

/* Bits definitions --------------------------------------------------------- */
/* Private macro ------------------------------------------------------------ */
/* Private variables -------------------------------------------------------- */

static const uint8_t default_regs[][2] =
{
  {0xff, 0x0},
  {0x2c, 0xff},
  {0x2e, 0xdf},
  {0xff, 0x1},
  {0x3c, 0x32},
  {0x11, 0x0},
  {0x9, 0x2},
  {0x4, 0xa8},
  {0x13, 0xe5},
  {0x14, 0x48},
  {0x2c, 0xc},
  {0x33, 0x78},
  {0x3a, 0x33},
  {0x3b, 0xfb},
  {0x3e, 0x0},
  {0x43, 0x11},
  {0x16, 0x10},
  {0x39, 0x2},
  {0x35, 0x88},

  {0x22, 0xa},
  {0x37, 0x40},
  {0x23, 0x0},
  {0x34, 0xa0},
  {0x6, 0x2},
  {0x6, 0x88},
  {0x7, 0xc0},
  {0xd, 0xb7},
  {0xe, 0x1},
  {0x4c, 0x0},
  {0x4a, 0x81},
  {0x21, 0x99},
  {0x24, 0x40},
  {0x25, 0x38},
  {0x26, 0x82},
  {0x5c, 0x0},
  {0x63, 0x0},
  {0x46, 0x22},
  {0xc, 0x3a},
  {0x5d, 0x55},
  {0x5e, 0x7d},
  {0x5f, 0x7d},
  {0x60, 0x55},
  {0x61, 0x70},
  {0x62, 0x80},
  {0x7c, 0x5},
  {0x20, 0x80},
  {0x28, 0x30},
  {0x6c, 0x0},
  {0x6d, 0x80},
  {0x6e, 0x0},
  {0x70, 0x2},
  {0x71, 0x94},
  {0x73, 0xc1},
  {0x3d, 0x34},
  {0x12, 0x4},
  {0x5a, 0x57},
  {0x4f, 0xbb},
  {0x50, 0x9c},
  {0xff, 0x0},
  {0xe5, 0x7f},
  {0xf9, 0xc0},
  {0x41, 0x24},
  {0xe0, 0x14},
  {0x76, 0xff},
  {0x33, 0xa0},
  {0x42, 0x20},
  {0x43, 0x18},
  {0x4c, 0x0},
  {0x87, 0xd0},
  {0x88, 0x3f},
  {0xd7, 0x3},
  {0xd9, 0x10},
  {0xd3, 0x82},
  {0xc8, 0x8},
  {0xc9, 0x80},
  {0x7c, 0x0},
  {0x7d, 0x0},
  {0x7c, 0x3},
  {0x7d, 0x48},
  {0x7d, 0x48},
  {0x7c, 0x8},
  {0x7d, 0x20},
  {0x7d, 0x10},
  {0x7d, 0xe},
  {0x90, 0x0},
  {0x91, 0xe},
  {0x91, 0x1a},
  {0x91, 0x31},
  {0x91, 0x5a},
  {0x91, 0x69},
  {0x91, 0x75},
  {0x91, 0x7e},
  {0x91, 0x88},
  {0x91, 0x8f},
  {0x91, 0x96},
  {0x91, 0xa3},
  {0x91, 0xaf},
  {0x91, 0xc4},
  {0x91, 0xd7},
  {0x91, 0xe8},
  {0x91, 0x20},
  {0x92, 0x0},

  {0x93, 0x6},
  {0x93, 0xe3},
  {0x93, 0x3},
  {0x93, 0x3},
  {0x93, 0x0},
  {0x93, 0x2},
  {0x93, 0x0},
  {0x93, 0x0},
  {0x93, 0x0},
  {0x93, 0x0},
  {0x93, 0x0},
  {0x93, 0x0},
  {0x93, 0x0},
  {0x96, 0x0},
  {0x97, 0x8},
  {0x97, 0x19},
  {0x97, 0x2},
  {0x97, 0xc},
  {0x97, 0x24},
  {0x97, 0x30},
  {0x97, 0x28},
  {0x97, 0x26},
  {0x97, 0x2},
  {0x97, 0x98},
  {0x97, 0x80},
  {0x97, 0x0},
  {0x97, 0x0},
  {0xa4, 0x0},
  {0xa8, 0x0},
  {0xc5, 0x11},
  {0xc6, 0x51},
  {0xbf, 0x80},
  {0xc7, 0x10},
  {0xb6, 0x66},
  {0xb8, 0xa5},
  {0xb7, 0x64},
  {0xb9, 0x7c},
  {0xb3, 0xaf},
  {0xb4, 0x97},
  {0xb5, 0xff},
  {0xb0, 0xc5},
  {0xb1, 0x94},
  {0xb2, 0xf},
  {0xc4, 0x5c},
  {0xa6, 0x0},
  {0xa7, 0x20},
  {0xa7, 0xd8},
  {0xa7, 0x1b},
  {0xa7, 0x31},
  {0xa7, 0x0},
  {0xa7, 0x18},
  {0xa7, 0x20},
  {0xa7, 0xd8},
  {0xa7, 0x19},
  {0xa7, 0x31},
  {0xa7, 0x0},
  {0xa7, 0x18},
  {0xa7, 0x20},
  {0xa7, 0xd8},
  {0xa7, 0x19},
  {0xa7, 0x31},
  {0xa7, 0x0},
  {0xa7, 0x18},
  {0x7f, 0x0},
  {0xe5, 0x1f},
  {0xe1, 0x77},
  {0xdd, 0x7f},
  {0xc2, 0xe},

  {0xff, 0x0},
  {0xe0, 0x4},
  {0xc0, 0xc8},
  {0xc1, 0x96},
  {0x86, 0x3d},
  {0x51, 0x90},
  {0x52, 0x2c},
  {0x53, 0x0},
  {0x54, 0x0},
  {0x55, 0x88},
  {0x57, 0x0},

  {0x50, 0x92},
  {0x5a, 0x50},
  {0x5b, 0x3c},
  {0x5c, 0x0},
  {0xd3, 0x4},
  {0xe0, 0x0},

  {0xff, 0x0},
  {0x5, 0x0},

  {0xda, 0x8},
  {0xd7, 0x3},
  {0xe0, 0x0},

  {0x5, 0x0},

  {0xff,0xff}
};

static const uint8_t rgb565_regs[][2] =
{
  { BANK_SEL, BANK_SEL_DSP },
  { RESET, RESET_DVP },
  { IMAGE_MODE, IMAGE_MODE_RGB565 },
  { 0xD7, 0x03 },
  { 0xE1, 0x77 },
  { RESET, 0x00 },
  { 0, 0 }
};

/* Private function prototypes ---------------------------------------------- */
uint8_t SCCB_Write(uint8_t addr, uint8_t data);
uint8_t SCCB_Read(uint8_t addr);
void OV2640_ReadID(OV2640_IDTypeDef* OV2640ID);
int32_t OV2640_CheckID(OV2640_IDTypeDef* OV2640ID);
void OV2640_SetCameraRegisters(void);

/* Private functions -------------------------------------------------------- */
uint8_t SCCB_Write(uint8_t addr, uint8_t data)
{
  uint8_t ret = 0;
  uint8_t buf[] = {addr, data};

  __disable_irq();
  if(HAL_I2C_Master_Transmit(&hi2c1, OV2640_WRITE_ADDR, buf, 2, TIMEOUT) != HAL_OK)
  {
    ret = 0xFF;
  }
  __enable_irq();
  return ret;
}

uint8_t SCCB_Read(uint8_t addr)
{
  uint8_t data = 0;
  __disable_irq();
  if(HAL_I2C_Master_Transmit(&hi2c1, OV2640_READ_ADDR, &addr, 1, TIMEOUT) != HAL_OK)
  {
    data = 0xFF;
    goto error_w;
  }
  if(HAL_I2C_Master_Receive(&hi2c1, OV2640_READ_ADDR, &data, 1, TIMEOUT) != HAL_OK)
  {
    data = 0xFF;
  }
  error_w:
    __enable_irq();
    return data;
}

void OV2640_ReadID(OV2640_IDTypeDef* OV2640ID)
{
  SCCB_Write(0xFF, 0x01);
  OV2640ID->Manufacturer_ID1 = SCCB_Read(MIDH);
  OV2640ID->Manufacturer_ID2 = SCCB_Read(MIDL);
  OV2640ID->Version = SCCB_Read(REG_VER);
  OV2640ID->PID = SCCB_Read(REG_PID);
}

int32_t OV2640_CheckID(OV2640_IDTypeDef* OV2640ID)
{
  //uint16_t manufacturerID = (OV2640ID->Manufacturer_ID1 << 8) | (OV2640ID->Manufacturer_ID2);
  if(((OV2640ID->Manufacturer_ID1 << 8) | (OV2640ID->Manufacturer_ID2)) != OV2640_MANUFACTURER_ID)
  {
    return -1;
  }
  if(OV2640ID->PID != OV2640_PID)
  {
    return -1;
  }
  if(OV2640ID->Version != OV2640_VERSION)
  {
    return -1;
  }
  return 0;
}

void OV2640_SetCameraRegisters(void)
{
  uint32_t i = 0;
  const uint8_t(*regs)[2];

  /* Reset all the registers */
  SCCB_Write(BANK_SEL, BANK_SEL_SENSOR);
  SCCB_Write(COM7, COM7_SRST);

  HAL_Delay(10);

  /* Write initial registers */
  i = 0;
  regs = default_regs;
  while(regs[i][0])
  {
    SCCB_Write(regs[i][0], regs[i][1]);
    HAL_Delay(DELAY);
    i++;
  }

  /* Set output image format */
  i = 0;
  regs = rgb565_regs;
  while(regs[i][0])
  {
    SCCB_Write(regs[i][0], regs[i][1]);
    HAL_Delay(DELAY);
    i++;
  }
}

/* Public functions --------------------------------------------------------- */
extern int32_t OV2640_Init(void)
{
  OV2640_IDTypeDef OV2640ID;

  DCMI_PWRDN_HIGH();
  HAL_Delay(10);

  DCMI_PWRDN_LOW();
  HAL_Delay(100);

  DCMI_RST_LOW();
  HAL_Delay(10);

  DCMI_RST_HIGH();
  HAL_Delay(10);

  OV2640_ReadID(&OV2640ID);
  
  if(OV2640_CheckID(&OV2640ID) != 0)
  {
    printf("Camera OV2640 not found.\n\r");
    return -1;
  }
  
  OV2640_SetCameraRegisters();

  return 0;
}

/* ****************************** END OF FILE ******************************* */

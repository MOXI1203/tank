#ifndef  _POWER_H
#define  _POWER_H
#include "main.h"
#include "stm32f1xx_hal.h"

#define PowerSin        HAL_GPIO_ReadPin(PS_IN_GPIO_Port,PS_IN_Pin)
#define PowerOut_ON		HAL_GPIO_WritePin(PS_OUT_GPIO_Port,PS_OUT_Pin,GPIO_PIN_SET)
#define PowerOut_OFF	HAL_GPIO_WritePin(PS_OUT_GPIO_Port,PS_OUT_Pin,GPIO_PIN_RESET)
#define Beep_ON			HAL_GPIO_WritePin(BEEP_GPIO_Port,BEEP_Pin,GPIO_PIN_SET)
#define Beep_OFF		HAL_GPIO_WritePin(BEEP_GPIO_Port,BEEP_Pin,GPIO_PIN_RESET)
#define LED1_ON			HAL_GPIO_WritePin(LED1_GPIO_Port,LED1_Pin,GPIO_PIN_RESET)
#define LED1_OFF		HAL_GPIO_WritePin(LED1_GPIO_Port,LED1_Pin,GPIO_PIN_SET)

#define LED2_ON			HAL_GPIO_WritePin(LED2_GPIO_Port,LED2_Pin,GPIO_PIN_RESET)
#define LED2_OFF		HAL_GPIO_WritePin(LED2_GPIO_Port,LED2_Pin,GPIO_PIN_SET)

typedef struct 
{
	uint32_t Bus_Vmv;
	uint32_t Bus_Vpe;
} VbusTypedef;


void PowerTask(void const * argument);
void PowerInit(void);
VbusTypedef GetVbusPar(void);

#endif


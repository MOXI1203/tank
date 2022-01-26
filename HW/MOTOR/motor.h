#ifndef _MOTOR_H
#define _MOTOR_H

#include "stm32f1xx_hal.h"
#include "cmsis_os.h"

#define LED_ON  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,GPIO_PIN_RESET)
#define LED_OFF  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,GPIO_PIN_SET)

#define CtrlParLen   RX_PLOAD_WIDTH

void  RxDataInit(uint8_t Rxdata[]);

int16_t Limit(int16_t input, int16_t min, int16_t max);

void MotorCtrl(uint8_t input_x,uint8_t input_y);


void ServoCtrl(uint8_t Input,uint8_t State);

uint8_t Follow_Charge(uint8_t Target,uint8_t Value);

void MotorCtrlTask(void const * argument);

#endif

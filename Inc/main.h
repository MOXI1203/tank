/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define NRF_IRQ_Pin GPIO_PIN_1
#define NRF_IRQ_GPIO_Port GPIOA
#define NRF_IRQ_EXTI_IRQn EXTI1_IRQn
#define N_CS_Pin GPIO_PIN_2
#define N_CS_GPIO_Port GPIOA
#define Servo6_Pin GPIO_PIN_3
#define Servo6_GPIO_Port GPIOA
#define SPI_CE_Pin GPIO_PIN_4
#define SPI_CE_GPIO_Port GPIOA
#define Servo3_Pin GPIO_PIN_0
#define Servo3_GPIO_Port GPIOB
#define Servo4_Pin GPIO_PIN_1
#define Servo4_GPIO_Port GPIOB
#define PS_IN_Pin GPIO_PIN_2
#define PS_IN_GPIO_Port GPIOB
#define LED3_Pin GPIO_PIN_10
#define LED3_GPIO_Port GPIOB
#define LEDV_Pin GPIO_PIN_11
#define LEDV_GPIO_Port GPIOB
#define BEEP_Pin GPIO_PIN_12
#define BEEP_GPIO_Port GPIOB
#define Servo5_Pin GPIO_PIN_14
#define Servo5_GPIO_Port GPIOB
#define DRV_FAULT_Pin GPIO_PIN_15
#define DRV_FAULT_GPIO_Port GPIOB
#define DRV_FAULT_EXTI_IRQn EXTI15_10_IRQn
#define M1A_Pin GPIO_PIN_8
#define M1A_GPIO_Port GPIOA
#define M1B_Pin GPIO_PIN_9
#define M1B_GPIO_Port GPIOA
#define M2A_Pin GPIO_PIN_10
#define M2A_GPIO_Port GPIOA
#define M2B_Pin GPIO_PIN_11
#define M2B_GPIO_Port GPIOA
#define PS_OUT_Pin GPIO_PIN_3
#define PS_OUT_GPIO_Port GPIOB
#define Servo1_Pin GPIO_PIN_4
#define Servo1_GPIO_Port GPIOB
#define Servo2_Pin GPIO_PIN_5
#define Servo2_GPIO_Port GPIOB
#define LED1_Pin GPIO_PIN_8
#define LED1_GPIO_Port GPIOB
#define LED2_Pin GPIO_PIN_9
#define LED2_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */
#define NrfReceQueueSize   10
#define NrfReceQueueLeng   1

#define USE_NRFIRQ       1
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

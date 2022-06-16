/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32g0xx_hal.h"

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

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Beep_Pin GPIO_PIN_1
#define Beep_GPIO_Port GPIOC
#define OLED_CS_Pin GPIO_PIN_1
#define OLED_CS_GPIO_Port GPIOA
#define OLED_RES_Pin GPIO_PIN_3
#define OLED_RES_GPIO_Port GPIOA
#define OLED_DC_Pin GPIO_PIN_4
#define OLED_DC_GPIO_Port GPIOA
#define Handle_SW_Pin GPIO_PIN_8
#define Handle_SW_GPIO_Port GPIOA
#define Heater_Pin GPIO_PIN_7
#define Heater_GPIO_Port GPIOC
#define NST1001_PWR_Pin GPIO_PIN_11
#define NST1001_PWR_GPIO_Port GPIOA
#define NST1001_DAT_Pin GPIO_PIN_12
#define NST1001_DAT_GPIO_Port GPIOA
#define EC11_B_Pin GPIO_PIN_3
#define EC11_B_GPIO_Port GPIOB
#define EC11_A_Pin GPIO_PIN_4
#define EC11_A_GPIO_Port GPIOB
#define EC11_A_EXTI_IRQn EXTI4_15_IRQn
#define EC11_KEY_Pin GPIO_PIN_5
#define EC11_KEY_GPIO_Port GPIOB
#define EC11_KEY_EXTI_IRQn EXTI4_15_IRQn
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "stm32g4xx_hal.h"

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
#define LEDG_Pin GPIO_PIN_0
#define LEDG_GPIO_Port GPIOF
#define LEDR_Pin GPIO_PIN_1
#define LEDR_GPIO_Port GPIOF
#define ENCODER2_A_Pin GPIO_PIN_0
#define ENCODER2_A_GPIO_Port GPIOA
#define ENCODER2_B_Pin GPIO_PIN_1
#define ENCODER2_B_GPIO_Port GPIOA
#define VUSB_Pin GPIO_PIN_2
#define VUSB_GPIO_Port GPIOA
#define REF_MOT2_Pin GPIO_PIN_3
#define REF_MOT2_GPIO_Port GPIOA
#define IN_MOT_CH2R_Pin GPIO_PIN_4
#define IN_MOT_CH2R_GPIO_Port GPIOA
#define EN_MOT_CH2R_Pin GPIO_PIN_5
#define EN_MOT_CH2R_GPIO_Port GPIOA
#define IN_MOT_CH2L_Pin GPIO_PIN_6
#define IN_MOT_CH2L_GPIO_Port GPIOA
#define EN_MOT_CH2L_Pin GPIO_PIN_7
#define EN_MOT_CH2L_GPIO_Port GPIOA
#define ENCODER1_B_Pin GPIO_PIN_8
#define ENCODER1_B_GPIO_Port GPIOA
#define ENCODER1_A_Pin GPIO_PIN_9
#define ENCODER1_A_GPIO_Port GPIOA
#define EN_MOT_CH1L_Pin GPIO_PIN_10
#define EN_MOT_CH1L_GPIO_Port GPIOA
#define REF_MOT1_Pin GPIO_PIN_4
#define REF_MOT1_GPIO_Port GPIOB
#define IN_MOT_CH1R_Pin GPIO_PIN_5
#define IN_MOT_CH1R_GPIO_Port GPIOB
#define EN_MOT_CH1R_Pin GPIO_PIN_6
#define EN_MOT_CH1R_GPIO_Port GPIOB
#define IN_MOT_CH1L_Pin GPIO_PIN_7
#define IN_MOT_CH1L_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

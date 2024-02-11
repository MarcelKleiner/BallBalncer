/*
 * ApplicationMain.cpp
 *
 *  Created on: Feb 3, 2024
 *      Author: marce
 */

#include "ApplicationMain.h"
#include "main.h"

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim6;
extern TIM_HandleTypeDef htim15;
extern TIM_HandleTypeDef htim16;

ApplicationMain::ApplicationMain()
{
	// TODO Auto-generated constructor stub

}

void ApplicationMain::StartUp()
{
	HAL_GPIO_WritePin(LEDR_GPIO_Port, LEDR_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LEDG_GPIO_Port, LEDG_Pin, GPIO_PIN_SET);


	HAL_TIM_Base_MspInit(&htim6);	//task handler timer
	HAL_TIM_Base_Start_IT(&htim6);

	//ToDo do some initialisation here

	Main();
}

void ApplicationMain::Main()
{
	while (true) 
	{
		if(taskhandler.IsLedTask())
		{
			HAL_GPIO_TogglePin(LEDG_GPIO_Port, LEDG_Pin);
			HAL_GPIO_WritePin(LEDR_GPIO_Port, LEDR_Pin, GPIO_PIN_RESET);
		}


		if(taskhandler.IsDriveTask())
		{

		}
	}
}

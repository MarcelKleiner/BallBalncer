/*
 * ApplicationMain.cpp
 *
 *  Created on: Feb 3, 2024
 *      Author: marce
 */

#include "ApplicationMain.h"
#include "main.h"



ApplicationMain::ApplicationMain()
{
	// TODO Auto-generated constructor stub
}

void ApplicationMain::StartUp()
{
	HAL_GPIO_WritePin(LEDR_GPIO_Port, LEDR_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LEDG_GPIO_Port, LEDG_Pin, GPIO_PIN_SET);


	HAL_TIM_Base_MspInit(&htim1);
	HAL_TIM_Base_MspInit(&htim2);
	HAL_TIM_Base_MspInit(&htim6);	//task handler timer
	HAL_TIM_Base_MspInit(&htim15);
	HAL_TIM_Base_MspInit(&htim16);


	HAL_TIM_Base_Start_IT(&htim6);

	HAL_TIM_Base_Start(&htim1);
	HAL_TIM_Base_Start(&htim2);
	HAL_TIM_Base_Start(&htim15);
	HAL_TIM_Base_Start(&htim16);


	driveCoontrolXAxis.Init();
	driveCoontrolYAxis.Init();
	//ToDo do some initialization here

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
		driveCoontrolXAxis.DriveRight(30000);

		if(taskhandler.IsDriveTask())
		{

		}
	}
}

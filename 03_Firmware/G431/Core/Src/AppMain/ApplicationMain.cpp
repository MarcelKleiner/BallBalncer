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


	HAL_TIM_Base_MspInit(&htim1);	//Encoder 1
	HAL_TIM_Base_MspInit(&htim2);	//Encoder 2
	HAL_TIM_Base_MspInit(&htim3);	//PWM
	HAL_TIM_Base_MspInit(&htim4);	//task handler timer
	HAL_TIM_Base_MspInit(&htim17);	//PWM


	HAL_TIM_Base_Start_IT(&htim4);

	HAL_TIM_Encoder_Start(&htim1, TIM_CHANNEL_ALL);
	HAL_TIM_Encoder_Start(&htim2, TIM_CHANNEL_ALL);

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

		if(taskhandler.IsDriveTask())
		{
			if(!driveCoontrolXAxis.IsHomingSttus())
			{
				HomeDriveX.HomeDrive(RotationDirection::Left);
			}

			if(!driveCoontrolYAxis.IsHomingSttus())
			{
				HomeDriveY.HomeDrive(RotationDirection::Right);
			}
		}

		if(taskhandler.IsEncoderTask()){
			encoder1.Update();
			encoder2.Update();
		}

	}
}

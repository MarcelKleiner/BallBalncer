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

	driveControlXAxis.Init();
	driveControlYAxis.Init();


    taskhandler.SetErrorTaskEnable(true);
    taskhandler.SetDriveTaskEnable(true);
    taskhandler.SetEncoderTaskEnable(true);
    taskhandler.SetLedTaskEnable(true);

	//ToDo do some initialization here

	Main();
}

void ApplicationMain::Main()
{
	while (true) 
	{
		if(taskhandler.IsErrorTask())
		{
			if(error.GetError() != Error::NoError)
			{
				HAL_GPIO_TogglePin(LEDR_GPIO_Port, LEDR_Pin);
				HAL_GPIO_WritePin(LEDG_GPIO_Port, LEDG_Pin, GPIO_PIN_RESET);
			}
		}

		//Led update
		if(taskhandler.IsLedTask())
		{
			HAL_GPIO_TogglePin(LEDG_GPIO_Port, LEDG_Pin);
			HAL_GPIO_WritePin(LEDR_GPIO_Port, LEDR_Pin, GPIO_PIN_RESET);
		}

		//Drive Update
		if(taskhandler.IsDriveTask())
		{
			if(!driveControlXAxis.IsHomingStatus())
			{
				HomeDriveX.HomeDrive(RotationDirection::Left);
			}

			if(!driveControlYAxis.IsHomingStatus())
			{
				HomeDriveY.HomeDrive(RotationDirection::Right);
			}

			if(driveControlXAxis.IsHomingStatus() && driveControlYAxis.IsHomingStatus())
			{
				taskhandler.SetControllerTaskEnable(true);
				CheckDriveZeroPosition(&driveControlXAxis, &encoderX);
				CheckDriveZeroPosition(&driveControlYAxis, &encoderY);
			}
		}

		//Encoder update
		if(taskhandler.IsEncoderTask())
		{
			encoderX.Update();
			encoderY.Update();
		}

		//Controller update
		if(taskhandler.IsControllerTask())
		{
			xController.UpdateController(-20);
			yController.UpdateController(-20);
		}
	}
}

void ApplicationMain::CheckDriveZeroPosition(DriveControl* driveControl, IEncoder* encoder)
{
	if(driveControl->IsHomingStatus() && encoder->GetValue() <= 0)
	{
		driveControlYAxis.DriveStop();
		driveControlXAxis.DriveStop();
		taskhandler.SetControllerTaskEnable(false);
		taskhandler.SetDriveTaskEnable(false);
		taskhandler.SetLedTaskEnable(false);
		error.SetError(Error::DrivePositionOutOfBoundsError);
	}
}

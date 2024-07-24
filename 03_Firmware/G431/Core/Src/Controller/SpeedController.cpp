/*
 * SpeedController.cpp
 *
 *  Created on: Jan 21, 2024
 *      Author: marce
 */

#include "SpeedController.h"

SpeedController::SpeedController(IEncoder *encoder)
{
	_encoder = encoder;
}

int32_t SpeedController::Update(int32_t targetSpeed)
{
	currentEncoderValue = _encoder->GetValue();

	currentSpeed = currentEncoderValue - lastEncoderValue;

	currentSpeedError = targetSpeed - currentSpeed;

	speedGainPart = speedError * speedKp;

	speedErrorSummation = speedErrorSummation
			+ ((currentSpeedError + lastSpeedError) / 2);

	lastSpeedError = currentSpeedError;
}

void SpeedController::Reset()
{

}

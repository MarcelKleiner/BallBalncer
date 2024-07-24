/*
 * PositionController.cpp
 *
 *  Created on: Jan 21, 2024
 *      Author: marce
 */

#include "PositionController.h"

PositionController::PositionController(IEncoder *encoder)
{
	_encoder = encoder;
}

int32_t PositionController::Update(int32_t targetPosition)
{
	currentPosValue = _encoder->GetValue();

	posError = targetPosition - currentPosValue;

	resultPosValue = posError * posKp;

	if(resultPosValue < MinPosValue)
		return MinPosValue;

	if(resultPosValue > MaxPosValue)
		return MaxPosValue;

	return resultPosValue;
}

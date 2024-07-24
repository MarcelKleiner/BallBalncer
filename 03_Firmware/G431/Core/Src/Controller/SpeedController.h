/*
 * SpeedController.h
 *
 *  Created on: Jan 21, 2024
 *      Author: marce
 */

#ifndef SRC_CONTROLLER_SPEEDCONTROLLER_H_
#define SRC_CONTROLLER_SPEEDCONTROLLER_H_

#include "../Encoder/IEncoder.h"

class SpeedController
{
	public:
		SpeedController(IEcndoer *encoder);

		int32_t Update(int32_t targetSpeed);
		void Reset();

	private:
		IEncoder* _encoder;

		float speedKp = 10.0;
		float speedTi = 1.05;

		int32_t currentEncoderValue = 0;
		int32_t lastEncoderValue = 0;

		int32_t currentSpeed = 0;
		int32_t currentSpeedError = 0;
		int32_t lastSpeedError = 0;

		int32_t speedErrorSummation;

		float speedGainPart = 0.0;
		float speedIntegralPart = 0.0;


};

#endif /* SRC_CONTROLLER_SPEEDCONTROLLER_H_ */

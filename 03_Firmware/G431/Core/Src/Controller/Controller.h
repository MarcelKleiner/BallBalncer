#include "../Drive/DriveControl.h"
#include "../Encoder/IEncoder.h"
#include "CalculationHelper/AngleCalculation.h"
#include <stm32g4xx_hal.h>
#include <tuple>

#ifndef SRC_CONTROLLER_CONTROLLER_H_
#define SRC_CONTROLLER_CONTROLLER_H_

class Controller
{
	public:
		Controller(DriveControl* driveControl, IEncoder* encoder);

		void UpdateController(float targetAngle);

	private:
		DriveControl* _driveControl;
		IEncoder* _encoder;

		AngleCalculation *_ancleCalculatin;

		void ValidateAngle(float* angle);

		void UpdatePosition(float EncoderValue);

		float previewAngle = 0;
		float encoderValue= 0;
};

#endif /* SRC_CONTROLLER_CONTROLLER_H_ */

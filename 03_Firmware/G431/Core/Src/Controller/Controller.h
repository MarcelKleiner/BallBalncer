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
		Controller(DriveControl* driveControlX, DriveControl* driveControlY, IEncoder* encoderX, IEncoder* encoderY);

		void UpdateController(float xAngle, float yAngle);

	private:
		DriveControl* _driveControlX;
		DriveControl* _driveControlY;
		IEncoder* _encoderX;
		IEncoder* _encoderY;

		AngleCalculation *_ancleCalculatin;

		void ValidateAngle(float* angle);

		void UpdateYPosition(float EncoderValueY);
		void UpdateXPosition(float EncoderValueX);


		float previewXAngle = 0;
		float previewYAngle = 0;

		float EncoderValueY = 0;
		float EncoderValueX= 0;

};

#endif /* SRC_CONTROLLER_CONTROLLER_H_ */

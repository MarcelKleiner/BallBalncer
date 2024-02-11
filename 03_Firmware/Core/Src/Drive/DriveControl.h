#include "../IO/IOHandle.h"
#include "RotationDirection.h"
#include "stdint-gcc.h"
#include "stm32l412xx.h"
#include "tim.h"

#ifndef SRC_DRIVE_DRIVECONTROL_H_
#define SRC_DRIVE_DRIVECONTROL_H_

class DriveControl
{
	public:
		DriveControl(TIM_HandleTypeDef timer, IOHandle* enLeft, IOHandle* inLeft, IOHandle* enRight, IOHandle* inRight);
		void DriveLeft(uint16_t speed);
		void DriveRight(uint16_t speed);

	private:
		TIM_HandleTypeDef _timer;
		IOHandle* _enLeft;
		IOHandle* _inLeft;
		IOHandle* _enRight;
		IOHandle* _inRight;
		RotationDirection _rotationDirection;
};

#endif /* SRC_DRIVE_DRIVECONTROL_H_ */

#ifndef SRC_DRIVE_DRIVECONTROL_H_
#define SRC_DRIVE_DRIVECONTROL_H_

#include "../IO/IOHandle.h"
#include "RotationDirection.h"
#include "stdint-gcc.h"
#include <stm32g431xx.h>
#include "tim.h"

class DriveControl
{
	public:
		DriveControl(IOHandle* enLeft, IOHandle* inLeft, IOHandle* enRight, IOHandle* inRight, IOHandle* refSwitch);
		void Init();
		void DriveLeft(uint16_t speed);
		void DriveRight(uint16_t speed);
		void DriveStop();

		IOHandle* GetRefSwitch();

		bool IsHomingSttus();
		void SetHomingSttus(bool homingSttus);

		uint32_t GetHomingPosition();
		void SetHomingPosition(uint32_t homingPosition);

	private:
		TIM_HandleTypeDef _timer;
		IOHandle* _enLeft;
		IOHandle* _inLeft;
		IOHandle* _enRight;
		IOHandle* _inRight;
		IOHandle* _refSwitch;
		RotationDirection _rotationDirection;
		bool _homingSttus;
		uint32_t _homingPosition;
};

#endif /* SRC_DRIVE_DRIVECONTROL_H_ */

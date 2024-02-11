#include "DriveControl.h"


DriveControl::DriveControl(TIM_HandleTypeDef timer, IOHandle* enLeft, IOHandle* inLeft, IOHandle* enRight, IOHandle* inRight)
{
	_enLeft = enLeft;
	_inLeft = inLeft;
	_enRight = enRight;
	_inRight = inRight;
     _timer = timer;
	_rotationDirection = RotationDirection::Undefined;

	_enLeft->Write(true);
	_enRight->Write(true);
}


void DriveControl::DriveLeft(uint16_t speed)
{
	if (_rotationDirection != RotationDirection::Left) 
	{
		_inLeft->SetFunction(IOFunction::PWM);
		_inRight->SetFunction(IOFunction::Output);
		_inRight->Write(false);
		_rotationDirection = RotationDirection::Left;
	}
	_inRight->SetPWM(speed);
}

void DriveControl::DriveRight(uint16_t speed)
{
	if (_rotationDirection != RotationDirection::Right)
	{
		_inLeft->SetFunction(IOFunction::Output);
		_inRight->SetFunction(IOFunction::PWM);
		_inLeft->Write(false);
		_rotationDirection = RotationDirection::Right;
	}
	_inRight->SetPWM(speed);
}

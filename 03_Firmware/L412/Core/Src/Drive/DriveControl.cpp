#include "DriveControl.h"


DriveControl::DriveControl(IOHandle* enLeft, IOHandle* inLeft, IOHandle* enRight, IOHandle* inRight)
{
	_enLeft = enLeft;
	_inLeft = inLeft;
	_enRight = enRight;
	_inRight = inRight;
	_rotationDirection = RotationDirection::Undefined;
}

void DriveControl::Init()
{
	_enLeft->SetFunction(IOFunction::Output);
	_enRight->SetFunction(IOFunction::Output);
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
	_inLeft->SetPWM(speed);
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

#include "Home.h"
#include "math.h"


Home::Home( DriveControl* driveControl, IEncoder* encoder)
{
	_currentHomingState = HomingState::DriveToSwitch;
	_nextHomingState = HomingState::DriveToSwitch;
	_encoder = encoder;
	_driveControl = driveControl;
}

void Home::HomeDrive(RotationDirection rotationDirection)
{

	switch (_currentHomingState) {
		case HomingState::DriveToSwitch:
			if(DriveToSwitchPos(rotationDirection))
			{
				_driveControl->DriveStop();
				_encoder->ResetValue();
				_nextHomingState = HomingState::DriveToCenterPos;
			}
			break;
		case HomingState::DriveToCenterPos:
			if(DriveToCenterPos(rotationDirection))
			{
				_driveControl->DriveStop();
				_driveControl->SetHomingSttus(true);
				_nextHomingState = HomingState::DriveToSwitch;
			}
			break;
		default:
			_nextHomingState = HomingState::DriveToSwitch;
			break;
	}

	_currentHomingState = _nextHomingState;
}

bool Home::DriveToSwitchPos(RotationDirection rotationDirection)
{
	IOHandle* refSwitch = _driveControl->GetRefSwitch();
	if(HAL_GPIO_ReadPin(refSwitch->GetPort(), refSwitch->GetPin()) == GPIO_PIN_SET)
	{
		_driveControl->DriveLeft(0);
		return true;
	}

	if(rotationDirection == RotationDirection::Left)
	{
		_driveControl->DriveLeft(speed);
	}

	if(rotationDirection == RotationDirection::Right)
	{
		_driveControl->DriveRight(speed);
	}

	return false;
}

bool Home::DriveToCenterPos(RotationDirection rotationDirection)
{
	if(abs(_encoder->GetValue()) > 63000)
	{
		_driveControl->DriveLeft(0);
		return true;
	}

	if(rotationDirection == RotationDirection::Right)
	{
		_driveControl->DriveLeft(speed);
	}

	if(rotationDirection == RotationDirection::Left)
	{
		_driveControl->DriveRight(speed);
	}

	return false;
}

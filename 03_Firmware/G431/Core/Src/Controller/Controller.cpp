

#include "../AppSettings.h"
#include "Controller.h"


Controller::Controller(DriveControl* driveControl, IEncoder* encoder)
{
	this->_driveControl = driveControl;
	this->_encoder = encoder;
	this->_ancleCalculatin = new AngleCalculation();
}

void Controller::UpdateController(float targetAngle)
{

	if(previewAngle != targetAngle)
	{
		ValidateAngle(&targetAngle);
		encoderValue = _ancleCalculatin->CalculateTargetEncoderValue(targetAngle);
	}
	
	UpdatePosition(encoderValue);
	previewAngle = targetAngle;
}


void Controller::ValidateAngle(float* angle)
{
    *angle = (*angle < MinAngle) ? MinAngle : *angle;
    *angle = (*angle > MaxAngle) ? MaxAngle : *angle;
}


void Controller::UpdatePosition(float EncoderValueY)
{

}

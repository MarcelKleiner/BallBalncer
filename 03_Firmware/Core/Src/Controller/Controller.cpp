

#include "../AppSettings.h"
#include "Controller.h"


Controller::Controller(DriveControl* driveControlX, DriveControl* driveControlY, IEncoder* encoderX, IEncoder* encoderY)
{
	this->_driveControlX = driveControlX;
	this->_driveControlY = driveControlY;
	this->_encoderX = encoderX;
	this->_encoderY = encoderY;
	this->_ancleCalculatin = new AngleCalculation();
}

void Controller::UpdateController(float xAngle, float yAngle)
{

	if(previewXAngle != xAngle || previewYAngle != yAngle)
	{
		ValidateAngle(&xAngle);
		ValidateAngle(&yAngle);
	}

	if(previewXAngle != xAngle)
	{
		EncoderValueX = _ancleCalculatin->CalculateTargetEncoderValue(xAngle);
	}

	if(previewYAngle != yAngle)
	{
		EncoderValueY = _ancleCalculatin->CalculateTargetEncoderValue(yAngle);
	}
	
	UpdateYPosition(EncoderValueY);
	UpdateXPosition(EncoderValueX);

	previewYAngle = yAngle;
	previewXAngle = xAngle;
}


void Controller::ValidateAngle(float* angle)
{
    *angle = (*angle < MinAngle) ? MinAngle : *angle;
    *angle = (*angle > MaxAngle) ? MaxAngle : *angle;
}


void Controller::UpdateYPosition(float EncoderValueY)
{

}



void Controller::UpdateXPosition(float EncoderValueX)
{

}



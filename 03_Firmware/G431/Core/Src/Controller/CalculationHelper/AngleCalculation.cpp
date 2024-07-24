/*
 * AngleCalculation.cpp
 *
 *  Created on: Jan 21, 2024
 *      Author: marce
 */

#include "AngleCalculation.h"
#include "../../AppSettings.h"
#include "math.h"

AngleCalculation::AngleCalculation()
{
	// TODO Auto-generated constructor stub

}

int32_t AngleCalculation::CalculateTargetEncoderValue(float angle)
{
	float angleRad = ConvertFromDegreeToRad(angle);

	float targetAngle = ArcSinusApproximation((PlatformArmLength/MotorArmLength) * SinusApproximation(angleRad));

	return (int32_t)((targetAngle * encoderRation) + ZeroDegreeEncoderValue);
}


float AngleCalculation::ConvertFromDegreeToRad(float angle)
{
	return angle * angleConvertFactor;
}


float AngleCalculation::SinusApproximation(float angleRad)
{
	float x1 = angleRad;
	float x3 = angleRad*angleRad*angleRad; //pow(angleRad, 3);
	float x5 = x3*angleRad*angleRad;	//pow(angleRad,5);

	return x1 + a1*x3 + a2*x5;
}


float AngleCalculation::ArcSinusApproximation(float angleRad)
{
	float x1 = angleRad;
	float x3 = angleRad*angleRad*angleRad; //pow(angleRad, 3);
	float x5 = x3*angleRad*angleRad;	//pow(angleRad,5);

	return x1 + b1*x3 + b2*x5;
}

#include "AMT102V.h"

AMT102V::AMT102V(TIM_HandleTypeDef* timer)
{
	this->timer = timer;
}

void AMT102V::SetValue(int32_t value)
{
	encoderValue = value;
}

void AMT102V::ResetValue()
{
	SetValue(0);
}

void AMT102V::Update()
{
	currentValue = timer->Instance->CNT;
	deltaValue = currentValue - lastValue;

	//forward overflow
	if (deltaValue < -32768)
	{
		deltaValue = (deltaValue + 65535);
	}

	//backwards overflow
	if (deltaValue > 32768)
	{
		deltaValue = (deltaValue - 65535);
	}

	encoderValue += deltaValue;				//Increase the encoder value by the difference
	lastValue = currentValue;						//previous value = current value
}

int32_t AMT102V::GetValue()
{
	return encoderValue;
}

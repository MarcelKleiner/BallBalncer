#include "IOHandle.h"
#include <stm32g4xx_hal.h>

IOHandle::IOHandle(GPIO_TypeDef* port, uint32_t pin, TIM_HandleTypeDef* timer, uint32_t channel)
{
     _port = port;
     _pin = pin;
     _timer = timer;
     _channel = channel;
}

IOHandle::IOHandle(GPIO_TypeDef* port, uint32_t pin)
{
     _port = port;
     _pin = pin;
     _timer = nullptr;
     _channel = 0;
}

void IOHandle::Write(bool status)
{
     if (_IoFunction != IOFunction::Output)
     {
          return;
     }

     GPIO_PinState state = (status == true ? GPIO_PIN_SET : GPIO_PIN_RESET);
     HAL_GPIO_WritePin(_port, _pin, state);
}

bool IOHandle::Read()
{
     if (_IoFunction != IOFunction::Input)
     {
          return false;
     }

     return HAL_GPIO_ReadPin(_port, _pin) == GPIO_PIN_SET ? true : false;
}

void IOHandle::StartTimer()
{
     if (!IsPWMFunction())
     {
          HAL_TIM_PWM_Start(_timer, _channel);
     }
}

void IOHandle::StopTimer()
{
     if (!IsPWMFunction())
     {
          HAL_TIM_PWM_Stop(_timer, _channel);
     }
}

void IOHandle::SetPWM(uint32_t pwm)
{
     if (!IsPWMFunction())
     {
          return;
     }

     __HAL_TIM_SET_COMPARE(_timer, _channel, pwm);

}

bool IOHandle::IsPWMFunction() {
     return (_IoFunction == IOFunction::PWM && _timer != nullptr);
}

void IOHandle::SetFunction(IOFunction ioFunction)
{
     _IoFunction = ioFunction;

     switch (ioFunction)
     {    
          case NotDefined:
          case Input:
               InitAsDigitalIn();
               break;
          case Output:
               InitAsDigitalOut();
               break;
          case PWM:
               if (IsPWMFunction()) 
               {
                    InitAsPWMOut();
               }
               else 
               {
                    InitAsDigitalIn();
               }

               break;
          default:
               break;
     }
}

IOFunction IOHandle::GetFunction() const
{
     return _IoFunction;
}

void IOHandle::InitAsDigitalIn() 
{
     GPIO_InitStruct.Pin = _pin;
     GPIO_InitStruct.Mode = GPIO_MODE_INPUT; // Digital output mode
     GPIO_InitStruct.Pull = GPIO_NOPULL;
     GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
     HAL_GPIO_Init(_port, &GPIO_InitStruct);
}

void IOHandle::InitAsDigitalOut() 
{
     GPIO_InitStruct.Pin = _pin;
     GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP; // Digital output mode
     GPIO_InitStruct.Pull = GPIO_NOPULL;
     GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
     HAL_GPIO_Init(_port, &GPIO_InitStruct);
}

void IOHandle::InitAsPWMOut() 
{
	  TIM_OC_InitTypeDef sConfigOC = {0};
     HAL_TIM_PWM_Stop(_timer, _channel);

     sConfigOC.OCMode = TIM_OCMODE_PWM1;
     sConfigOC.Pulse = 0;
     sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
     sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
     sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
     sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
     sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
     if (HAL_TIM_PWM_ConfigChannel(_timer, &sConfigOC, _channel) != HAL_OK)
     {

     }

     GPIO_InitStruct.Pin = _pin;
     GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
     GPIO_InitStruct.Pull = GPIO_NOPULL;
     GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

     if(_timer->Instance == TIM17)
         GPIO_InitStruct.Alternate = GPIO_AF10_TIM17;

     if(_timer->Instance == TIM3 && _channel == TIM_CHANNEL_4)
         GPIO_InitStruct.Alternate = GPIO_AF10_TIM3;

     if(_timer->Instance == TIM3 && (_channel == TIM_CHANNEL_1 || _channel == TIM_CHANNEL_2))
         GPIO_InitStruct.Alternate = GPIO_AF2_TIM3;

     HAL_GPIO_Init(_port, &GPIO_InitStruct);

     HAL_TIM_PWM_Start(_timer, _channel);
}

uint32_t IOHandle::GetPin()
{
	return _pin;
}

GPIO_TypeDef* IOHandle::GetPort()
{
	return _port;
}

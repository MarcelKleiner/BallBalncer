#include "IOHandle.h"


IOHandle::IOHandle(GPIO_TypeDef* port, uint32_t pin, TIM_HandleTypeDef* timer, uint32_t channel)
{
     HAL_TIM_PWM_MspInit(_timer);
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

     switch (_channel)
     {
     case 1:
          __HAL_TIM_SET_COMPARE(_timer, TIM_CHANNEL_1, pwm);
          break;
     case 2:
          __HAL_TIM_SET_COMPARE(_timer, TIM_CHANNEL_2, pwm);
          break;
     case 3:
          __HAL_TIM_SET_COMPARE(_timer, TIM_CHANNEL_3, pwm);
          break;
     case 4:
          __HAL_TIM_SET_COMPARE(_timer, TIM_CHANNEL_4, pwm);
          break;
     case 5:
          __HAL_TIM_SET_COMPARE(_timer, TIM_CHANNEL_5, pwm);
          break;
     case 6:
          __HAL_TIM_SET_COMPARE(_timer, TIM_CHANNEL_6, pwm);
          break;
     default:
          break;
     }
}

bool IOHandle::IsPWMFunction() {
     return (_IoFunction == IOFunction::PWM && _timer != nullptr);
}

void IOHandle::SetFunction(IOFunction ioFunction)
{
     _IoFunction == ioFunction;

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
     HAL_TIM_PWM_Stop(_timer, _channel);
     GPIO_InitStruct.Pin = _pin;
     GPIO_InitStruct.Mode = GPIO_MODE_AF_PP; // Alternative function mode
     GPIO_InitStruct.Pull = GPIO_NOPULL;
     GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
     HAL_GPIO_Init(_port, &GPIO_InitStruct);
     HAL_TIM_PWM_Start(_timer, _channel);
}
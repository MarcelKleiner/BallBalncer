#include "IOFunction.h"
#include <stm32g431xx.h>
#include <stm32g4xx_hal.h>

#ifndef SRC_IO_IOHANDLE_H_
#define SRC_IO_IOHANDLE_H_

class IOHandle
{
	public:
		IOHandle(GPIO_TypeDef* port, uint32_t pin, TIM_HandleTypeDef* timer, uint32_t channel);
		IOHandle(GPIO_TypeDef* port, uint32_t pin);

		void Write(bool status);
		bool Read();
		void StartTimer();
		void StopTimer();
		void SetPWM(uint32_t pwm);
		void SetFunction(IOFunction ioFunction);
		IOFunction GetFunction() const;

		uint32_t GetPin();
		GPIO_TypeDef* GetPort();

	private:
		IOFunction _IoFunction;
		GPIO_TypeDef* _port;
		uint32_t _pin;
		TIM_HandleTypeDef* _timer;
		uint32_t _channel;
		
		GPIO_InitTypeDef GPIO_InitStruct;

		bool IsPWMFunction();
		void InitAsDigitalIn();
		void InitAsDigitalOut();
		void InitAsPWMOut();
};

#endif /* SRC_IO_IOHANDLE_H_ */

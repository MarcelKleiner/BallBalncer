
#ifndef SRC_ENCODER_H_
#define SRC_ENCODER_H_

#include <stm32g431xx.h>
#include "stdint.h"

class IEncoder
{
    public:
		virtual ~IEncoder() {};

        virtual int32_t GetValue() = 0;
        virtual void SetValue(int32_t value)= 0;
        virtual void ResetValue()= 0;
        virtual void Update()= 0;
};

#endif

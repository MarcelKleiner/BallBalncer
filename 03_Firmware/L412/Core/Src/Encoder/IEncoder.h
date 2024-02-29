#include "stm32l4xx.h"  //ToDo set correcto controller include
#include "stdint.h"

#ifndef SRC_ENCODER_H_
#define SRC_ENCODER_H_

class IEncoder
{
    public:
        virtual int32_t GetValue();
        virtual void SetValue(int32_t value);
        virtual void ResetValue();
        virtual void Update();
};

#endif

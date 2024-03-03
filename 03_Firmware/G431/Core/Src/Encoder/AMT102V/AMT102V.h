
#include "tim.h"

#ifndef SRC_AMT102V_H_
#define SRC_AMT102V_H_

#include "../IEncoder.h"

class AMT102V: public IEncoder
{
    public:
        AMT102V(TIM_HandleTypeDef* timer);

        int32_t GetValue() override;
        void SetValue(int32_t value) override;
        void ResetValue() override;
        void Update() override;

    private:
		TIM_HandleTypeDef* timer;

		int32_t currentValue;
		int32_t lastValue;
		int32_t deltaValue;
		int32_t encoderValue;
};


#endif

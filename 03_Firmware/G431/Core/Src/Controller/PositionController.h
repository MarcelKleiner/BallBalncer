
#ifndef SRC_CONTROLLER_POSITIONCONTROLLER_H_
#define SRC_CONTROLLER_POSITIONCONTROLLER_H_

#include "stm32g4xx_hal.h"
#include "stdint-gcc.h"

#include "../Encoder/IEncoder.h"


class PositionController
{
	public:
		PositionController(IEncoder *encoder);

		int32_t Update(int32_t targetPosition);

	private:

		IEncoder* _encoder;

		int32_t posKp = 10;
		int32_t posError = 0;
		int32_t currentPosValue = 0;
		int32_t resultPosValue = 0;

		constexpr int32_t MaxPosValue = 20000;
		constexpr int32_t MinPosValue = -20000;

};

#endif /* SRC_CONTROLLER_POSITIONCONTROLLER_H_ */

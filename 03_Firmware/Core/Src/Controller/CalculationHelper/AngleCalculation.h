#include <stm32l4xx_hal.h>

#ifndef SRC_CONTROLLER_CALCULATIONHELPER_ANGLECALCULATION_H_
#define SRC_CONTROLLER_CALCULATIONHELPER_ANGLECALCULATION_H_

//Sin approximation Polynomial coefficients;
constexpr float a1 = -1/6;
constexpr float a2 = 1/120;

//ArcSin approximation Polynomial coefficients:
constexpr float b1 = 1/6;
constexpr float b2 = 3/40;

constexpr float angleConvertFactor = 0.017453293; //pi/180


class AngleCalculation
{
	public:
		AngleCalculation();

		int32_t CalculateTargetEncoderValue(float angle);

	private:
		float ConvertFromDegreeToRad(float angle);
		float SinusApproximation(float angleRad);
		float ArcSinusApproximation(float angleRad);
};

#endif /* SRC_CONTROLLER_CALCULATIONHELPER_ANGLECALCULATION_H_ */

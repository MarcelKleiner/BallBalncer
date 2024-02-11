#include "../Taskhandler/Taskhandler.h"
#include "../Drive/DriveControl.h"
#include "../IO/IOHandle.h"

#include "main.h"

#ifndef SRC_APPMAIN_APPLICATIONMAIN_H_
#define SRC_APPMAIN_APPLICATIONMAIN_H_

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim6;
extern TIM_HandleTypeDef htim15;
extern TIM_HandleTypeDef htim16;

class ApplicationMain
{
	public:
		ApplicationMain();

		void StartUp();
		void Main();


		Taskhandler taskhandler = Taskhandler();
	private:

		IOHandle ioHandleXAxisEnR = IOHandle(EN_CH1R_GPIO_Port, EN_CH1R_Pin);
		IOHandle ioHandleXAxisInR = IOHandle(IN_CH1R_GPIO_Port, IN_CH1R_Pin, &htim1, TIM_CHANNEL_3);

		IOHandle ioHandleXAxisEnL = IOHandle(EN_CH1L_GPIO_Port, EN_CH1L_Pin);
		IOHandle ioHandleXAxisInL = IOHandle(IN_CH1L_GPIO_Port, IN_CH1L_Pin, &htim15, TIM_CHANNEL_2);


		IOHandle ioHandleYAxisEnR = IOHandle(EN_CH2R_GPIO_Port, EN_CH2R_Pin);
		IOHandle ioHandleYAxisInR = IOHandle(IN_CH2R_GPIO_Port, IN_CH2R_Pin, &htim15, TIM_CHANNEL_1);

		IOHandle ioHandleYAxisEnL = IOHandle(EN_CH2L_GPIO_Port, EN_CH2L_Pin);
		IOHandle ioHandleYAxisInL = IOHandle(IN_CH2L_GPIO_Port, IN_CH2L_Pin, &htim16, TIM_CHANNEL_1);


		DriveControl driveCoontrolXAxis = DriveControl(
				&ioHandleXAxisEnL,
				&ioHandleXAxisInL,
				&ioHandleXAxisEnR,
				&ioHandleXAxisInR);

		DriveControl driveCoontrolYAxis = DriveControl(
				&ioHandleYAxisEnL,
				&ioHandleYAxisInL,
				&ioHandleYAxisEnR,
				&ioHandleYAxisInR);
};

#endif /* SRC_APPMAIN_APPLICATIONMAIN_H_ */

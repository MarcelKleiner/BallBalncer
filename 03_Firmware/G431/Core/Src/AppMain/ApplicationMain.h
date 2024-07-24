

#ifndef SRC_APPMAIN_APPLICATIONMAIN_H_
#define SRC_APPMAIN_APPLICATIONMAIN_H_

#include "../Taskhandler/Taskhandler.h"
#include "../Drive/DriveControl.h"
#include "../IO/IOHandle.h"
#include "../Drive/Homing/Home.h"
#include "../Encoder/AMT102V/AMT102V.h"
#include "../Controller/Controller.h"
#include "../Error/Error.h"

#include "main.h"


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

		void CheckDriveZeroPosition(DriveControl* driveControl, IEncoder* encoder);

		Error error = Error();

		AMT102V encoderX = AMT102V(&htim1);
		AMT102V encoderY =  AMT102V(&htim2);

		IOHandle refSwitchXAxis = IOHandle(REF_MOT1_GPIO_Port, REF_MOT1_Pin);

		IOHandle ioHandleXAxisEnR = IOHandle(EN_MOT_CH1R_GPIO_Port, EN_MOT_CH1R_Pin);
		IOHandle ioHandleXAxisInR = IOHandle(IN_MOT_CH1R_GPIO_Port, IN_MOT_CH1R_Pin, &htim17, TIM_CHANNEL_1);

		IOHandle ioHandleXAxisEnL = IOHandle(EN_MOT_CH1L_GPIO_Port, EN_MOT_CH1L_Pin);
		IOHandle ioHandleXAxisInL = IOHandle(IN_MOT_CH1L_GPIO_Port, IN_MOT_CH1L_Pin, &htim3, TIM_CHANNEL_4);

		IOHandle refSwitchYAxis = IOHandle(REF_MOT2_GPIO_Port, REF_MOT2_Pin);

		IOHandle ioHandleYAxisEnR = IOHandle(EN_MOT_CH2R_GPIO_Port, EN_MOT_CH2R_Pin);
		IOHandle ioHandleYAxisInR = IOHandle(IN_MOT_CH2R_GPIO_Port, IN_MOT_CH2R_Pin, &htim3, TIM_CHANNEL_2);

		IOHandle ioHandleYAxisEnL = IOHandle(EN_MOT_CH2L_GPIO_Port, EN_MOT_CH2L_Pin);
		IOHandle ioHandleYAxisInL = IOHandle(IN_MOT_CH2L_GPIO_Port, IN_MOT_CH2L_Pin, &htim3, TIM_CHANNEL_1);


		DriveControl driveControlXAxis = DriveControl(
				&ioHandleXAxisEnL,
				&ioHandleXAxisInL,
				&ioHandleXAxisEnR,
				&ioHandleXAxisInR,
				&refSwitchXAxis);

		DriveControl driveControlYAxis = DriveControl(
				&ioHandleYAxisEnL,
				&ioHandleYAxisInL,
				&ioHandleYAxisEnR,
				&ioHandleYAxisInR,
				&refSwitchYAxis);

		Home HomeDriveX = Home(&driveControlXAxis, &encoderX);
		Home HomeDriveY = Home(&driveControlYAxis, &encoderY);

		Controller xController = Controller(&driveControlXAxis, &encoderX);
		Controller yController = Controller(&driveControlYAxis, &encoderY);
};

#endif /* SRC_APPMAIN_APPLICATIONMAIN_H_ */

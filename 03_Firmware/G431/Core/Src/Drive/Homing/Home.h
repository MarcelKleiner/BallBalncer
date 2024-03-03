

#ifndef SRC_DRIVE_HOMING_HOME_H_
#define SRC_DRIVE_HOMING_HOME_H_

#include "../DriveControl.h"
#include "HomingState.h"
#include "../../Encoder/IEncoder.h"

class Home final {
public:
	Home(DriveControl* driveControl, IEncoder* encoder);
	void HomeDrive(RotationDirection rotationDirection);

private:
	static constexpr uint16_t speed = 1500;

	HomingState _currentHomingState;
	HomingState _nextHomingState;

	IEncoder* _encoder;
	DriveControl* _driveControl;

	bool DriveToSwitchPos(RotationDirection rotationDirection);
	bool DriveToCenterPos(RotationDirection rotationDirection);
};

#endif /* SRC_DRIVE_HOMING_HOME_H_ */

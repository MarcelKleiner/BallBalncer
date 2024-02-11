#include "stdint-gcc.h"


#ifndef SRC_APPSETTINGS_H_
#define SRC_APPSETTINGS_H_

constexpr float MinAngle = -30;
constexpr float MaxAngle = 30;

//Angle calculation helper

constexpr uint8_t PlatformArmLength = 110;
constexpr uint8_t MotorArmLength = 52.5;

//Encoder increments per 1/pi
constexpr int encoderRation = 32595; //increments per output rad


//task time

constexpr int LedUpdateTime = 401;
constexpr int DriveUpdateTime = 11;
constexpr int EncoderUpdateTime = 5;
constexpr int ErrorUpdateTime = 499;


#endif

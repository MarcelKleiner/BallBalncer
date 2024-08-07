#include "../AppSettings.h"
#include "Taskhandler.h"

Taskhandler::Taskhandler() {}

void Taskhandler::UpdateTaskhandler()
{
     if(_taskCounter % ErrorUpdateTime == 0)
     {
          _isErrorTaskUpdateRequest = true;
     }

     if(_taskCounter % DriveUpdateTime == 0)
     {
          _isDriveTaskUpdateRequest = true;
     }

     if(_taskCounter % EncoderUpdateTime == 0)
     {
          _isEncoderTaskUpdateRequest = true;
     }

     if(_taskCounter % ControllerUpdateTime == 0)
     {
    	 _isControllerUpdateReques = true;
     }

     if(_taskCounter % LedUpdateTime == 0)
     {
          _isLedTaskUpdateRequest = true;
     }

     _taskCounter++;
	 if(_taskCounter == 11005445+1)
	 {
		 _taskCounter = 0;
	 }


}

bool Taskhandler::IsErrorTask()
{
	if(!_isErrorTaksUpdateEnable)
		return false;

     bool isTaskUpdateRequest = _isErrorTaskUpdateRequest;
     _isErrorTaskUpdateRequest = false;
     return isTaskUpdateRequest;
}

bool Taskhandler::IsDriveTask()
{
	if(!_isDriveTaskUpdateEnable)
		return false;

     bool isTaskUpdateRequest = _isDriveTaskUpdateRequest;
     _isDriveTaskUpdateRequest = false;
     return isTaskUpdateRequest;
}

bool Taskhandler::IsEncoderTask()
{
	if(!_isEncoderTaskUpdateEnable)
		return false;

     bool isTaskUpdateRequest = _isEncoderTaskUpdateRequest;
     _isEncoderTaskUpdateRequest = false;
     return isTaskUpdateRequest;
}

bool Taskhandler::IsLedTask()
{
	if(!_isLedTaskUpdateEnable)
		return false;

     bool isTaskUpdateRequest = _isLedTaskUpdateRequest;
     _isLedTaskUpdateRequest = false;
     return isTaskUpdateRequest;
}

bool Taskhandler::IsControllerTask()
{
	if(!_isControllerUpdateEnable)
		return false;

	bool isTaskUpdateRequest = _isControllerUpdateReques;
	_isControllerUpdateReques = false;
	return isTaskUpdateRequest;
}

bool Taskhandler::SetErrorTaskEnable(bool status)
{
	_isErrorTaksUpdateEnable = status;
}

bool Taskhandler::SetDriveTaskEnable(bool status)
{
	_isDriveTaskUpdateEnable = status;
}

bool Taskhandler::SetEncoderTaskEnable(bool status)
{
	_isEncoderTaskUpdateEnable = status;
}

bool Taskhandler::SetLedTaskEnable(bool status)
{
	_isLedTaskUpdateEnable = status;
}

bool Taskhandler::SetControllerTaskEnable(bool status)
{
	_isControllerUpdateEnable = status;
}

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
     bool isTaskUpdateRequest = _isErrorTaskUpdateRequest;
     _isErrorTaskUpdateRequest = false;
     return isTaskUpdateRequest;
}

bool Taskhandler::IsDriveTask()
{
     bool isTaskUpdateRequest = _isDriveTaskUpdateRequest;
     _isDriveTaskUpdateRequest = false;
     return isTaskUpdateRequest;
}

bool Taskhandler::IsEncoderTask()
{
     bool isTaskUpdateRequest = _isEncoderTaskUpdateRequest;
     _isEncoderTaskUpdateRequest = false;
     return isTaskUpdateRequest;
}

bool Taskhandler::IsLedTask()
{
     bool isTaskUpdateRequest = _isLedTaskUpdateRequest;
     _isLedTaskUpdateRequest = false;
     return isTaskUpdateRequest;
}

#ifndef SRC_TASKHANDLER_TASKHANDLER_H_
#define SRC_TASKHANDLER_TASKHANDLER_H_

class Taskhandler
{
     public:

     Taskhandler();

     void UpdateTaskhandler();

     bool IsErrorTask();
     bool IsDriveTask();
     bool IsEncoderTask();
     bool IsLedTask();
     bool IsControllerTask();

     bool SetErrorTaskEnable(bool status);
     bool SetDriveTaskEnable(bool status);
     bool SetEncoderTaskEnable(bool status);
     bool SetLedTaskEnable(bool status);
     bool SetControllerTaskEnable(bool status);

     private:

     int _taskCounter = 0;

     bool _isErrorTaskUpdateRequest = false;
     bool _isEncoderTaskUpdateRequest = false;
     bool _isDriveTaskUpdateRequest = false;
     bool _isLedTaskUpdateRequest = false;
     bool _isControllerUpdateReques = false;

     bool _isErrorTaksUpdateEnable = false;
     bool _isEncoderTaskUpdateEnable = false;
     bool _isDriveTaskUpdateEnable = false;
     bool _isLedTaskUpdateEnable = false;
     bool _isControllerUpdateEnable = false;
};

#endif /* SRC_TASKHANDLER_TASKHANDLER_H_ */

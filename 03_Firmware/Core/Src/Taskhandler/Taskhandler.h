/*
 * Taskhandler.h
 *
 *  Created on: Feb 3, 2024
 *      Author: marce
 */

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


     private:

     int _taskCounter = 0;

     bool _isErrorTaskUpdateRequest = false;
     bool _isEncoderTaskUpdateRequest = false;
     bool _isDriveTaskUpdateRequest = false;
     bool _isLedTaskUpdateRequest = false;


};

#endif /* SRC_TASKHANDLER_TASKHANDLER_H_ */

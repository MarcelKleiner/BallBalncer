/*
 * Error.h
 *
 *  Created on: Mar 17, 2024
 *      Author: marce
 */

#ifndef SRC_ERROR_ERROR_H_
#define SRC_ERROR_ERROR_H_

class Error {
public:

	enum ErrorCode
	{
		NoError = 0,
		DrivePositionOutOfBoundsError = 1,
		TargetAngleOutOfRangeError = 2
	};

	Error();

	void SetError(ErrorCode errorCode);
	void Reset();
	ErrorCode GetError();

	bool HasError();

private:
	ErrorCode _errorCode;

};

#endif /* SRC_ERROR_ERROR_H_ */

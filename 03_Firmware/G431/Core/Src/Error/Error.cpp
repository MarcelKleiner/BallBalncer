/*
 * Error.cpp
 *
 *  Created on: Mar 17, 2024
 *      Author: marce
 */

#include "Error.h"

Error::Error() {
	// TODO Auto-generated constructor stub
}

void Error::SetError(ErrorCode errorCode)
{
	_errorCode = errorCode;
}


Error::ErrorCode Error::GetError()
{
	return _errorCode;
}

bool Error::HasError()
{
	return (_errorCode != ErrorCode::NoError);
}

void Error::Reset()
{
	_errorCode = ErrorCode::NoError;
}

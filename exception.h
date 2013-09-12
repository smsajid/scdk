#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

#include "object.h"

namespace scdk {
/** Base Exception class **/
class SCException {
protected:	
	int        _number;
	const char *_message;

public:
	SCException(int n, const char *d){
		_number = n;
		_message = d;
	}

	int getNumber() {
		return _number;
	}

	const char* getMessage() {
		return _message;
	}
};

class SCInvalidColorException: public SCException {
public:
	SCInvalidColorException(): SCException(100, "InvalidColorException") {
	}
};

}

#endif

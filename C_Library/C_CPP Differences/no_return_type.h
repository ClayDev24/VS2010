#ifndef __NO_RETURN_TYPE_H__
#define __NO_RETURN_TYPE_H__
#include <stdio.h>

// No return type:
no_return() {		// C. returns int(default).
	return 77;		// Comments out this line to return garbage.
};

void no_return2() {};// C/C++.  Returns nothing.

void _no_return_type() {
	int i;
	no_return();
	no_return2();
	printf("no_return :%d\n", no_return());
	//printf("no_return2:%d\n", no_return2()); //ERROR: func defines void as ret type.
}

#endif // __NO_RETURN_TYPE_H__
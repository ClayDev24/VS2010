#pragma once
#include <iostream>
#include <assert.h>	// assert(bool)

namespace utils {
	// NOT IMPLEMENTED YET!
	static void _assert(int* myInt) {
		assert(myInt);//!=NULL);
		if(myInt)
			std::cout << *myInt << std::endl;
		
	}
	// ***************** <<_USAGE_>> *****************
	static void _assertUsage() {
		int a =10;
		int *b=NULL;
		b=&a;
		_assert(b);

		//int *c;
		//_assert(c);
		//assert(c);
	}

} // utils
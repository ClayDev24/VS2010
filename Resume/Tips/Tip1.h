#pragma once
#include <iostream>
enum mytypes { myexp1 = 1, myexp2 };

static void _tip1() {
    try {
		throw myexp2;
	//>>>Tip1: Specify exception objs by const reference in exception handlers. It is rare to modify and rethrow an exception:
	// Doin' so avoid obj slicin' or even duplicatin' objs.
	} catch(const mytypes &ex) { // Exception type (class names) usually gives ya enough info to deal w/ it.
		std::cout << "Exception type: " << ex << "\n";
	} catch(...) { //>>>Tip2: A catchall clause (ellipses) must be put at the very end.
		std::cout << "Any kinda exception\n";
	}
}
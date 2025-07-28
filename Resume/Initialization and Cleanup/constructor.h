// The class designer can guarantee initialization o'every obj by providing a function: constructor.
#pragma once
#include <iostream>
#include "defines.h"
using std::cout;

class Tree {
	int height;
public:
	// Constructor's job's 2 initialize a block o'memo properly
	Tree(int _h) {
		DS_("Tree()");
		height = _h;
	}
	// Automatic called by the compile when obj goes outta scope.
	~Tree() { DS("~Tree()") }
	inline void printsize() { P_(height) }
};
 
static void _constructor() {

	{ // beginning of a scope:
		cout << "{\n\t";	
		// Needlees to call any initialize C-fashion function...
		// In C++ definition and initialization are unified concepts with abstract data type (class).
		Tree t(2); TAB	// The compiler always calls the constructor at the point of declaration.
		t.printsize();	// Proper initialized, right to use at this point.
		cout << "}\n";
	} // end'of scope

}	// Destructor called in here
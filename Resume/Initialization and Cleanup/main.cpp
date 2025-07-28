// A large segment of C bugs occur when the programmer forgets to initializa or clean up a variable.
//#include "vld.h" // No memory leakds DETECTED!
#include <iostream>
#include "constructor.h"
#include "default_constructor.h"
#include "destructor.h"
#include "initializer_list.h"
using namespace std;

int main() {

	_constructor();
	_default_constructor();
	_destructor();
	_initializer_list();

	system("pause");
	return(0);
}
#include <iostream>
#include "header1.h"

void function1() {
	global = 33;
	std::cout << "function1():" << global << std::endl;
}
// Only one definition allowed. ERROR!:
//void function1() { // ...already has a body
//	global = 33;
//	std::cout << "function1():" << global << std::endl;
//}
//#include "vld.h" // No memory leaks DETECTED!
#include <iostream>
#include "virtual_base.h"
#include "nested.h"
#include "list.h"
using namespace std;

int main() {

	_listUsage();
	_virtual_baseUsage();
	_nestedUsage();

	system("pause");
	return(0);
} 
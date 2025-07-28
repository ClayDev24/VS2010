//#include "vld.h" // No memory leaks DETECTED!
#include <iostream>
#include "header1.h"
#include "header2.h"
using namespace std;

int main() {
	global = 44;
	cout << "Multiple instances of global var defined.\n"
		 << "Each one in a different translation unit: header1.cpp & main.cpp:\n";
	function1();
	cout << "global     :" << global << endl;

	system("pause");
	return(0);
}
//#include "vld.h" // No memory leaks DETECTED!
#include <iostream>
#include "default_arguments.h"
#include "overloading.h"
#include "redefining.h"
#include "var_params.h"
#include "virtual.h"
using namespace std;

// Prototype:
long multiply(long, long); // Optional var names

int main() {
	
	cout << "2 x 3 = " << multiply(2, 3) << endl;
	_overloading();
	_redefining();
	_var_params();
	_virtual();
	_default_arguments();
	
	system("pause");
	return(0);
}

static long multiply(long left, long right) { // Var names are optional if not used inside func body. Otherwise how would ya reference them?
	return (long)left * right;
}
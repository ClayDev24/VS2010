//#include "vld.h" // No memory leaks DETECTED!
#include <iostream>
#include "MyError.h"
#include "resumption.h"
#include "mytypes.h"
#include "inheritance.h"
#include "terminate.h"
#include "resource_management.h"
#include "RAII.h"
#include "catch_inside_constructor.h"
#include "auto_ptr.h"
#include "function_try_block.h"
#include "specification.h"
using namespace std;

int main() {
	
	_MyError();
	//_resumption();
	//_mytypes();
	//_inheritance();
	//_terminate();
/*	{
		cout << "Stack Unwinding w/ exception inside constructor:\n";
		_resource_management();
		cout << "\n2 ways to prevent such memo leaks:\n1-Catchin' exceptions inside constructor:\n";
		_catch_inside_constructor();
		cout << "\n2-(RAII)Placing allocations/deallocations inside external objs:\n";
		_RAII();
	}
*/	//_auto_ptr();
	//_function_try_block();
	//_specification();

	system("pause");
	return(0);
}
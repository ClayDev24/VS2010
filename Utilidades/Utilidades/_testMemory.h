#pragma once
#include <iostream>
#include <new>

namespace utils {

	static void _testMemory(void* pt) {
		if(!pt) {
			std::cout << "ERROR!: Memory could not be allocated";
			exit(0);
		}
	}
	static bool _testPointer(void* pt, const char* msg, const int& errorCode=0) {
		if(!pt) {
			std::cout << msg;
			if(errorCode)
				std::cout << " Error Code: " << errorCode;
			return false;
		}
		return true;
	}
	// ***************** <<_USAGE_>> *****************
	// CÓDIGO COM ERRO DE FUNCIONALIDADE....
	static void _testMemoryUsage() {
		using namespace std;
		int *i = new int(55);
		cout << *i << endl;
		_testMemory(i);
		delete i;
		//int *i2;// = new int(5);		// warning msg
		//_testPointer(i2, "error");	// ERROR msg
	}
} // utils
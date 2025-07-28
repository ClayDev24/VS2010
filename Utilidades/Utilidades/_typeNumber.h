#pragma once
#include <iostream>
#include <conio.h>
#include <sstream>
#include <string>
#include <new>
#include "_isNumber.h"

namespace utils {

	static float* _typeNumber(const signed int &_max, std::string msg = "Type a positive integer number (x to exit): ") {
		using namespace std;
		string str;
		float *a1 = new float[_max];
		int cont = 0;
		float value = 0.0;
		do {
			std::cout << msg << std::endl;  // Negative numbers to be implemented yet.
			getline(cin, str);
			stringstream(str) >> value;
			std::cout << value << std::endl;
				if(_isNumber(str)) {
					a1[cont++] = value;
					continue;
				} else {
					puts("(valor nao numerico)");
					continue;
				}
		} while((str != "x") && (cont < _max));
		return a1;
	}

	// ***************** <<_USAGE_>> *****************
	static void _typeNumberUsage() {
		int max = 5;
		float *arrayNum = _typeNumber(max);

		for(int i=0; i<max; i++)
			std::cout << arrayNum[i] << std::endl;
	}

} // utils


#pragma once
#include <iostream>
#include <string>
#include <new>
#include "_random.h"

namespace utils {

	static std::string _randomWords(const int &_sz, int _min, int _max) {
		char *text = new char[_sz+1];
		for (int i=0; i<_sz; i++)
			text[i] = _random(_min, _max);
		
		text[_sz] = 0;
		std::string s=text;
		delete []text;
		return s;
	}
	// ***************** <<_USAGE_>> *****************
	static void _randomWordsUsage() {
		for(int i=0; i<100; i++)
			std::cout << _randomWords(_random(3, 10), 'a', 'z') << std::endl;
	}

} // utils
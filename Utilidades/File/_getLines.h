#pragma once
// Break a file into whitespace-separated words
#include <iostream> // cout, cin
#include <string>   // string
#include <fstream>  // ifstream
#include "..\Utilidades\_showVetor.h"

namespace utils {

	static vetorStr* _getLines(const char* _str) {
		vetorStr* v=new vetorStr();
		std::ifstream in(_str);
		std::string line;
		while(getline(in, line))
			v->push_back(line); 
		in.close();
		return v;
	}
	// **************<<_USAGE_>>****************
	static void _getLinesUsage() {
		vetorStr* lines=_getLines("main.cpp");
		_showVetor(*lines);
		delete lines;
	}
} // utils
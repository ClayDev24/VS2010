#pragma once
// Break a file into whitespace-separated words
#include <iostream> // cout, cin
#include <string>   // string
#include <fstream>  // ifstream
#include <vector>   // vector<>
#include <conio.h>  // getche()
#include "..\Utilidades\_showVetor.h"

namespace utils {

	static vetorStr* _getWords(const char* _str) {
		vetorStr *words = new vetorStr();
		std::string word;
		std::ifstream in(_str);
		while(in >> word)
			words->push_back(word); 
		in.close();
		return words;
	}
	// **************<<_USAGE_>>****************
	static void _getWordsUsage() {
		vetorStr* words=_getWords("main.cpp");
		_showVetor(*words);
		delete words;
	}

} // utils

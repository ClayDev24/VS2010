// Read an entire file into a single string
#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

namespace resume {

	static void _fillString() {

		ifstream in("_fillString.h");
		string s, line;
		while(getline(in, line))
			s += line + "\n";
		cout << s;

	}

} // resume
#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "DOS\StackDOS.h"
#include "DOS\StackDOS2.h"
#include "DOS\StackDOS3.h"
#include "..\..\Utilidades\Utilidades\_require.h"
using namespace std;

namespace dos {

	static void stackDOSUsage() {
		ifstream in("main.cpp");
		utils::assure(in,  "main.cpp");
		Stack textlines;
		string line;
		// Read file and store lines in the stack:
		while(getline(in, line))
			textlines.push(new string(line));
		// Pop the lines from the stack and print them:
		string *s;
		while((s = (string*)textlines.pop()) != 0) {
			cout << *s << endl;
			delete s; 
		}

		// StrStack:
		ifstream in2("main.cpp");
		utils::assure(in2,  "main.cpp");
		StrStack text;
		while(getline(in2, line))
			text.push(new string(line));
		while((s = text.pop()) != 0) { // No cast!
			cout << *s << endl;
			delete s;
		}

		// StrStack2:
		ifstream in3("main.cpp");
		utils::assure(in3,  "main.cpp");
		StrStack2 text2;
		while(getline(in3, line))
			text2.push(new string(line));
		while((s = text2.pop()) != 0) // No cast!
			cout << *s << endl;
	}

} // dos

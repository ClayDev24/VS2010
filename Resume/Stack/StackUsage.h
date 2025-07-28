// Test of nested linked list (Stack)
#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "stack.h"
#include "stack2.h"
#include "stack3.h"
#include "..\..\Utilidades\Utilidades\_require.h"
using namespace std;

namespace res {

	static void stackUsage() {
		ifstream in("main.cpp");
		utils::assure(in, "main.cpp");
		Stack stk;
		stk.initialize();
		string line;
		string* s;
		// Read file and store lines in the Stack:
		while(getline(in, line))
			stk.push(new string(line));
		in.close();
		// Pop the lines from the Stack and print them:
		while((s = (string*)stk.pop())) { // void* must be first cast back to a string ptr.
			cout << *s << endl; // String ptr dereferenced.
			delete s; 
		}
		stk.cleanup();

		// Stack2:
		// Now the interface presented to the client programmer is truly that of a push-down stack.
		// It happens to be implemented as a linked list,
		// but now, with class access specifiers, you can change it w/out breakin'up clients code.
		ifstream in2("main.cpp");
		utils::assure(in2, "main.cpp");
		Stack2 stk2;
		stk2.initialize();
		// Read file and store lines in the Stack:
		while(getline(in2, line))
			stk2.push(new string(line));
		in2.close();
		// Pop the lines from the Stack and print them:
		while((s = (string*)stk2.pop())) { // void* must be first cast back to a string ptr.
			cout << *s << endl; // String ptr dereferenced.
			delete s; 
		}
		stk2.cleanup();

		// Stack3:
		ifstream in3("main.cpp");
		utils::assure(in3, "main.cpp");
		Stack3 stk3; // Needless to call initialize(). Constructor called automatically.
		// Read file and store lines in the Stack:
		while(getline(in2, line))
			stk3.push(new string(line));
		in3.close();
		// Pop the lines from the Stack and print them:
		while((s = (string*)stk3.pop())) { // void* must be first cast back to a string ptr.
			cout << *s << endl; // String ptr dereferenced.
			delete s; // Lib user ownership.
		}
	}

} // res
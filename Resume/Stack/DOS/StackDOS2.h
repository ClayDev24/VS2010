// Specializing the Stack class (Hold strings)
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "DOS\StackDOS.h"
#include "..\..\Utilidades\Utilidades\_require.h"
using namespace std;

namespace dos {

	class StrStack : public Stack {
	public:
		inline void push(string* str) {
			Stack::push(str);
		}
		inline string* peek() const {
			string* s = (string*)Stack::peek();
			return s;
		}
		inline string* pop() {
			return (string*)Stack::pop();
		}
		~StrStack() {
			string* top = pop();
			while(top) {
				delete top;
				top = pop();
			}
		}
	};

} // dos
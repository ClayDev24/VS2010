// Composition vs. inheritance:
// One of the clearest ways to determine whether you shoud be using composition
// or inheritance is by asking whether you'll ever need to upcast from your new class.
#pragma once 
#include <iostream>
#include <fstream>
#include <string>
#include "DOS\StackDOS.h"
#include "..\..\Utilidades\Utilidades\_require.h"
using namespace std;

namespace dos {

	class StrStack2 {
		Stack stack; // Embed instead of inherit
	public:
		inline void push(string* str) {
			stack.push(str);
		}
		inline string* peek() const {
			return (string*)stack.peek();
		}
		inline string* pop() {
			return (string*)stack.pop();
		}
	};

} // dos
#pragma once
#include <iostream>

/*struct*/class A {

private: // Redundant: structures default to public: Available to everyone.
	char c1;
public:
	char getChar() {
		return c1;
	};
	void setChar(char c) {
		c1 = c;
		//std::cout << "Settin'up c1: " << c1 << std::endl;
	};
};

static void _public() {
	using namespace std;
	A a;
	char ch;
	//a.c1 = 'a'; // Settin'up...
	//std::cout << "Showin'up c1: " << a.c1 << std::endl;
	a.setChar('b');
	ch = a.getChar();
	cout << "Showin'up c1: " << ch << endl;

	a.setChar('c');
	ch = a.getChar();
	cout << "Showin'up c1: " << ch << endl;

	//::cout << "Showin'up c1: " << a.c1 << std::endl;
};
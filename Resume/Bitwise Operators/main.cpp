// Bitwise.cpp
//#include "vld.h" // No memory leaks DETECTED!
#include <iostream>
#include <conio.h>
#include "bitwise.h"
using namespace std;

// A macro to save typing:
#define PR(STR, EXPR) \
	cout << STR; _printBinary(EXPR); cout << endl;  

int main(void) {
	unsigned int getval;
	unsigned char a, b;
	cout << "Enter a number between 0 and 255: ";
	cin >> getval;
	a = getval;
	PR("a in binary: ", a);
	cout << "Enter a number between 0 and 255: ";
	cin >> getval; b = getval;
	PR("b in binary: ", b);
	PR("a | b = ", a | b);
	PR("a & b = ", a & b);
	PR("a ^ b = ", a ^ b);
	PR("~a = ", ~a);
	PR("~b = ", ~b);
	// An interesting bit pattern:
	unsigned char c = 0x5A; 
	PR("c in binary: ", c);
	a |= c;
	PR("a |= c; a = ", a);
	b &= c;
	PR("b &= c; b = ", b);
	b ^= a;
	PR("b ^= a; b = ", b);

	_rol(a);
	PR("rol(a) = ", a);
	_ror(a);
	PR("ror(a) = ", a);
	_rol(b);
	PR("rol(b) = ", b);
	_ror(b);
	PR("ror(b) = ", b);

	unsigned char d = 1;
	for(int i=0; i<8; i++)
		PR("ror(d) = ", _ror(d))
	for(int i=0; i<8; i++)
		PR("ror(d) = ", _rol(d))

	system("pause");
	return(0);
}

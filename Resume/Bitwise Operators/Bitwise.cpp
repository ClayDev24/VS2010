#include <iostream>
#include "bitwise.h"

void _printBinary(const unsigned char val) {
	for(int i=7; i>=0; i--)
		if(val & (1 << i))
			std::cout << "1";
		else
			std::cout << "0";
}

// Rotation.cpp
// Perform left and right rotations in C++

unsigned char _rol(unsigned char &val) {
	int highbit;
	if(val & 0x80) // 0x80 is the high bit only
		highbit = 1;
	else
		highbit = 0;
	// Left shift (bottom bit becomes 0):
	val <<= 1;
	// Rotate the high bit onto the bottom:
	val |= highbit;
	return val;
}

unsigned char _ror(unsigned char &val) {
	int lowbit;
	if(val & 1) // Check the low bit
		lowbit = 1;
	else
		lowbit = 0;
	val >>= 1; // Right shift by one position
	// Rotate the low bit onto the top:
	val |= (lowbit << 7);
	return val;
}

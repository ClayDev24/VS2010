#pragma once
#include <iostream>
#include <string>
#include "_1_character_strings.h" //  macro PR()

namespace resume {

	static void _assign() {
		using namespace std;
		string str;
		string base = "The quick brown fox jumps over a lazy dog.";
		// used in the same order as described above:
		str.assign(base);							PR(str) // "The quick brown fox jumps over a lazy dog."
		str.assign(base, 10, 9);					PR(str) // "brown fox"
		str.assign("pangrams are cool", 7);			PR(str) // "pangram"
		str.assign("c-string");						PR(str) // "c-string"
		str.assign(10, '*');						PR(str) // "**********"
		str.assign<int>(10, 0x2D);					PR(str) // "----------"
		str.assign(base.begin()+16, base.end()-12); PR(str) // "fox jumps over"
	}

} // resume
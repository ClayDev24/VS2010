#pragma once
#include <iostream>
#include <string>
#include "_1_character_strings.h"

namespace resume {

	static void _operators() {
		using namespace std;
		// String Assignment:
		string s1, s2, s3;
		s1 = "string1";		PR(s1) // string1
		s2 = "string2";		PR(s2) // string2
		s3 = s1 + " " + s2;	PR(s3) // string1 + string2

		// string::operator+= (Append to string)
		string name("John");	PR(name)
		string family("Smith");	PR(family)
		name += " K. ";			PR(name) // c-string
		name += family;			PR(name) // string
		name += '\n';			PR(name) // character

		// string::operator[]
		string str("length()");
		// The at member function has the same behavior as this, but performs a check range.
		for(unsigned int i=0; i < str.length(); i++)
			cout << str[i] << endl; // Gets char in the string
	}

} // resume
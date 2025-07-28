// string constructor
#pragma once
#include <iostream>
#include <string>

namespace resume {

	static void _constructor() {
		using namespace std;
		string s0 ("Initial string");
		// constructors used in the same order as described above:
		string s1;				// Empty strings
		string s2(s0);

		string s2a = "Hello, World.";	// Initialization1
		string s2b("I am"); 			// Initialization2

		string s3(s0, 8, 3);			// (str, pos, n)
		string s4("A character sequence", 6);			// (char, sz)	  : "A char"
		string s5("Another character sequence", 8, 9);	// (char, pos, sz): "character"
		string s6(10, 'x');				// "xxxxxxxxxx"
		string s7a(10, 42);				// "**********"
		string s7b(s0.begin(), s0.begin()+7); // "Initial"

		string s8  = "Today"; 			// Assigning to a string
		string s9  = s0 + " " + s3;		// Combining strings
		s9		  += " 8 "; 			// Appending to a string
		cout << s1 + s2 + "!" << endl;

		cout << "\n s1 : " << s1  << "\n s2 : " << s2 << "\n s3 : " << s3;
		cout << "\n s4 : " << s4  << "\n s5 : " << s5 << "\n s6 : " << s6;
		cout << "\n s7a: " << s7a << "\n s7b: " << s7b << endl;
	}

}  // resume
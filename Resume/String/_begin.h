#pragma once
#include <iostream>
#include <string>
//string::begin
//string::end

namespace resume {

	static void _begin() {
		using namespace std;
		string str("begin() test string...\n");
		string::iterator it;
		// Returns an iterator referrin' to the first character in teh string.
		for(it = str.begin(); it < str.end(); it++)
			cout << *it;
	}

	static void _rbegin() {
		using namespace std;
		string str("rbegin() test string...\n");
		string::reverse_iterator it;
		// Returns reverse iterator to reverse begin/end :
		for(it = str.rbegin(); it < str.rend(); it++)
			cout << *it;
		cout << endl;
	}

} // resume
#pragma once
#include <iostream>
#include <string>

namespace resume {

	// Erases part o'the str content. Shortenin' its length:
	static void _erase() {
		using namespace std;
		string str("This is an example phrase.");
		
		// erase used in the same order as described above:
		str.erase(10,8); // (pos, span)
		cout << str << endl;        // "This is an phrase."

		string::iterator it;
		it=str.begin()+9;
		str.erase(it); // only char at pos 9 ('n') is affected
		cout << str << endl;        // "This is a(n) phrase."

		str.erase(str.begin()+5, str.end()-7); // Erases all chars between first and last iterators.
		cout << str << endl;        // "This phrase."
	}

} // resume
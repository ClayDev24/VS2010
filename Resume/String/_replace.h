#pragma once
#include <iostream>
#include <string>

namespace resume {

#define PR(x) \
	cout << #x << ": " << x << endl;

	// Replaces part o'string:
	static void _replace() {
		using namespace std;
		string str  = "this is a test string."; PR(str)
		string str2 = "n example";				PR(str2)
		string str3 = "sample phrase";			PR(str3)
		string str4 = "useful.";				PR(str4)
		// function versions used in the same order as described above:
		// Using positions:
		str.replace(9, 5, str2);			PR(str) // "this is an example string."
		str.replace(19, 6, str3, 7, 6);     PR(str) // "this is an example phrase."
		str.replace(8, 10, "just all", 6);	PR(str) // "this is just a phrase."
		str.replace(8, 6, "a short");		PR(str) // "this is a short phrase."
		str.replace(22, 1, 3, '!');			PR(str) // "this is a short phrase!!!"

		// Using iterators:
		string::iterator it = str.begin();				//  ^
		str.replace(it, str.end()-3, str3);		PR(str) // "sample phrase!!!"
		str.replace(it, it+6, "replace it", 7); PR(str) // "replace phrase!!!"
		it += 8;										//          ^
		str.replace(it, it+6, "is cool");		PR(str) // "replace is cool!!!"
		str.replace(it+4, str.end()-4, 4, 'o'); PR(str) // "replace is cooool!!!"
		it+=3;											//             ^
		str.replace(it, str.end(), str4.begin(), str4.end()); PR(str)
		// "replace is useful."
	}

} // resume
#pragma once
#include <iostream>
#include <string>

namespace resume {

	static void _clear() {
		using namespace std;
		string str("clear() test string...");
		cout << "\"" << str << "\" - size: " << str.size() << "\n";
		str.clear(); // Sets str to an empty str thus leaving its size at 0 chars.
		cout << "\"" << str << "\" - size: " << str.size() << "\n";
	}

} // resume
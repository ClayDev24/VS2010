#pragma once
#include <iostream>
#include <string>


namespace resume {

	static void _substr() {
		using namespace std;
		string str("We think in generalities, but we live in details.");
		// quoting Alfred N. Whitehead
		string str2, str3;	

		str2 = str.substr(12, 12);		// "generalities"
		size_t pos = str.find("live");	// position of "live" in str
		str3 = str.substr(pos);			// get from "live" to the end

		cout << str2 << ' ' << str3 << endl;
	}

} // resume
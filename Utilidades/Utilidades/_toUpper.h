#pragma once
#include <iostream>
#include <algorithm>// transform()
#include <string>

namespace utils {

	static void _str2Upper(std::string &_str) {
		transform(_str.begin(), _str.end(), _str.begin(), ::toupper);
	}
	static void _str2Lower(std::string &_str) {
		transform(_str.begin(), _str.end(), _str.begin(), ::tolower);
	}
	static char _ch2Upper(const char _ch) {
		return toupper(_ch);
	}
	static char _ch2Lower(const char _ch) {
		return tolower(_ch);
	}
	// ***************** <<_USAGE_>> *****************
	static void _2UpperUsage() {
		using namespace std;
		std::string s = "clailton";
		_str2Upper(s);
		cout << s << endl;
		_str2Lower(s);
		cout << s << endl;

		cout << _ch2Upper('a') << endl;
		cout << _ch2Lower('A') << endl;
	}

} // utils

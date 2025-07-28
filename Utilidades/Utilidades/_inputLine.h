#pragma once
#include <iostream>
#include <sstream>
#include <string>

namespace utils {
	// Gets the whole line:
	static std::string _inputLine(std::string msg = "Type a LINE: ") {
		std::string str;
		std::cout << msg;
		std::cin.clear();
		getline(std::cin, str);
		return str;
	}
	// ***************** <<_USAGE_>> *****************
	static void _inputLineUsage() {
		std::string s = _inputLine("What's your complete name? \n");
		std::cout << "Hello, " << s << std::endl;
	}

} // utils
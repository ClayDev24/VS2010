#pragma once
#include <iostream> // cout, cin
#include <string>

namespace utils {
	// Gets only the first word:
	static std::string _inputWord(std::string msg = "Type a WORD: ") {
		std::cout << msg;
		std::string s;
		std::cin >> s;
		//P_(s.length())
		return s;
	}
	// ***************** <<_USAGE_>> *****************
	static void _inputWordUsage() {
		std::string s = _inputWord("Type your first name: ");
		std::cout << s << std::endl;
	}

} // utils
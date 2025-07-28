#pragma once
#include <iostream>
#include <string>

namespace resume {

	static void _copy() {
		int  sz;
		char buffer[20];
		std::string str("Test string...");
		sz = str.copy(buffer, 6, 5); //(buf, span, pos)
		buffer[sz] = '\0'; // zero terminated string
		std::cout << "buffer contains: " << buffer << "\n";
	}

} // resume
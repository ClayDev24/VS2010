// comparing size, length, capacity and max_size
#pragma once
#include <iostream>
#include <string>
#include "defines.h"

namespace resume {

	static void _length() {
		std::string str("lenght() test string...");			 
		std::cout << "str     : " << str			<< "\n"; // lenght() test string...
		std::cout << "size    : " << str.size()     << "\n"; // The sz of str contents
		std::cout << "length  : " << str.length()   << "\n"; // Alias to above
		std::cout << "capacity: " << str.capacity() << "\n"; // The sz o'allocated str space. Equal or greater than the str contents.
		std::cout << "max_size: " << str.max_size() << "\n"; // The maximum number o'chars that the str obj can hold.

		char *str2 = "Clailton";
		int length = strlen(str2);
		P_(str2)
			P_(length)
	}

} // resume
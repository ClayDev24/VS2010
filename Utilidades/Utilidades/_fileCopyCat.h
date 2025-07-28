#pragma once
#include <string>
#include <fstream>

namespace utils {

	static void _fileCopyCat(const char *_f1, const char *_f2) {
		std::ifstream in(_f1);	// Open for reading
		std::ofstream out(_f2);	// Open for writing
		std::string s;
		while(getline(in, s))	// Discards newline char
			out << s << "\n";	// ... must add it back
		in.close();
		out.close();
	}
	// ***************** <<_USAGE_>> *****************
	static void _fileCopyCatUsage() {
		_fileCopyCat("main.cpp", "mainCopyTest.txt");
	}

} // utils

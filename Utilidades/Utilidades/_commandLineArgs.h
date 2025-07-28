#pragma once
#include <iostream>

namespace utils {

	static void _commandLineArgs(int argc, char *argv[]) {
		// this must be in main function: int main(int argc, char *argv[]) {
		// prints the always seen message
		if(argc < 2)
			std::cout << "No arguments found...\n";
		else
			for(int i=0; i<argc; i++)
				std::cout << argv[i] << std::endl;
	}
	// ***************** <<_USAGE_>> *****************
	static void _commandLineArgsUsage(int argc, char *argv[]) {
		std::cout << "Open this prog in command line and try to type some args...\n";
		_commandLineArgs(argc, argv);
	}

} // utils
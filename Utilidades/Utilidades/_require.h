// Test for error conditions in programs
#pragma once
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <string>

#define DEBUGREQUIRE // another flag in define_print.h
#ifdef  DEBUGREQUIRE
#define REQUIRE(OP) \
	((OP) ? (void)0 : utils::require(OP, #OP));
#else
#define REQUIRE(OP) \
	((void)0);
#endif

namespace utils {

	static void require(bool requirement, 
		const std::string& msg = "Requirement failed") {
			if (!requirement) {
				fputs(msg.c_str(), stderr);
				fputs("\n", stderr);
				std::cout << stderr;
				system("pause");
				//exit(1);
			}
	}
	static void requireArgs(int argc, int args, 
		const std::string& msg = 
		"Must use %d arguments") {
			if (argc != args + 1) {
				fprintf(stderr, msg.c_str(), args);
				fputs("\n", stderr);
				exit(1);
			}
	}
	static  void requireMinArgs(int argc, int minArgs,
		const std::string& msg =
		"Must use at least %d arguments") {
			if(argc < minArgs + 1) {
				fprintf(stderr, msg.c_str(), minArgs);
				fputs("\n", stderr);
				exit(1);
			}
	}
	static void assure(std::ifstream& in, 
		const std::string& filename = "") {
			if(!in) {
				fprintf(stderr, "Could not open file %s\n",
					filename.c_str());
				exit(1);
			}
	}
	static void assure(std::ofstream& out, 
		const std::string& filename = "") {
			if(!out) {
				fprintf(stderr, "Could not open file %s\n", 
					filename.c_str());
				exit(1);
			}
	}
	// ***************** <<_USAGE_>> *****************
	static void _requireUsage() {
		// IMPORTANT: Set DEBUG flat mode ON: (above)

		unsigned int var = 10;
		REQUIRE(var >= 0 && var <= 9)
	}

} // utils
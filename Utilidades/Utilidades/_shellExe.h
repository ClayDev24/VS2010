#pragma once
#include <cstdlib> // system();

namespace utils {

	static void _exe(const char* _str) {
		// USAGE:
		system(_str);
		// or:
		//system("c:\\windows\\system32\\calc.exe");
	}
	// ***************** <<_USAGE_>> *****************
	static void _exeUsage() {
		_exe("calc.exe");
	}

} // utils
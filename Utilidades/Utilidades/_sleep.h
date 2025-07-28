#pragma once
#include <Windows.h> // Sleep()

namespace utils {

	static void _sleep(const int &_milliseconds) {

		Sleep(_milliseconds);

	}
	// ***************** <<_USAGE_>> *****************
	static void _sleepUsage() {
		std::cout << "Contar 10 segundos...";
		for(int i=1; i < 11; i++) {
			Sleep(1000);
			std::cout << i << "...";
		}
		std::cout << std::endl;
	}
} // utils
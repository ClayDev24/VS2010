#pragma once
#include <iostream>
#include <cstdint>

static uint32_t s_AllocCount = 0;
static uint32_t s_AllocSize  = 0;
//void* operator new(size_t size);

namespace utils {
	void* operator new(size_t size);
	static void prtAlloc() {
		std::cout << s_AllocCount << " allocations (";
		std::cout << s_AllocSize  << " bytes)\n";
	}

	// ***************** <<_USAGE_>> *****************
	static void _allocCountUsage() {
		// NOT IMPLEMENTED YET!
		//std::string *temp = new std::string[10];
		//std::string s = "aaa";

		prtAlloc();
	}


} // utils
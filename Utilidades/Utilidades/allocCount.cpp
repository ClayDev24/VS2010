#include "_allocCount.h"

void* operator new(size_t size) {
	s_AllocCount++;
	s_AllocSize += size;
	//std::cout << "Allocating " << size << " bytes\n";

	return malloc(size);
}
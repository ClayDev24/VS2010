#pragma once
// C-like library converted to C++
// 1- The first fundamental twist o'C++ over C: Functions
// inside structs: abstract data type (creatin'objects/instances).
struct Stash {
	// struct's defaults to public in C++:
	int m_size;				// Size of each space
	int m_total;				// Number of storage spaces
	int m_next;				// Next empty space
	unsigned char* storage;	// Dynamically allocated array of bytes:
	// Functions! (ptr obs is implicit in function calls)
	void  initialize(int size);
	void  clean();
	int   size();
	void  grow(int increase);
	void* get (int index);
	int   add (const void* data);
};
// ***************** <<_USAGE_>> *****************
void StashUsage();
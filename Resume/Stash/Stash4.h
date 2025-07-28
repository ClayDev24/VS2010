#pragma once
// Usin' Function Overloadin'(constructor)
class Stash4 {
	int m_size;				// Size of each space
	int m_total;				// Number of storage spaces
	int m_next;				// Next empty space
	const int m_increment;
	unsigned char* storage;	// Dynamically allocated array of bytes:
	void inflate(int increase);// Used in underlyin'implementation (func add)
public:
	Stash4(int size);
	// Constructor overloading:
	Stash4(int size, int initQnt);
	~Stash4();
	void* get(int index);
	int   add(const void* data); // Sometime later you can change to a better memory management system (in grow()) w/out breakin'up client codes.
	int   size();
};
// ***************** <<_USAGE_>> *****************
void Stash4Usage();

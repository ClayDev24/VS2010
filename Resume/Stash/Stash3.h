#pragma once
// 1- Usin'constructor/destructor instead of initialize/cleanup:
class Stash3 { // Defaults to private
	// Implementation: Internal usage only. Ya could change at will
	int m_size;				// Size of each space
	int m_total;			// Number of storage spaces allocated (offset)
	int m_next;				// Next empty space
	const int m_increment;
	unsigned char* storage;	// Dynamically allocated array of bytes:
	void grow(int increase);// Used in underlyin'implementation (func add)
public: // Interface. Client programmer usage:
	Stash3(int size); // Constructor (initialization)
	~Stash3();		  // Destructor  (cleanup chores)
	void* get(int index);
	int   add(const void* data); // Sometime later you can change to a better memory management system (in grow()) w/out breakin'up client codes.
	int   size();
};
// ***************** <<_USAGE_>> *****************
void Stash3Usage();
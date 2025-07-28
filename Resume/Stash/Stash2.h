#pragma once
// Usin'class instead o'struct
// 1- Usage of access specifiers. The implementation & interface are now clearly distinguished.
// There's no way o'client programmer accidentally manipulate a part o'the class he should not.
class Stash2 {
	// Defaults to private
	// Implementation: Internal usage only. Ya could change at will
	int m_size;				// Size of each space
	int m_total;			// Number of storage spaces
	int m_next;				// Next empty space
	unsigned char* storage;	// Dynamically allocated array of bytes:
	void grow(int increase);// Used in underlyin'implementation (func add)
public: // Interface. Client programmer usage:
	void  initialize(int size);
	void  clean();
	int   size();
	void* get (int index);
	int   add (const void* data); // Sometime later you can change to a better memory management system (in grow()) w/out breakin'up client codes.
};
// ***************** <<_USAGE_>> *****************
void Stash2Usage();
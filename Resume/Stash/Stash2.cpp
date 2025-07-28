// C library converted to C++
#include <iostream>
#include <cassert>
#include <fstream>
#include <string>
#include "Stash2.h"
using namespace std;

const int increment = 100; // Storage increased by...

void Stash2::initialize(int _sz) {
	m_size  = _sz;// Size of each space (sizeof(type)) being used:
	m_total = 0;  // Apply the member selector s->m_total automatically
	m_next  = 0;  // s->m_next didn't really add any meanin' to what you were doin' anyway.
	// if you want to access the address of this function use 'this' keyword:
	this->storage = 0; // same as: 's->m_storage in CStash version. Redundant in this case
}

void Stash2::clean() {
	if(storage)
		delete []storage;
}

int Stash2::add(const void* _data) {
	if(m_next >= m_total) // Enough space left?
		grow(increment);
	// Calculatin' nest empty space:
	int startBytes   = m_next * m_size; 
	unsigned char* e = (unsigned char*)_data;
	// Byte-by-byte copyin':
	for(int i=0; i<m_size; i++)
		storage[startBytes + i] = e[i];
	m_next++;
	return(m_next - 1); // Zero index number
}
// Scope resolution (::) operator - Names now can belongs to an scope:
void* Stash2::get(int _index) {
	// Check index boundaries:
	assert(_index >= 0);
	if(_index >= m_next)
		return 0; // To indicate the end
	// Produce pointer to desired element:
	return &(storage[_index * m_size]);
}

int Stash2::size() {
	return m_next; // Number of elements in CStash
}

void Stash2::grow(int _increase) {
	assert(_increase > 0);
	int newSize  = m_total + _increase;
	int newBytes = newSize * m_size;
	int oldBytes = m_total * m_size;
	unsigned char* b = new unsigned char[newBytes];
	for(int i=0; i<oldBytes; i++)
		b[i] = storage[i]; // Copy old to new
	delete []storage; // Old storage
	storage = b; // Point to new memory
	m_total = newSize;
}
// ***************** <<_USAGE_>> *****************
void Stash2Usage() {
	Stash2   s2;	// Declaration (allocates uninitialized storage).
	string   line;
	ifstream in("main.cpp"); assert(in);
	s2.initialize(sizeof(char)*128); // Initialization

	while(getline(in, line))
		s2.add(line.c_str());
	// C++ access specifiers prevent direct access via member variable: s2.next
	for(int i=0; i < s2.size(); i++)
		cout << (char*)s2.get(i) << endl;		

	s2.clean();
	in.close();
}
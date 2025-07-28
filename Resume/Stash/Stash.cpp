// C library converted to C++
#include <iostream>
#include <cassert>
#include <fstream>
#include <string>
#include "Stash.h"
using namespace std;

const int increment = 100; // Storage increased by...
int size;	// It does not clashes with struct member var.
// Compiler secrets passes the &s inside struct.
void Stash::initialize(/*struct &s,*/int _sz) {
	// Size of each space (sizeof(type)) being used:
	m_size  = _sz;// Compiler first search for members struct bfore uses the global version instead.
	m_total = 0;  // And apply the member selector s->m_total automatically
	m_next  = 0;  // s->m_next didn't really add any meanin' to what you were doin' anyway.
	// if you want to access the address of this function use 'this' keyword:
	this->storage = 0; // same as: 's->m_storage in CStash version. Redundant in this case
}

int Stash::add(const void* _data) {
	if(m_next >= m_total) // Enough space left?
		grow(increment);
	// Calculatin' nest empty space:
	int startBytes   = m_next * m_size; 
	unsigned char* e = (unsigned char*)_data;
	// Byte-by-byte copyin':
	for(int i=0; i<m_size; i++)
		storage[startBytes + i] = e[i];
	m_next++;
	return(m_next - 1); // Index number
}
// Scope resolution (::) operator - Names now can belongs to an scope:
void* Stash::get(int _index) {
	// Check index boundaries:
	assert(_index >= 0);
	if(_index >= m_next)
		return 0; // To indicate the end
	// Produce pointer to desired element:
	return &(storage[_index * m_size]);
}

int Stash::size() {
	return m_next; // Number of elements in CStash
}

void Stash::grow(int _increase) {
	assert(_increase > 0);
	int newQuantity  = m_total + _increase;
	int newBytes     = newQuantity * m_size;
	int oldBytes     = m_total * m_size;
	unsigned char* b = new unsigned char[newBytes];
	for(int i=0; i<oldBytes; i++)
		b[i] = storage[i]; // Copy old to new
	delete []storage; // Old storage
	storage = b; // Point to new memory
	m_total   = newQuantity;
}

void Stash::clean() {
	if(storage)
		delete []storage;
}
// ***************** <<_USAGE_>> *****************
void StashUsage() {
	Stash    s1;	// typedefless
	string   line;
	ifstream in("main.cpp"); assert(in);
	s1.initialize(sizeof(char)*128); // 128 bytes / line
	while(getline(in, line))
		s1.add(line.c_str());

	for(int i=0; i < s1.size(); i++)	  // Dumb programmers use struct member direct: 'strStash.next'
		cout << (char*)s1.get(i) << endl; // zero indexed array

	s1.clean();
	in.close();
}

// C library converted to C++
#include <iostream>
#include <cassert>
#include <fstream>
#include <string>
#include "Stash4.h"
#include "..\..\Utilidades\Utilidades\_require.h"
using namespace std;

Stash4::Stash4(int _sz):m_increment(100) {
	m_size  = _sz;
	m_total = 0; 
	m_next  = 0; 
	this->storage = 0;
}
// 2- Function Overloading (constructor):
Stash4::Stash4(int _sz, int _growSz):m_increment(_growSz) {
	m_size  = _sz;// Compiler first search for members struct bfore uses the global version instead.
	m_total = 0; // And apply the member selector s->m_total automatically
	m_next  = 0; // s->m_next didn't really add any meanin' to what you were doin' anyway.
	// if you want to access the address of this function use 'this' keyword:
	this->storage = 0; // same as: 's->m_storage in CStash version. Redundant in this case
	inflate(_growSz);
}

Stash4::~Stash4() {
	cout << "~Stash4()\n";
	if(storage)
		delete []storage;
}

int Stash4::add(const void* _data) {
	if(m_next >= m_total) // Enough space left?
		inflate(m_increment);
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
void* Stash4::get(int _index) {
	// Check index boundaries:
	utils::require(_index >= 0, "Stash4::out of index ERROR!");
	if(_index >= m_next)
		return 0; // To indicate the end
	// Produce pointer to desired element:
	return &(storage[_index * m_size]);
}

int Stash4::size() {
	return m_next; // Number of elements in CStash
}

void Stash4::inflate(int _increase) {
	//cout << "inflate()...\n";
	utils::require(_increase > 0, "Stash4::grow zero or negative increase");
	int newSize  = m_total + _increase;
	int newBytes = newSize * m_size;
	int oldBytes = m_total * m_size;
	unsigned char* b = new unsigned char[newBytes];
	for(int i=0; i<oldBytes; i++)
		b[i] = storage[i];	// Copy old to new
	delete []storage;		// Old storage
	storage = b;			// Point to new memory
	m_total = newSize;
}
// ***************** <<_USAGE_>> *****************
void Stash4Usage() {
	string   line;
	ifstream in("main.cpp"); assert(in);
	// Function Overloading (constructor):
	Stash4 s4(sizeof(char)*128, 10); // Declaration & initializations takes place together (in constructor argument list)

	while(getline(in, line))
		s4.add(line.c_str());
	// C++ access specifiers prevent direct access via member variable: s2.next
	for(int i=0; i < s4.size(); i++)
		cout << (char*)s4.get(i) << endl;		
	// s3.~Stash3(); // Destructor are called automatically when obj goes outta scope
	in.close();
}
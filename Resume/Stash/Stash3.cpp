// C library converted to C++
#include <iostream>
#include <cassert>
#include <fstream>
#include <string>
#include "Stash3.h"
#include "..\..\Utilidades\Utilidades\_require.h"
using namespace std;

Stash3::Stash3(int _sz):m_increment(100) {
	m_size  = _sz;
	m_total = 0;
	m_next  = 0;
	this->storage = 0;
}

Stash3::~Stash3() {
	cout << "~Stash3()\n";
	if(storage)
		delete []storage;
}

int Stash3::add(const void* _data) {
	if(m_next >= m_total) // Enough space left?
		grow(m_increment);
	// Calculatin' nest empty space:
	int startBytes   = m_next * m_size; 
	unsigned char* e = (unsigned char*)_data;
	// Byte-by-byte copyin':
	for(int i=0; i<m_size; i++)
		storage[startBytes + i] = e[i];
	m_next++;
	return(m_next - 1);
}

void* Stash3::get(int _index) {
	// Check index boundaries:
	utils::require(_index >= 0, "Stash3::out of index");
	if(_index >= m_next)
		return 0; // To indicate the end
	// Produce pointer to desired element:
	return &(storage[_index * m_size]);
}

int Stash3::size() {
	return m_next; // Number of elements in CStash
}

void Stash3::grow(int _increase) {
	utils::require(_increase > 0, "Stash3::grow zero or negative increase");
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
void Stash3Usage() {
	string   line;
	ifstream in("main.cpp"); assert(in);

	// In C++ you can define objs where needed. It leads to:
	Stash3 s3(sizeof(char)*128); // Declaration & initializations takes place together (in constructor argument list)

	while(getline(in, line))
		s3.add(line.c_str());
	// C++ access specifiers prevent direct access via member variable: s2.next
	for(int i=0; i < s3.size(); i++)
		cout << (char*)s3.get(i) << endl;		
	// s3.~Stash3(); // Destructor are called automatically when obj goes outta scope
	in.close();
}
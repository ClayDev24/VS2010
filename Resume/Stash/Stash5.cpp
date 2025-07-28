#include <iostream>
#include <cassert>
#include <fstream>
#include <string>
#include "Stash5.h"
using namespace std;

int Stash5::add(void *_data) {
	if(m_next >= m_total) // Enough space left?
		inflate(m_increment);
	// Copy element into storage,
	// starting at next empty space:
	int index = m_next * m_size;
	unsigned char *e = (unsigned char*)_data;
	for(int i=0; i<m_size; i++)
		m_storage[index+i] = e[i];
	m_next++;
	return(m_next-1); // Index number
}

void Stash5::inflate(const int &_inc) {
	assert(_inc >= 0);
	if(_inc == 0) return;
	int newSize  = m_total + _inc;
	int newBytes = newSize * m_size;
	int oldBytes = m_total * m_size;
	unsigned char* b = new unsigned char[newBytes];
	for(int i=0; i<oldBytes; i++)
		b[i] = m_storage[i]; // Copy old to new
	delete [](m_storage);	 // Release old storage
	m_storage = b;			 // Point to new memory
	m_total   = newSize;	 // Adjust the size
}
// ***************** <<_USAGE_>> *****************
void Stash5Usage() {
	Stash5 s1(sizeof(int));
	for(int i=0; i<100000; i++)
		s1.add(&i);
	for(int i=0; i<s1.size(); i++)
		cout << "s1.get(" << i << ")=> " << *(int*)s1.get(i) << endl;

	const int buf = 80;
	Stash5 s2(sizeof(char) * buf, 100);
	ifstream in("main.cpp");
	utils::assure(in,  "main.cpp");
	string line;
	while(getline(in, line))
		s2.add((char*)line.c_str());

	char* cp;
	int i=0;
	while((cp=(char*)s2.get(i++))!=0)
		cout << "s2.get(" << i << ")=> " << cp << endl;
}


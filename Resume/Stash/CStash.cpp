// Implementation of example C-like library. Declare structure and functions:
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include "CStash.h"

using namespace std;
// Quantity o'elements to add when growin'storage:
const int increment = 100;

void CStash_initialize(CStash* _s, int _sz) {
	_s->size    = _sz; // size of the type being storage
	_s->total   = 0;
	_s->next    = 0;
	_s->storage = 0;
}

void CStash_clean(CStash* _s) {
	if(_s->storage)
		delete []_s->storage;
}

int CStash_size(CStash* _s) {
	return _s->next;
}

int CStash_add(CStash* _s, const void* _data) {
	if(_s->next >= _s->total) // Enough space left?
		CStash_grow(_s, increment);

	int startBytes   = _s->next * _s->size; 
	unsigned char* e = (unsigned char*)_data;
	// Byte-by-byte copyin':
	for(int i=0; i<_s->size; i++)
		_s->storage[startBytes + i] = e[i];		

	return((++_s->next)-1); // Index number
}

void* CStash_get(CStash* _s, int _index) {
	assert(_index >= 0);	// Check index boundaries:
	if(_index >= _s->next)	// Reachs the end
		return 0;
	// Produce ptr 2 desired data(byte):
	return &(_s->storage[_index * _s->size]);
}

void CStash_grow(CStash* _s, int _increase) {
	assert(_increase > 0);
	int newTotal     = _s->total + _increase;
	int newBytes     =  newTotal * _s->size;
	int oldBytes     = _s->total * _s->size;
	unsigned char* n = new unsigned char[newBytes];

	for(int i=0; i<oldBytes; i++)
		n[i] = _s->storage[i];	// Copy old to new

	delete [](_s->storage);	// Old storage
	_s->storage = n;		// Point  to new memory
	_s->total   = newTotal;	// Update total
}
// ***************** <<_USAGE_>> *****************
void CStashUsage() {
	// Test the C-like library: Stash.h
	// Define vars at beginning of the block, as in C:
	CStash intStash, strStash;
	int i;
	char *dt;
	ifstream in;
	string line;
	const int bufsz = 80;
	// Now remember to initialize the variables:
	CStash_initialize(&intStash, sizeof(int));
	for(i=0; i<100; i++)
		CStash_add(&intStash, &i);
	for(i=0; i<CStash_size(&intStash); i++)
		cout << "fetch(&intStash, " << i << ") = " << *(int*)CStash_get(&intStash, i) << endl;
	
	// Holds 80-character strings:
	CStash_initialize(&strStash, sizeof(char)*bufsz);
	in.open("main.cpp");
	assert(in);
	while(getline(in, line))
		CStash_add(&strStash, line.c_str());
	i = 0;
	while((dt = (char*)CStash_get(&strStash,i++))!=0)
		cout << "fetch(&stringStash, " << i << ") = " << dt << endl;
	
	CStash_clean(&intStash);
	CStash_clean(&strStash);
}



#pragma once
#include "..\..\Utilidades\Utilidades\_require.h"
// Inline functions

class Stash5 {
	int m_size;   // Size of each space
	int m_total;  // Number of storage spaces
	int m_next;   // Next empty space
	const int m_increment;
	// Dynamically allocated array of bytes:
	unsigned char *m_storage;
	void inflate(const int &increase);
public:
	Stash5(int sz):m_increment(100), m_size(sz), m_total(0), m_next(0), m_storage(0) {}
	Stash5(int sz, int initQnt):m_increment(initQnt),m_size(sz), m_total(0), m_next(0), m_storage(0) { 
		inflate(initQnt); 
	}
	Stash5::~Stash5() {
		if(m_storage != 0) 
			delete []m_storage;
	}
	int  add(void *data);
	void *get(const int &index) const {
		utils::require(0 <= index, "Stash::fetch (-)index");
		if(index >= m_next)
			return 0; // To indicate the end
		// Produce pointer to desired element:
		return &(m_storage[index * m_size]);
	}
	int size() const { return m_next; }
};
// ***************** <<_USAGE_>> *****************
void Stash5Usage();


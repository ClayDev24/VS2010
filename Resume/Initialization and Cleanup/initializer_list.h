// Initializing const in classes
#pragma once
#include <iostream>

class Fred {
	const int m_size;
public:
	Fred(int sz);
	void Print();
};

Fred::Fred(int _sz) : m_size(_sz) {} // Constructor initialization list (Special initialization point)
void Fred::Print() { std::cout << m_size << std::endl; }

class Integer {
	int m_i;
public:
	Integer(int _i = 0);
	void Print();
};

Integer::Integer(int _i) : m_i(_i) {}
void Integer::Print() { std::cout << m_i << ' '; }

static void _initializer_list() {
	Fred f1(1), f2(2), f3(3);
	f1.Print(), f2.Print(), f3.Print();

	Integer i1[100]; // Already initialized to zero
	for(int i = 0; i<100; i++)
		i1[i].Print();
};
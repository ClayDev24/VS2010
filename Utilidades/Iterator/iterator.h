#pragma once
#include <iostream>
#include <iterator>

class Iterador : public std::iterator<std::input_iterator_tag, int> {
	int *p;
public:
	Iterador(int *x) :p(x) {}
	Iterador(const Iterador& mit) : p(mit.p) {}
	Iterador& operator++() { ++p; return *this; }
	Iterador& operator++(int) { p++; return *this; }
	bool operator==(const Iterador& rhs) { return p==rhs.p; }
	bool operator!=(const Iterador& rhs) { return p!=rhs.p; }
	int& operator*() { return *p; }
};

static void _iteratorUsage() {
	using namespace std;

	int numbers[] = {10,20,30,40,50};
	Iterador start(numbers+2);
	Iterador end(numbers+5);

	for(Iterador it=start; it!=end; it++)
		cout << *it << " ";
	cout << endl;
}
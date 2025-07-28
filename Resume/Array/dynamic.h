#pragma once
#include <new>		// std::nothrow
#include "include_all.H"
#include "utils.h"
#include "defines.h"
using namespace std;

class Obj {
	int i;
public:
	Obj(int _i=0):i(_i) {}; // Default constructor
	~Obj() { DS_("~Obj()...") }

	friend ostream& operator<<(ostream& os, const Obj &obj) {
		return os << "obj.i: " << obj.i << endl;
	};
};

struct Values {
	int i1, i2;
	Values(int _i1=0, int _i2=1):i1(_i1), i2(_i2) {}
	friend ostream& operator<<(ostream& os, const Values &v) {
		return os << "Values: v:" << v.i1 << ", v2:" << v.i2 << endl;
	}
};

//****PROTOTYPES****
void uniDim (const int &Size);
void multiDim (const int &Size);
void structUnidim(const int &Size);
void classUnidim(const int &Size);

// Creates array dynamically on the heap:
void _dynamic() {
	int sz;
	cout << "Enter the size o'the arrays: ";
	cin  >> sz;

	//uniDim(sz);
	//multiDim(sz);
	//structUnidim(sz);
	classUnidim(sz);
}

void uniDim(const int &_sz) {	
	char** const nomes  = new(nothrow) char*[_sz];	// Defining a dynamic array o'chars
	int* const inteiros = new(nothrow) int[_sz];
	std::string* const strings = new(nothrow)std::string[_sz];
	utils::_testMemory(nomes);
	utils::_testMemory(inteiros);
	utils::_testMemory(strings);
	memset(inteiros, 0, sizeof(int)*_sz);
	for(int i=0; i<_sz; i++) {	// So declarin'em:
		nomes[i]   = "claybom";
		strings[i] = "flatland";
		cout << "names   [" << i << "] = " << nomes[i]    << endl;
		cout << "inteiros[" << i << "] = " << inteiros[i] << endl;
		cout << "strings [" << i << "] = " << strings[i]  << endl;
	}	
	delete []nomes;
	delete []inteiros;
	delete []strings;
}

void multiDim(const int &_sz) {
	const int COLUMN = 5;
	const int LINE   = 3;
	using namespace  std;
	using namespace utils;
	// Must be compiled time constants:
	int trueMulti[COLUMN][LINE]; 
	int pseudoMulti[COLUMN*LINE];
	//int *trueMulti   = new(nothrow) int[COLUMN][LINE]; ERROR!
	//int *pseudoMulti = new(nothrow) int[COLUMN*LINE];

	utils::Console cmd(80, 40, "<<_ARRAY_MULTIDIMENSIONAL_>>");

	// Abstraction for programmers (fancy way of accessing vars).
	cout << "Multidimensional array:" << endl;
	for(int x=0; x<COLUMN; x++)
		for(int y=0; y<LINE; y++) {
			trueMulti[x][y] = x;
			cmd.gotoxy(x, y+2);
			cout << trueMulti[x][y];
		}
	cout << "\nPseudo-Multidimensional Array:" << endl;
	for(int x=0; x<COLUMN; x++)
		for(int y=0; y<LINE; y++) {
			pseudoMulti[(x*LINE) + y] = x;
			cmd.gotoxy(x, y+8);
			cout << pseudoMulti[(x*LINE) + y];
		}
	cout << endl;
} 

void structUnidim(const int &_sz) {
	Values* const v = new(nothrow) Values[_sz]; // Uses default constructor to create sz Values objs on the heap.
	utils::_testMemory(v);
	for(int i=0; i<_sz; i++)
		P_(v[i])
	delete []v;
}

void classUnidim(const int &_sz) {
	Obj* const objs = new(nothrow) Obj[_sz];
	utils::_testMemory(objs);
	for(int i=0; i<_sz; i++) {
		objs[i] = i;
		P_(objs[i])
	}
	delete []objs;
	//delete objs; // 'Releases the whole amount of memo but calls the destructor of jus' the first one obj in the array.
}
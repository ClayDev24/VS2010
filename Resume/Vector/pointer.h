#pragma once
#include <vector>
#include "defines.h"

typedef std::vector<int> vetorInt;
typedef std::vector<int>::iterator it; // define iterator type through STL

static void _pointer() {
	using namespace std;
	vector<int> *v = new vector<int>(10); // Looks much like an array[10] 
	v->at(2) = 47;     //Retrieve using pointer to member
	P_(v->at(2))     //Retrieve using pointer to member
	P_(v->at(3))     //Retrieve using pointer to member
	v->operator[](2);  //Retrieve using pointer to operator member
	P_(v->size())    //Retrieve size
	vetorInt &vr = *v; //Create a reference
	P_(vr[2])        //Normal access through reference
	delete &vr;		   // Delete the reference.
	//delete v;		   // You could do the same with a pointer (but not both!)
}
// Exceptions clean up complete objects only
#pragma once
#include <iostream>
using std::cout;

class Trace2 {
	static int cntr;
	char *data;
	int id;
public:
	Trace2() {
		id = ++cntr;
		cout << "Trace#" << id << "\n";
		data = new char[10];
		// To prevent memo leaks when a exception occurs inside obj constructor
		try {
			if(id==3) throw id;
		} catch(int _id) { // Catch it while still inside the constructor. 
			cout << "~Trace()#" << _id << " destructed in catch handle inside obj constructor\n";
			delete []data; // And release memory here
			throw; // Rethrowing
		}
	}
	~Trace2() {
		cout << "~Trace()#" << id << "\n";
		delete []data;
	}
};

int Trace2::cntr = 0;

static void _catch_inside_constructor() {
	try {
		Trace2 n1;
		// Throws exception:
		Trace2 array[5];
		Trace2 n2;  // won't get here
	} catch(const int &i) {
		// After unwinding stack cleanup (NOT releasing resources for it)
		// Only sucesseded constructed objs will have their destructor called.
		cout << " Trace()#" << i << " obj generated an exception. It was destroyed previously\n";
	}
	cout << "Execution resumes here." << endl;
}
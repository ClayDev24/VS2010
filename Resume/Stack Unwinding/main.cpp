// Stack Unwinding => The automatic cleanup of LOCAL objs after them go out o'scope.
//#include "vld.h" //
#include <iostream>
using namespace std;

class Trace {
	static int cntr;
	char *data;
	int id;
public:
	Trace() {
		id = ++cntr;
		cout << "Trace()#" << id << "\n";
		data = new char[10]; // Memory leak occurs here for this obj id (#3) 
		// Trhowin' an exception in the obj contructing cause no unwinding stack cleanup for it.
		if(id==3) throw id; // comment this line out to free no memory leaks
	}
	~Trace() {
		cout << "~Trace()#" << id << "\n";
		delete []data;
	}
};

int Trace::cntr = 0;

int main() {
	try {
		Trace n1;
		Trace array[5]; // Supose to throw exceptions:
		Trace n2;		// won't get here
	} catch(int i) {
		// After unwinding stack cleanup (NOT releasing resources for it)
		// Only sucesseded constructed objs will have their destructor called.
		cout << "~Trace()#" << i << " NOT destroyed!\n";
	}
	cout << "Execution resumes here.\n";

	system("pause");
	return(0);
} 

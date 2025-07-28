// Enumhack, which is the use of an
// untagged enumeration with no instances. An enumeration must have all
// its values established at compile-time, it's local to the class, and its
// values are available for constant expressions:
//#include "vld.h" // No memory leaks DETECTED!
#include <iostream>
using namespace std;

class Bunch {
	// const int size = 100;
	enum { SIZE = 1000 };
	int i[SIZE];
};

int main() {
	cout << "sizeof(Bunch)   = " << sizeof(Bunch) << endl
		 << "sizeof(i[1000]) = " << sizeof(int[1000]) << endl
		 << "sizeof(int)     = " << sizeof(int) << endl;

	system("pause");
	return(0);
}

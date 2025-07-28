// Simple demo of new & delete
//#include "vld.h" // Memory Leak Detector
#include <iostream>
#include <conio.h> // getche()
using namespace std;

class Tree {
	int height;
public:
	Tree(int treeHeight) : height(treeHeight) {}
	~Tree() { std::cout << "~Tree()..." << endl; }
	friend ostream& operator<<(ostream& _os, const Tree &_t) {
		return _os << "Tree height is: " << _t.height << endl;
	}
}; 

int main() {
	// 2 things occurs when new expression is called:
	// 1- Storage is allocated;
	// 2- The constructor is called:
	Tree* t1 = new Tree(40);
	cout << *t1;

	Tree t2(55);
	cout << t2;
	// 2 things happens when operator delete is called:
	// 1- Destructor is called;
	// 2- Storage is deallocated:
	delete t1;

	system("pause");
	return(0);
}

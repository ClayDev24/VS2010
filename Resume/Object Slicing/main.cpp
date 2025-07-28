//#include "vld.h" // No memory leaks DETECTED!
#include <iostream>
#include <string>
using namespace std;

class Pet {
	string pname;
public:
	Pet(const string& name) : pname(name) {}
	virtual string name() const { return pname; }
	virtual string description() const {
		return "This is " + pname;
	}
	// Makin' pure virtual function prevents objs slicing:
	//virtual void func() const = 0;
};

class Dog : public Pet {
	string favoriteActivity;
public:
	Dog(const string& name, const string& activity)
		: Pet(name), favoriteActivity(activity) {}
	string description() const {
		return Pet::name() + " likes to " +
			favoriteActivity;
	}
};

// Object Slicing occurs when you pass an obj by value to a func:
void describe(const Pet _p) { // Slices the object
	cout << _p.description() << endl;
}
void describe2(const Pet &_p) { // NOT Slices the object
	cout << _p.description() << endl;
}

int main() {
	Pet p1("Alfred");
	Dog d1("Fluffy", "sleep");
	describe(p1);
	describe(d1); // Slicing

	describe2(p1);
	describe2(d1); // Not slicing

	Pet *p2 = new Pet("Alfred2");
	Dog *d2 = new Dog("Fluffy", "sleep");
	describe(*p2);
	describe(*d2); // Slicing

	describe2(*p2);
	describe2(*d2); // Not slicing

	delete p2;
	delete d2;

	system("pause");
	return(0);
}

#pragma once
#include <iostream>
using namespace std;

class Cat {
public:
	Cat()  { cout << "Cat()\n"; }
	~Cat() { cout << "~Cat()\n"; }
};

class Dog {
public:
//	Dog() { throw 47; cout << "Dog()\n" << endl; }
//	~Dog() { cout << "~Dog()\n" << endl; }
	void* operator new(size_t sz) {
		cout << "Out-of-memory allocatin' a Dog\n";
		throw 47; // Throwin' an exception to simulate out-of-memory error
		return ::operator new(sz);
	}
	void operator delete(void* p) {
		cout << "deallocating a Dog\n";
		::operator delete(p);
	}
	void* operator new[](size_t sz) {
		cout << "Out-of-memory allocatin' a Dog[](" << sz << ")\n";
		throw 47; // Throwin' an exception to simulate out-of-memory error
		return ::operator new[](sz);
	}
	void operator delete[](void* p) {
		cout << "deallocating a Dog[](~)\n";
		::operator delete[](p);
	}
};

class UseResources {
	Cat* cats;
	Dog* dog;
public:
	UseResources(int cnt = 1) {
		cout << "UseResources()\n";
		cats = new Cat[cnt];
		dog  = new Dog;
	}
	~UseResources() {
		cout << "~UseResources()\n";
		delete []cats; // Array delete
		delete dog;
	}
};

static void _resource_management() {
	try {
		UseResources ur(3);
	} catch(const int &i) {
		cout << "inside handler (NOT realising resources): " << i << endl;
	}
	cout << "Execution resumes here.\n";
}

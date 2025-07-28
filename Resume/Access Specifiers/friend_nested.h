#pragma once
#include <iostream>
#include <cstring> // memset()
const int sz = 10;

class Holder {
	int a[sz];
public:
	Holder();
	// Nested class aint got auto friend. To do so follow steps below:
	class Pointer;			// 1- Declare the nested class/structure:
	friend class Pointer;	// 2- Declare it as a friend
	// 3- Defines the class/struct itself:
	class Pointer {
		Holder *h;
		int *p;
	public:
		Pointer(Holder *h);
		// Move around in the array:
		void next();
		void previous();
		void top();
		void end();
		// Access values:
		int  read();
		void set(int i);
	};
};

Holder::Holder() {
	memset(a, 0, sz * sizeof(int));
};

Holder::Pointer::Pointer(Holder* hd):h(hd), p(hd->a) {}

void Holder::Pointer::next() {
	if(p < &(h->a[sz - 1])) p++;
};

void Holder::Pointer::previous() {
	if(p > &(h->a[0])) p--;
};

void Holder::Pointer::top() {
	p = &(h->a[0]);
};

void Holder::Pointer::end() {
	p = &(h->a[sz - 1]);
};

int Holder::Pointer::read() {
	return *p;
};

void Holder::Pointer::set(int i) {
	*p = i;
}

static void _friend_nested() {
	Holder h;
	Holder::Pointer hp(&h);
	Holder::Pointer hp2(&h);
	
	for(int i=0; i<sz; i++) {
		hp.set(i);
		hp.next();
	}
	hp.top();
	hp2.end();
	for(int i=0; i<sz; i++) {
		std::cout << "hp : " << hp.read()
			     << " hp2: " << hp2.read() << std::endl;
		hp.next();
		hp2.previous();
	}
}
#pragma once
#include <iostream>
// In C++ everything must be declared b4 any reference to it:
struct Bob;

struct Ted {
	void init_bob(Bob*, int i);
};

struct Bob {
	// Only Bob can tell who's its friends are
	// There's no way to do this from outside Bob interface:
	friend void Ted::init_bob(Bob*, int i);	// Struct member   friend
	// Declaration as friends without been global declared first:
	friend void global_show(Bob*);			// Global function friend
	friend struct Rob;						// Entire struct   friend
private:
	int i;
};
// Must be defined after Bob:
void Ted::init_bob(Bob* bob, int i) {
	bob->i = i;
};
// Global function friend declaration and definition:
void global_show(Bob* bob) {
	std::cout << "bob->i:" << bob->i << std::endl;
};

struct Rob {
	void g(Bob* bob);
private:
	int i;
};

void Rob::g(Bob* bob) {
	bob->i += i;
};

void _friend() {
	Bob bob;
	Ted ted;
	ted.init_bob(&bob, 33);
	global_show(&bob);
};
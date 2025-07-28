#pragma once
#include <iostream>

class X {
public:
	class Trouble {};
	class Small : public Trouble {};
	class Big   : public Trouble {};
	inline void f()  { throw Small();   }
	inline void f1() { throw Big();     }
	inline void f2() { throw Trouble(); }
};

static void _inheritance() {
	using namespace std;
	X x;
	try {
		x.f();
	} catch(const X::Trouble&) { // Always use reference args instead of value ones to avoid slicing info.
		cout << "caught Trouble\n";
		// Hidden by previous handler. The following will never catch anything:
	} catch(const X::Small&) {
		cout << "caught Small Trouble\n";
	} catch(const X::Big&) {
		cout << "caught Big Trouble\n";
	}
	// Always put less specific types at the end:
	//catch(X::Trouble&) {
	//	cout << "caught Trouble" << endl;
}
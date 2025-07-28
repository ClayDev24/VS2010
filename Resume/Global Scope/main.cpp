// Global scope resolution
//#include "vld.h" // No memory leaks DETECTED!
#include "internal.h"
#include "external.h"
// Global vars are defined outside all function bodies n' are available everywhere even in other files:
// Its lifetime lasts till program's over.
int globe;
void func();

int main(void) {
	S *s = new S();
	s->f();

	globe = 12;
	std::cout << globe << std::endl;
	func(); // Modifies globe
	std::cout << globe << std::endl;

	delete s;

	system("pause");
	return(0);
}

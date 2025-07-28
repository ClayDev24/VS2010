// Function misdeclaration:
#include <iostream>
void f(char) {} // @@f$qc // C++ name decoration

int main() {
	// Linker unsresolved reference:
	f(1); // @@f$qc != @@f$qi
	// C bypass this error

	system("pause");
	return(0);
}
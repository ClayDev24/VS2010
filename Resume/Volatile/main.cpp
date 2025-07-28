// The volatile keyword
//#include "vld.h" // No memory leaks DETECTED!
#include <iostream> // cout
class Comm {
	const volatile unsigned char byte;
	// Volatile vars are ALWAYS read whenever its value is required
	// Even if it was jus'read the line before.
	volatile unsigned char flag;
	enum { bufsize = 100 }; //enumhack
	unsigned char buf[bufsize];
	int index;
public:
	Comm();
	void isr() volatile;
	char read(int index) const;
};

Comm::Comm():index(0), byte(0), flag(0) {}

// Only a demo; won't actually work
// as an interrupt service routine:
void Comm::isr() volatile {
	flag = 0;
	buf[index++] = byte;
	// Wrap to beginning of buffer:
	if(index >= bufsize) index = 0;
}

char Comm::read(int index) const {
	if(index<0 || index>=bufsize)
		return 0;
	return buf[index];
}

int main() {
	volatile Comm Port;
	Port.isr(); // OK
	//!  Port.read(0); // Error, read() not volatile
	
	system("pause");
	return(0);
}

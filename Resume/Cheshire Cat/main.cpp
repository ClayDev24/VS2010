// Use the Handle class
//#include "vld.h" // No memory leaks DETECTED!
#include <iostream>
#include "handle.h"
#include "no_handle.h"
using namespace std;

int main() {
	// The only thing that client programmer can access is the public interface of a lib
	// As long as the def. file is the only thing that changes, this file never needs recompilation
	Handle	 h;
	NoHandle n;

	h.init();
	n.init();

	h.set(123);
	n.set(456);

	cout << "h.get():" << h.get() << endl;
	cout << "n.get():" << n.get() << endl;

	// It's safe to have the structures compiled inside an implementation file (obj)
	// rather than exposed in a header file.
	cout << "Hacking visible private info:\n";
	//cout << "sizeof(NoHandle): " << sizeof(NoHandle) << endl;
	float* f = reinterpret_cast<float*>(&n);
	//f[1]=6.78;
	cout << "f: " << f[1] << endl;

	h.cleanup();

	system("pause");
	return(0);
}
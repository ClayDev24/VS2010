//#include "vld.h" // No memory leaks DETECTED!
#include <iostream> // std::cout

int main() {
    // Esta linha exibe "Hello, World!" no console.
    std::cout << "Hello, World!" << std::endl;

	// Leak memory test:
	int *ptr = new int(33);
	system("pause");
    return 0;
}

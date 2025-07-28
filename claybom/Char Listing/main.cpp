//#include "vld.h"
#include <iostream>
#include "utils.h"

void CharListin() { //const int &_sz=128) {
	for(int i=0; i<256; i++)
		if (i != 26)  // ANSI Terminal Clear screen
			std::cout << " value: " << i 
			      << " char: " 
			       << char(i) // Type conversion
			        << std::endl;
}

int main() {

	utils::_chronometer(&CharListin);

	system("pause");
	return(0);
}

// The infamous goto is supported in C++
//#include "vld.h" // No memory leaks DETECTED!
#include <iostream>
#include <conio.h> // _getche()
using namespace std;

int main() {

top:
	cout << "Countin test...\n";
	for(int i=0; i<10; i++)
		cout << "i=> " << i << endl;

	char ch = 'a';
	while(toupper(ch) != 'N') {
		std::cout << "again? (y/n):\n";
		ch = toupper(_getche());
		if((ch) == 'Y') goto top;
	}

	system("pause");
	return(0);
}

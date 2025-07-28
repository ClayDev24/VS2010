//#include "vld.h" // No memory leaks DETECTED!
#include <iostream>
#include <cstdlib>
#include "utils.h" // utils.lib
using namespace std;

int main() {

	double d = 5.5;

	unsigned char* cp = reinterpret_cast<unsigned char*>(&d);
	for(int i=sizeof(double); i>0 ; i-=2) {
		utils::PrintBinary(cp[i-1]);
		cout << "_";
		utils::PrintBinary(cp[i]);
		cout << "_";
	}
	cout << endl;

	system("pause");
	return(0);
}
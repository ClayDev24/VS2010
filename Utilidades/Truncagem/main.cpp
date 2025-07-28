#include <iostream>
#include "..\Utilidades\_random.h"
using namespace std;

int main() {
	double d=0.0;
	unsigned int    x=0;
	for(int i=0; i<1000; i++) {
		d = utils::_random(10, 1000);
		d /= utils::_random(2,10);
		d = d*100;
		cout << d << endl;
		x = d;
		cout << x << endl;
	}

	system("pause");
	return(0);
}
//#include "vld.h" // No memory leaks DETECETD!
#include <iostream>
using namespace std;

int main() {
	int a, b = 0;
	cout << "Enter 2 Integers: ";
	cin >> a;
	cin >> b;
	cout.setf(ios::boolalpha);
	cout << "a  > b is " << (a  > b) << endl;
	cout << "a  < b is " << (a  < b) << endl;
	cout << "a >= b is " << (a >= b) << endl;
	cout << "a <= b is " << (a <= b) << endl;
	cout << "a == b is " << (a == b) << endl;
	cout << "a != b is " << (a != b) << endl;
	cout << "a && b is " << (a && b) << endl;
	cout << "a || b is " << (a || b) << endl;
	cout << "(a < 10) && (b < 10) is " << ((a < 10) && (b < 10))  << endl;

	system("pause");
	return(0);
}

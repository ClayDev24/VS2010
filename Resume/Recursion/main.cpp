//#include "vld.h" // No memory leaks DETECTED!
#include <iostream>
#include <conio.h>
using namespace std;

// Functions Prototypes:
void removeHat(char);
long factorial(long); // Func not valid for values greater than 15. Long type restriction reason

// Recursion is used when evaluating some sort o'arbitrarily complex problem. 
// The func can just keep recursing until it's reached the end o'the problem.
int main() {
	long val;
	removeHat('A');
	cout << "Input value to calculate its factorial: ";
	cin  >> val;
	cout << "Factorial(" << val << "): " << factorial(val) << endl;

	system("pause");
	return(0);
}

void removeHat(char cat) {
	for(char c = 'A'; c < cat; c++)
		cout << "  ";
	if(cat <= 'Z') {
		cout << "cat " << cat << endl;
		removeHat(cat + 1); // Recursive call
	} else
		cout << "VOOM!!!" << endl;
}

long factorial(long a) {
	if(a>1)
		return a*factorial(a-1);
	else
		return 1;
}
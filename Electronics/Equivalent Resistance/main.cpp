// C�lculo de Resist�ncia Equivalente:
#include <iostream> // cout
#include <string>
#include <new>
#include "equivalent.h"
#include "utils.h"
using namespace std;
using namespace utils;

int main() {
	utils::_setLocale();

	int sz, qual;
	sz = qual = 0;
	int  *pRes = NULL;

	cout << "C�lculo da RESIST�NCIA EQUIVALENTE:\n";
	cout << "Type what you wanna know <enter>:\n";
	PrintColour_("1- Serial   Resistance;", 0, FWI);
	PrintColour_("2- Parallel Resistance.", 0, FWI);
	cin >> qual;

	cout << "Type the how many values: \n";
	cin >> sz;

	pRes = new (std::nothrow) int[sz];
	if(!pRes)
		cout << "Error: memory could not be allocated";

	cout << "Type the (R)esistance values (separated by commas): <enter>: \n";
	for(int i=0; i<sz; i++)
		cin >> pRes[i];

	switch(qual) { // just accept integer types at compile-time.
	case 1:
		cout << "O Total da Resist�ncia Serial Equivalente �: " << _serial(pRes, sz) << " Ohms\n\n";
		break;
	case 2:
		cout << "O Total da Resist�ncia Paralela Equivalente �: " << _parallel(pRes, sz) << " Ohms\n\n";
		break;
	default: cout << "Error...default msg!\n";
	}

	delete[] pRes;

	system("pause");
	return(0);
}


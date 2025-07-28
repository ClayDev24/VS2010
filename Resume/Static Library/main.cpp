#include <iostream>
#include "MyLib.h"
// Project->Porperties (Alt+F7)->Configuration Properties->C/C++ ->General-> Additional Include Directories
// to add the path of the power include directory
// or include the followin' line here:
//#include "..\Static Library_Creating\MyLib.h"
using namespace std;

int main(void) {
    signed int x;
	x = res::soma(8, 3);
	cout << x << endl;

	system("pause");
	return(0);
}

// [Project]->Properties (Alt_F7)...
// Configuration Properties->Linker->General->Additional Library Directories
// Configuration Properties->Linker->Input->Additional Dependencies->[...] MyLib.lib
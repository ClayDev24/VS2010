#include <iostream>
#include "MyLib.h"
// Project->Porperties (Alt+F7)->Configuration Properties->C/C++ ->General-> Additional Include Directories
// to add the path of the power include directory
//#include "..\Static Library_Creating\MyLib.h"

using namespace std;

int res::soma(signed int a, signed int b) {
	signed long int num = a + b;
	cout << "MyLib.lib" << endl;
	return num;

}

// Usage:
//int main() {
//	cout << clb::soma(10, 2) << endl;
//	return 0;
//}

//>bcc32 -c MyLib // -c compile to obj file only. Do not link
//>tlib MyLib.lib +MyLib, lsit.lst // Creates MyLib.lib from MyLib.obj file
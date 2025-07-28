//#include "vld.h"
#include <iostream>
#include "CStash.h"
#include "Stash.h"
#include "Stash2.h"
#include "Stash3.h"
#include "Stash4.h"
#include "Stash5.h"
#include "..\..\Utilidades\Utilidades\_require.h"
using namespace std;

int main() {
	//CStashUsage();
	//StashUsage();
	//Stash2Usage();
	//Stash3Usage();
	//Stash4Usage();
	Stash5Usage();
	cout << "C++ structures matchs its counterpart in C (no overhead):\n";
	cout << "sizeof(CStash ):" << sizeof(CStash) << endl;
	cout << "sizeof( Stash ):" << sizeof(Stash)  << endl;
	cout << "sizeof( Stash2):" << sizeof(Stash2) << endl;
	cout << "sizeof( Stash3):" << sizeof(Stash3) << endl; // adds 4 bites in size from new member m_increment
	cout << "sizeof( Stash4):" << sizeof(Stash4) << endl;
	cout << "sizeof( Stash5):" << sizeof(Stash5) << endl;

	system("pause");
	return(0);
}
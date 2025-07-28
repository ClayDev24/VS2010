///////////////////////////////////////////////////////
// usedll.cpp (mydll.dll)
// use_dll.cpp
#include <iostream.h>
#include <afxwin.h>
#include "C:\claybom\linguagens\c++\progs\Visual C++\minha dll\mydll.h"
void main() {
HINSTANCE hDll; // dll handler
hDll = LoadLibrary("..\\..\\mydll\\Debug\\mydll.dll"); // load dll
// handle error while loading dll handler
if (!hDll) {
cout << "Error while loading DLL handler" << endl;
exit(1);
}
// function pointers equivalent to dll functions
void (WINAPI * c_dllTest)();
int (WINAPI *c_plus_1)(int);
int (WINAPI *c_plus_2)(int);
// link function pointers to dll functions
c_dllTest = (void (WINAPI *)())GetProcAddress(hDll, "dllTest");
c_plus_1 = (int (WINAPI *)(int))GetProcAddress(hDll, "plus_1");
c_plus_2 = (int (WINAPI *)(int))GetProcAddress(hDll, "plus_2");
// handle error while loading functions
if(!c_dllTest || !c_plus_1 || !c_plus_2) {
cout << "Error while loading functions from DLL" << endl;
exit(1);
}
// now, use the functions freely
c_dllTest();
cout << "3+1=" << c_plus_1(3) << endl;
cout << "5+2=" << c_plus_2(5) << endl;
}
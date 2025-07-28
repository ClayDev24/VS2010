///////////////////////////////////////////////////////
// mydll.cpp
#include <iostream.h>
#include "mydll.h"
void WINAPI dllTest() {
  cout << "You're inside a Dll" << endl;
}
int WINAPI plus_1(int i) {
  return i+1;
}
int WINAPI plus_2(int i) {
  return i+2;
}
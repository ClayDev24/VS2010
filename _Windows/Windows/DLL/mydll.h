///////////////////////////////////////////////////////
// mydll.h
#if !defined(_MYDLL_H_)
  #define _MYDLL_H_
  #include <afxwin.h>
  // place the prototypes of dll functions
  void WINAPI dllTest();
  int WINAPI plus_1(int i);
  int WINAPI plus_2(int i);
#endif // _MYDLL_H_
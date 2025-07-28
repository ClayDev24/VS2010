#ifndef OPEN_FILE
#define OPEN_FILE

#include <windows.h>
#include <iostream>
#include "ParseFileString.h"
using namespace std;
/*******************************************
Open_File is a class wrapper for the 
Open/save file dialogs. Using this avoids 
adding an active x control to your programs. 
This of course lowers the over all file 
weight......by FallenHobbit.................
*******************************************/

class Open_File
{
public:
	Open_File();
	virtual LPTSTR Open(HWND, PBOOL);
	virtual LPTSTR Save(HWND, PBOOL);
	virtual void SetFilter(TCHAR *newFilter, unsigned int len);
	virtual LPTSTR GetName();
	virtual LPTSTR GetRelativePath(LPTSTR tmp);
	~Open_File();
private:
	void initOpenFile();
	OPENFILENAME OpenFileName;
	FileFilter filter;//bug fix on 8/20/02
	TCHAR szFile[MAX_PATH];
	LPTSTR lpszFileName;
	HINSTANCE ghInst;
	bool findchar(TCHAR *s,TCHAR fnd);
	void right(TCHAR *s, int num);
};

#endif


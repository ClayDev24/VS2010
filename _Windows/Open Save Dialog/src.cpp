#include "OpenFile.h"
void main()
{
	TCHAR fltr[83] = {"HTML files(*.html,*.htm)\0*.html;*.htm\0Text Files(*.txt)\0*.txt\0All Files(*.*)\0*.*\0\0"};
	Open_File opn;
	opn.SetFilter(fltr,83);
	BOOL cancel=FALSE;
	opn.Save(NULL,&cancel);
	if(!cancel)
	{
		LPTSTR name = opn.GetName();
		cout << name << endl;
	}
}
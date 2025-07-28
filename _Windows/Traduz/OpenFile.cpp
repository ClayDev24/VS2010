#include "stdafx.h"
#include "OpenFile.h"

/*******************************************
Open_File is a class wrapper for the 
Open/save file dialogs. Using this avoids 
adding an active x control to your programs. 
This of course lowers the over all file 
weight......by FallenHobbit.................
*******************************************/

Open_File::Open_File()
{//init vars for structure
	ghInst=NULL;
	szFile[0] = __TEXT('\0');
	lpszFileName = new TCHAR[2];//doing this so that if user presses cancel and caller tries to use the returned value anyway...we dont throw an exception
	lpszFileName[0]= __TEXT('\0');
	TCHAR Filter[]=__TEXT("All Files(*.*)\0*.*\0\0");//filter for open box...using TCHAR because it is compatible with ansi and unicode...     
	filter.SetFilter(Filter,21);
	initOpenFile();//init structure
}

Open_File::~Open_File()
{
//	delete [] szFilter;
}

void Open_File::initOpenFile()
{
	OpenFileName.lStructSize       = sizeof(OPENFILENAME);     
	OpenFileName.hwndOwner         = NULL;//callers hwnd.....CHANGE
	OpenFileName.hInstance         = ghInst;///again required...ignored unless 
	/*If the OFN_ENABLETEMPLATEHANDLE flag is set in the Flags member, 
	hInstance is the handle of a memory object containing a dialog box template. 
	If the OFN_ENABLETEMPLATE flag is set, hInstance identifies a module 
	that contains a dialog box template named by the lpTemplateName member. 
	If neither flag is set, this member is ignored. */
	TCHAR temp[100];
	filter.GetFilter(temp);
	OpenFileName.lpstrFilter       = temp;  //creating this is confusing as hell....CHANGE
	OpenFileName.lpstrCustomFilter = (LPTSTR) NULL;//ignored in general     
	OpenFileName.nMaxCustFilter    = 0L;//size of customk filter     
	OpenFileName.nFilterIndex      = 1L;//filter in filter string to point to, starts with 1...     
	OpenFileName.lpstrFile         = szFile;//buffer for file
	OpenFileName.nMaxFile          = sizeof(szFile);//size of file buffer
	OpenFileName.lpstrFileTitle    = NULL;//dont need     
	OpenFileName.nMaxFileTitle     = 0;//derrr     
	OpenFileName.lpstrInitialDir   = NULL;//dont need     
	OpenFileName.lpstrTitle        = NULL;//__TEXT("Choose a File");     
	OpenFileName.nFileOffset       = 0;     
	OpenFileName.nFileExtension    = 0;     
	OpenFileName.lpstrDefExt       = NULL;  // No default extension     
	OpenFileName.lCustData         = 0;      
}

LPTSTR Open_File::Open(HWND hWnd, PBOOL pbUserCancel)
{
	TCHAR temp[100];
	filter.GetFilter(temp);
	OpenFileName.hwndOwner = hWnd;//callers hwnd.....  
	OpenFileName.lpstrTitle = __TEXT("Choose A File To Open");     
	OpenFileName.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY | OFN_EXPLORER | OFN_LONGNAMES | OFN_NONETWORKBUTTON;//flags relating to the dialog appearance
	OpenFileName.lpstrFilter = temp;//set new filter for types to open

	if(GetOpenFileName(&OpenFileName))     
	{ 
		*pbUserCancel = FALSE;         // We have a valid filename, let's copy it into the buffer         
		int i = strlen(OpenFileName.lpstrFile);
		lpszFileName = new TCHAR[i+10];//init buffer to size needed
		_tcscpy(lpszFileName,OpenFileName.lpstrFile); //copy over the file name
		int index = OpenFileName.nFilterIndex;
		if(index >0)
		{
			_tcscpy(temp,(TCHAR*)lpszFileName);
			right(temp,5);
			if(!findchar(temp,'.'))
			{
				filter.GetFilterByIndex(temp,index);
				_tcscat((TCHAR*)lpszFileName,temp);
			}
		}
		return(lpszFileName); 
	}     
	else // User didn't select a file     
	{         
		lpszFileName = new TCHAR[2];
		lpszFileName[0]= __TEXT('\0');
		*pbUserCancel = TRUE; 
		return (lpszFileName);
	}     
}

LPTSTR Open_File::Save(HWND hWnd, PBOOL pbUserCancel)
{
	TCHAR temp[100];
	OpenFileName.hwndOwner = hWnd;//callers hwnd.....  
	OpenFileName.lpstrTitle = __TEXT("Choose A Name For The File");     
	OpenFileName.Flags = OFN_OVERWRITEPROMPT| OFN_HIDEREADONLY | OFN_EXPLORER | OFN_LONGNAMES | OFN_NONETWORKBUTTON;//flags relating to the dialog appearance
	filter.GetFilter(temp);
	OpenFileName.lpstrFilter = temp;

	if(GetSaveFileName(&OpenFileName))     
	{ 
		*pbUserCancel = FALSE;         // We have a valid filename, let's copy it into the buffer         
		int i = strlen(OpenFileName.lpstrFile);
		lpszFileName = new TCHAR[i+10];//init buffer to size needed
		_tcscpy(lpszFileName,OpenFileName.lpstrFile); //copy over the file name
		int index = OpenFileName.nFilterIndex;
		if(index >0)
		{
			_tcscpy(temp,(TCHAR*)lpszFileName);
			right(temp,5);
			if(!findchar(temp,'.'))
			{
				filter.GetFilterByIndex(temp,index);
				_tcscat((TCHAR*)lpszFileName,temp);
			}
		}
		return(lpszFileName); 
	}     
	else // User didn't select a file     
	{         
		lpszFileName = new TCHAR[2];
		lpszFileName[0]= __TEXT('\0');
		*pbUserCancel = TRUE; 
		return (lpszFileName);
	}     
}


void Open_File::SetFilter(TCHAR *newFilter,unsigned int len)
{
	filter.SetFilter(newFilter,len);
}

LPTSTR Open_File::GetName()
{
	return 	(lpszFileName);
}

LPTSTR Open_File::GetRelativePath(LPTSTR tmp)
{
	DWORD dw = MAX_PATH;
	LPTSTR str = new char[MAX_PATH];
	LPTSTR file = new char[10];
	LPTSTR part;
	strcpy(file, tmp);
	str[0]= '\0';
	GetFullPathName(file, dw,str,&part);
	return str;
}

bool Open_File::findchar(TCHAR *s,TCHAR fnd)
{
	int len = _tcslen(s);
	bool ret=false;
	bool cont=true;
	for(int i = 0; i<len; i++)
	{
		if((s[i]==fnd) && (cont == true))
		{
			ret = true;
			cont = false;
		}
	}
	return ret;
}

void Open_File::right(TCHAR *s, int num)
{
	int i = _tcslen(s);
	int c=0, cc=0;
	TCHAR *hld = new TCHAR[num+1];
	if(i>num || i==num)
	{
		for(c=(i-num); c<i; c++)
		{
			hld[cc] = s[c];
			++cc;
		}
		hld[num]='\0';
		for(c=0; c<(num+1); c++)
		{
			s[c] = hld[c];
		}
	}
	delete [] hld;
}
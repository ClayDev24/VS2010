#ifndef FILE_FILTER
#define FILE_FILTER

#include <stdlib.h>
#include <ctype.h>
#include <tchar.h>
/*************************************
This is a class wrapper for the file
filter string needed by the open/save
common dialogs...it provides a series
of my own string parsing functions for
stripping off the desired file 
extension as chosen by the user....
this is a bug fix for my open/save
class wrapper......FallenHobit 08/21/02
*************************************/

class FileFilter
{
private: 
	TCHAR fltr[_MAX_FNAME];
	unsigned int fltrlen;
	bool testStrings(TCHAR *s1, TCHAR *s2);
	void left(TCHAR *s, int num);
	void right(TCHAR *s, int num);
	void copyFltr(TCHAR *s1, TCHAR *s2, unsigned int len);
	unsigned int getFirstNull(TCHAR *s, unsigned int len);
	void leftFltr(TCHAR *s, unsigned int num, unsigned int len);
	void rightFltr(TCHAR *s, unsigned int num, unsigned int len);
	void getFilterByIndex(TCHAR *fltr, TCHAR *buff, unsigned int fltrlen, unsigned int index);
	unsigned int findchar(TCHAR *s,TCHAR fnd);
public:
	FileFilter();
	FileFilter(TCHAR *s, unsigned int len);
	~FileFilter();
	void SetFilter(TCHAR *s, unsigned int len);
	void GetFilter(TCHAR *s);
	void GetFilterByIndex(TCHAR *s, unsigned int index);
	unsigned int FilterLength();
};

#endif
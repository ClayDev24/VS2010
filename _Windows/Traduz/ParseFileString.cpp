#include "stdafx.h"
#include "ParseFileString.h"
/*************************************
default constructor
*************************************/
FileFilter::FileFilter()
{
	fltrlen =0;
}

/*************************************
constructor that takes a filter string
*************************************/
FileFilter::FileFilter(TCHAR *s,unsigned int len)
{
	if(len>0)
	{
		if(s!=NULL)
		{
			copyFltr(fltr,s,len);	
		}
		fltrlen = len;
	}
}

/*************************************
destructor does nothing...............
*************************************/
FileFilter::~FileFilter(){}

/*************************************
test two strings for equality
*************************************/
bool FileFilter::testStrings(TCHAR *s1, TCHAR *s2)
{//test's to cstrings for equality, returns true or false
	unsigned int x1=0;
	bool ret=true;
	x1 = _tcslen(s1);
	if(_tcslen(s2) != x1)
	{
		ret=false;
	}
	else
	{
		for(unsigned int i=0;i<x1;i++)
		{
			if(s1[i] != s2[i])
				ret = false;
		}
	}
	return ret;
}

/*************************************
get left part of string of length num
*************************************/
void FileFilter::left(TCHAR *s, int num)
{
	int i = _tcslen(s);
	int c=0;
	TCHAR *hld = new TCHAR[num+1];
	if (i>num || i==num)
	{
		for(c=0; c<num; c++)
		{
			hld[c] = s[c];
		}
		hld[num] = '\0';
		for(c=0; c<(num+1); c++)
		{
			s[c] = hld[c];
		}
	}
	delete [] hld;
}

/*************************************
get right part of string of length num
*************************************/
void FileFilter::right(TCHAR *s, int num)
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

/*************************************
derr, finds the first null('\0')
*************************************/
unsigned int FileFilter::getFirstNull(TCHAR *s, unsigned int len)
{
	unsigned int ret=0;
	for(unsigned int i=0; i<len; i++)
	{
		if(s[i]=='\0')
		{
			ret = i;
			break;
		}
	}
	return ret;
}

/*************************************
same as left but for filters
*************************************/
void FileFilter::leftFltr(TCHAR *s, unsigned int num, unsigned int len)
{
	unsigned int i = len;
	unsigned int c=0;
	if(num<0)
		return;
	if(len<0)
		return;
	TCHAR *hld = new TCHAR[num+1];
	if (i>num || i==num)
	{
		for(c=0; c<num; c++)
		{
			hld[c] = s[c];
		}
		hld[num] = '\0';
		for(c=0; c<(num+1); c++)
		{
			s[c] = hld[c];
		}
	}
	delete [] hld;
}

/*************************************
same as for right but for filters
*************************************/
void FileFilter::rightFltr(TCHAR *s, unsigned int num, unsigned int len)
{
	unsigned int i = len;
	unsigned int c=0, cc=0;
	if(num<0)
		return;
	if(len<0)
		return;
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

/*************************************
gets the file extension by its index,
copies it into buff
*************************************/
void FileFilter::getFilterByIndex(TCHAR *fltr, TCHAR *buff, unsigned int fltrlen, unsigned int index)
{
	unsigned int plc = 0;
	if(fltrlen<0)
	{
		buff[0]='\0';
		return;
	}
	if(index <= 0)
	{
		buff[0]='\0';
		return;
	}
	plc = getFirstNull(fltr,fltrlen);
	rightFltr(fltr,fltrlen-(plc+1),fltrlen);
	for(unsigned int i=1; i<index; i++)
	{
		plc = getFirstNull(fltr,fltrlen);
		rightFltr(fltr,fltrlen-(plc+1),fltrlen);
		plc = getFirstNull(fltr,53);
		rightFltr(fltr,fltrlen-(plc+1),fltrlen);
	}
	_tcscpy(buff,fltr);
	if(!testStrings(buff,"*.*"))
	{
		if(buff[0]=='*')
		{
			int i = _tcslen(buff);
			right(buff,i-1);
		}
		plc = findchar(buff,';');
		if(plc != -1)
		{
			left(buff, plc);
		}
	}
}

/*************************************
finds the index of the specified char
*************************************/
unsigned int FileFilter::findchar(TCHAR *s,TCHAR fnd)
{
	unsigned int len = _tcslen(s);
	unsigned int ret=-1;
	bool cont=true;
	for(unsigned int i = 0; i<len; i++)
	{
		if((s[i]==fnd) && (cont == true))
		{
			ret = i;
			cont = false;
		}
	}
	return ret;
}

void FileFilter::copyFltr(TCHAR *s1, TCHAR *s2, unsigned int len)
{
	for(unsigned int i = 0; i< len; i++)
	{
		s1[i] = s2[i];
	}
}

/*************************************
sets the fltr tchar
*************************************/
void FileFilter::SetFilter(TCHAR *s, unsigned int len)
{
	if(len>0)
	{
		if(s!=NULL)
		{
			copyFltr(fltr,s,len);
			fltrlen = len;
		}
	}
}

/*************************************
returns the fltr tchar
*************************************/
void FileFilter::GetFilter(TCHAR *s)
{
	if(fltrlen>0)
	{
		copyFltr(s,fltr,fltrlen);
	}
}

/*************************************
external method for internal function
*************************************/
void FileFilter::GetFilterByIndex(TCHAR *s, unsigned int index)
{
	TCHAR temp[_MAX_FNAME];
	if(index >=0)
	{
		if(fltrlen>0)
		{	
			copyFltr(temp,fltr,fltrlen);
			getFilterByIndex(temp,s,fltrlen,index);
		}
	}
}

/*************************************
returns the fltr length
*************************************/
unsigned int FileFilter::FilterLength()
{
	return  fltrlen;
}
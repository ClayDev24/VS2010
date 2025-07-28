/**********************************************
by FallenHobit
win32 header file for console programs....an 
assortment of general purpose functions I have 
written ........................................
**********************************************/

//static causes these functions to have only a file scope.....
//works better then ifndef...........iow they will be local to the source file you 
//include this header in =0)
#include <iostream.h>
#include <iomanip.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fstream.h>
#include <io.h>
#include <fcntl.h>
#include <tchar.h>

static double convF(TCHAR s[80])//traps for user input error using this nifty stdlib function
{
	double x; 
	x = atof(s);//<~~~the function
	return x;
}

static int convI(TCHAR s[80])//same as above
{
	int x;
	x = atoi(s);//the function
	return x;
}

//program functions to aid main display function
static void wash()//function to clear the console screen....
{
	system("cls");//thats sweet as <censored>!!!
	//runs dos command from what i gather....
}

//the below is an overloaded function for taking char input and not requireing the user to hit enter
static int getCha(TCHAR arr[], int num)
{
	int ch;//declare var to hold return value of key pressed
	bool kill=false;
	do
   {
      ch = _getch();//call _getch to get the input char....found this function in msdn
      ch = toupper( ch );//convert to upper to elliminate case sensitivity
	  for (int x=0; x < num; x++)
		if (ch == arr[x])
		  kill = true;
   } while(kill == false);//if it equals the character to look for then kill loop
	return ch;//as stated return it
}

static int getCh(TCHAR look)
{
	int ch;//declare var to hold return value of key pressed
	do
   {
      ch = _getch();//call _getch to get the input char....found this function in msdn
      ch = toupper( ch );//convert to upper to elliminate case sensitivity
   } while( ch != look);//if it equals the character to look for then kill loop
	return ch;//as stated return it
}

static int getCh(void)
{
	int ch;//declare var to hold return value of key pressed
	do
   {
      ch = _getch();//call _getch to get the input char....found this function in msdn
      ch = toupper( ch );//convert to upper to elliminate case sensitivity
   } while( ch == NULL);//if it equals the character to look for then kill loop
	return ch;//as stated return it
}

static int getPass(TCHAR *pass, TCHAR *serch)//function to test for one string in another
{									//this is to save repeating this same block
	int  result;					//block for each damn month
	TCHAR *pdest;
	pdest = strstr( pass, serch );//search for one string inside the other....again i got this off msdn cd
	result = pdest - pass + 1;//get pos of it 
	return result;
}

static bool testdigit(TCHAR h[])
{//test a string for an unsigned or signed numeric value
	bool test = true;
	int i = _tcslen(h);
	for (int x = 0; x < i; x++)
	{	
		switch (h[x])//allowed for signed numbers and floats
		{
			case '.':
				continue ;
				break;
			case '+':
				continue;
				break;
			case '-':
				continue;
				break;
		}

		if (test == false)//if test already fialed then continue through rest without testing again
		{
			continue;
		}
		test = isdigit(h[x]);
	}
	return test;//return value
}


static void pause()
{//pause program till user hits a key
	TCHAR ch;
	_cputs( "Press any Key....." );
	ch = _getch();
}

static void getstr( TCHAR *s, int len )
{//gets a line of input of specified length
	fflush( stdin );
   TCHAR buffer[5000];//max size of buffer
   int i, ch;
   /* Read in single line from "stdin": got this from msdn....*/
   for( i = 0; (i < len) &&  ((ch = getchar()) != EOF) 
                        && (ch != '\n'); i++ )
      buffer[i] = (TCHAR)ch;
   /* Terminate string with null character: */
   buffer[i] = '\0';
 
   _tcscpy(s,buffer);
}

static void fillchar(TCHAR *s, TCHAR c, int x)
{//fills a buffer with a certain char
	for (int i=0; i < x; i++)
	{
		s[i]=c;
	}
	s[i]='\0';
}


static int getlength(TCHAR *s, TCHAR del, int max)
{//gets number of chars in a string up until the delimiter
	int x=0;
	while(s[x]!=del && x<max)
	{
		x++;
	}
	return x;
}

static void convUp(TCHAR *s)
{//converts a cstring to uppercase
	int i;
	i = _tcslen(s);
	for(int y=0; y < i; y++)
	{
		s[y] = toupper(s[y]);
	}
}

static void convDown(TCHAR *s)
{//converts a cstring to uppercase
	int i;
	i = _tcslen(s);
	for(int y=0; y < i; y++)
	{
		s[y] = tolower(s[y]);
	}
}
static void convFA(double num, TCHAR ret[])
{//converts a float to ascii
	int decimal, sign, l=0, tr=0;
	TCHAR *buffer;
	buffer = _fcvt(num,6,&decimal,&sign);
	l = _tcslen(buffer);
	if(sign ==1)
	{
		ret[tr]='-';
		++tr;
	}
	for (int i=0; i<l;i++)
	{
		if (i==decimal)
		{
			ret[tr]='.';
			++tr;
		}
		ret[tr]=buffer[i];
		++tr;
	}
	ret[tr]='\0';
}

static bool testStrings(TCHAR *s1, TCHAR *s2)
{//test's to cstrings for equality, returns true or false
	int x1=0;
	bool ret=true;
	x1 = _tcslen(s1);
	if(_tcslen(s2) != x1)
	{
		ret=false;
	}
	else
	{
		for(int i=0;i<x1;i++)
		{
			if(s1[i] != s2[i])
				ret = false;
		}
	}
	return ret;
}

/********************************************
returns the specified left number of chars
equivalent to the vb left statement
********************************************/
static void left(TCHAR *s, int num)
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

/********************************************
returns the specified right number of chars
equivalent to the vb right statement
********************************************/
static void right(TCHAR *s, int num)
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

/********************************************
returns the specified number of chars starting
at the position specified and going for the 
specified length............................
equivalent to the vb mid statement...........
********************************************/
static void mid(TCHAR *s, int strt, int num = 0)
{
	int i = _tcslen(s);
	int c=0, cc=0;

	if (num == 0)
	{
		num = i - strt;
	}
	TCHAR *hld = new TCHAR[num+1];
	
	if(i>(strt + num) || i ==(strt+num))
	{
		for(c=strt; c<(strt+num); c++)
		{	 
			hld[cc] = s[c];
			++cc;
		}
		hld[cc]='\0';
		for(c=0; c<(num+1); c++)
		{
			s[c] = hld[c];
		}
	}
	delete [] hld;
}

/****************************************
finds and returns the location  within 
the array of the specified character ....
returns -1 on failure....................
****************************************/
static int findchar(TCHAR *s,TCHAR fnd)
{
	int len = _tcslen(s);
	int ret=-1;
	bool cont=true;
	for(int i = 0; i<len; i++)
	{
		if((s[i]==fnd) && (cont == true))
		{
			ret = i;
			cont = false;
		}
	}
	return ret;
}


long GetFileLength(TCHAR *str)
{
	int fh;
	if((fh= _topen(str,_O_RDONLY))!= -1)
	{
		return (_filelength(fh));
		 _close( fh );
	}
	else
	{
		return -1;
	}
}


// VBString.h: interface for the VBString class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VBSTRING_H__A23C7D7B_943C_4AA5_A918_F2915C9DC005__INCLUDED_)
#define AFX_VBSTRING_H__A23C7D7B_943C_4AA5_A918_F2915C9DC005__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef VBSTRING_USE_NAMESPACE_STD
	#include <iostream>
	#include <string>
	#include <cstdio>  // sprintf
	#include <cstdlib>  // abs
	#include <cctype> // isspace
	#include <ctime>  // time
	using namespace std;
#else
	#include <iostream.h>
	#include <string.h>
	#include <stdio.h>  // sprintf
	#include <stdlib.h>  // abs
	#include <ctype.h> // isspace
	#include <time.h>  // time
#endif

#ifdef WIN32  // Visual C++ only !!!
	#include <crtdbg.h> // include necessary to handle memory leak debug (win32 only)
	#include <atlbase.h> // BSTR
#endif


/////////////////////////////////////////////////////////////////////
//
// defines of VBLib
//
/////////////////////////////////////////////////////////////////////
#define VB_SAFEDELETE(x) {if (x) {delete x; x=0;} }
#define VB_SAFEDELETE_A(x) {if (x) {delete [] x; x=0;} }
#ifndef NULL
	#define NULL 0
#endif

#define scapeSequence escapeSequence
#define scapeSequenceReverse escapeSequenceReverse


/////////////////////////////////////////////////////////////////////
//
// VBShowSTLContainer
// class to show a STL container
// if n==0, show the complete container, 
// if n > 0, show only n first elements
//
/////////////////////////////////////////////////////////////////////
template <class containerType> 
void VBShowSTLContainer(const containerType & containerObj, const int sampleCount = 0,
						ostream & myCout = cout) 
{   
	typename containerType::const_iterator iteratorObj;   
	if (containerObj.empty()) {     
		myCout << "======Container empty" << endl;
		return;   
	}   
	myCout << "======show the STL container ";
	if (sampleCount>0) 
		myCout << "sample(" << sampleCount << ")";
	else
		myCout << "contents";
	myCout << ", size=" << containerObj.size() << endl;   
	int n = 0;
	for (iteratorObj = containerObj.begin() ;     
		(iteratorObj != containerObj.end()) && ( !(sampleCount>0) || (n < sampleCount) ) ;     
		iteratorObj++) {
		myCout << *iteratorObj << endl; 
		n++;
	}
}; 


/////////////////////////////////////////////////////////////////////
//
// VBList
// a generic (using template) single linked list 
//
/////////////////////////////////////////////////////////////////////


template <class dataType>
class VBList 
{
	struct node {
		dataType data;
		node *p_next;
	}; // end of class node
	
	node *p_first, *p_last, *p_nextSave;
	//  void (*error_function)();  // pointer to function
	
		dataType *GetFirstConst(void* & externalPointer) const {
			if (p_first)
			{
				externalPointer = p_first->p_next;
				return &p_first->data;
			}
			else
				return NULL;
		};

		dataType *GetNextConst(void* & externalPointer) const {
			node *ret = (node*) externalPointer;
			if (ret)
			{
				externalPointer = (void*) ret->p_next;
				return &ret->data;
			}
			else
				return NULL;
		};

	public:
		// default constructor
		VBList() 
		{  
			p_first = p_last = p_nextSave = NULL;
			// error_function=error_fun;
		}; // end of VBList();

		dataType *GetFirst() {
			if (p_first)
			{
				p_nextSave = p_first->p_next;
				return &p_first->data;
			}
			else
				return NULL;
		};

		dataType *GetNext() {
			node *ret = p_nextSave;
			if (p_nextSave)
			{
				p_nextSave = (node*) p_nextSave->p_next;
				return &ret->data;
			}
			else
				return NULL;
		};
	
		// add data to list (addTail)
		bool add(const dataType & newData) 
		{
			node *p_new;
			//	ASSERT(p_new=new node);
			if ((p_new = new node) == NULL)
				return (1); 
			// return true if allocation fails
			
			p_new->data = newData;  // copies data to list
			// if new element is the first element of list
			if (!p_first)
			{
				p_first = p_last = p_new;
				p_new->p_next = NULL;
			}
			// if new element is NOT the first element of list
			else 
			{ 
				p_last->p_next = p_new; // previous p_last points to new element
				p_new->p_next = NULL; // finnish list
				p_last = p_new;  // now p_last points to new element
			}
			return (0);
		}; // end of void add(dataType & newData)

		// delete the whole list
		void deleteAll() 
		{
			node *p_t1, *p_t2;
			if (p_first) // if list exists
			{
				p_t1 = p_first;
				p_t2 = p_first->p_next;
				do 
				{ // since list exists, at least 1 delete
					delete p_t1;
					p_t1 = p_t2;
					if (p_t2) 
						p_t2 = p_t2->p_next;
				} while (p_t1 != NULL);
				p_last = p_first = NULL;
			} 
		};  // end void deleteAll()
		
		// delete one data from list
		void remove(const dataType & dataToDelete) {
			node *p_t1, *p_t2, *p_t3;
			if (p_first) // if list exists
			{
				p_t1 = p_first;
				p_t2 = p_first->p_next;

				// if data to delete is the first one
				// dataType must have operator== defined
				if (p_first->data == dataToDelete) {
					// for debug
					// cout << "DEBUG Deleted:"<< p_first->data << endl;
					delete p_first;
					p_first = p_t2;
					remove(dataToDelete); // recursivelly calls remove, to 
						// be sure 
				}
				else { // the data to delete is not the first one
					
					// this loop will seek for data to delete and delete it
					while (p_t1->p_next != NULL)
					{ // since list exists, at least 1 delete

						if (p_t2->data == dataToDelete) {
							// for debug
							// cout << "DEBUG Deleted:"<< p_t2->data << endl;
							p_t3 = p_t2->p_next;
							delete p_t2;
							p_t1->p_next = p_t3; // re-links the list (bypass p_t2)
							// break; // if after deleting, stop the loop, uncomment this break
							// but it's better not to stop. Keep trying to delete until the end of list
							p_t2 = p_t3; // to keep going
						}
						else {
							// move pointers one step into the list
							// only if no remove was made.
							p_t1 = p_t2;
							p_t2 = p_t2->p_next;
						}

					} // while
				} // else
			} // if p_first
		} // remove

		// default destructor
		~VBList() 
		{ 
			deleteAll();
		};// end of ~VBList();

		// copy constructor
		VBList(const VBList & obj) {
			p_first = p_last = p_nextSave = NULL;
			void *externalPointer;
			dataType *p;
			for (p = obj.GetFirstConst(externalPointer) ; p ; p = obj.GetNextConst(externalPointer)) {
				add(*p);
			}
		}

		void operator=(const VBList & obj) {
			void *externalPointer;
			dataType *p;
			for (p = obj.GetFirstConst(externalPointer) ; p ; p = obj.GetNextConst(externalPointer)) {
				add(*p);
			}
		}
}; // end of template <class dataType>



/////////////////////////////////////////////////////////////////////
//
// VBString class
//
/////////////////////////////////////////////////////////////////////

/* VB_N is the number of chars per buffer in strList
this number can be anything more than 1, so that the 
usability of VBString is not changed.
Internally, in operator>> (for instance), "chunks" of
VB_N bytes will be alloced  in a list to store
input stream of bytes.
*/

// size of string blocks when using getline method.
// changing this number does not affect usage of the VBString class
static const int VB_N = 80;

// type to define the number of chars in a VBString
typedef unsigned long size_vbs;

class VBString
{

	// code for debug purposes only
	struct VBObjectType // struct for debug
	{
	#ifdef VBSTRINGDEBUG
		char debug;
		int tag;  // object tag
	#endif // VBSTRINGDEBUG
	};
	static VBObjectType _VBObject;
	// end of code for debug

	struct strList // char used in linked list, in method getLine (operator>>)
	{
		char buffer[VB_N];

		// useless, but needed to compile in unix
		bool operator==(strList) {return true;};
	};

	void allocStr(size_vbs size_in);  // redim

	size_vbs m_size;		// number of char inside the string
	unsigned m_decs;		// number of decimals when adding float or double
	char *m_str;			// the pointer to the string data
	istream * m_myIstream;	// pointer to copy of cin

	static const char *m_chgHiCaps; //     = "¡…Õ”⁄¿»Ã“ŸƒÀœ÷‹¬ Œ‘€√’—«™∫";
	static const char *m_chgLoCaps; //     = "·ÈÌÛ˙‡ËÏÚ˘‰ÎÔˆ¸‚ÍÓÙ˚„ıÒÁ™∫";
	static const char *m_chgHiCapsSafe; // = "AEIOUAEIOUAEIOUAEIOUAONCAO";
	static const char *m_chgLoCapsSafe; // = "aeiouaeiouaeiouaeiouaoncao";

	// this consctuctor is private
	// code must be in the header due to initialization of m_myIstream
	// VBString(const int len) : m_myIstream(cin)
	VBString(const int len);

	void error(const char *) const;

	VBString strtok_helper(char tok, size_vbs n, bool & found, size_vbs & tokPos) const;
	void initCin() { m_myIstream = &cin; } // code nas to be in header due to instantiation of cin
	void privateConstructor();
	char p_extendedToUpper(char in);
	char p_extendedToLower(char in);
	char p_safeToUpper(char in);
	char p_safeToLower(char in);
	#ifdef VBSTRINGDEBUG
		int _stringObjectTag;
	#endif // VBSTRINGDEBUG
	
	unsigned char p_ToAscii(unsigned char z) const;
	unsigned char p_ToAsciiReverse(unsigned char z) const;
	void p_toHex(unsigned char ch, char *ch_hex) const;
	unsigned char p_toHexReverse(char *ch_hex) const;
	char p_toSafe(char in) const;
	void strchg(const char *find,const char *replace);

	VBString strAfter(size_vbs pos) const;
	VBString strBefore(size_vbs pos) const;

	void getLineNamespace(char endChar = '\n'); // auxiliary method for extractor
public:

	// constructors
	VBString(const VBString & s); // copy constructor
	VBString(const char* s = ""); // default contructor

	// destructor
	~VBString();
	
	// const comparison operators
	bool operator== (const VBString & s) const;
	bool operator!= (const VBString & s) const;
	bool operator<  (const VBString & s) const;
	bool operator<= (const VBString & s) const;
	bool operator>  (const VBString & s) const;
	bool operator>= (const VBString & s) const;

	// const comparison operators (continuation)
	bool operator== (const char * s) const;
	bool operator!= (const char * s) const;
	bool operator<  (const char * s) const;
	bool operator<= (const char * s) const;
	bool operator>  (const char * s) const;
	bool operator>= (const char * s) const;
	
	// const operator+
	VBString operator+(const VBString & s) const;
	VBString operator+(const char* s) const;
	VBString operator+(const char ch) const;
	VBString operator+(const int i) const;
	VBString operator+(const unsigned i) const;
	VBString operator+(const float f) const;
	VBString operator+(const double d) const;
	VBString operator+(const long double d) const;
	// global function to contatenate strings
	friend VBString operator+(const char* str,const VBString & vbs);

	// non-const operator=
	void operator=(const VBString & s);
	void operator=(const char* s);
	void operator=(const char ch);
	void operator=(const int i);
	void operator=(const unsigned i);
	void operator=(const float f);
	void operator=(const double d);
	void operator=(const long double d);

	// non-const operator+=
	void operator+=(const VBString & s);
	void operator+=(const char* s);
	void operator+=(const char ch);
	void operator+=(const int i);
	void operator+=(const unsigned i);
	void operator+=(const float f);
	void operator+=(const double d);
	void operator+=(const long double d);

	// basic utilities
	size_vbs getLength() const {return m_size;}; // get the string length (number of chars)
	bool IsEmpty() const; // true if zero length
	void Empty(); // clear contents to empty
	void myDelete(); // release memory used by object
	operator const char*() const {return m_str;};  // VBString type cast for "const char*"
	const char *getStr() const {return m_str;};
	const char *c_str() const {return m_str;};
	char getChar(size_vbs pos); // return char at position

	// handling number of decimal digits after the dot, when converting float point to VBString
	void setDecs(const unsigned decs) { m_decs = decs; };
	unsigned getDecs() const { return m_decs; };

	// handling of token
	size_vbs countSubString(const char *subStr) const; // return the number of sub-strings
	size_vbs tokCount(const char tok) const;
	VBString strtok(const char tok, const size_vbs n) const;
	VBString strtok(const char tok, const size_vbs n, bool & found) const;
	void strtokchg(const char tok, const size_vbs n, const char *newData);

	// advanced string manipulation
	VBString strAfterPosition(const size_vbs pos) const;
	VBString strUntilPosition(const size_vbs pos) const;
	VBString strInside(size_vbs from, size_vbs to) const; 
	size_vbs strtokpos(const char tok, const size_vbs n) const;
	VBString afterFind(const char *find) const;
	VBString afterFind(const char *find, bool & found) const;
	VBString beforeFind(const char *find) const;
	void strschg(const char *find,const char *replace); // deprecated method. Use "replace" instead
	void replace(const char *find,const char *replaceStr) 
		{ strschg(find,replaceStr); }; // alternative name for strschg
	bool existSubstring(const char* subStr) const;
	VBString debug(int format = 1) const;
	void setUnterminatedString(const char *str, size_vbs length); // this = str
	void wipeLeadingSpace(); // wipe leading spaces, tabs and returns
	void wipeCtrmM(); // wipe ^M (happens when reading windows text files in Windows
	bool eofDetected() const;

	void setIstream(istream & is) { m_myIstream = &is; };
	void getLine(char endChar = '\n'); // auxiliary method for extractor

	// overload insersor and extractor
	// code must be in the header due to instantiation of istream
	friend istream & operator>>(istream & stream, VBString & obj) // extractor
	{
		obj.setIstream(stream);
		#ifdef VBLIB_USE_NAMESPACE_STD
			obj.getLineNamespace();
		#else
			obj.getLine();
		#endif
		
		return stream;
	}
	// code must be in the header due to instantiation of ostream
	friend ostream & operator<<(ostream & stream, const VBString & obj) // insersor
	{
		if (obj.m_size) 
			stream << obj.m_str;
		return stream;
	}

	// char case manipulation, allowing accented char
	void toLower(); // ignore extended char
	void toUpper(); // ignore extended char
	void extendedToLower(); // convert to extended char lo caps
	void extendedToUpper(); // convert to extended char hi caps
	void safeToLower(); // convert to standard ascii char lo caps
	void safeToUpper(); // convert to standard ascii char hi caps
	void toSafe(); // convert to safe (non-extended) chars

	// simple encryption handling
	void simpleEncrypt(unsigned short code = 46);
	void simpleEncryptReverse(unsigned short code = 46);

	// http escape sequence handling
	void escapeSequence();        // convert object to web escape sequence
	void escapeSequenceReverse(); // convert object to web reverse escape sequence

#ifdef WIN32  // Visual C++ only !!!
	// methods for BSTR
	void getBSTR(const BSTR & pWord);
#endif
}; // end of VBString

char *strsrep(char *str,const char *search,const char *replace);
char *strinc(const char *str1,char *str2);
char *strschg(char *str,const char *find,const char *replace);
char *strdel(const char *substr,char *str);
char *strins(const char *instr,char *str,size_vbs st_pos);

#endif // !defined(AFX_VBSTRING_H__A23C7D7B_943C_4AA5_A918_F2915C9DC005__INCLUDED_)

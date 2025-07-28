// VBString.cpp: implementation of the VBString class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "VBString.h"
#include <string> // std::string

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

// size of char buffer used in some methods
#define BUF_SIZE 100

/////////////////////////////////////////////////////////////////
//
// VBString
//
/////////////////////////////////////////////////////////////////

// static variable initialization
const char *VBString::m_chgHiCaps     = "¡…Õ”⁄¿»Ã“ŸƒÀœ÷‹¬ Œ‘€√’—«™∫";
const char *VBString::m_chgLoCaps     = "·ÈÌÛ˙‡ËÏÚ˘‰ÎÔˆ¸‚ÍÓÙ˚„ıÒÁ™∫";
const char *VBString::m_chgHiCapsSafe = "AEIOUAEIOUAEIOUAEIOUAONCAO";
const char *VBString::m_chgLoCapsSafe = "aeiouaeiouaeiouaeiouaoncao";




//////////////////////////////////////////////////////
// constructors

void VBString::privateConstructor() 
{
	initCin(); // stores a pointer to cin in a member
	m_str = NULL; // indispensable
	m_decs = 2; // number of decimals when adding float or double
#ifdef VBSTRINGDEBUG
	_stringObjectTag = _VBObject.tag++; // increment _VBObject tag
	_VBObject = { 0, 0 };
#endif // VBSTRINGDEBUG
}

// this constructor is private
VBString::VBString(const int len) 
{
	privateConstructor();
	allocStr(len);
}


// default constructor
VBString::VBString(const char* s)
{
	privateConstructor();
	if (!s) s = "";
	int len = strlen(s);
	allocStr(len);
	strcpy(m_str,s);
}

// copy constructor
VBString::VBString(const VBString & s) 
{
	privateConstructor();
	allocStr(s.m_size);
	if (s.m_size) strcpy(m_str,s.m_str);
}


VBString VBString::strAfterPosition(const size_vbs pos) const 
{ 
	return strAfter(pos); 
};  

VBString VBString::strUntilPosition(const size_vbs pos) const 
{ 
	return strBefore(pos+1); 
}; 

VBString VBString::strInside(size_vbs from, size_vbs to) const 
{
	return this->strAfterPosition(from).strUntilPosition(to-from); 
}


// true if zero length
bool VBString::IsEmpty() const
{
	return (getLength() == 0);
}

// clear contents to empty
void VBString::Empty()
{
	*this = "";
}

// convert this string to debug format
VBString VBString::debug(int format) const
{
	VBString ret = *this;
	VBString aux, aux2;
	size_vbs i;
	switch (format)
	{
	case 1:
		ret = "";
		for (i = 0; i < getLength() ; i++)
		{
			aux = m_str[i];
			aux.simpleEncrypt(0); // convert to hexa
			ret += aux;
			ret += ".";
		}
		break;
	case 2:
		ret = "";
		for (i = 0; i < getLength() ; i++)
		{
			char ch = m_str[i];
			bool charOK = ch >= ' ' && ch <= 'z'+4;
			if (charOK)
				aux = ch;
			else
				aux = ".";
			ret += aux;
			ret += "  ";
		}
		break;
	case 3:
		aux = ret;
		ret = aux.debug(1);
		ret += '\n';
		ret += aux.debug(2);
		break;
	default:
		{} // do nothing
	}
	return ret;
}

// getline for namespace version
void VBString::getLineNamespace(char endChar) 
{
	std::string str;
	std::istream *pIstream = (std::istream*)m_myIstream;
	std::getline(*pIstream,str,'\n');
	*this = str.c_str();
	wipeCtrmM();
}

// old comment
// getline is a long method, usually implemented in cpp, not in a *.h.
// but it is defined in the header to avoid ambiguity error when using namespace std
// new comment: now getLine is implemented in the *.cpp
void VBString::getLine(char endChar) 
{
	// the 2 lines below are necessary to avoid unwanted chars in the buffer
	// int gc = m_myIstream.gcount();
	// if (gc > 0) m_myIstream.ignore(gc);

	// a linked list of strList objects
	VBList<strList> myList;

	// a loop to keep adding strList objects to a list, 
	// until the input stream of char is finished.
	strList b;
	bool listEnd = false;
	int elements = 0;
	int lengthOfLastBuffer;
	while (!listEnd) {
		for (int i=0 ; i < VB_N ; i++) {
			b.buffer[i] = m_myIstream->get();
			if (m_myIstream->eof() || (b.buffer[i] == endChar)) {
				b.buffer[i] = 0;  // end string
				listEnd = true;
				lengthOfLastBuffer = i;
				break;  // end for loop
			}
		}
		myList.add(b);
		elements++;
		// cout << "DEBUG: Added element " << elements << endl;
	}

	// one buffer to store the complete input string
	char *completeBuffer = new char [elements * VB_N];
	if (!completeBuffer)
		error("Alloc error !");
	
	// scans the list and copies the contents of each element
	// to completeBuffer
	strList *p = myList.GetFirst();
	for (int i=0 ; i < elements ; i++) {
		for (int k=0 ; k < VB_N ; k++)
			completeBuffer[k + VB_N*i] = p->buffer[k];
		p = myList.GetNext();
	}

	// the contents is copied. Now terminate string with the zero at the end
	int terminateStringPosition = (elements-1)*VB_N + lengthOfLastBuffer;

	// eliminate ^M char, that happens when unix programs read text files from windows
	// char lastChar = completeBuffer[terminateStringPosition-1];
	// if (lastChar == 13 && terminateStringPosition > 0) terminateStringPosition--; // ^M in decimal is 13

	completeBuffer[terminateStringPosition] = 0; // terminate string

	(*this) = completeBuffer; // copies the buffer to the object
	delete [] completeBuffer;

	wipeCtrmM();

} // end of getLine


void VBString::wipeCtrmM()
{
	char lastChar = (*this)[getLength()-1];
	if (lastChar == 13) // 13 = ^M
		*this = strInside(0,getLength()-2);
}


// return true if the string contains the sub string
bool VBString::existSubstring(const char* subStr) const
{
	bool ret = (bool) (::strstr((*this).getStr(), subStr) != 0); 
	// ::strstr is the global strstr, 
	return ret;
}


// Example: z_aux = 15, return 'f'
// Example: z_aux = 3, return = '3'
unsigned char VBString::p_ToAscii(unsigned char z_aux) const
{
	unsigned char z = tolower(z_aux);
	if (z < 10)  z += '0';
	else 	     z += 'a' - 10;
	return z;
}

// Example: z_aux = 'F' or 'f',  return = 15
// Example: z_aux = '3', return = 3
unsigned char VBString::p_ToAsciiReverse(unsigned char z_aux) const
{
	unsigned char z = tolower(z_aux);
	if (z < ('9'+1) )  z -= '0';
	else               z -= 'a' - 10;
	return z;
}

// Example: ch = 'A' (input) ,  ch_hex = "41" (output)
void VBString::p_toHex(unsigned char ch, char *ch_hex) const
{
	unsigned char a;
	a = (ch & 0x0f);
	ch_hex[1] = p_ToAscii(a); // LSB
	a = (ch & 0xf0)/16;
	ch_hex[0] = p_ToAscii(a);; // MSB
}

// Example: ch_hex = "41",  return = 'A'
unsigned char VBString::p_toHexReverse(char *ch_hex) const
{
	unsigned char ret;
	int msb, lsb;
	msb = p_ToAsciiReverse(ch_hex[0]);
	lsb = p_ToAsciiReverse(ch_hex[1]);
	ret = lsb + msb * 16;
	return ret;
}


// encrypts object using code [0~255]
void VBString::simpleEncrypt(unsigned short code)
{
	// code is any number from 0 to 255
	VBString ret;
	size_vbs len = strlen(m_str);
	unsigned char ch;
	char ch_hex[3];
	ch_hex[2] = 0; // string terminator
	for (size_vbs i=0 ; i < len ; i++) {
		ch = m_str[i] ^ code;  // ^ is bitwise xor
		p_toHex(ch,ch_hex);
		ret += ch_hex; // adding string
	}
	*this = ret;
}

// de-encrypts object using code
void VBString::simpleEncryptReverse(unsigned short code)
{
	// code is any number from 0 to 255
	VBString ret;
	size_vbs len = strlen(m_str);
	char ch[2];  
	ch[1] = 0; // string terminator
	char ch_hex[2];
	for (size_vbs i=0 ; i < len/2 ; i++) {
		ch_hex[0] = m_str[2*i];
		ch_hex[1] = m_str[2*i+1];
		ch[0] = p_toHexReverse(ch_hex);
		ch[0] ^= code;  // ^ is bitwise xor
		ret += ch;
	}
	*this = ret;
}

// return the number of sub-strings
size_vbs VBString::countSubString(const char *subStr) const
{
	size_vbs ret=0;
	VBString a = afterFind(subStr);
	while (strlen(a)!=0) {
		// cout << "DEBUG: " << a << endl;
		ret++;
		// cout << "DEBUG: " << ret << endl;
		VBString b = a.afterFind(subStr);
		a = b;
	}
	return ret;
}

// return the number of tokens
size_vbs VBString::tokCount(char tok) const
{
	size_vbs ret=0;
	size_vbs len = getLength();
	for (size_vbs i=0; i < len ; i++) {
		if (m_str[i]==tok)
			ret++;
	}
	return ret;
}

void VBString::strtokchg(const char tok, const size_vbs n, const char *newData) 
{
	if (n > tokCount(tok)) {// if n too big
		// cout << "n too big" << endl; // debug
		return; // do nothing
	}
	size_vbs tokPos_initial = strtokpos(tok,n) + 1;
	size_vbs tokPos_final   = strtokpos(tok,n+1) + 1;
	if (n == tokCount(tok)) // the last string
		tokPos_final++;
	VBString before = strBefore(tokPos_initial);
	VBString after = strAfter(tokPos_final-1);
	*this = before + newData + after;
}

void VBString::myDelete() 
{
	if (m_str) {
		#ifdef VBSTRINGDEBUG
			cout << "Deleted object #: " << _stringObjectTag << endl;
		#endif // VBSTRINGDEBUG
		delete [] m_str;
		m_str = NULL;
	}
}

VBString::~VBString() 
{
	myDelete();
} 

char VBString::p_extendedToUpper(char in) 
{
	in = toupper(in);
	// change extended chars 
	int lenChg = strlen(m_chgHiCaps);
	for (int k=0 ; k < lenChg ; k++) {
		if (in == m_chgLoCaps[k]) { // test for each char of chgLoCaps
			return m_chgHiCaps[k];  // set correspondent HiCaps in its place
		}
	} // for k
	return in;
}

char VBString::p_extendedToLower(char in) 
{
	in = tolower(in);
	// change extended chars 
	int lenChg = strlen(m_chgHiCaps);
	for (int k=0 ; k < lenChg ; k++) {
		if (in == m_chgHiCaps[k]) { // test for each char of chgLoCaps
			return m_chgLoCaps[k];  // set correspondent LoCaps in its place
		}
	} // for k
	return in;
}

char VBString::p_safeToUpper(char in) 
{
	in = p_toSafe(in);
	in = toupper(in);
	return in;
}

char VBString::p_safeToLower(char in) 
{
	in = p_toSafe(in);
	in = tolower(in);
	return in;
}

// change extended chars to safe (non-extended) ones
char VBString::p_toSafe(char in) const
{
	int lenChg = strlen(m_chgHiCaps);
	for (int k=0 ; k < lenChg ; k++) {
		if (in == m_chgHiCaps[k]) { // test for each char of chgHiCaps
			return m_chgHiCapsSafe[k];  // set correspondent safe
		}
		if (in == m_chgLoCaps[k]) { // test for each char of chgLoCaps
			return m_chgLoCapsSafe[k];  // set correspondent safe
		}
	} // for k
	return in;
}

// ignore extended char
void VBString::toLower() 
{
	size_vbs len = strlen(m_str);
	for (size_vbs i=0 ; i < len ; i++)
		m_str[i] = tolower(m_str[i]);
}

 // ignore extended char
void VBString::toUpper() 
{
	size_vbs len = strlen(m_str);
	for (size_vbs i=0 ; i < len ; i++)
		m_str[i] = toupper(m_str[i]);
}

// convert to extended char lo caps
void VBString::extendedToLower() 
{
	size_vbs len = strlen(m_str);
	for (size_vbs i=0 ; i < len ; i++)
		m_str[i] = p_extendedToLower(m_str[i]);
}

// convert to extended char hi caps
void VBString::extendedToUpper() 
{
	size_vbs len = strlen(m_str);
	for (size_vbs i=0 ; i < len ; i++)
		m_str[i] = p_extendedToUpper(m_str[i]);
}

// convert to standard ascii char lo caps
void VBString::safeToLower() 
{
	size_vbs len = strlen(m_str);
	for (size_vbs i=0 ; i < len ; i++)
		m_str[i] = p_safeToLower(m_str[i]);
}

// convert to standard ascii char hi caps
void VBString::safeToUpper() 
{
	size_vbs len = strlen(m_str);
	for (size_vbs i=0 ; i < len ; i++) {
		// cout << "before=" << m_str[i] << endl;
		m_str[i] = p_safeToUpper(m_str[i]);
		// cout << "after="<< m_str[i] << endl;
	}
}

// convert to standard ascii char hi or lo caps
void VBString::toSafe() 
{
	size_vbs len = strlen(m_str);
	for (size_vbs i=0 ; i < len ; i++) {
		m_str[i] = p_toSafe(m_str[i]);
	}
}


// void VBString::setErrorFunction(void (*fun)(const char *)) 
// {	m_errorFunction = fun; }

void VBString::error(const char *msg) const
{
	// m_errorFunction(msg);
	throw msg;
} 

void VBString::allocStr(size_vbs size_in) // redim
{ 
	// m_size = abs(size_in); // not necessary
	m_size = size_in;
	if (m_str) delete [] m_str;
	if (m_size >= 0) {
		m_str = new char [m_size+1];
		if (!m_str) 
			error("Alloc error !!!");
		#ifdef VBSTRINGDEBUG
			cout << "Alloced object #: " << _stringObjectTag << endl;
		#endif // VBSTRINGDEBUG
		m_str[0] = 0; // terminate string
	} 
	else {
		#ifdef VBSTRINGDEBUG
			cout << "Attempt to alloc empty string, object #: " << _stringObjectTag << endl;
		#endif // VBSTRINGDEBUG
		m_str = NULL;
	}
}

VBString operator+(const char* str,const VBString & vbs) 
{
	VBString r(str);
	VBString ret = r + vbs;
	return ret;
}

//////////////////////
// BSTR

#ifdef WIN32
void VBString::getBSTR(const BSTR & pWord) 
{
	size_vbs i=0;
	while (pWord[i]) 
		i++;
	// after this loop, i has the length of the BSTR
	size_vbs length = i;
	char *p = new char [length+1];
	if (!p) error("Could't alloc memory");
	for (i=0 ; i < length ; i++)
		p[i] = (char) pWord[i];
	p[length]=0; // terminate string
	(*this) = p; // place the string to object
	delete [] p; // delete p not to leak memory
}
#endif


char VBString::getChar(size_vbs pos) 
{
	if (pos < getLength())
		return m_str[pos];
	else
		return 0; // null char
}


/////////////////////////////////////////////////////////////
// operator=

void VBString::operator=(const VBString & s) 
{
	allocStr(s.m_size);
	if (s.m_size) strcpy(m_str,s.m_str);
}

void VBString::operator=(const char *s) 
{
	if (!s) s = "";
	size_vbs len = strlen(s);
	allocStr(len);
	if (len) strcpy(m_str,s);
}

void VBString::operator= (const char ch) 
{
	VBString aux;
	aux += ch;
	*this = aux;
}

void VBString::operator=(const int i)
{
	VBString aux;
	aux += i;
	*this = aux;
}

void VBString::operator=(const unsigned i)
{
	VBString aux;
	aux += i;
	*this = aux;
}

void VBString::operator=(const float f)
{
	VBString aux;
	aux.setDecs(getDecs()); // use the number of decs of this
	aux += f;
	*this = aux;
}

void VBString::operator=(const double d)
{
	VBString aux;
	aux.setDecs(getDecs()); // use the number of decs of this
	aux += d;
	*this = aux;
}

void VBString::operator=(const long double d)
{
	VBString aux;
	aux.setDecs(getDecs()); // use the number of decs of this
	aux += d;
	*this = aux;
}


/////////////////////////////////////////////////////////////
// operator+=
void VBString::operator+=(const char ch) 
{
	VBString ret = (*this) + ch;
	operator=(ret);
}

void VBString::operator+=(const int i) 
{
	VBString ret = (*this) + i;
	operator=(ret);
}

void VBString::operator+=(const unsigned i) 
{
	VBString ret = (*this) + i;
	operator=(ret);
}

void VBString::operator+=(const double d) 
{
	VBString ret = (*this) + d;
	operator=(ret);
}

void VBString::operator+=(const long double d) 
{
	VBString ret = (*this) + d;
	operator=(ret);
}

void VBString::operator+=(const float f) 
{
	VBString ret = (*this) + f;
	operator=(ret);
}

void VBString::operator+=(const char* s) 
{
	VBString ret = (*this) + s;
	operator=(ret);
}

void VBString::operator+=(const VBString & s) 
{
	VBString ret = (*this) + s;
	operator=(ret);
}

/////////////////////////////////////////////////////////////
// operator+

VBString VBString::operator+(const char ch) const
{
	char buffer[2];
	buffer[0] = ch;
	buffer[1] = 0; // terminator string
	VBString ret = (*this) + buffer; // buffer is char*
	return ret;
}

VBString VBString::operator+(const int i) const
{
/* old and buggy version
	char buffer[BUF_SIZE];
	sprintf(buffer,"%d",i);
	return operator+(buffer);
*/
	char buffer[BUF_SIZE];
	sprintf(buffer,"%d",i);
	VBString ret = (*this) + buffer;
	return ret;
}

VBString VBString::operator+(const unsigned i) const
{
/* old and buggy version
	char buffer[BUF_SIZE];
	sprintf(buffer,"%d",i);
	return operator+(buffer);
*/
	char buffer[BUF_SIZE];
	sprintf(buffer,"%u",i);
	VBString ret = (*this) + buffer;
	return ret;
}

VBString VBString::operator+(const float f) const
{
	VBString ret = operator+((double)f);
	return ret;
}

VBString VBString::operator+(const double d) const
{
	char buffer[BUF_SIZE];
	char sprintfBuffer[BUF_SIZE];
	sprintf(sprintfBuffer,"%c1.%df",'%',m_decs); 
	// cout << "DEBUG=" << sprintfBuffer << endl;
	// cout << "DEBUG=" << d << endl;
	// create a buffer for next sprintf. 
	// If m_decs == 2, springBuffer is "%1.2f"
	sprintf(buffer,sprintfBuffer,d);
	VBString ret = (*this) + buffer;
	return ret;
}

VBString VBString::operator+(const long double d) const
{
	char buffer[BUF_SIZE];
	char sprintfBuffer[BUF_SIZE];
	sprintf(sprintfBuffer,"%c1.%dlf",'%',m_decs); 
	sprintf(buffer,sprintfBuffer,d);
	VBString ret = (*this) + buffer;
	return ret;
}

VBString VBString::operator+(const char* s) const
{
	if (s) {
		size_vbs len = strlen(s);
		if (!m_size) { // if string is null
			VBString ret(len);
			if (len) strcpy(ret.m_str,s);
			return ret;
			/*
			myDelete();
			allocStr(strlen(s));
			strcpy(str,s);
			return (*this);
			*/
		}
		VBString ret(m_size + len);
		if (m_size) strcpy(ret.m_str,m_str);
		if (len) strcat(ret.m_str,s);
		return ret;
	}
	else 
		return (VBString(0));  // return empty VBString
}


VBString VBString::operator+(const VBString & s) const
{
	if (s.m_str)
		return operator+(s.m_str);
	else
		return operator+("");
/*	
	VBString ret(size + s.size);
	strcpy(ret.str,str);
	strcat(ret.str,s.str);
	return ret;
*/
}

VBString VBString::afterFind(const char *find, bool & found) const
{
	found = true;
	VBString b = beforeFind(find);
	if (b.getLength() == getLength()) {
		found = false;
		return (VBString(""));
	}
	char *inStr = m_str;
	size_vbs pos = b.getLength() + strlen(find);
	VBString ret(inStr+pos);
	return ret;
}


// return the string before fing
// VBString r,a("123456789");
// r = a.afterFind("56"); // r = "789";
// r = a.afterFind("xx"); // r = ""; // string not found
VBString VBString::afterFind(const char *find) const
{
	bool found;
	return (afterFind(find,found));
}

// return the string before fing
// VBString r,a("123456789");
// r = a.beforeFind("56"); // r = "1234";
// r = a.beforeFind("xx"); // r = "123456789"; // string not found
VBString VBString::beforeFind(const char *find) const
{
	char *inStr = new char [getLength()+1];
	if (!inStr)
		error("Alloc error !!!");
	strcpy(inStr,getStr());
	char *r = strinc(find,inStr);
	size_vbs stopLen;
	if (r) 
		stopLen = strlen(inStr) - strlen(r);
	else
		stopLen = strlen(inStr);
	inStr[stopLen] = 0;  // end string
	VBString ret(inStr);
	delete [] inStr;
	return ret;
}

// find and replace 1 string 
void VBString::strchg(const char *find,const char *replace) 
{
	VBString ret = beforeFind(find);
	bool found;
	VBString a = afterFind(find,found);
	if (found) 
		ret += replace + a;
	(*this) = ret; // place effect to the own object
}

#if 0
// this is the old version
// find and replace all instances of find string 
void VBString::strschg(const char *find,const char *replace) {
	VBString save = (*this);
	VBString ret = save;
	ret.strchg(find,replace);
	bool stop = (ret == save);
	while (!stop) {
		save = ret;
		ret.strchg(find,replace);
		stop = (ret == save);
	}
	(*this) = ret; // place effect to the own object
}
#endif

// new version
// find and replace all instances of find string 
void VBString::strschg(const char *find,const char *replace) {
	VBString ret, after, before;
	before = beforeFind(find);
	after = (*this);
	ret = before;
	bool stop = (after == before);
	if (!stop) ret += replace;
	while (!stop) {
		after = after.afterFind(find);
		before = after.beforeFind(find);
		stop = (after == before);
		if (!stop) {
			ret += before;
			ret += replace;
		}
		else {
			ret += before;
		}
	}
	(*this) = ret; // place effect to the own object
}

VBString VBString::strtok(char tok, unsigned long n, bool & found ) const
{
	unsigned long tokPos;
	return strtok_helper(tok,n,found,tokPos);
}

// VBString = "abc,def,ghi"
// tok =','
// n = 2
// return = "def"
// tokpos is the position of the token in the string
VBString VBString::strtok_helper(char tok, size_vbs n, bool & found, 
			size_vbs & tokPos) const
{
	found = false;
	char *str = m_str;
	if (!str) return VBString(""); // token not found 
	size_vbs len = getLength();
	size_vbs tokCount = 0;
	size_vbs i=0, initial=0, final=0;
	bool initOK = false, finalOK = false;

#if 0
	// fix loop in case first letter is the tok
	if ((str[0] == tok) && (n==0)) {
		initial = 0;  // initial stores the position of nth token
		initOK = true;
		tokCount = 1;
		i = 1;
	}
#endif

	// loop to identify the position of nth string
	for ( ; (i < len) && !finalOK ; i++) 
	{
		if (str[i] == tok) 
			tokCount++;
//		if ((str[0] == tok) || (!initOK && (tokCount == n))) {
		if (!initOK && (tokCount == n)) {
			initial = i;  // initial stores the position of nth token
			initOK = true;
		}
		if (tokCount == (n+1)) { 
			final = i; // final stores the position of (n+1)th token
			finalOK = true;
		}
	}
	
	if (initOK && finalOK) 
	{
		found = true;
		char *buffer = new char [final - initial + 1];
		size_vbs offset;
		if (n == 0)	offset = 0;
		else offset = 1;
		for (i=initial+offset ; i < final ; i++)
			buffer[i-initial-offset] = str[i];
		buffer[i-initial-offset] = 0; // end string
		VBString ret(buffer);
		delete [] buffer;
		tokPos = initial+1; // +1 to get on the token
		if (n==0) tokPos=0;
		return ret;
	}
	if (initOK && !finalOK)  // n points to the last string
	{ 
		found = true;
		VBString ret(str+initial+1);
		tokPos = initial+1; // +1 to get on the token
		if (n==0) 
		{
			tokPos=0;
			ret = str;
		}
		return ret;
	}

	if ((str[0] == tok) && (n==0)) 
	{
		found = true; // in this case, return is "", but str is found
		tokPos = 0;
	}

	tokPos = getLength();
	return VBString(""); // token not found or n too big

} // end of method strtok_helper


VBString VBString::strtok(char tok, size_vbs n) const
{
	bool found;
	return (strtok(tok,n,found));
}

/* use getLength method instead of length
unsigned long VBString::length() {
	if (m_str)
		return strlen(m_str);
	else
		return 0;
}
*/

// *this "1234567890"
// pos = 3
// ret = "4567890"
VBString VBString::strAfter(size_vbs pos) const
{
	if (pos > 0) {
		VBString ret = m_str + pos;
		if (pos >= getLength())
			ret = "";
		return ret;
	}
	else 
		return *this;
}

// *this "1234567890"
// pos = 3
// ret = "123"
VBString VBString::strBefore(size_vbs pos) const
{
	size_vbs len = getLength();
	char *p = new char [len+1]; // +1 for the terminator char
	strcpy(p,m_str); // copy string to other buffer
	if (pos > len) pos = len;
	p[pos] = 0;  // terminate the string
	VBString ret = p;
	delete [] p;
	return ret;
}

// return the position of the token
// VBString a = "abc,def,ghi,123,456,7890,yyy";
// int n=3;
// char tok = ',';
// int pos = a.strtokpos(tok,n); // pos=
size_vbs VBString::strtokpos(char tok, size_vbs n) const
{
	size_vbs tokPos;
	bool found;
	strtok_helper(tok,n,found,tokPos);
	return tokPos - 1 ;
}

#if 0
size_vbs VBString::strtokLen(char tok) const
{
	size_vbs ret=0;
	bool found;
	do {
		strtok(tok,ret,found);
		if (found)
			ret++;
	} while (found);

	return ret;
}
#endif


bool VBString::operator<(const VBString & s) const
{
	return (strcmp(m_str,s.m_str) < 0);
}

bool VBString::operator<=(const VBString & s) const
{
	return (strcmp(m_str,s.m_str) <= 0);
}

bool VBString::operator>(const VBString & s) const
{
	return (strcmp(m_str,s.m_str) > 0);
}

bool VBString::operator>=(const VBString & s) const
{
	return (strcmp(m_str,s.m_str) >= 0);
}

bool VBString::operator==(const VBString & s) const
{
	return (strcmp(m_str,s.m_str)==0);
}

bool VBString::operator!=(const VBString & s) const
{
	return (!((*this)==s));
}

bool VBString::operator<(const char * s) const { return operator<(VBString(s)); }
bool VBString::operator<=(const char * s) const { return operator<=(VBString(s)); }
bool VBString::operator>(const char * s) const { return operator>(VBString(s)); }
bool VBString::operator>=(const char * s) const { return operator>=(VBString(s)); }
bool VBString::operator==(const char * s) const { return operator==(VBString(s)); }
bool VBString::operator!=(const char * s) const { return operator!=(VBString(s)); }



// convert object to web scape sequence
void VBString::scapeSequenceReverse() 
{

	// Convert all + chars to space chars
    strschg("+"," ");

	bool hasChange;
	VBString ret, before, after = (*this);
	do {
		hasChange = false;
		for (size_vbs x = 0; x < after.getLength(); x++) {
			if (after.m_str[x] == '%') {
				hasChange = true;
				before = after.strBefore(x);

				// convert the code after the '%' to ascii, and use it as replace string
				char strToReplace[2];
				strToReplace[0] = p_toHexReverse(after.m_str+x+1);
				strToReplace[1] = 0; // terminate string

				ret += before + strToReplace;
				after = after.strAfter(x+3);
				break;
			}
		}
		if (!hasChange) 
			ret += after;
	}
	while (hasChange);

	// copy 
	(*this) = ret;
}

// convert object to web unscape sequence
void VBString::scapeSequence() 
{

	// Convert % separatelly not to give problem with the general % case
    strschg("%","%25");

	const char *charToConvert = "=.,?<>[]{};:'\"`~!@&#$^()+-*/_|\\¡…Õ”⁄√’—¿»Ã“Ÿ‹«¬ Œ‘€·ÈÌÛ˙„ıÒ‡ËÏÚ˘¸Á‚ÍÓÙ˚";

	// Convert all %xy hex codes into ASCII chars 
	bool hasChange;
	do {
		hasChange = false;
		for (size_vbs x = 0; x < m_size; x++) {
			for (size_vbs y = 0; y < strlen(charToConvert) ; y++) {
				if (m_str[x] == charToConvert[y]) {
					hasChange = true;
					char strToSearch[2];
					strToSearch[0] = charToConvert[y]; 
					strToSearch[1] = 0; // terminate string

					// replace string is %xx<zero>, where xx is charToConvert[y] converted to hex
					char strToReplace[4];
					strToReplace[0] = '%';
					p_toHex(charToConvert[y],strToReplace+1);
					strToReplace[3] = 0; // terminate string
					strschg(strToSearch,strToReplace); // convert
					break;
				} // if
			} // for y
		} // for x
	} while (hasChange);
    
	strschg(" ","+"); // convert space char separatelly, since version 2.3 of VBMcgi
}

// this = str
// useful for expat XML processing
void VBString::setUnterminatedString(const char *str, size_vbs length) 
{
	myDelete();
	m_str = new char [length + 1];
	for (size_vbs i = 0; i < length ; i++)
		m_str[i] = str[i];
	m_str[length] = 0;
	m_size = length;
}

void VBString::wipeLeadingSpace() 
{
	size_vbs i = 0;
	while ((m_str[i] == '\n' || m_str[i] == '\t' || m_str[i] == ' ') && i < m_size)
		i++;
	if (i != 0)
	{
		// *this = m_str+i; // can't do this
		VBString s = m_str+i;
		*this = s;
	}

}

/////////////////////////////////////////////////////////////////
//
// Some string global functions (comes from CXL)
//
/////////////////////////////////////////////////////////////////


char *strins(const char *instr,char *str,size_vbs st_pos)
{
    register size_vbs i,leninstr;

    /* get length of string to insert */
    leninstr=strlen(instr);

    /* shift affected portion of str text to the right */
    for(i=strlen(str);i>=st_pos;i--) *(str+leninstr+i)=*(str+i);

    /* insert instr text */
    for(i=0;i<leninstr;i++) *(str+st_pos+i)=*(instr+i);

    /* return address of modified string */
    return(str);
}

char *strdel(const char *substr,char *str)
{
    char *src,*dest;

    dest=strinc(substr,str);
    if(!dest) return(NULL);
    src=dest+strlen(substr);
    strcpy(dest,src);
    return(str);
}


char *strsrep(char *str,const char *search,const char *replace)
{
    char *p;

    if((p=strinc(search,str))!=NULL) {
        strdel(search,str);
        strins(replace,str,(int)((unsigned long)p-(unsigned long)str));
        p=str;
    }

    return(p);
}


char *strinc(const char *str1,char *str2)
{
    register size_vbs max;
    char *p;

    max=strlen(str1);

    for(p=str2;*p;p++) {
        if(!strncmp(str1,p,max)) return(p);
    }
    return(NULL);                       /* string1 not found in string2 */
}


char *strschg(char *str,const char *find,const char *replace)
{
    register size_vbs count=0;
    register char *p;

    p=str;
    while((p=strinc(find,p))!=NULL) {
        strsrep(p,find,replace);
/***************** line included by Sergio Villas Boas **************/
        p += (int) strlen(replace); 
/*------------------------------------------------------------------*/
        count++;
    }

	if (count) return (str);
    else return (NULL);
//    return(count?str:NULL);
}


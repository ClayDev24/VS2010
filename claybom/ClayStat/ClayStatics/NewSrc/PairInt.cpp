// CPairInt.cpp: implementation of the CCPairInt class.
//
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "ClayStat2.h"
#include "PairInt.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
////////////////////////////////////////////////////////////////////

CPairInt::CPairInt() : m_counter(0) {};

CPairInt::~CPairInt()
{
	//TRACE("~CPairInt()...");
};//dad handles all tha job of cleanin'...

CPairInt::CPairInt(CString *val, int count) : CPair(0, val) {
	m_counter = count;
};

CString CPairInt::operator = (CPairInt *pi) const {
	char ch[5];
	return (CString)*pi->get_value() + " " + (CString)itoa(pi->get_counter(), ch, 10);  
};

CString CPairInt::toString(void) const {
	char ch[5];
	return *m_value + " =>" + itoa(m_counter, ch, 10);
};  

CString CPairInt::toString2(void) const {
    CString out;
	out.Format("(%i msgs)=>%s", m_counter, *m_value);
	return out;
};  
/*
bool CPairInt::GreaterThan(CPairInt *inPair) const {
  if(m_counter < inPair->m_counter) return true;
  if(m_counter > inPair->m_counter) return false;
  return false;
};
*/
bool CPairInt::LessThan(CPairInt *inPair) const {
  if(m_counter > inPair->m_counter) return true;
  if(m_counter < inPair->m_counter) return false;
  return false;
};

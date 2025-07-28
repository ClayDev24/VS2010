// Pair.cpp: implementation of the CPair class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ClayStat2.h"
#include "Pair.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

CPair::~CPair() {
	if(m_value && m_value != NULL) {
		TRACE("~CPair()... " + *m_value + (CString)"\n");
		delete m_value;
	} //else
		//TRACE("nothing...\n");
};

CPair::CPair(const int key, CString *value) : m_key(key) {
	m_value = value;
};

CString CPair::toString() {
	CString k = "";
	if(m_key == ID_HEADER_NICKNAME)
	    k = "From:";
	else if(m_key == ID_HEADER_GROUPS)
		k = "Newsgroups:";
	else if(m_key == ID_HEADER_SUBJECT)
		k = "Subject:";
	else if(m_key == ID_HEADER_HOUR)
		k = "Date:";
	else if(m_key == ID_HEADER_NEWSREADER)
		k = "X-Newsreader:";
	else if(m_key == ID_HEADER_MSGID)
		k = "Message-ID:";
	return k + " " + *m_value;
}
/*
bool CPair::operator ==(CPair *inPair) const {
	if(*m_value != *inPair->m_value) return false;
	return true;
};

bool CPair::operator >(CPair *inPair) const {
	if(*m_value > *inPair->m_value) return true;
	if((CString)m_key < *inPair->m_value) return false;
	return true;
};

bool CPair::operator <(CPair *inPair) const {
	if((CString)m_key < *inPair->m_value) return true;
	if((CString)m_key > *inPair->m_value) return false;
	return false;
};
*/
void CPair::operator=(CPair pair) {
	this->m_key   = pair.m_key;
	*this->m_value = *pair.m_value;
}

bool CPair::LessThan(CPair *inPair) const {
	if(*m_value < *inPair->m_value) return true;
	if(*m_value > *inPair->m_value) return false;
	return false;
};

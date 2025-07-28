#include <iostream>
#include "Pair.h"

CPair::~CPair() {
	if(m_value && m_value != NULL)
		std::cout << "~CPair()...\n" << m_value;
	else
		std::cout << "nothing...\n";
};

CPair::CPair(const int key, std::string value):m_key(key) {
	m_value = value;
};

std::string CPair::toString() {
	std::string s = "";
	if(m_key == ID_HEADER_NICKNAME)
	    s = "From:";
	else if(m_key == ID_HEADER_GROUPS)
		s = "Newsgroups:";
	else if(m_key == ID_HEADER_SUBJECT)
		s = "Subject:";
	else if(m_key == ID_HEADER_HOUR)
		s = "Date:";
	else if(m_key == ID_HEADER_NEWSREADER)
		s = "X-Newsreader:";
	else if(m_key == ID_HEADER_MSGID)
		s = "Message-ID:";
	return s + " " + m_value;
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
	this->m_value = pair.m_value;
}

bool CPair::LessThan(CPair *inPair) const {
	if(m_value < inPair->m_value) return true;
	if(m_value > inPair->m_value) return false;
	return false;
};

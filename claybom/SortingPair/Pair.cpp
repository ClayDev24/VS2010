#include "pair.h"

CPair::~CPair() {
    //cout << "~CPair()..." << countP-- << endl;
    if(m_value != NULL) {

//	cout << "deleting m_value... " << *m_value << endl;
	delete m_value;
    }
};

CPair::CPair(const HEADER &key, std::string *value) : m_key(key) {
    //cout << "CPair()..." << countP++ << endl;
    m_value = value;
};

void CPair::operator=(CPair pair) {
    this->m_key = pair.m_key;
    *this->m_value = *pair.m_value;
}

//bool CPair::operator ==(CPair *inPair) const {
//    if(*m_value != *inPair->m_value) return false;
//    return true;
//};


std::string CPair::toString(void) const {
    return "m_key" + (std::string)" " + *m_value;
};

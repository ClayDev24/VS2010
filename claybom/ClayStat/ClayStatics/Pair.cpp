#include "Pair.h"
#include "define_print.h"

CPair::~CPair() {
    DS_("~CPair()...")// << countP-- << endl;
    if(m_value) {
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
	std::string str = "";
	if(m_key == ID_HEADER_NICKNAME)
	    str = "From:";
	else if(m_key == ID_HEADER_GROUPS)
		str = "Newsgroups:";
	else if(m_key == ID_HEADER_SUBJECT)
		str = "Subject:";
	else if(m_key == ID_HEADER_HOUR)
		str = "Date:";
	else if(m_key == ID_HEADER_NEWSREADER)
		str = "X-Newsreader:";
	else if(m_key == ID_HEADER_MSGID)
		str = "Message-ID:";
	return str + " " + *m_value;
};

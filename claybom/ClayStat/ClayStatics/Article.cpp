#include "Article.h"

CArticle::~CArticle() {
//    cout << "~CArticle()..." << countA-- << endl;
    vtPair::iterator it;
//    for(it = m_headers->begin(); it != m_headers->end(); it++)
//        delete *it;
    delete []m_headers;
}

CArticle::CArticle(/*vtPair *headers*/CPair *headers, bool ref, std::string body) {
//    cout << "CArticle()..." << countA++ << endl;
    m_thread  = ref;
    m_headers = headers;
    m_body    = body;
};
  	  	
std::string CArticle::toString() const {
	return "\tAutor:   " + get_header(ID_HEADER_NICKNAME) + "\n" +
    	      "\tAssunto: " + get_header(ID_HEADER_SUBJECT)  + "\n" +
             "\tGrupo:   " + get_header(ID_HEADER_GROUPS)   + "\n" +
            "\tHora:    " + get_header(ID_HEADER_HOUR)     + "\n";
};

std::string CArticle::toString2() const {
	return "\t" + get_header(ID_HEADER_NICKNAME) + "\n" +
  	      "\t" + get_header(ID_HEADER_MSGID)    + "\n" +
  	     "\t" + get_header(ID_HEADER_SUBJECT)  + "\n" +
            "\t" + get_header(ID_HEADER_IP)       + "\n" +
	   "\t" + get_header(ID_HEADER_HOUR)     + "\n";
};

std::string CArticle::get_header(const HEADER &hdr) const {
/*    vtPair::iterator it;
    for(it = m_headers->begin(); it != m_headers->end(); it++) {        
	CPair *pair = *it;
	if(pair->get_key() == hdr)
	   return *pair->get_value();
    }
    return NULL;
*/
    switch (hdr)
    {
	case ID_HEADER_NICKNAME :
	    return *m_headers[0].get_value();
	case ID_HEADER_EMAIL:
	    return *m_headers[1].get_value();
	case ID_HEADER_GROUPS:
	    return *m_headers[2].get_value();
	case ID_HEADER_HOUR:
	    return *m_headers[3].get_value();
	case ID_HEADER_IP:
	    return *m_headers[4].get_value();
	case ID_HEADER_SUBJECT:
	    return *m_headers[5].get_value();
	case ID_HEADER_NEWSREADER:
	    return *m_headers[6].get_value();
	case ID_HEADER_MSGID:
	    return *m_headers[7].get_value();
	default:
	    return "NULL";;
    }
};

// CArticle.cpp: implementation of the CArticle class.
//
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "ClayStat2.h"
#include "Article.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CArticle::~CArticle() {
	//TRACE("~CArticle()...");
	delete []headers;
}

CArticle::CArticle(CPair *headers, bool thread, CString body) {
	CArticle::thread  = thread;
	CArticle::headers = headers;
	CArticle::body    = body;
};
  	  	
CString CArticle::toString() const {
	return "Autor:   " + get_header(ID_HEADER_NICKNAME) + "\n" +
    	  "Assunto: " + get_header(ID_HEADER_SUBJECT) + "\n" +
         "Grupo:   " + get_header(ID_HEADER_GROUPS) + "\n" +
        "Hora:    " + get_header(ID_HEADER_HOUR) + "\n";
};

CString CArticle::toString2() const {
	return "          " + get_header(ID_HEADER_NICKNAME) + "\n" +
  		  "          " + get_header(ID_HEADER_MSGID) + "\n" +
  	     "          " + get_header(ID_HEADER_SUBJECT) + "\n" +
        "          " + get_header(ID_HEADER_IP) + "\n" +
	   "          " + get_header(ID_HEADER_HOUR) + "\n";
};

CString CArticle::get_header(const int &hdr) const {
	 switch (hdr)
	 {
	 case ID_HEADER_NICKNAME :
		 return *headers[0].get_value();
	 case ID_HEADER_EMAIL:
		 return *headers[1].get_value();
	 case ID_HEADER_GROUPS:
		 return *headers[2].get_value();
	 case ID_HEADER_HOUR:
		 return *headers[3].get_value();
	 case ID_HEADER_IP:
		 return *headers[4].get_value();
	 case ID_HEADER_SUBJECT:
		 return *headers[5].get_value();
	 case ID_HEADER_NEWSREADER:
		 return *headers[6].get_value();
	 case ID_HEADER_MSGID:
		 return *headers[7].get_value();
	 default: 
		 return "NULL";;
	 }
};
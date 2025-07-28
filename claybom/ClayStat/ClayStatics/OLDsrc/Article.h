#ifndef _ARTICLE_H
#define _ARTICLE_H

#define NICKNAME   0
#define EMAIL      1
#define GROUPS     2
#define HOUR       3
#define IP         4
#define SUBJECT    5
#define NEWSREADER 6
#define MSGID      7

#include <iostream>
#include <vector>
#include "ClayUtils.h"
#include "Pair.h"

typedef std::vector<CPair*> vtPair;

class CArticle {
    //vtPair *m_headers;
    CPair *m_headers;
    //CTime     *m_date;
    std::string m_body;
    bool   m_thread;

  public:
    CArticle() {};
    ~CArticle();
    CArticle(/*vtPair *headers*/CPair *headers, bool ref, std::string body);
    std::string toString(void) const;
    std::string toString2(void) const;
    //inline functions:
    bool    is_thread(void) const { return m_thread;  }
    std::string  get_body(void) const { return m_body;    }
//    vtPair* get_headers(void) const { return m_headers; }
    std::string  get_header(const HEADER &hdr) const;
};

#endif // _ARTICLE_H


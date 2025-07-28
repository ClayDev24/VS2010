#ifndef _PAIR_H
#define _PAIR_H

#include <string>
#include "ClayUtils.h"

static int countP = 0;

enum HEADER {
    ID_HEADER_NICK_E_EMAIL_E_GROUP = 1,
    ID_HEADER_SUBJECT_E_GROUP = 2,
    ID_HEADER_NICK_E_EMAIL = 3,
    ID_HEADER_CROSS_GROUPS = 4,
    ID_HEADER_NEWSREADER = 5,
    ID_HEADER_NICK_E_IP = 6,
    ID_HEADER_NICKNAME = 7,
    ID_HEADER_SUBJECT = 8,
    ID_HEADER_GROUPS = 9,
    ID_HEADER_HOUR = 10,
    ID_HEADER_IP = 11,
    ID_HEADER_EMAIL = 12,
    ID_HEADER_MSGID = 13
};

class CPair  
{
protected:
    HEADER m_key;
    string *m_value;
public:
    CPair() : m_key(ID_HEADER_NICKNAME) { m_value = new std::string(); }
    CPair(const HEADER &key, string *value);
    virtual ~CPair();
    HEADER get_key(void) const { return m_key; }
    string* get_value(void) const { return m_value; }
    string toString(void) const;
    void operator=(CPair pair);

    //bool operator==(CPair *x) const;
//      friend ostream & operator<< (ostream &stream , const CPair &obj) {
//	  stream << *(CPair)obj.m_key << " " << *(CPair)obj.m_value;
//	  return stream;
//      }	
};

#endif // _PAIR_H


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <iostream>

//enum HEADER { 
	//ID_HEADER_NICK_E_EMAIL_E_GROUP,
	//ID_HEADER_SUBJECT_E_GROUP,
	//ID_HEADER_NICK_E_EMAIL,
	//ID_HEADER_CROSS_GROUPS,
	//ID_HEADER_NEWSREADER,
	//ID_HEADER_NICK_E_IP,
	//ID_HEADER_NICKNAME,
	//ID_HEADER_SUBJECT,
	//ID_HEADER_GROUPS,
	//ID_HEADER_MSGID
	//ID_HEADER_HOUR,
	//ID_HEADER_IP 
//};

class CPair  
{

public:
	virtual ~CPair();

protected:
	int m_key;
	CString  *m_value;
public:
	CPair() : m_key(0) { m_value = new CString(); };
    CPair(const int key, CString *value);
    const int get_key(void) const { return m_key; }
    CString* get_value(void) const { return m_value; }
	CString toString();
	void operator=(CPair pair);
	//Often used comparison operators
	//bool operator == (CPair*) const;
	//bool operator > (CPair*) const;
	//bool operator < (CPair*) const;
    //Seldom used comparison methods
	//bool Equal(CPair*) const;
	//bool GreaterThan(CPair*) const;
    bool LessThan(CPair*) const;
};

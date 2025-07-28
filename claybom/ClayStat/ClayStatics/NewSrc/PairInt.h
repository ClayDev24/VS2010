#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Pair.h"

class CPairInt : public CPair  
{
public:
    int m_counter;	
  public:
    CPairInt();
	virtual ~CPairInt();
    CPairInt(CString *value, int count = 1);	
	CString operator =(CPairInt*) const;
    void increment_counter(void) { m_counter++; }
	int get_counter(void) const { return m_counter; }
	CString toString(void) const;
    CString toString2(void) const;
//	bool Equal(Pair*) const;
	//bool GreaterThan(CPairInt*) const;
    bool LessThan(CPairInt*) const;
};

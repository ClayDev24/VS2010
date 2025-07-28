// PairInt.h: interface for the CPairInt class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PAIRINT_H__FBF2CB30_9E74_4595_B476_289A95E8DBAA__INCLUDED_)
#define AFX_PAIRINT_H__FBF2CB30_9E74_4595_B476_289A95E8DBAA__INCLUDED_

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
	CString operator = (CPairInt*) const;
    void increment_counter(void) { m_counter++; }
	int get_counter(void) const { return m_counter; }
	CString toString(void) const;
    CString toString2(void) const;
//	bool Equal(Pair*) const;
	//bool GreaterThan(CPairInt*) const;
    bool LessThan(CPairInt*) const;
};

#endif // !defined(AFX_PAIRINT_H__FBF2CB30_9E74_4595_B476_289A95E8DBAA__INCLUDED_)

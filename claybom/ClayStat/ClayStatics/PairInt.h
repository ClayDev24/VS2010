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
	CPairInt(std::string *value, int count=1);	
	void increment_counter(void) { m_counter++; }
	int  get_counter(void) const { return m_counter; }
	std::string toString(void) const;
	std::string toString2(void) const;
	std::string operator=(CPairInt*) const;
	//bool operator==(CPairInt*) const;
	//bool Equal(Pair*) const;
	//bool GreaterThan(CPairInt*) const;
	bool LessThan(CPairInt*) const;
};

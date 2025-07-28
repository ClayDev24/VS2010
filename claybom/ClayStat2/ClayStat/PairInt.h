#ifndef _PAIRINT_H
#define _PAIRINT_H

#include "Pair.h"

class CPairInt : public CPair  
{
public:
    int m_counter;	
  public:
    CPairInt();
    virtual ~CPairInt();
    CPairInt(string *value, int count = 1);	
    void increment_counter(void) { m_counter++; }
    int get_counter(void) const { return m_counter; }
    string toString(void) const;
    string toString2(void) const;
    //string operator=(CPairInt*) const;
    //bool operator==(CPairInt*) const;
};

#endif // _PAIRINT_H

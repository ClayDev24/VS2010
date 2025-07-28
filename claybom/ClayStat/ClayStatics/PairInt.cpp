#include "PairInt.h"
#include "include_all.h"

CPairInt::CPairInt():m_counter(0) {};

CPairInt::~CPairInt()
{
    DS_("~CPairInt()...")
};//daddy handles all tha job of cleanin'...

CPairInt::CPairInt(std::string *val, int count) : CPair((HEADER)0, val) {
    m_counter = count;
};

std::string CPairInt::operator=(CPairInt *pi) const {
	char ch[5];
	return (std::string)*pi->get_value() + " " + (std::string)itoa(pi->get_counter(), ch, 10);  
};

std::string CPairInt::toString(void) const {
	return *m_value + " => " + utils::_toStr(m_counter);
};  

std::string CPairInt::toString2(void) const {
	return "(" + utils::_toStr(m_counter) + " msgs)=>" + *m_value;
};

/*
bool CPairInt::GreaterThan(CPairInt *inPair) const {
  if(m_counter < inPair->m_counter) return true;
  if(m_counter > inPair->m_counter) return false;
  return false;
};
*/
bool CPairInt::LessThan(CPairInt *inPair) const {
  if(m_counter > inPair->m_counter) return true;
  if(m_counter < inPair->m_counter) return false;
  return false;
};

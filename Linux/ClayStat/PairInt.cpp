#include "PairInt.h"

CPairInt::CPairInt() {};

CPairInt::~CPairInt()
{
    //cout << "~CPairInt()..." ;
};//dad handles all tha job of cleanin'...

CPairInt::CPairInt(string *val, int count) : CPair((HEADER)0, val) {
    m_counter = count;
};

//string CPairInt::operator = (CPairInt *pi) const {
//    return *pi->get_value() + " " + clb::int2str(m_counter);
//};

string CPairInt::toString(void) const {
    return *m_value + " => " + clb::int2str(m_counter);
};  

string CPairInt::toString2(void) const {
    return "(" + clb::int2str(m_counter) + " msgs)=>" + *m_value;
};
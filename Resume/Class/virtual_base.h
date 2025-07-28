#pragma once
#include <iostream>
int claybom;

class base {
public:
    int m_base_i; // atributo publico
};

class derived_A:public base {
public:
    int m_derived_A_i;
};

class derived_B:public base {
public:
    int m_derived_B_i;
};

class derived_level_2:public derived_A, public derived_B {
public:
    int m_derived_level_2_i;
};
// inherits from base as virtual
class v_derived_A: virtual public base {
public:
    int m_derived_A_i;
};
// inherits from base as virtual
class v_derived_B: virtual public base {
public:
    int m_derived_B_i;
};
class v_derived_level_2:public v_derived_A, public v_derived_B {
public:
    int m_derived_level_2_i;
};

static void _virtual_baseUsage() {
	derived_level_2 a;
	v_derived_level_2 v;
	// fill all attributes of object �a�
	//a.m_base_i = 1; // Erro de ambiguidade...
	a.derived_A::m_base_i = 1;
	a.derived_B::m_base_i = 5;
	a.m_derived_A_i = 2;
	a.m_derived_B_i = 3;
	a.m_derived_level_2_i = 4;
	// fill all attributes of object �v�
	v.m_base_i = 1;
	v.m_derived_A_i = 2;
	v.m_derived_A_i = 3;
	v.m_derived_level_2_i = 4;
}
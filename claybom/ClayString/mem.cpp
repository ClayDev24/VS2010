#include <cstring> // memset(), memcoy()
#include "mem.h"

// Default Constructor:
/*
clb::Mem::Mem() {
	m_memo = 0; // must set to zero to allow delete shores below (1*)
	m_size = 0;
	pointer(0);
	//DS_("Mem()...")
}*/

clb::Mem::Mem(int _sz) {
	m_memo = 0; // must set to zero to allow delete shores below (1*)
	m_size = 0;
	pointer(_sz);
	DS_(Mem()...)
}

byte* clb::Mem::pointer(int _minSz) {
	if(m_size < _minSz) {
		byte*  newmem = new byte[_minSz];
		memset(newmem + m_size, 0, _minSz - m_size);
		memcpy(newmem, m_memo, m_size);
		delete []m_memo; // (1*)
		m_memo = newmem;
		m_size = _minSz;
	}
	return m_memo;
}
#pragma once
#include <iostream>
#include "mem.h"

namespace clb {

	class CStr {
		Mem *m_buf;
	public:
		CStr():m_buf(0) {}
		CStr(char *str);
		~CStr() { delete m_buf; DS_(~CStr()...) }
		void concat(char *str);
		void print(std::ostream &os);
		char* c_str() { return (char*)m_buf->memo(); }
	};
	// ***************** <<_USAGE_>> *****************
	void CStrUsage();
};
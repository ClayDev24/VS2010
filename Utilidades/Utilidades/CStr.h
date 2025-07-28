#pragma once
#include <string>

namespace utils {

	class CStr{			
		void inflate();
		char *m_buffer;
		int   m_size; // Tamanho da zero-terminated string
		int   m_capacity;
		void start();
	public:
		CStr(const char *Phrase);
		//CStr(std::string Phrase);
		~CStr(); 
		char* get_at(int index);
		inline int  get_size() { return m_size; }
		void reset();
		friend std::ostream& operator<<(std::ostream& _os, const CStr &_c) {
			return _os << _c.m_buffer << std::endl;
		}
	};
	// ***************** <<_USAGE_>> *****************
	void CStrUsage();
	void testMemory2();

}; // utils

#pragma once
#include "utils.h"

namespace qmc {

	class Elements {
	private: // defaults to private
		int  m_a, m_b;
	protected:
	public:
		// Construtor padr�o:
		Elements():m_a(0), m_b(1) { DS_("Elements()...") /*REQUIRE()*/ } 
		Elements(const int &_a, const int &_b): m_a(_a), m_b(_b) { DS_("Elements(const int, const int)...") /*REQUIRE()*/ } 
		~Elements() { DS_("~Elements()...") }
		// Opera��es:
		// (...)
		// Streamming de sa�da:
		friend std::ostream& operator<<(std::ostream& _os, const Elements &_e) {
			//_os << _e.m_a << "/" << _e.m_b;
			//return _os;
		}
	};
	// **************<<_USAGE_>>****************
	void _elementsUsage();// {
//		Elements e;
//	}

} // qmc
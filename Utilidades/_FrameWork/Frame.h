#pragma once
#include <iostream>
#include "utils.h"

namespace utils {

	enum colour { RED, BLUE, YELLOW, GREEN }; // Same as assining names to ints	

	class Frame {
	private: // defaults to private
		int    m_a, m_b;
		bool   m_bool;
		double m_double;
	protected:
	public:
		// Construtor padr�o:
		Frame():m_a(0), m_b(1), m_double(0.0) { }//DS_("Frame()...") /*utils::require()*/ } 
		Frame(const int &_a, const int &_b): m_a(_a), m_b(_b) { }//DS_("Frame(const int, const int)...") /*utils::require()*/ } 
		//~Frame() { DS_("~Frame()...") }
		// Opera��es:
		// (...)
		// Streamming de sa�da:
		friend std::ostream& operator<<(std::ostream& _os, const Frame &_f) {
			_os << _f.m_a << "/" << _f.m_b;
			return _os;
		}
	};
	// **************<<_USAGE_>>****************
	static void _frameUsage() {
		Frame f;
	}

} // utils
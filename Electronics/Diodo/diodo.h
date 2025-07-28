#pragma once
#include <iostream>

namespace elect {

	enum colour { RED, BLUE, YELLOW, GREEN }; // Same as assining names to ints	

	class Diodo {
	private: // defaults to private
		int    m_a, m_b;
		bool   m_bool;
		double m_double;
	protected:
	public:
		// Construtor padrão:
		Diodo():m_a(0), m_b(1), m_double(0.0) { }//DS_("Diodo()...") /*utils::require()*/ } 
		Diodo(const int &_a, const int &_b): m_a(_a), m_b(_b) { }//DS_("Diodo(const int, const int)...") /*utils::require()*/ } 
		//~Diodo() { DS_("~Diodo()...") }
		// Operações:
		// (...)
		// Streamming de saída:
		friend std::ostream& operator<<(std::ostream& _os, const Diodo &_d) {
			_os << _d.m_a << "/" << _d.m_b;
			return _os;
		}
	};
	// **************<<_USAGE_>>****************
	static void _diodoUsage() {
		Diodo d1;
	}

} // elect
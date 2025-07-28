#pragma once
#include <vector>
#include "utils.h"

namespace math {

	class Monomio {
	private: // defaults to private
		std::string m_term;
		bool        m_sign; // true/false (+ / -)
		signed int  m_coeficient;
		signed int  m_exponent;
		std::vector<char> m_incognitas;

	protected:
	public:
		// Construtor padrão:
		Monomio(): m_term(""), m_sign(true), m_coeficient(1), m_exponent(1) { DS_("Monomio()...") /*REQUIRE()*/ }
		Monomio(std::string _s);
		~Monomio() { DS_("~Monomio()...") }
		// Operações:
		void evaluate();
		void evaluate2();
		// Streamming de saída:
		friend std::ostream& operator<<(std::ostream& _os, const Monomio &_m) {
			_os << _m.m_term;
			return _os;
		}
	};
	// **************<<_USAGE_>>****************
	static void _monomioUsage() {
		// Gerador de monômios:
		for(int i=0; i<10; i++) {
			std::string s="";
			if(i%2)
				s+="-";
			//s += utils::_randomWords(utils::_random(0, 9), '0', '9');
			s += utils::_randomWords(utils::_random(0, 3), 'a', 'z');
			s += "^2";
			//s += utils::_randomWords(utils::_random(0, 3), 'a', 'z');+
			Monomio M(s);
			P_(M)
		}
	}

} // math
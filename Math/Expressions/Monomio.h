#pragma once
#include "include_all.h"

namespace math {
	// Monômio=> Em álgebra, monõmio é um único termo, podendo conter letras (variáveis) e números (coeficientes).
	class Monomio { // defaults to private:
		signed int m_coeficiente;
		char m_incognita;
		char m_signal;
		void evaluate() {
			P_(utils::_strTo<int>("123"))
			std::string s = "ABC/0123456789:abc";//+m_incognita;
			for(unsigned int i=0; i<s.length(); i++) {
				P_(s.at(i))
				if((s.at(i) >= '0') && (s.at(i) <= '9')) 
					std::cout << "NUMBER\n";
				else
					std::cout << "NOT\n";
			}
			P_(utils::_strTo<int>(s.c_str()))
		}
	public:
		// default constructor:
		Monomio():m_coeficiente(0), m_incognita('x'), m_signal('*') { evaluate(); }
		Monomio(int _c, char _i='x', char _s='*'):m_coeficiente(_c), m_incognita(_i), m_signal(_s) {}
		~Monomio() {}
		friend std::ostream& operator<<(std::ostream& _os, const Monomio &_m) {
			_os << _m.m_coeficiente;
			if(_m.m_signal != '*')
				_os << _m.m_signal;
			_os << _m.m_incognita;
			return _os;
		}
		std::string label() {
			return std::string("Monômio=> Em álgebra, monõmio é um único termo, podendo conter letras (variáveis) e números (coeficientes).");
		}
	};
	// **************<<_USAGE_>>****************
	void _monomio() {
		using namespace std;
		utils::_setLocale();

		Monomio m1;
		Monomio m2(5);
		
		utils::PrintColour_(m1.label().c_str(), FRI); 

		P_(m1)
		P_(m2)

		//Monomio m3(-13, 'y',
	}

} // math
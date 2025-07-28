#pragma once
#include <vector>
#include "Monomio.h"
#include "utils.h"

namespace math {

	class Expressao {
	private: // defaults to private
		std::vector<Monomio> m_terms;
	protected:
	public:
		// Construtor padrão:
		Expressao() {
			DS_("Expressao()...") /*REQUIRE()*/
		}
		Expressao(std::string _s);
		~Expressao() { DS_("~Expressao()...") }
		// Operações:
		// (...)
		// Streamming de saída:
		friend std::ostream& operator<<(std::ostream& _os, const Expressao &_e) {
			for(unsigned int i=0; i < _e.m_terms.size(); i++)
				_os << _e.m_terms[i] << " / ";
			return _os;
		}
	};
	// **************<<_USAGE_>>****************
	static void _expressaoUsage() {
		// Expressão do 1 grau:
		Expressao E1("235a + 347b");
		// Expressão Quadrática (2 grau)
		//Expressao E("x^2 + 3x + 8");
		P_(E1)
	}

} // math
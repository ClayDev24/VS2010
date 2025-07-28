#pragma once
#include <iostream>
#include "fracao.h"

namespace mat {

	class Porcentagem {
	private:
		int    m_a, m_b;
		bool   m_propria;
		int    m_taxaPercentual;
		double m_taxaUnitaria;
		
	protected:
	public: // Porcentagem é uma RAZÃO Centesimal/Percentual especial com consequente 100.
			// Ex.: 25/100 = 0,25 = 25%. Onde:
			// 25/1000   (Razão centesimal/percentual)
			// 0,25 (Taxa Unitária / fator de multiplicação)
			// 25%  (Taxa Percentual)
		    // Em porcentagem as grandezas são sempre Diretamente Proporcionais.
		Porcentagem()  { std::cout << "Porcentagem()..." << std::endl;  }
		Porcentagem(const int &A, const int &B);
		~Porcentagem() { std::cout << "~Porcentagem()..." << std::endl; }
		// Operações:
		friend std::ostream& operator<<(std::ostream& _os, const Fracao &_f) {
			//_os << m_a << "/" << m_b;
			//return _os;
		}
	};
	// **************<<_USAGE_>>****************
	void _porcentagem() {

	}

} // mat
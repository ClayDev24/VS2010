#pragma once
#include <iostream>
#include "..\Fracoes\fracao.h"
#include "defines.h"

namespace math {
	// Probabilidade=> É o cálculo da chance de um determinado evento ocorrer. Foco de estudo: Experimentos aleatórios. (contrário de experimentos determinísticos. Ex.: determinar o tempo de queda de um objeto)
	// Experimento aleatório=> Depende do acaso. O resultado é imprevisível.
	// Ex.: lançamento de dados/moedas/cartas, etc.
	// Espaco amostral=> Conjunto de todos os resultados possíveis (representado pela letra grega ômega). Tem de ser
	// equimostrável (todos os elementos tem a mesma chance de ocorrer)
	// 0 <= P <= 1 Sempre na faixa entre 0 e 1 (ou 0% - 100%)

	class Probabilidade {
		Fracao m_f;    
		double m_Pe;     // Probabilidade
		double m_events; // n. elementos do EVENTO / CASOS FAVORÁVEIS (n(e))
		double m_omega;  // n. de elementos do ESPAÇO AMOSTRAL / N. TOTAL (n(o)) (usar análise combinatória para calcular)
		
	public:
		Probabilidade(const double &_e, const double &_o):m_Pe(0), m_events(_e), m_omega(_o) { start(); }
		~Probabilidade() {}
		inline void start() {
			// Probabilidade é o n. de casos FAVORÁVEIS (n(e)) dividido pelo n. de TOTAL eventos do ESPAÇO AMOSTRAL (n(o)):
			m_Pe = m_events / m_omega;
		}
		friend std::ostream& operator<<(std::ostream& _os, const Probabilidade &_p) {
			_os << _p.m_Pe;
			return _os;
		}
	};

	static void _probabilidade() {
		std::cout << "_probabilidade()...\n";
	}
	// **************<<_USAGE_>>****************
	static void _probabilidadeUsage() {
		using namespace std;
		// probabilidade de um dado cair num n. primo
		// Espaçao amostral = 6 - ômega (Um dado tem 6 faces logo o total de possibilidades é 6)
		// n. de eventos = {2, 3 e 5} 3 ns. primos,logo n(e)=3
		Probabilidade p(3,6);
		cout << p << endl;
		// Problema 2:
		// Jogamos 2 dados comuns e somamos. Ql a probabilidade de sair a soma 8?
		// Espaço amostral => 6 possibilidades combinatórias do dado1 e 6 do dado2. 6 e 6 = 6 x 6= 36      n(o)=36 ômega
		// n. de eventos   => 5 combinações possíveis p/ a somatória 8 {(3,5), (5,3), (2,6), (6,2), (4,4)} n(e)=5
		Probabilidade p2(5,36);
		cout << p2 << endl;		
		//_probabilidade();
	}
} // math
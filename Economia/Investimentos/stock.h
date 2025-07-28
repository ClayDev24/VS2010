#pragma once
#include <windows.h> // SetConsoleOutputCP(65001); // para acentuação correta no console
#include <iostream>
#include "utils.h"
//#include "_colour.h" // utils::PrintColour()

// Ações Ordinárias (ON)
// Ações Unit       (

namespace economy {

	class Cota { // Ação
	private: // defaults to private
		double  m_value;

	protected:
	public:
		// Construtor padrão:
		Cota():m_value(0.0) { } //DS_("Cota()...") /*utils::require()*/ } 
		Cota(const double &value): m_value(value) { }//DS_("Cota(const int, const int)...") /*utils::require()*/ } 
		~Cota() { /*std::cout << "~Cota()..." << std::endl;*/ }
		// Operações:
		// (...)
		// Streamming de saída:
		// *Função para calcular o Magic Number em Fundos Imobiliários (FIIs)
		double magicNumber(double dividendYield, double cota = 0) {
			double magicNumber = 0;
			if(dividendYield <= 0) {
				std::cerr << "Erro: O rendimento por cota deve ser maior que zero." << std::endl;
				return -1.0; // Valor inválido
			}
			if(cota == 0)
				magicNumber = m_value / dividendYield;
			else 
				magicNumber = cota / dividendYield;

			return magicNumber;
		}
		friend std::ostream& operator<<(std::ostream& _os, const Cota &cota) {
			_os << cota.m_value << std::endl;
			return _os;
		}
	};
	// **************<<_USAGE_>>****************
	static void _cotaUsage() {
		using namespace std;
		utils::dicShow("economy", "Número Mágico");

		Cota cota(9.17); // valor da ação/cota
		P_(cota.magicNumber(0.10))
	}

} // utils
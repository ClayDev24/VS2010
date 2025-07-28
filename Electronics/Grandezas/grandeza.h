#pragma once
#include <iostream>
#include "utils.h"

#include <iomanip>
#include <limits> // Para ter a máxima precisão
namespace elect {

enum grandeza {
		  // Sistema Métrico Internacional (S.I.):
		  Comprimento=0,
		  Massa,
		  Tempo,
		  CorrenteEletrica,
		  TemperaturaTermodinamica,
		  IntensidadeLuminosa,
		  QuantidadedeMateria,
		  // Derivadas do S.I.:
		  Energia,
		  Forca,
		  Potencia,
		  CargaEletrica,
		  PotencialEletrica,
		  ResistênciaEletrica,
		  CondutânciaEletrica,
		  CapacitânciaEletrica,
		  IndutânciaEletrica,
		  Frequencia,
		  FluxoMagnetico,
		  DensidadeDeFluxoMagnetico
};

enum prefixos {
	YOCTO=0,
	ZEPTO,
	ATTO,
	FEMTO,
	PICO,
	NANO, 
	MICRO,
	MILLI,
	UM,//=8
	QUILO,
	MEGA,
	GIGA, 
	TERA, 
	PETA, 
	EXA, 
	ZETA,
	YOTA
};

static char* prefixos2[] = {
	"Yocto",
	"Zepto",
	"Atto",
	"Femto",
	"Pico",
	"Nano",
	"Micro",
	"Milli",
	"",
	"Quilo",
	"Mega",
	"Giga",
	"Tera",
	"Peta",
	"Exa",
	"Zeta",
	"Yota"
};

	class Grandeza {
	private: // defaults to private
		grandeza m_g;
		double   m_val;
		int      m_prefix;
		double   matrix[17];
		char *   matrix2[17];

		void initMatrix() {
			for(int i=m_prefix; i>=YOCTO; i--)
				m_val *= 1000;
			for(int i=0; i<=16; i++)
				matrix[i] = m_val /= 1000;
			initMatrix2();
		}
		void initMatrix2() {
			using namespace std;
			string point(".");
			string b4, after;

			string s = utils::_toStr(matrix[UM]);
			utils::Tokenizer token(s.c_str(), ".");

			int sz = token.get_size();
			if(sz==2) {
				for(int i=0; i<token.get_size(); i++)
					cout << token.get_at(i) << endl;
			} else if(sz==1) {
				P_(token.get_size())
			} else // Exception > 2
				cout << "tokens size > 2: " << sz << endl;

			//P_(s);
			//P_(matrix[UM])
		}
	protected:
	public:
		// Construtor padrão:
		Grandeza():m_g(Comprimento), m_val(0.0), m_prefix(UM) { initMatrix(); }// utils::require()*/ } 
		Grandeza(const grandeza &_g, const double &_v, const int &_p=8): m_g(_g), m_val(_v), m_prefix(_p) {
			initMatrix();
		}

		//~Grandeza() { DS_("~Grandeza()...") }
		// Operações:
		void printPrefix(prefixos p) {
			using namespace std;
			cout << matrix[p] << " " << prefixos2[p] << endl;
		}
		void printAll() {
			for(int i=YOCTO; i<=YOTA; i++)
				std::cout << matrix[i] << " " << prefixos2[i] << std::endl;
		}
		// Streamming de saída:
		friend std::ostream& operator<<(std::ostream& _os, const Grandeza &_g) {
			_os << _g.matrix[UM] << " " << prefixos2[UM] << std::endl; // Valor padrão
			return _os;
		}
	};
	// **************<<_USAGE_>>****************
	static void _grandezaUsage() {
		// Testing default constructor:
		//Grandeza g;
		//P_(g)

		Grandeza g1(DensidadeDeFluxoMagnetico, 33.21, UM); // (grandeza, valor, prefixo) 
		//g1.printPrefix(MILLI);
		//g1.printAll();
		//P_(g1)
	}
	static void _grandezaTest() {
		//for(int i=0; i<10; i++) {
		for(int i=YOCTO; i<=YOTA; i++) {
			Grandeza g1(DensidadeDeFluxoMagnetico, 2, i);//utils::_random(1, 5), UM);
			g1.printAll();
		}
	}

} // elect

#pragma once
#include <iostream>
#include <iomanip>  // std::setprecision()
#include <string>
#include "utils.h"
void _stripeTable();

namespace elect {

	class CResistor {
		int    stripe[5];
		int    m_size;
		double m_tolerance;
		double m_resistance;
		// Prata (10%) e Ouro(5%) (4 faixas - filme de carbono)
		// Preto ou sem cor (20%)
		// Marrom(1%), vermelho(2%), verde(0.5%), azul(0,25%) e violeta(0,1%) (5 faixar - filme metálico)
		float m_power; // Potência nominal (em Watts). Indica a máxima dissipação de potência que um resistor suporta sem queimar.
		float m_faixa_ohmica_maior;
		float m_faixa_ohmica_menor;
		//float m_working_voltage;
		void initConstructor(const int &_v0, const int &_v1, const int &_v2, const int &_v3, const int &_v4);
		void fillStripe(const int &Tolerance);
		void makeTolerance();
	public:
		CResistor(double Resistance=0): m_resistance(Resistance), m_size(5)       { fillStripe(0);   } // Preenche stripes 0, 1, 2 e 3
		CResistor(double Res, int Sz, int Tol = -1):m_resistance(Res), m_size(Sz) { fillStripe(Tol); } // tolerancia padrão -1 = gold
		CResistor(const int &v0, const int &v1, const int &v2, const int &v3, const int &v4):m_size(5) { initConstructor(v0,v1,v2,v3,v4); }
		CResistor(const int &v1, const int &v2, const int &v3, const int &v4):m_size(4)                { initConstructor(0, v1,v2,v3,v4); } // Se não tiver faixa a tolerância padrão é 20% (stripe4 = 0)
		~CResistor() {}
		std::string prtGrandeza();
		int    signDigits() const { return ((stripe[0]*100)+(stripe[1]*10)+(stripe[2])); }
		double multiplier() { return utils::_pow(10.0, stripe[3]); }
		double resistance() const { return m_resistance; }
		double tolerance()  const { return m_tolerance;  }
		double ohmic_higher();
		double ohmic_lower();
		double ohmic_percentage();

		void print() {
			//printf("%1.3f ohm\n", m_resistance);
			std::cout << "Resistance: " << std::setprecision(13) << prtGrandeza() << std::endl;//<< " ohm\n";
		}
		static void showRegTABLE(const int &v0, const int &v1, const int &v2, const int &v3, const double &_tol);
		void showStripes();
		//void tolerance(float t);

		const CResistor operator+(const CResistor &_r) const {
			return CResistor(m_resistance + _r.m_resistance);
		}

		const bool operator==(CResistor &_r) const {
			return this->resistance() == _r.resistance();
		}

		const bool operator>(CResistor &_r) const {
			return this->resistance() > _r.resistance();
		}

		const bool operator<(CResistor &_r) const {
			return this->resistance() < _r.resistance();
		}

		friend std::ostream & operator<<(std::ostream & os, const CResistor & _r) {
			os << std::setprecision(15) << _r.m_resistance;
			return os;
		}
	};
	// **************<<_USAGE_>>****************
	void printReg(CResistor _r);
	void resistorUsage();

} // elect


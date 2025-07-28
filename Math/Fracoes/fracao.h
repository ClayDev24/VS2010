#pragma once

namespace math {
	// Tipos de FRAÇÕES:
	// Própria   => Numerador < denominador
	// Imprópria => Numerador > denominador
	// Aparente  => É uma fração imprópria com divisão exata: 4/2 = 2
	// Fração Equivalente: Representam a mesma parte do todo. 1/2 e 2/4 = 0,5
	// Fração Decimal:     São frações onde os denominadores são potências de 10. "Ex.: 5/10 (cinco décimos)."

	// Inverso Multiplicativo=> Qndo vc inverte uma fração: 1/2=0.5 e 1/0.5=2
	// Simplificação / redução=> uma fração a/b é irredudível qndo o mdc(a, b)=1. (Ou seja qno o numerador e o denominador são primos entre si)
	class Fracao {
	private:
		int    m_numerador, m_denominador;
		int    m_integer; // if impropria
		double m_periodic;
		double m_decimal;
		bool   m_propria;
		void setDecimal(bool Periodic=false);
	protected:
	public:
		// Construtor padrão:
		Fracao():m_numerador(0), m_denominador(1), m_propria(true), m_integer(0), m_decimal(0.0) {}
		Fracao(const double &Decimal);
		Fracao(const int    &Numerador, const int &Denominador);
		Fracao(const int    &Integer,   const int &Numerador, const int &Denominador);
		~Fracao() { std::cout << "~Fraçao()..." << std::endl; }
		void setFracao(const int &Numerador, const int &Denominador);
		// Operações:
		void divisao();
		void multiplica();
		void soma(const Fracao &Right);
		void subtracao(const Fracao &Right);
		void power(const int &Expoente);
		inline void setPeriodic(bool _p=true) {
			setDecimal(_p);
		}
		
		Fracao equivalente(const int &Multiplicador);
		bool simplify();  // Simplificação / Redução=> Qndo o MDC(num, den)=1
		bool simplify2(); // Versão didática
		bool setMisto();  // Converts an improper fraction to a mist number.
		bool impropria(); // Converts a mist number to an improper fraction.
		inline bool  getPropria()     { return m_propria;  }
		inline int   getInteger()     { return m_integer;  }
		inline double getDecimal()    { return m_decimal;  }
		inline double getPeriodic()   { return m_periodic; }
		inline double getPercentage() { return m_decimal*100; }
		inline int getNumerador() const { return m_numerador; }
		inline int getDenominador() const { return m_denominador; }
		// Razão Centesimal / percentual:
		inline void setRazaoPercentual() {
			double d = m_decimal*100;
			//P_(d)
			Fracao f(2.5);
			//P_(f)
		}
		// **********<__SOBRECARGA DE OPERADORES_>>**********
		Fracao& operator=(const Fracao &_right);
		const Fracao operator+(const Fracao &_right);
		const Fracao operator-(const Fracao &_right);
		const Fracao operator*(const Fracao &_right);
		const Fracao operator/(const Fracao &_right);
		bool operator==(const Fracao &_right);
		bool operator>(const Fracao &_right);
		bool operator<(const Fracao &_right);
		friend std::ostream& operator<<(std::ostream& _os, const Fracao &_f);
	};
	// **************<<_USAGE_>>****************
	void _fracaoUsage();

} // mat
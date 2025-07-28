#pragma once
#include <complex>
#include "utils.h"
#include "..\Math\_divisores.h"
#include "..\Math\_root.h"

namespace math {
	// A radiciação é a operação inversa da potenciação
	// 2. Raiz quadrada de um quadrado perfeito:
	// √a^2 = |a|  Onde |a| = { +a, se a>=0, -a, se a<0
	// o valor de a tanto pode ser positivo qnto negativo. Apesar de que o valor resultante da
	// expressão em si sempre ser positivo.
	// Ex.: √49 = 7
	//     √-49 = 7
	class Radical {
	private: // defaults to private
		double m_indice;
		double m_radicando;
	protected:
	public:
		// Construtor padrão:
		Radical():m_indice(0), m_radicando(1) { DS_("Radical()...") /*REQUIRE()*/ } 
		Radical(const double &_i, const double &_r): m_indice(_i), m_radicando(_r) { DS_("Radical(const int, const int)...") /*REQUIRE()*/ } 
		~Radical() { DS_("~Radical()...") }
		// Operações:
		// (...)
		double evaluate();
		// Streammingde saída:
		friend std::ostream& operator<<(std::ostream& _os, const Radical &_r) {
			_os << "sqr(" << _r.m_indice << ", " << _r.m_radicando << ")";
			return _os;
		}
	};

	static int square(const int &_n) {
		int dig = _n%10;
		int dig2= _n;
		if(dig==2 || dig==3 || dig==7 || dig==8) 
			return 0;
		int digs[2];
		MEMSET(digs,2)

		int base =0;
		int index=0;
		while(index<2) {
			++base;
			int sqr=base*base;
			sqr%=10;
			//P_(sqr)
			if(sqr==dig)
				digs[index++] = base;
		}
		dig2/=100;
		//P_(dig2)
		base=0;
		while(true) {
			int sqr=++base*base;
			if(dig2<sqr)
				break;
		}
		--base;
		//base*=(base+1);
		//P_(base)
		if(dig>base*base)
			return (base*10+digs[0]);
		else
			return (base*10+digs[1]);
		//P(digs[0])
		//P(digs[1])
		return 1;
	}
	// Retorna todas as combinações de simplificação de raízes quadradas:
	static void simplify(const int &_n) {
		using namespace std;
		int sqr1, sqr2;
		P_(_n)
		vetorInt vi = math::_divisores(_n);
		int sz = vi.size();
		utils::_showVetor(vi);
		
		for(int i=1; i<sz/2; i++) {
			sqr1 = vi.at(i);
			sqr2 = vi.at(0) / vi.at(i);
			if(math::_isSquare(sqr1) && math::_isSquare(sqr2))
				cout << setw(8) << sqrt(static_cast<double>(sqr1)) << setw(8) << "x (" << sqrt(static_cast<double>(sqr2)) << ")\n";
			else if(math::_isSquare(sqr1))
				cout << setw(8) << sqrt(static_cast<double>(sqr1)) << setw(8) << "x sqr(" << sqr2 << ")\n";
			else if(math::_isSquare(sqr2))
				cout << setw(8) << sqrt(static_cast<double>(sqr2)) << setw(8) << "x sqr(" << sqr1 << ")\n";
			else // nenhum square n.:
				cout << "sqr(" << setw(4) << sqr1 << ")" << setw(7) << " x sqr(" << sqr2 << ")\n";
		}
	}
	static void toExponent(const int &radical, const int &raiz=2, const int &exponent=1) {
		std::cout << "raiz(" << raiz << ") de " << radical << "^" << exponent << "\n";
		std::cout << radical << "^" << exponent << "/" << raiz << std::endl;
	}
	static void toExponent2(const int &numerador, const int &radical, const int &raiz=2, const int &exponent=1) {
		std::cout << numerador << "/ (raiz(" << raiz << ") de " << radical << "^" << exponent << ")\n";
		std::cout << radical << "^" << exponent*-1 << "/" << raiz << std::endl;
	}
	static void Exponent2Raiz(const int &base, const int &ExpoNum, const int &ExpoDen) {
		std::cout << base << "^" << ExpoNum << "/" << ExpoDen << "\n";
		//std::cout << radical << "^" << exponent*-1 << "/" << raiz << std::endl;
	}
	// **************<<_USAGE_>>****************
	static void radicalUsage() {

		utils::Console cmd(80, 20000);
		utils::PrintColour_("<<_Square_Root>>", FGI);
		// Raízes quadradas de zero à 25:
		for(int radicando=0; radicando<=1000000; radicando++) {

			Radical r(radicando, 1.0/2.0);
			double raiz = r.evaluate();

			double intPart, fractPart;
			fractPart = modf(raiz, &intPart);

			if(fractPart==0) {
				P_(radicando)
				//P_(raiz)
			}
			//P_(intPart)
			//P_(fractPart) N
		
		}
		P_(-8)
		Radical r(125, 1.0/3.0);
		r.evaluate();

		P_(sqrt(1024.0))
		double negativeNumber = -49;
		std::complex<double> number( negativeNumber, 0 );
		std::complex<double> result = sqrt( number );
		double realpart = result.real();

		P_(result)
		P_(realpart)
/*
		P_(square(1))
		P_(square(4))
		P_(square(9))
		P_(square(16))
		P_(square(25))
		P_(square(36))
		P_(square(10404))
		//}

		clb::PrintColour_("<<_Simplify_>>", FGI);
		radical::simplify(72);
		radical::simplify(50);

		clb::PrintColour_("<<_Radical to Exponent_>>", FGI);
		radical::toExponent(6);
		radical::toExponent(1,3,1);
		radical::toExponent(7,2,5);
		radical::toExponent(1,4,3);

		clb::PrintColour_("<<_Radical to Exponent2_>>", FGI);
		radical::toExponent2(1,1,2,1);
		radical::toExponent2(1,1,4,3);

		clb::PrintColour_("<<_Exponent to raiz_>>", FGI);
		radical::Exponent2Raiz(8,4,3);
		*/
	}
} // math

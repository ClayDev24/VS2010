#pragma once
#include "utils.h"
#include "mat.h"

namespace math {

	class Dizima {
	private: // defaults to private
		std::string  m_dizima;
//		Fracao *m_fracao;
		int     m_integer;
		int     m_periodo;
		int     m_intruder;
		void    parser();
		void    scan(std::string scan, std::string str);
	public:
		// Construtor padrão:
		Dizima():m_dizima("0.0"), m_periodo(0), m_intruder(0), m_integer(0) {
			DS_("Dizima()...") /*utils::require()*/
			parser();
		} 
		Dizima(const std::string &_d): m_dizima(_d), m_periodo(0), m_intruder(0), m_integer(0) {
			DS_("Dizima(const std::string &_d)...")
			parser();
			//m_fracao = new Fracao(_d);
		}//DS_("Dizima(const int, const int)...") /*utils::require()*/ } 
		~Dizima() { DS_("~Dizima()...") }
		// Operações:
		// (...)
		// Streamming de saída:
		void /*fração*/geratriz(double _dizima) {
			std::cout << "dizima periódica: " << _dizima << std::endl;
		}
		friend std::ostream& operator<<(std::ostream& _os, const Dizima &_d) {
			_os << _d.m_dizima;
			return _os;
		}
	};
	// **************<<_USAGE_>>****************
	static void _testDizima();

	static void _dizimaUsage() {

		utils::dicShow("mathematics", "Dízima Periódica");
		std::cout << "\n\n";
		// Dízima Periódica é um n. decímal onde um n. sempre está se repetindo após a vírgula: 0,45454545
		for(int i=1; i<=10; i++) {
			float f = static_cast<float>(i);
			std::cout << static_cast<float>(1/f) << std::endl;
		}
		// Classificação:
		// Simples:  Ex.: 1,424242...  (42 = período)
		// Composto: Ex.: 1,3424242... (3 não faz parte do período)

		// Fração Geratriz (fração que gera a dízima periódica
		// Ex.: 0,2222... (2 é o período)
		// 2/9
		//geratriz(0.111);
		Dizima d1;
		P_(d1);
		Dizima d2("489.250250250");//0.25);
		P_(d2)

		//_testDizima();
	}

	static void math::_testDizima() {
		for(int i=0; i<10; i++) {
			double d = utils::_random(1, 100);
			d /=10;
			std::string str = utils::_toStr<double>(d);
			Dizima diz(str.c_str());
			P_(diz)
		}
	}

} // math
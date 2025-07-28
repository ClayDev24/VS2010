//#include "fracao.h"
#include "utils.h"
#include "mat.h"
#include "testFrac.h"
//#include "..\Math\_mdc.h"
//#include "..\Math\_mmc.h"
//#include "..\Math\_fatoresPrimos.h"

math::Fracao::Fracao(const int &_num, const int &_den):m_numerador(_num), m_denominador(_den), m_integer(0) { REQUIRE(_den != 0)
	if(_num >= _den)
		m_propria = false; // imprópria
	else
		m_propria = true;  // própria

	m_periodic = false;
	setDecimal();
}
math::Fracao::Fracao(const double &_dec):m_decimal(_dec), m_integer(0) {

	//using namespace std;
	//double x = 14.86;

	//double intPart, fractPart;
	//fractPart = modf(x, &intPart);
	//cout << x << " = " << intPart << " + " << fractPart << endl;


	if(_dec < 0)
		m_propria = false; // imprópria
	else
		m_propria = true; // própria
	//0,25
	//250000000
	int i = 1000000000;
	int in = static_cast<int>(_dec*i);
	while(!(in%10)) {
		in /=10;
		i  /=10;
	}
	//PRT_(i)
	m_numerador   = static_cast<int>(_dec*i);
	m_denominador = i;

	m_periodic = false;
	setDecimal();
}
// ***************<<_Fração Mista->>****************
math::Fracao::Fracao(const int &_int, const int &_num, const int &_den):m_integer(_int), m_numerador(_num), m_denominador(_den) { REQUIRE(_den != 0)
	m_propria     = false; // imprópria
	if((_int==0) && (_num < _den)) {
		m_propria = true; // própria
	}
	m_periodic = false;
	setDecimal();
}
void math::Fracao::setFracao(const int &_num, const int &_den) {
	m_numerador   = _num;
	m_denominador = _den;
	if(_num >= _den)
		m_propria = false; // imprópria
	else
		m_propria = true;  // própria
	m_integer=0;

	setDecimal();
}
void math::Fracao::power(const int &_exp) {
	int n = m_numerador;
	int d = m_denominador;
	for(int i=0; i<_exp; i++) {
		m_numerador   *= n;
		m_denominador *= d;
	}
}
// Simplificação / Redução: Uma fração é irredutível qndo o numerador e o denominador são primos entre si. Ou seja, mdc=1
bool math::Fracao::simplify() { // Irredutível=> A fração que não pode ser simplificada.
	int n = m_numerador;
	int d = m_denominador;
	if(m_numerador && m_denominador) {
		int MDC = math::_mdc(2, m_numerador, m_denominador);
		m_numerador   /= MDC;
		m_denominador /= MDC;
	}
	if(n==m_numerador && d==m_denominador)
		return true;
	return false;
}
bool math::Fracao::simplify2() {
	using namespace std;
	vetorULLng vl1 = math::_fatoresPrimos2(m_numerador);
	vetorULLng vl2 = math::_fatoresPrimos2(m_denominador);
	utils::_showVetor(vl1);
	utils::_showVetor(vl2);

	vetorULLng vl3 = utils::vetorComparison(vl1, vl2, "match");
	cout << setw(4) << m_numerador;
	for(unsigned int i=0; i<vl1.size(); i++) {
		cout << setw(4) << vl1[i];
	}
	cout << " = " << endl;

	return false;
}
// Toda fração com um n. inteiro no numerador e no denominador tem um equivalente decimal:
void math::Fracao::setDecimal(bool _periodic) {
	m_periodic = 0;
	Fracao f1 = *this;
	double n, d;
	if(!m_propria) {// imprópria
		f1.impropria();
		n = f1.m_numerador;
		d = f1.m_denominador;
	} else { // própria:
		n = m_numerador;
		d = m_denominador;

		if(_periodic) {			  // se denominador = multiplo de 10 (100, 1000...)
			if(!(m_denominador%10)) {
				m_periodic = m_denominador;
				d = m_periodic-1; // 9 (99, 999...)
				m_denominador=static_cast<int>(d);
			}
		}

	}
	m_decimal = n / d;
}
bool math::Fracao::impropria() {
	if(!m_propria) { // imprópria
		//if(atributos negativos) // to be implemented yet.
		m_numerador = abs(m_integer) * abs(m_denominador) + abs(m_numerador);
		m_decimal = 0;
		m_integer = 0;
		return true;
	}
	return false;
}
bool math::Fracao::setMisto() {
	if(!m_propria) { // imprópria	
		m_integer   = m_numerador / m_denominador;
		m_numerador = m_numerador % m_denominador;
		m_decimal = 0;
		return true;
	}
	return false;
}
math::Fracao math::Fracao::equivalente(const int &_m) { //REQUIRE((_m>0))
	if(!m_propria)
		impropria();
	simplify();
	m_numerador   *= _m;
	m_denominador *= _m;

	return Fracao(m_numerador,m_denominador);
}
// Método fácil (soma subtração):
void math::Fracao::soma(const Fracao &_right) {
	Fracao f1 = *this;
	Fracao f2 = _right;
	f1.impropria();
	f2.impropria();
	// numerador = multiplicação cruzada:
	m_numerador   = (f1.m_numerador * f2.m_denominador) + (f1.m_denominador * f2.m_numerador);
	m_denominador = f1.m_denominador * f2.m_denominador; // denominador = multiplicação dos denominadores.
	if(m_numerador > m_denominador)
		m_propria = false; // imprópria
	setDecimal();
	simplify();
	//return f1;
}
void math::Fracao::subtracao(const Fracao &_right) {
	Fracao f1 = *this;
	Fracao f2 = _right;
	f1.impropria();
	f2.impropria();
	// numerador = multiplicação cruzada:
	m_numerador   = (f1.m_numerador * f2.m_denominador) - (f1.m_denominador * f2.m_numerador);
	m_denominador = f1.m_denominador * f2.m_denominador; // denominador = multiplicação dos denominadores.
	// Subracão de fração nunca resultamem frações impróprias. (a não ser que sejam duas frações impróprias)
	setDecimal();
	simplify();
	//return f1;
}
// **********<__SOBRECARGA DE OPERADORES_>>**********
math::Fracao& math::Fracao::operator=(const Fracao &_right) {
	// Handle self-assignment:
	if(this == &_right)
		return *this;

	m_numerador   = _right.m_numerador;
	m_denominador = _right.m_denominador;
	m_integer     = _right.m_integer;
	m_decimal     = _right.m_decimal;
	m_propria     = _right.m_propria;
	return *this;
}
const math::Fracao math::Fracao::operator+(const Fracao &_right) {
	Fracao f1 = *this;
	Fracao f2 = _right;
	f1.impropria();
	f2.impropria();
	int MMC  = math::_MMC(2, f1.m_denominador, f2.m_denominador);
	int num1 = MMC / f1.m_denominador * f1.m_numerador;
	int num2 = MMC / f2.m_denominador * f2.m_numerador;
	Fracao res(num1 + num2, MMC);
	if(m_numerador > m_denominador)
		m_propria = false; // imprópria
	res.setDecimal();
	res.simplify();

	return res;
}
const math::Fracao math::Fracao::operator-(const Fracao &_right) {
	Fracao f1 = *this;
	Fracao f2 = _right;
	if(!m_propria) {
		f1.impropria();
		f2.impropria();
	}
	int MMC  = math::_MMC(2, f1.m_denominador, f2.m_denominador);
	int num1 = MMC / f1.m_denominador * f1.m_numerador;
	int num2 = MMC / f2.m_denominador * f2.m_numerador;
	Fracao res(static_cast<int>((num1 - num2)), MMC);
	res.simplify();

	return res;
}
const math::Fracao math::Fracao::operator*(const Fracao &_right) {
	Fracao f1 = *this;
	Fracao f2 = _right;
	if(!m_propria) {
		f1.impropria();
		f2.impropria();
	}
	// Estraightforward multiplication:
	int num = f1.m_numerador  *  f2.m_numerador;
	int den = f1.m_denominador * f2.m_denominador;
	Fracao res(num, den);
	//res.simplify();

	return res;
}
const math::Fracao math::Fracao::operator/(const Fracao &_right) {
	Fracao f1 = *this;
	Fracao f2 = _right;
	if(!m_propria) {
		f1.impropria();
		f2.impropria();
	}
	// Multiplication the inverse:
	int num = f1.m_numerador  *  f2.m_denominador;
	int den = f1.m_denominador * f2.m_numerador;
	Fracao res(num, den);
	//res.simplify();

	return res;
}
bool math::Fracao::operator==(const Fracao &_right) {
	Fracao f1 = *this;
	Fracao f2 = _right;
	if(!m_propria) {
		f1.impropria();
		f2.impropria();
	}
	f1.simplify();
	f2.simplify();
	if((f1.m_numerador==f2.m_numerador) && (f1.m_denominador == f2.m_denominador))
		return true;
	return false;
}
bool math::Fracao::operator>(const Fracao &_right) {
	if(m_numerador*_right.m_denominador > m_denominador*_right.m_numerador)
		return true;
	return false;
}
bool math::Fracao::operator<(const Fracao &_right) {
	if(m_numerador*_right.m_denominador < m_denominador*_right.m_numerador)
		return true;
	return false;
}
std::ostream& math::operator<<(std::ostream& _os, const Fracao &_f) {
	if(_f.m_propria)
		_os << _f.m_numerador << "/" << _f.m_denominador;
	else
		_os << _f.m_integer << " " << _f.m_numerador << "/" << _f.m_denominador;
	return _os;
}
void math::Fracao::divisao() {
}
void math::Fracao::multiplica() {
}

// **************<<_USAGE_>>****************
void math::_fracaoUsage() {

	utils::dicShow("mathematics", "Fração");

	Fracao f1, f2;
	_prtProperties(Fracao());
	_prtProperties(Fracao(9, 12));
	_prtProperties(Fracao(12, 9));
	_prtProperties(Fracao(0.25));

	f1.setFracao(1,4);
	P_(f1.equivalente(2))
	//_prtProperties(f1);

	f1.setRazaoPercentual();
	//P_(f1)

	f1.setFracao(1,9);
	//P_(f1.equivalente(2))
	_prtProperties(f1);
	system("pause");

	// 3 quartos de 1000 = 750
	f1.setFracao(3,4);
	f2.setFracao(1000,1);
	
	std::cout << "3 quartos de 1000=";
	f1=f1*f2;
	P_(f1.getDecimal())
	
	//Fracao f3(285714,1000000);
	Fracao f3(7,8);
	f3.setPeriodic(false);
	_prtProperties(f3);

//	f1.simplify2();
	//PRT_(Chronometer(&_testFrac))
	
	f1.setFracao(9,10);
	f2.setFracao(5,6);	
	//PRT_((f1+f2))
	f1 = f1-f2;
	_prtProperties(f1);

	f1.setFracao(9,10);
	f2.setFracao(5,6);	
	//PRT_((f1.soma(f2)))
	f1.subtracao(f2);
	_prtProperties(f1);

	std::cout << "Multiplicação de Frações Mistas: \n";
	Fracao mista1(3,2,3);
	Fracao mista2(1,4,7);

	_prtProperties(mista1);
	_prtProperties(mista2);

	mista1 = mista1/mista2;
	_prtProperties(mista1);

	std::cout << "Adição de Frações Mistas: \n";
	Fracao mista3(5,4,9);
	Fracao mista4(11,7,9);
	Fracao mista5(3,8,9);
	Fracao mista6(1,5,9);

	mista3 = mista3+mista4;
	mista3 = mista3+mista5;
	mista3 = mista3+mista6;
	_prtProperties(mista3);

/*	f1 = f2;
	_prtProperties(f1);
	_prtProperties(f2);

	f1.setFracao(31, 65);
	f2.setFracao(12, 24);
	_prtProperties(f1);
	_prtProperties(f2);
	PRT_((f1==f2))
		_prtProperties(f1);
	_prtProperties(f2);

	f1.setFracao(4,6);
	f2.setFracao(2,3);
	_prtProperties(f1);
	_prtProperties(f2);
	PRT_((f1==f2))
		_prtProperties(f1);
	_prtProperties(f2);
	PRT_((f1+f2))
		_prtProperties(f1);
	_prtProperties(f2);

	f1.setFracao(1,2);
	f2.setFracao(1,2);
	Fracao f3(1,2);
	Fracao f4(1,2);
	f1 = f1 + f2;
	f1 = f1 + f3;
	f1 = f1 + f4;
	_prtProperties(f1);

	f1.setFracao(3,4);
	f2.setFracao(10,1);
	f1 = f1*f2;
	_prtProperties(f1);

	f1.setFracao(2,3);
	_prtProperties(f1);
	f1.power(3);
	_prtProperties(f1);

	f1.setFracao(1,5);
	f2.setFracao(2,5);
	PRT_((f1>f2))
	PRT_((f1<f2))
	PRT_((f1==f2))
*/
	Fracao a(0.25);
	_prtProperties(a);
	a.setPeriodic();
	_prtProperties(a);
}
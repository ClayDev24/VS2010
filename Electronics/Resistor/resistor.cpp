#include <assert.h>
#include <stdio.h>
#include <math.h>    // pow, fmod
#include "defines.h" // P_()
#include "resistor.h"
#include "series.h"
#include "utils.h"
using namespace utils;

int    pColor[]     = {0, BR, BRI, BY, BYI, BGI, BBI, BMI, BW, BWI};
double pTolerance[] = {10.0, 5.0, 20.0, 1.0, 2.0, 0.5 , 0.25, 0.10, 0.05};
//#define DEBUG

void _stripeTable() {
	std::cout << "TABELA de cores de Resistores:\n\n";
	PrintColour("-2-Silver; \n", BW);
	PrintColour("-1-Gold.  \n" , BYI);
	PrintColour(" 0-Black; \n" , FWI );
	PrintColour(" 1-Brown; \n" , FWI, BR );
	PrintColour("  2-Red;   \n", BRI);
	PrintColour("   3-Orange;\n", BY );
	PrintColour("    4-Yellow \n", BYI);
	PrintColour("     5-Green; \n", BGI);
	PrintColour("      6-Blue;  \n", BBI);
	PrintColour("       7-Violet;\n", BMI);
	PrintColour("        8-Gray;  \n", BW );
	PrintColour("         9-White; \n", BWI);
	PrintColour("\n", FWI); // padraão b/w }
}

void _assertion(int v0, int v1, int v2, int v3, int v4) {
	assert(v0 >= 0 && v0 <=9);
	assert(v1 >= 0 && v1 <=9);
	assert(v2 >= 0 && v2 <=9);
	assert(v3 >=-2 && v3 <=6); // multiplier
	assert((v4 >= -4 && v4 <=8) && (v4 != 3) && (v4 != 4)); // tolerance
}

void elect::CResistor::initConstructor(const int &_v0, const int &_v1, const int &_v2, const int &_v3, const int &_v4) {
	MEMSET(stripe, 5) // <=> 0
	stripe[0] = _v0;
	stripe[1] = _v1;
	stripe[2] = _v2;
	stripe[3] = _v3;  // multiplicador
	//P_(_v3)
	stripe[4] = _v4;  // tolerância
	//_assertion(stripe[0],stripe[1],stripe[2],stripe[3],stripe[4]);
	m_resistance = ((stripe[0]*100)+(stripe[1]*10)+(stripe[2])) * pow(10.0, stripe[3]); // 10^multiplicador
	makeTolerance();
}

void elect::CResistor::fillStripe(const int &_tol) {
	int v0, v1, v2, v3=0;
	while(m_resistance < 100 && m_resistance != 0) {
		m_resistance *= 10;
		v3--; // As cores OURO (-1 = 0.1) e PRATA (-2 0.001) representam multiplicadores fracionários.
	} 
	if(!v3)
		while(m_resistance >= 1000) {
			m_resistance /= 10;
			v3++;
		}
	// Fillin' Sign Digits:
	if(m_size==5) {
		v2 = static_cast<int>(fmod(m_resistance, 10)); 
		m_resistance /= 10;
		v1 = static_cast<int>(fmod(m_resistance, 10));
		m_resistance /= 10;
		v0 = static_cast<int>(m_resistance);
	} else if(m_size==4) {
		m_resistance /= 10;
		v2 = static_cast<int>(fmod(m_resistance, 10));
		m_resistance /= 10;
		v1 = static_cast<int>(fmod(m_resistance, 10));
		m_resistance /= 10;
		v0 = 0;
		v3++;

	}
	initConstructor(v0,v1,v2,v3,_tol);
	// As cores OURO e PRATA jamais aparecerão na primeira e segunda faixas.
}

std::string elect::CResistor::prtGrandeza() {
	std::string s;
	double d2 = m_resistance;
	char* grz[] = {" Ohms", " Kilo Ohms", " Mega Ohms"};
	int i;
	for(i=0; d2>=1000; i++)
		d2 /= 1000;
	s=utils::_toStr(d2);
	s+=grz[i];
	return s;
}

double elect::CResistor::ohmic_percentage() {
	return m_tolerance * m_resistance / 100;
}

double elect::CResistor::ohmic_higher() {
	return ((m_tolerance / 100)+1) * m_resistance;
}

double elect::CResistor::ohmic_lower()  {
	return (((m_tolerance / 100)-1) * (m_resistance*-1));
}

void elect::CResistor::makeTolerance() {
	if(stripe[4] == -3) m_tolerance = 40.0;	// Deprecated - For ilustretade purposes only
	if(stripe[4] == -2) m_tolerance = 10.0;
	if(stripe[4] == -1) m_tolerance =  5.0;
	if(stripe[4] ==  0) m_tolerance = 20.0;
	if(stripe[4] ==  1) m_tolerance =  1.0;
	if(stripe[4] ==  2) m_tolerance =  2.0;
	if(stripe[4] ==  5) m_tolerance =  0.5;
	if(stripe[4] ==  6) m_tolerance =  0.25;
	if(stripe[4] ==  7) m_tolerance =  0.10;
	if(stripe[4] ==  8) m_tolerance =  0.05;
}

void elect::CResistor::showRegTABLE(const int &_v0, const int &_v1, const int &_v2, const int &_v3, const double &_tol) {
	int total=0;
	for(int i=0; i< _v0; i++)
		for(int i1=0; i1< _v1; i1++)
			for(int i2=0; i2< _v2; i2++)
				for(int i3=-2; i3< _v3; i3++) {
					CResistor R1(i, i1, i2, i3, _tol);
					R1.print();
					P_(R1.resistance())
					R1.showStripes();
					PrintColour("", FRI, 0);
					total++;
				}
	P_(total)
}

void elect::CResistor::showStripes() {
	signed int index=0;
	for(int a=0; a<2; a++) {
		for(int i=0; i<5; i++) {
			// Routine to include gold(-1) n' silver(-2) in the display:
			index = stripe[i];
			if((i==3) || (i==4)) { // multiplier(3) & tolerance(4)
				if(stripe[i] == -1) index = 4; // gold
				if(stripe[i] == -2) index = 8; // silver
			}
			PrintColour(" ",  0, pColor[index]);
			PrintColour("  ", 0, 0);
		} N
	}
	PrintColour("", 0, FGI); // back to default green}
}
// **************<<_USAGE_>>****************
void elect::printReg(CResistor _r) {
	_r.showStripes();
	_r.print(); //P_(_r.prtGrandeza())
	P_(_r.resistance())
	P_(_r.signDigits())
	P_(_r.multiplier())	
	P_(_r.ohmic_percentage())
	P_(_r.ohmic_higher())
	P_(_r.ohmic_lower())
	P_(_r.tolerance())
	CEserie serie(_r.resistance(), _r.tolerance());
	P_(serie.getStr())
	P_(serie. getLower())
	P_(serie. getClose())
	P_(serie.getHigher())
	if(!serie.getClose())
		system("pause");
	N
}

void elect::resistorUsage() {

//	CResistor R; // Resistor padrão zero ohms
//	printReg(R);

	CEserie c1(0.0, 5.0);
	//double *serie = c1.getPtr();
	int total=0;

	for(int i=1; i<=10000000; i*=10) {
		double *serie = c1.getPtr();
		while(*serie) {
			P_(*serie)
			CResistor R1(*(serie++)*i, 4, -1);
			//float d = 5.1;
			//d*=100;
			//P_(d)
			//CResistor R1(d, 4, -1);
			printReg(R1);
			total++;
		}
		P_(total);
	}


/*
	double d = 999999999; // maior resistor possível para este algoritmo => 9 dígitos
	// Teste de todos os decimais de uma resistência:
	for(int i=0; i<9; i++) {
		P_(d)
		CResistor R1(d,5,5);
		printReg(R1);
		d /= 10;
	}
	// Teste todos os resistores de um range:
	for(int i=0; i<10000; i+=100) {
		CResistor R0(static_cast<double>(i),5,5);
		printReg(R0);
	}
	// Teste todos as séries (tolerâncias) de uma resistência:

	for(int i=0; i<10000000; i+=10000) {
		P_(i)
		for(int tol=-2; tol<=8; tol++) {
			if(tol!=3 && tol!=4) {
				CResistor R0(static_cast<double>(i),5,tol);
				printReg(R0);
			}
		}
	}
*/
//	CResistor R2(1.0); // Resistor padrão zero ohms
//	printReg(R2);
//	CResistor R3(0,0,1,0,0); // Resistor padrão zero ohms
//	printReg(R3);
	//R2.showRegTABLE(9,9,9,6,0);
}
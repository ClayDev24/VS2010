#include "resistor.h"
#include "series.h"
#include "utils.h"
using namespace std;

//std::string pLabel[] = {
const char *pLabel[] = {
	"A série E3  tem  3 valores diferentes entre 1 e 10. (50% tolerance (Obsolet) - no longer used)",
	"A série E6  tem  6 valores diferentes entre 1 e 10. (20% tolerance (now seldom used). Apenas 3 faixas de cores",
	"A série E12 tem 12 valores diferentes entre 1 e 10. (10% de tolerância)",
	"A série E24 tem 24 valores diferentes entre 1 e 10. (5%  de tolerância)",
	"A série E48 tem 48 valores diferentes entre 1 e 10. (2%  de tolerância)",
	"A série E96 tem 96 valores diferentes entre 1 e 10. (1%  de tolerância)",
	"A série E192 tem 192 valores diferentes entre 100 e 1000. (0.5, 0.25, 0.1% and higher tolerances)"};

// Eseries is subdivided into 2 main groups:
// GROUP 1- E3 to E24 (2-significant digits)
// A série E3 tem valores diferentes entre 1 e 10. (50% tolerance (Obsolet) - no longer used). the standard only specifies a tolerance greater than 20%, other sources indicate 40% or 50%.
double pE3[]  = {1.0,2.2,4.7,0}; //The E3 series is defined as a series of the numbers 1.0, 2.2 and 4.7. If a manufacturer sold resistors with E3 series values in a range of 1 ohm to 10 megohms, then the available resistance values would be: 1 Ω, 2.2 Ω, 4.7 Ω, 10 Ω, 22 Ω, 47 Ω, 100 Ω, 220 Ω, 470 Ω, 1 kΩ, 2.2 kΩ, 4.7 kΩ, 10 kΩ, 22 kΩ, 47 kΩ, 100 kΩ, 220 kΩ, 470 kΩ, 1 MΩ, 2.2 MΩ, 4.7 MΩ, 10 MΩ.
// A série E6 tem 6 valores diferentes entre 1 e 10. (20% tolerance (now seldom used)
double pE6[]  = {1.0,1.5,2.2,3.3,4.7,6.8,0};
// A série E12 tem 12 valores diferentes entre 1 e 10. (10% de tolerância)
double pE12[] = {1.0,1.2,1.5,1.8,2.2,2.7,3.3,3.9,4.7,5.6,6.8,8.2,0}; 
// A série E24 tem 24 valores diferentes entre 1 e 10. (5%  de tolerância)
double pE24[] = {1.00,1.10,1.20,1.30,1.50,1.60,1.80,2.00,2.20,2.40,2.70,3.00,
	3.30,3.60,3.90,4.30,4.70,5.10,5.60,6.20,6.80,7.50,8.20,9.10,0};

// group 2- E48 to E192 (3-significant digists)
// A série E48 tem 48 valores diferentes entre 1 e 10. (2%  de tolerância)
double pE48[] = {1.00,1.05,1.10,1.15,1.21,1.27,
	1.33,1.40,1.47,1.54,1.62,1.69,
	1.78,1.87,1.96,2.05,2.15,2.26,
	2.37,2.49,2.61,2.74,2.87,3.01,
	3.16,3.32,3.48,3.65,3.83,4.02,
	4.22,4.42,4.64,4.87,5.11,5.36,
	5.62,5.90,6.19,6.49,6.81,7.15,
	7.50,7.87,8.25,8.66,9.09,9.53,0};

// A série E96 tem 96 valores diferentes entre 1 e 10. (1%  de tolerância)
double pE96[] = {1.00,1.02,1.05,1.07,1.10,1.13,
	1.15,1.18,1.21,1.24,1.27,1.30,
	1.33,1.37,1.40,1.43,1.47,1.50,
	1.54,1.58,1.62,1.65,1.69,1.74,
	1.78,1.82,1.87,1.91,1.96,2.00,
	2.05,2.10,2.16,2.21,2.26,2.32,
	2.37,2.43,2.49,2.55,2.61,2.67,
	2.74,2.80,2.87,2.94,3.01,3.09,
	3.16,3.24,3.32,3.40,3.48,3.57,
	3.65,3.74,3.83,3.92,4.02,4.12,
	4.22,4.32,4.42,4.53,4.64,4.75,
	4.87,4.99,5.11,5.23,5.36,5.49,
	5.62,5.76,5.90,6.04,6.19,6.34,
	6.49,6.65,6.81,6.98,7.15,7.32,
	7.50,7.68,7.87,8.06,8.25,8.45,
	8.66,8.87,9.09,9.31,9.53,9.76,0};

// A série E192 tem 192 valores diferentes entre 100 e 1000. (0.5, 0.25, 0.1% and higher tolerances)
double pE192[] = {1.00,1.01,1.02,1.04,1.05,1.06,1.07,1.09,1.10,1.11,1.13,1.14,
	1.15,1.17,1.18,1.20,1.21,1.23,1.24,1.26,1.27,1.29,1.30,1.32,
	1.33,1.35,1.37,1.38,1.40,1.42,1.43,1.45,1.47,1.49,1.50,1.52,
	1.54,1.56,1.58,1.60,1.62,1.64,1.65,1.67,1.69,1.72,1.74,1.76,
	1.78,1.80,1.82,1.84,1.87,1.89,1.91,1.93,1.96,1.98,2.00,2.03,
	2.05,2.08,2.10,2.13,2.15,2.18,2.21,2.23,2.26,2.29,2.32,2.34,
	2.37,2.40,2.43,2.46,2.49,2.52,2.55,2.58,2.61,2.64,2.67,2.71,
	2.74,2.77,2.80,2.84,2.87,2.91,2.94,2.98,3.01,3.05,3.09,3.12,
	3.16,3.20,3.24,3.28,3.32,3.36,3.40,3.44,3.48,3.52,3.57,3.61,
	3.65,3.70,3.74,3.79,3.83,3.88,3.92,3.97,4.02,4.07,4.12,4.17,
	4.22,4.27,4.32,4.37,4.42,4.48,4.53,4.59,4.64,4.70,4.75,4.81,
	4.87,4.93,4.99,5.05,5.11,5.17,5.23,5.30,5.36,5.42,5.49,5.56,
	5.62,5.69,5.76,5.83,5.90,5.97,6.04,6.12,6.19,6.26,6.34,6.42,
	6.49,6.57,6.65,6.73,6.81,6.90,6.98,7.06,7.15,7.23,7.32,7.41,
	7.50,7.59,7.68,7.77,7.87,7.96,8.06,8.16,8.25,8.35,8.45,8.56,
	8.66,8.76,8.87,8.98,9.09,9.20,9.31,9.42,9.53,9.65,9.76,9.88,0};

int elect::CEserie::comparisonSeries(double *A, double *B, int szA, int szB) {
	double matching[192];
	double  missing[192];
	memset(matching, 0, 192 * sizeof(double));
	memset(missing,  0, 192 * sizeof(double));

	int i  = 0;
	int i2 = 0;
	bool miss = true;
	for(int a=0; a < szA; a++) {
		for(int b=0; b < szB; b++)
			if(A[a] == B[b]) {
				matching[i++] = A[a];
				miss = false;
			}
		if(miss)
			missing[i2++] = A[a];

		miss = true;
	}
	i = 0;
	cout << "Matching:\n";
	while(matching[i])
		P_(matching[i++])

	i = 0;
	cout << "\nMissing:\n";
	while(missing[i])
		P_(missing[i++])

	return 0;
}

void elect::CEserie::makeESerie(const double &_res, const double &_tol) {
	m_Hi=m_Low=m_Hit=0.0;
	pTMP = NULL;
	m_Sz=0;
	chooseSerie(_tol);


	int i=0;
	while(pTMP[i]) {
		pTMP[i++] *= 1.00000001;
	}


	CResistor r1(_res);
	float factor = r1.multiplier()*100.0f;
	int d1 = r1.signDigits();
	m_Low = (pTMP[m_Sz-2]) * factor; // Special case zero

	for(int i=0; i<m_Sz; i++) {
		CResistor r2(pTMP[i]);
		int d2 = r2.signDigits();

		if(d2 == d1) {   // Compare resistance x Eseries table
			m_Hit = (pTMP[i]) * factor;
			if(i>0)      m_Low = (pTMP[i-1]) * factor;
			else         m_Low = m_Hit;
			if(i<m_Sz-1) m_Hi  = (pTMP[i+1]) * factor;
			else         m_Hi  = m_Hit;
			break;
		} else if(d2 > d1) {
			m_Low = (pTMP[i-1]) * factor;
			m_Hi  = (pTMP[i])   * factor;
			break;
		}
	} // for
}

void elect::CEserie::chooseSerie(const double &_tol) {
	if(_tol >= 40.0) { pTMP = pE3;   }
	if(_tol == 20.0) { pTMP = pE6;   }
	if(_tol == 10.0) { pTMP = pE12;  }
	if(_tol ==  5.0) { pTMP = pE24;  }
	if(_tol ==  2.0) { pTMP = pE48;  }
	if(_tol ==  1.0) { pTMP = pE96;  }
	if(_tol == 0.50) { pTMP = pE192; }
	if(_tol == 0.25) { pTMP = pE192; }
	if(_tol == 0.10) { pTMP = pE192; }
	if(_tol == 0.05) { pTMP = pE192; }
	// Fill m_Sz field:
	while(pTMP[(m_Sz++)+1]);// {
		//float f = pTMP[(m_Sz)];
	//	P_(f)
	//}

	int cnt=0;
	for(int i=m_Sz; i>3; i/=2)
		cnt++;
	m_label = pLabel[cnt];
}

void elect::CEserie::displayAll(double _tol) {
	utils::Console cmd;
	int total = 0;
	chooseSerie(_tol);
//	cmd.setColour(BRI);
	cout << "E" << m_Sz << ": \n";
//	cmd.setColour(FRI);
	cout << m_label << endl;
//	PrintColour("");
	for(int i=0; i<m_Sz; i++) {
		//cout << setprecision(3) << pTMP[index] << " /";
		// E3 series values in a range of 1 ohm to 10 megohms,
//		cmd.setColour(FGI);
		printf("%1.2f /", pTMP[i]);				// ohm (original value)
//		cmd.setColour(FWI);

		printf("%1.2f /",  pTMP[i]*10);			// 10 ohm
		printf("%1.2f /",  pTMP[i]*100);		// 100 0hm
		printf("%1.2f /",  pTMP[i]*1000);		// 1 kilo ohm
		printf("%1.2f /",  pTMP[i]*10000);		// 10 kilo ohm
		printf("%1.2f /",  pTMP[i]*100000);		// 100 kilo ohm
		printf("%1.2f /",  pTMP[i]*1000000);	// 1 mega ohm
		printf("%1.2f /\n", pTMP[i]*10000000);	// 10 mega ohm
		// Ten line blocks:
		if(!((i+1) % 10))
			N
		total++;
	}
//	cmd.setColour(FRI);
	P_(total*8)
//	PrintColour("");
}
// **************<<_USAGE_>>****************
void elect::ceserieUsage() {
	//CEserie c1(22001, 40.0);
	P_(pE6[1])
	P_(utils::_toStr(pE6[1]))

	for(int i=0; i<10000000; i+=1000) {
		//P_(i)
		for(int tol=-2; tol<=8; tol++) {
			if(tol!=3 && tol!=4) {
				CResistor R0(i,5,tol);
				CEserie c1(R0.resistance(), R0.tolerance());
				if(c1.getClose()) {
					P_(c1.getStr())
					//P_(c1.getLower())
					P_(c1.getClose())
					//P_(c1.getHigher())
				}
			}
		}
	}

	double d = 245999999.0; // maior resistor possível para este algoritmo => 9 dígitos
	// Teste de todos os decimais de uma resistência:
/*	for(int i=0; i<9; i++) {
		P_(d)
		CEserie c1(d, 2.0);
		P_(c1.getStr())
		P_(c1. getLower())
		P_(c1. getClose())
		P_(c1.getHigher())
		d /= 10;
	} */
}
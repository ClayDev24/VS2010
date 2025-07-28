#include "utils.h"

namespace math {
	
	// Retorna 1 se o n. é umA raiz PERFEITA:
	static bool _isRoot(int _indice, const unsigned long long &_radicando, double &_raiz) {
		double exp = 1.0/(double)_indice;
		exp += 0.00000000000000009;
		//exp += 0.000000000000000009;

		_raiz = pow(static_cast<double>(_radicando), exp); // Ex.: 1.0/2.0 = square root. 1.0/3.0 =cubic root (...)
		unsigned long long r=static_cast<unsigned long long>(_raiz);
		while(--_indice)
			r*=static_cast<unsigned long long>(_raiz);
//		P_(r)		P_(_radicando)		P_(_raiz)
 		if(r==_radicando)
			return true;
		return false;
	}
	static bool _isRoot2(const int &_indice, const unsigned long long&_radicando, double &_raiz) {
		double exp = 1.0/(double)_indice;
		exp += 0.00000000000000009;
		//exp += 0.000000000000000009;
		_raiz = pow(static_cast<double>(_radicando), exp); // Ex.: 1.0/2.0 = square root. 1.0/3.0 =cubic root (...)
		// 3, 6, 7, 9, 11, 12, 13, 14, 15, 17, 18, 19
		double intPart, fractPart;
		fractPart = modf(_raiz, &intPart); // o float arredonda o valor do double
		//unsigned long long l = fractPart * 1000000000;
		unsigned long long l = static_cast<unsigned long long>(fractPart) * 10000000;
//		P_(_radicando)		P_(intPart)		P_(fractPart)		P_(_raiz)
		if(!l)//!fractPart)
			return true;
		return false;
	}
	static bool _isSquare(const unsigned long long&_radicando) {
		double exp = 1.0/2;
		exp += 0.00000000000000009;
		double _raiz = pow(static_cast<double>(_radicando), exp);
		double intPart, fractPart;
		fractPart = modf(_raiz, &intPart);
		if(!(static_cast<unsigned long long>(fractPart * 10000000)))
			return true;
		return false;
	}
	// **************<<_USAGE_>>****************
	static void _rootUsage() {

		//utils::dicShow("mathematics", "Números Quadrados");

		utils::PrintColour_("<<_SQUARE_NUMBERS_>>", FRI);
		int total=0;
		double raiz1, raiz2;
		bool b1, b2;
/*
		b1 = _isRoot(3, 64, raiz1);
					P_(raiz1)
					P_(b1) N
		b1 = _isRoot(3, 9800345, raiz1);
					P_(raiz1)
					P_(b1) N
		b1 = _isRoot(3, 9938374, raiz1);
					P_(raiz1)
					P_(b1) N
*/
		for(unsigned long long radicando=99999999990000; radicando<10000000000000; radicando++) {
			b1 = _isRoot(3, radicando, raiz1);
			b2 = _isRoot2(3, radicando, raiz2);
			if(!b2) {
				P(radicando) TAB P(raiz1) TAB P_(b1)
				P(radicando) TAB P(raiz2) TAB P_(b2) N

				if(raiz1!=raiz2) {
					utils::PrintColour_("<<_ERROR_>>", FRI);
					system("pause");
				}				
				++total;
			}
		}
		P_(total)
		// Maior n. 
		P(_isRoot(9, 4, raiz1)) TAB
		P_(raiz1)
		P(_isRoot(9, 9, raiz1)) TAB
		P_(raiz1)
		P(_isRoot(9, 16, raiz1)) TAB
		P_(raiz1)
		P(_isRoot(9, 25, raiz1)) TAB
		P_(raiz1)
		P(_isRoot(9, 36, raiz1)) TAB
		P_(raiz1)
		P(_isRoot(9, 49, raiz1)) TAB
		P_(raiz1)
		P(_isRoot(9, 64, raiz1)) TAB
		P_(raiz1)
		P(_isRoot(2, 18446744073709551615, raiz1)) TAB
		P_(raiz1)
		P(_isRoot2(2, 18446744073709551615, raiz2)) TAB
		P_(raiz2)
		P(_isRoot(2, 18446744065119617025, raiz1)) TAB
		P_(raiz1)
		P(_isRoot2(2, 18446744065119617025, raiz2)) TAB
		P_(raiz2)
	}
} // math
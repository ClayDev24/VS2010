#pragma once
#include "utils.h"
//#include "defines.h"

namespace math {
	// Log2 8 = 3 (2=base / 8=logaritmando / 3=logaritmo)
	//   2^3  = 8 (2=base / 8=resultado    / 3=expoente
	static long long log(const long long &Logaritmando, const long long &Base=10) {
		long long _l = Logaritmando;
		long long i;
		for(i=0; _l>=Base; i++)
			_l /= Base;
		return i;
	}
	// **************<<_USAGE_>>****************
	static void _listLogBase(const int &_base, const int &_qnt);
	static void _logTip1();

	static void _logUsage() {

		utils::dicShow("mathematics", "Logaritmos");

		P_(log(32,2))
		P_(log(1,17))
		P_(log(10)) // Log de 10 na base 10 (qnd o log for base 10 não precisar de notação)

		P_(log(100) + log(343,7) - log(27,27))
		P_(5*log(2,2)+7*log(27,3)-2*log(25,5))
		P_(2*log(100)-4*log(32,2)-3*log(1,15))

		_listLogBase(2,67); // base 2
		_listLogBase(3,39); // base 3
		_listLogBase(4,31);
		_listLogBase(5,27);
		_listLogBase(6,24);
		_listLogBase(7,22);
		_listLogBase(8,20);
		_listLogBase(9,19);
		_listLogBase(10,18);
		_listLogBase(11,18);
		_listLogBase(12,17);
		_listLogBase(13,17);
		_listLogBase(14,16);
		_listLogBase(15,15);
		_listLogBase(16,15);
		_listLogBase(17,15);
		_listLogBase(100,9);
		_listLogBase(1000,6);
		_listLogBase(10000,4);
		_listLogBase(100000,3);
		_listLogBase(1000000,3);
		_listLogBase(10000000,2);
		_listLogBase(100000000,2);
		_listLogBase(1000000000,2);

		_logTip1();
	}

	static void _listLogBase(const int &_base, const int &_qnt) {
		long long logaritmando = _base;
		for(int i=0; i<_qnt; i++) {
			int logaritmo = log(logaritmando, _base);
			std::cout << "Log(" << logaritmando << "," << _base << ")=> " << logaritmo << std::endl;
			logaritmando *=_base;
		}
	}

	// Tip1: log de n na base n é sempre 1:
	static void _logTip1() {
		P_(log(2,2))
		P_(log(3,3))
		P_(log(4,4))
		P_(log(5,5))
		P_(log(6,6))
		P_(log(7,7))
		P_(log(8,8))
		P_(log(9,9))
		P_(log(10,10))
	}
} // math
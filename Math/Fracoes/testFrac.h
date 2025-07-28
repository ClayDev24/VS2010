#pragma once
#include "fracao.h"

static void _prtProperties(math::Fracao &_f) {
	P_(_f)
	P_(_f.getPropria())
	P_(_f.getDecimal())
	P_(_f.getPeriodic())
	P_(_f.getInteger())
	P( _f. impropria())
	P_(_f)
	P( _f. setMisto())
	P_(_f)
	P( _f. simplify())
	P_(_f)
	std::cout << std::endl;	
}

static void _testFrac() {
	for(int i=0; i<1000; i++) {
		int num = utils::_random(1,100);
		int den = utils::_random(1,100);
		if(num > den) // impropria
			P_(math::Fracao(num, den))
			//_prtProperties(math::Fracao(num, den));
	}
	// Testing fração from decimal number:
/*
for(int i=0; i<10; i++) {
		double d = static_cast<double>(utils::_random(1,1000)) / 1000;
		P_(d)
		_prtProperties(math::Fracao(d));
	}
	// Testando frações equivalentes:
	math::Fracao f1(6,3);
	math::Fracao f2;
	for(int i=2; i<=100000; i++) {
		f2 = f1.equivalente(i);
		P_(f2)
	}
*/
}
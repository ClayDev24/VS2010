#pragma once
#include "fibonacci.h"

static unsigned long long math::_fib(int _n) {
	using namespace std;
	long long n1=1;
	long long n2=0;
	if(_n==0) return 0;
	if(_n==1) return 1;
	while((_n--)-1) {
		n1+=n2;
		n2=n1-n2;
	}
	// _fib(_n-1)+_fib(_n-2);
	return n1;
}

static double math::_fibD(int _n) {
	using namespace std;
	double n1=1.0;
	double n2=0;
	if(_n==0) return 0;
	if(_n==1) return 1;
	while((_n--)-1) {
		n1+=n2;
		n2=n1-n2;
	}
	// _fib(_n-1)+_fib(_n-2);
	return n1;
}
static vetorULLng math::_fibAll(int _n) {
	vetorULLng vtll;
	for(int i=1; i<=_n; i++)
		vtll.push_back(_fib(i));
	return vtll;
}
static vetorDlb math::_fibAllD(int _n) {
	vetorDlb vtd;
	for(int i=1; i<=_n; i++)
		vtd.push_back(_fibD(i));
	return vtd;
}
// **************<<_USAGE_>>****************
void math::_fibUsage() {
	using namespace std;

	utils::dicShow("mathematics", "Sequência de Fibonacci");

	vetorULLng vll = _fibAll(93);
	utils::_showVetor(vll);
	//vetorDlb vld = _fibAllD(93);
	//utils::_showVetor(vld);

	//for(int i=0; i<=92; i++)
	//	cout << "fib(" << i << ")=> " << _fib(i) << endl;

	utils::PrintColour_("The higher fibonacci number given by this algoritm:", FRI);
	P_(_fib(10))
	vll = _fibAll(10);
	utils::_showVetor(vll);
}
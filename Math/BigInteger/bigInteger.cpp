#include "bigInteger.h"

math::BigInteger::BigInteger(const unsigned int &_h, const unsigned int &_l):m_high(_h), m_low(_l) {}

const math::BigInteger math::BigInteger::operator+(const BigInteger &_right) {
	unsigned int high=0;
	unsigned int low=0;
	unsigned int resto=0;
	if(_right.m_high == 0) {
		unsigned int dif = 1000000000 - m_low; // O qnto ainda cabe em m_low
		P_(dif)
			P_(_right.m_low)
			if(_right.m_low > dif) {
				low = _right.m_low - dif;
				high += 1;
			} else
				low	= m_low + _right.m_low;
	}
	return BigInteger(high, low);
}
const math::BigInteger math::BigInteger::operator+(const unsigned int &_n) {
	unsigned int high=0;
	unsigned int low=0;
	unsigned int resto=0;

	unsigned int dif = 999999999 - m_low; // O qnto ainda cabe em m_low
	//P_(dif)
	//P_(_n)
	if(_n > dif) {
		low = _n - dif-1;
		high = m_high + 1;
	} else {
		low	= m_low + _n;
		high = m_high;
	}

	return BigInteger(high, low);
}
// **************<<_USAGE_>>****************
void math::_bigIntegerUsage() {
	using namespace std;
	BigInteger b1(5, 999999990); // max=> 999999999 / 999999999 (9-digits each)
	BigInteger b2(0, 15);
	std::cout << b1 << std::endl;
	//b1 = b1 + 3;
	//std::cout << b1 << std::endl;
	//b1 = b1 + 15;//b2;

	for(unsigned int i=0; i< 1000050; i++) {
		b1 = b1 + 10000;//b2;
		cout << b1 << endl;
	}
}

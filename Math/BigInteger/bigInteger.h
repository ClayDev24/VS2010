#pragma once
#include "utils.h"

namespace math {

	class BigInteger {
	private:
		struct {
			unsigned int HIGH;
			unsigned int LOW;
			//friend ostream& operator<<(ostream& os, const Str &p) {
			//	return os << p.x << ", " << p.y << endl;
			//};
		} Point;
		unsigned int m_high;
		unsigned int m_low;
	protected:
	public:
		BigInteger():m_high(0), m_low(0) { DS_("BigInteger()...")  }
		BigInteger(const unsigned int &High, const unsigned int &Low);
		~BigInteger() { DS_("~BigInteger()...") }

		const BigInteger operator+(const BigInteger &_right);
		const BigInteger operator+(const unsigned int &_n);

		friend std::ostream& operator<<(std::ostream& _os, const BigInteger &_bi) {
			unsigned int tmp = _bi.m_low;
			int sz=0;
			do {
				//PRT_(tmp)
				tmp /= 10;
				sz++;
			} while(tmp);
			sz = 9-sz;

			if(_bi.m_high > 0) {
				_os << _bi.m_high;
				for(int i=0; i<sz; i++)
					_os << "0";		
			}
			_os << _bi.m_low;
			return _os;
		}
	};
	// **************<<_USAGE_>>****************
	void _bigIntegerUsage();

} // math
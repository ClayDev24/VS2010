#pragma once
#include "include_all.h"

namespace math {

	class Equation { // defaults to private:
	public:
		// default constructor:
		Equation() {}
		~Equation() {}
		friend std::ostream& operator<<(std::ostream& _os, const Equation &_f) {
			//_os << _f.m_a << "/" << _f.m_b;
			return _os;
		}
	};
	// **************<<_USAGE_>>****************
	void _equation();

} // math
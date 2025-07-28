#pragma once
//#include "mat.h"

namespace math {

	template <typename Type>
	bool search2(Type &_vt1, Type &_vt2, Type &_result, bool _sort=false) {
		int index = 0;
		if(_sort)
			std::sort(_vt2.begin(), _vt2.end());
		bool found;
		_result.clear();
		for(unsigned int i=0; i<_vt1.size(); i++) {
			int first = 0;
			int last  = _vt2.size()-1;
			found = false;
			while((first <= last) && (!found)) {
				int middle = ((first + last) / 2);
				//std::cout << _vt1.at(middle) << " == " << _vt2.at(i) << " : " << (_vt1.at(middle) == _vt2.at(i)) << std::endl;
				if(_vt1.at(i) == _vt2.at(middle)) {
					found = true;
					index = middle;
					_result.push_back(_vt1.at(i));
					return true;
				} else if(_vt1.at(i) > _vt2.at(middle))
					first = middle + 1;
				else if(_vt1.at(i) < _vt2.at(middle))
					last = middle - 1;				
			}
		}
		return false;
	} // search2

	enum testType { // Untagged enum (no type name):
		MMC,
		MDC
	};

	void display(const int &_sz, testType, bool Show=false);
	void _teste();//testType);

} // math
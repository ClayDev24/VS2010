#include <algorithm>  // std::sort
#include "BinarySearch.h"
#include "typedefs.h"
#include "utils.h" // _showVetor()

template <class Type>
Type* utils::BinarySearch<Type>::search(Type *_vt1, Type *_vt2, bool _sort) {
	Type *result = new Type();
	if(_sort)
		std::sort(_vt2->begin(), _vt2->end());
	//bool found;
	for(unsigned int i=0; i<_vt1->size(); i++) {
		int first = 0;
		int last  = _vt2->size()-1;
		bool found = false;
		while((first <= last) && (!found)) {
			int middle = ((first + last) / 2);
			//std::cout << _vt1->at(middle) << " == " << _vt2->at(i) << " : " << (_vt1->at(middle) == _vt2->at(i)) << std::endl;
			if(_vt1->at(i) == _vt2->at(middle)) {
				found = true;
				m_index = middle;
			} else if(_vt1->at(i) > _vt2->at(middle))
				first = middle + 1;
			else if(_vt1->at(i) < _vt2->at(middle))
				last = middle - 1;
		}
		if(found)
			result->push_back(_vt1->at(i));
	}
	return result;
} // search
template <class Type>
bool utils::BinarySearch<Type>::search2(Type &_vt1, Type &_vt2, Type &_result, bool _sort) {
	if(_sort)
		std::sort(_vt2.begin(), _vt2.end());
	bool found;
	for(unsigned int i=0; i<_vt1.size(); i++) {
		int first = 0;
		int last  = _vt2.size()-1;
		found = false;
		while((first <= last) && (!found)) {
			int middle = ((first + last) / 2);
			//std::cout << _vt1.at(middle) << " == " << _vt2.at(i) << " : " << (_vt1.at(middle) == _vt2.at(i)) << std::endl;
			if(_vt1.at(i) == _vt2.at(middle)) {
				found = true;
				m_index = middle;
				std::cout << m_index << std::endl;
			} else if(_vt1.at(i) > _vt2.at(middle))
				first = middle + 1;
			else if(_vt1.at(i) < _vt2.at(middle))
				last = middle - 1;				
		}
		if(found)
			_result.push_back(_vt1.at(i));
		found = false;
	}
	return found;
} // search2
// ***************** <<_USAGE_>> *****************
void utils::binarySearchUsage() {
	
	vetorStr *vt1 = new vetorStr();
	vetorStr *vt2 = new vetorStr();
	vt1->push_back("a");
	vt1->push_back("b");
	vt1->push_back("maria");
	vt1->push_back("d");
	vt1->push_back("raimundo");
	vt1->push_back("f");
	vt1->push_back("g");
	vt1->push_back("h");
	vt1->push_back("clailton");

	vt2->push_back("j");
	vt2->push_back("k");
	vt2->push_back("clailton");
	vt2->push_back("m");
	vt2->push_back("n");
	vt2->push_back("a");
	vt2->push_back("maria");
	vt2->push_back("raimundo");
	vt2->push_back("b");

	BinarySearch<vetorStr> bs;
	vetorStr *vt3 = bs.search(vt1, vt2, false);
	utils::_showVetor(*vt3);
	//P_(bs.index())
	delete vt1;
	delete vt2;
	delete vt3;

	// Non-heap (automatic var) searching:
	vetorStr vt4, vt5, result;
	vt4.push_back("a");
	vt4.push_back("b");
	vt4.push_back("maria");
	vt4.push_back("d");
	vt4.push_back("raimundo");
	vt4.push_back("f");
	vt4.push_back("g");
	vt4.push_back("h");
	vt4.push_back("clailton");

	vt5.push_back("j");
	vt5.push_back("k");
	vt5.push_back("clailton");
	vt5.push_back("m");
	vt5.push_back("n");
	vt5.push_back("a");
	vt5.push_back("maria");
	vt5.push_back("raimundo");
	vt5.push_back("b");

	//showVetor(vt5);
	int index = bs.search2(vt4, vt5, result);
	utils::_showVetor(result);
	//showVetor(vt5);
	std::cout << bs.index() << std::endl;

	vetorInt vti, vti2, vti3;

	for(int i=10; i<50; i++)
		vti.push_back(i);
	for(int i=0; i<1000; i++)
		vti2.push_back(i);

	BinarySearch<vetorInt> bsi;
	index = bsi.search2(vti, vti2, vti3);
	utils::_showVetor(vti3);
	std::cout << bsi.index() << std::endl;
	std::cout << index << std::endl;
}
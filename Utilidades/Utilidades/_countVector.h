#pragma once
#include <iostream>
#include <functional> // std::greater<>()
#include <algorithm>  // std::sort
#include <utility>
#include <string>
#include "typedefs.h"
#include "_colour.h"
#include "_random.h"

typedef std::pair<unsigned int, unsigned int>      pairIntInt;
typedef std::vector<pairIntInt>  vetorPII;

static bool crescente(const pairIntInt &a, const pairIntInt &b) {
//static bool crescente(const std::pair<int, int> &a, const std::pair<int, int> &b) {
	if(a.second < b.second)
		return true;
	return false; 
}

static bool decrescente(const pairIntInt &a, const pairIntInt &b) {
	if(a.second > b.second)
		return true;
	return false;
}

namespace utils {

	template <typename T>
	static vetorPII* _countVector(T &_v, bool _sortSecond, bool _crescente=true) {
		vetorPII *v = new vetorPII();
		if(_crescente)
			std::sort(_v.begin(), _v.end());
		else
			std::sort(_v.begin(), _v.end(), std::greater<int>());
		for(unsigned int i=0; i<_v.size(); i++) {
			pairIntInt pair; // = new pairIntInt();
			pair.first  = _v[i];
			pair.second = 0;
			for(unsigned int i2=i; i2<_v.size(); i2++) {
				if(pair.first == _v[i2]) {
					pair.second++;
					i++;
				}
			}
			i--;
			v->push_back(pair);
		}
		if(_sortSecond)
			if(_crescente)
				std::sort(v->begin(), v->end(), crescente);
			else // decrescente:
				std::sort(v->begin(), v->end(), decrescente);
		return v;
	}
	// ***************** <<_USAGE_>> *****************
	static void _countVectorUsage() {
		utils::PrintColour_("\n<<_Printin' pairInt vetor_>>", BRI);
		unsigned int cnt =0;
		unsigned int cnt2=0;
		//vetorInt vi;
		vetorUInt vi;
		vetorPII *v;
/*		for(int a=0; a<100000; a++) {
			for(int i=0; i<10; i++)
				vi.push_back(i);
			for(int i=2; i<12; i++)
				vi.push_back(i);
			for(int i=4; i<14; i++)
				vi.push_back(i);
		}
*/		//_showVetor(vi);

		for(cnt=0; cnt<1000000; cnt++)
			vi.push_back(_random(0,100));
		v = _countVector(vi, true, false);

		for(unsigned int i=0; i<v->size(); i++) {
			//std::cout << i+1 << "=> " << v[i] << std::endl;
			pairIntInt pair = v->at(i);
			std::cout << pair.first;
			std::cout << " ";
			std::cout << pair.second << std::endl;
			cnt2 += pair.second;
		}
		std::cout << cnt  << std::endl;
		std::cout << cnt2 << std::endl;
		delete v;
	}
} // utils
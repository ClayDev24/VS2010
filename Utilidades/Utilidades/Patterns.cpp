#include <algorithm> // sort()
#include <iostream>
#include <vector>
#include "Patterns.h"
#include "utils.h"

utils::CPatterns::CPatterns(std::string _s, std::string _p, bool _sb): m_pattern(_p), m_subscript(_sb) { utils::require(m_pattern.size()<=64, "String de busca deve ser menor ou igual à 64 caracteres!");
	m_sort=false;
	m_sz=_s.size();
	// Initializing and filling the buffer:
	m_buffer = new(std::nothrow) char[m_sz+1];
	for(int i=0; i<m_sz; i++)
		m_buffer[i]=_s[i];
	m_buffer[m_sz]=0; // zero-terminated string

	fillCoords(m_pattern);
}
//*****************************************************************************
void utils::CPatterns::fillCoords(const std::string &_pattern) {
	SData data(this, _pattern);
	int sz = _pattern.size();
	for(int i=0; i<m_sz && sz; i++) {
		bool found = true;
		for(int offset=0; offset<sz; offset++) {
			if(_pattern[offset]!=m_buffer[i+offset] && _pattern[offset]!='*') {
				found=false;
				break;
			}
		}
		if(found) {
			data.s_coords.push_back(std::pair<int,int>(i, i+sz));
			if(!m_subscript) // não sobrescrever
				i+=sz-1;
		}
	}
	if(data.s_coords.size()) // Se encontrou o padrão preenche a estrutura de dados:
		m_data.push_back(data);
}
//*****************************************************************************
void utils::CPatterns::show(bool _unique) {
	for(unsigned int i=0; i<m_data.size(); i++) {
		if(_unique)
			if(m_data[i].s_coords.size()==1) // mostra apenas a reincidência do pattern
				continue;
		m_data[i].show();
	}
}
// ***************** <<_USAGE_>> *****************
void utils::_patternsUsage() {
	CPatterns dp("cabelo", "aaa");
	//dp.clear();
	//dp.setSubscript(false);
	//dp.setSort(true);
	dp.findPatterns(2);
	P_(dp.getSize())
	dp.show(false);
	
//	for(int i=0; i<10000000000; i++) {
//		std::string phrase  = _randomWords(_random(512, 512), 'a', 't');
//		Patterns dp2(phrase.c_str(), "clailton");
//		dp2.show();
//	}
//	TestPatterns();
}
//*****************************************************************************
void utils::TestPatterns() {
	// Teste Depct:
	for(int i=1; i<=100000; i++) {
		std::string pattern = _randomWords(_random(7,   7), '0', '9');
		std::string phrase  = _randomWords(_random(128, 128), '0', '9');
		CPatterns dp(phrase.c_str(), pattern.c_str());
		for(int i=8; i<=8; i++) {
			//Depict dp(phrase.c_str(), pattern.c_str());
			//dp.findPatterns(i);
			//P_(dp.getSize())
			dp.show(true);
		}
	}
}
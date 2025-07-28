#include <algorithm> // sort()
#include <iostream>
#include <vector>
#include "Pattern.h"
#include "utils.h"

utils::CPattern::CPattern(std::string _s, std::string _p, bool _sb): m_buffer(_s), m_pattern(_p), m_subscript(_sb) {
	//utils::require(m_pattern.size()<=64, "String de busca deve ser menor ou igual à 64 caracteres!");
	m_buffer+=static_cast<char>(0); // zero-terminated string
	setCoords();
}
//*****************************************************************************
void utils::CPattern::setCoords() {
	int patternSz = m_pattern.size();
	int phraseSz  = m_buffer.size();
	for(int i=0; i<phraseSz && patternSz; i++) {
		bool found = true;
		for(int offset=0; offset<patternSz; offset++) {
			if(m_pattern[offset] != m_buffer[i+offset] && m_pattern[offset] != '*') {
				found=false; // se falha breca
				break;
			}
		}
		if(found) {
			m_coords.push_back(std::pair<int,int>(i, i+patternSz-1));
			if(!m_subscript) // não sobrescrever
				i+=patternSz-1;
		}
	}
}
//*****************************************************************************
void utils::CPattern::show(bool _colour) {
	if(_colour)
		Color();
	else
		std::cout << m_buffer << std::endl;
	std::cout << "total found=> " << m_coords.size() << std::endl;
	for(unsigned int i=0; i<m_coords.size(); i++) {
		STR pattern = "";
		std::pair<int,int> par = m_coords[i];
		pattern = m_buffer.substr(par.first, (par.second - par.first)+1);
		std::cout << pattern << " - pair(" << par.first << ", " << par.second << ")\n";
	}
	std::cout << std::endl;
}
//*****************************************************************************
void utils::CPattern::Color() {
	int memo = 0;
	for(unsigned int i=0; i<m_coords.size(); i++) {
		std::pair<int,int> par = m_coords[i];
		std::cout << m_buffer.substr(memo, par.first-memo);
		utils::PrintColour(m_pattern.c_str(), FRI);
		memo = par.second+1;
	}
	std::cout << m_buffer.substr(memo, m_buffer.size()-1) << std::endl; // last token
}

// ***************** <<_USAGE_>> *****************
static void _testPattern();

void utils::_patternUsage() {
	//CPattern p("4.1234123412341234", "4.1");
	CPattern p("4.123_clailton_4123F_clailton_412341_clailton_234", "clailton");
	//p.show(true);
	
	std::cout << _chronometer(&_testPattern) << std::endl;
	std::cout << " segundos." << std::endl;
}

static void _testPattern() {
	using namespace utils;
	for(int i=0; i<1000000; i++) {
		STR phrase = _randomWords(_random(850, 1024), 'a', 't');
		//STR pattern = _randomWords(_random(7,   7), '0', '9');
		CPattern p2(phrase, "clailto");
		if(p2.getTotal())
			p2.show();
	}
}
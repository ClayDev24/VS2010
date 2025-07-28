#include <algorithm> // sort()
#include <iostream>
#include <vector>
#include "FindPatterns.h"
#include "utils.h"

utils::CFindPatterns::CFindPatterns(STR _ph, const int &_n, bool _sub, bool _st):m_phrase(_ph), m_subscript(_sub), m_sorting(_st) {
	m_phrase+=static_cast<char>(0); // zero-terminated string
	find(_n);
}

//*****************************************************************************
void utils::CFindPatterns::find(const int _n) {
	//P_(m_phrase)
	vetorStr v;
	int phraseSz= m_phrase.size();
	int n=_n;
	if(m_subscript)
		n=1;

	for(int i=0; i<phraseSz; i+=n) { // _n
		STR pattern = "";
		for(int offset=0; offset < _n; offset++) {
			if(!m_phrase[i+offset])  // se fim da string
				break;
			pattern += static_cast<char>(m_phrase[i+offset]);
		}
		if(pattern.size()==_n) 
			v.push_back(pattern);
	}
	if(m_sorting)
		sort(v.begin(), v.end());
	v.erase(std::unique(v.begin(), v.end()), v.end());
	_showVetor(v);

	for(unsigned int i=0; i<v.size(); i++)
		m_data.push_back(CPattern(m_phrase, v[i]));
}
//*****************************************************************************
void utils::CFindPatterns::show() {
	for(unsigned int i=0; i<m_data.size(); i++)
		m_data[i].show(false);
}
// ***************** <<_USAGE_>> *****************
static void _testFindPatterns();

void utils::_findPatternsUsage() {
	CFindPatterns fp("4.1234123412341234", 1, false);
	//P_(dp.getSize())
	//dp.show(false);

	std::cout << _chronometer(&_testFindPatterns);
	std::cout << " segundos." << std::endl;
}
//*****************************************************************************

void _testFindPatterns() {
	using namespace utils;
	for(int i=1; i<=1; i++) {
		//STR pattern = _randomWords(_random(7,   7), '0', '9');
		STR phrase  = _randomWords(_random(24, 24), 'a', 'z');
		for(int i=1; i<=24; i++) {
			CFindPatterns fp(phrase, i);//false, false);
			fp.show();
		}
	}
}
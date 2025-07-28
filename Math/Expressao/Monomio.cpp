#include <ctype.h> // isalnum(), etc...
#include <new>
#include "Monomio.h"

math::Monomio::Monomio(std::string _s):m_term(_s), m_sign(true), m_coeficient(1), m_exponent(1) {
	DS_("Monomio(string s)...") /*REQUIRE()*/
	evaluate();
}

void math::Monomio::evaluate() {
	using namespace std;
	int sz = strlen(m_term.c_str());
	
	string s = "";
	string e = "";
	vector<string> numbers;
	vector<string> letters;

	utils::Tokenizer *token = new utils::Tokenizer(m_term, "abcdefghijklmnopqrstuvwxyz^");
	P_(token->get_size())
	for(int i = 0; i < token->get_size(); i++) {
		P_(token->get_at(i))
		numbers.push_back(token->get_at(i));
	}
	delete token;

	token = new utils::Tokenizer(m_term, "-0123456789");
	P_(token->get_size())
	for(int i = 0; i < token->get_size(); i++) {
		P_(token->get_at(i))
		letters.push_back(token->get_at(i));
	}
	delete token;
}

void math::Monomio::evaluate2() {
	int sz = strlen(m_term.c_str());
	
	std::string s = "";
	std::string e = "";
	for(int i=0; i<sz; i++) { // Percorrer o termo
		//P_(m_term[i]);
		if(isdigit(m_term[i])) {
			s += m_term[i];
		} else if(isalpha(m_term[i])) {
			m_incognitas.push_back(m_term[i]);
		} else { // sigh
			if(m_term[i] == '-')
				m_sign = false; // negative
			else if(m_term[i] == '^') {
				if(isdigit(m_term[i])) {
					e += m_term[i];
				}
			}
		}
	}
	
	if(!(s==""))
		m_coeficient = utils::_strTo<int>(s.c_str());
	if(!m_sign)
		m_coeficient *= -1;

	P_(m_coeficient)
	//P_(m_incognitas.size())
	//utils::_showVetor(m_incognitas);
	//P_(m_sign)

	if(!m_sign) m_coeficient *= -1;
}
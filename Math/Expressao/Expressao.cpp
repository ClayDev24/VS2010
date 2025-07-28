#include "Expressao.h"

math::Expressao::Expressao(std::string _s) {
	DS_("Expressao(string s)...") /*REQUIRE()*/
	P_(_s)

	utils::Tokenizer *token = new utils::Tokenizer(_s, " +");
	//P_(token->get_size())
	
	for(int i=0; i<token->get_size(); i++) {
		m_terms.push_back(Monomio(token->get_at(i)));
	}
	//utils::_showVetor(m_terms);

	delete token;
} 
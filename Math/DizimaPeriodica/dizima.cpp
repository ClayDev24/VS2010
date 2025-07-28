#include "dizima.h"

void math::Dizima::parser() {
	vetorInt ns;
	vetorInt qnt;
	// Filling the digits:
	utils::Tokenizer token(m_dizima.c_str(), ".");//, "aeiouAEIOU");

	//	P_(token.get_size())
	//	for(int i = 0; i<token.get_size(); i++)
	//		P_(token.get_at(i))
	std::string decimal = token.get_at(1);
	int len = decimal.size();
	P_(decimal)

		for(int i=0; i<len; i++)
			ns.push_back(static_cast<int>(decimal[i])-48);

	int len2 = len/3;
	int sobra = len%3;
	P_(len)
	P_(len2)
	P_(sobra)
	P_(m_dizima.substr(sobra, 3))
	for(int i=0; i<len; i++) {
		int a=ns[i];
		scan(m_dizima, m_dizima.substr(sobra, 3));
	}
	m_dizima;
	m_periodo;
	m_intruder;
	m_integer;
}

void math::Dizima::scan(std::string scan, std::string str) {
	int len = scan.size();
	for(int a=0; a<len; a++) {
		
	}
}
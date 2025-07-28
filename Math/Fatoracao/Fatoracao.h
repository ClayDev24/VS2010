#pragma once
#include "typedefs.h"

namespace math {

	class Fatoracao {
	private:
		unsigned int m_fator;
		vetorInt fatores;
		vetorInt primos;
		vetorInt compostos;
	protected:
		vetorInt fatorationTree(unsigned int _dividendo, bool show = true);
	public:
		Fatoracao():m_fator(0) { DS_("Fatoracao()...") }
		Fatoracao(unsigned int Fator):m_fator(Fator) { DS_("Fatoracao(unsigned int)...") }
		~Fatoracao() { DS_("~Fatoracao()...") }
		inline void setFator(const unsigned int &Fator) { m_fator = Fator; }
		inline unsigned int getFator() { return m_fator; }
		inline vetorInt getDivisores() { return fatorationTree(m_fator); }
		//vetorInt getDivisoresSz() { return fatorationTree(m_fator); }
	};
	// **************<<_USAGE_>>****************
	void _fatoracao();

} // math
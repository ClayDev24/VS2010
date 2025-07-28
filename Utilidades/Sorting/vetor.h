#pragma once
#include "typedefs.h"

namespace utils {

	class Classifica {
		vetorInt *m_vt1;
	public:
		Classifica() { m_vt1 = NULL; }
		~Classifica() {}
		vetorInt *ordena(vetorInt *_v, bool Crescente=true);
	private:
		void troca(const int &_ind1, const int &_ind2) {
			int temp = m_vt1->at(_ind1);
			m_vt1->at(_ind1) = m_vt1->at(_ind2);
			m_vt1->at(_ind2) = temp;
		}
	};
	// ***************** <<_USAGE_>> *****************
	void classificaUsage();
} // utils
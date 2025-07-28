#include "radical.h"

double math::Radical::evaluate() {
	double raiz = pow(m_indice, m_radicando);
	return raiz;
}
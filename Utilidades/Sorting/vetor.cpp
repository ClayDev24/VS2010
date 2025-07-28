#include <iostream>
#include "vetor.h"

vetorInt* utils::Classifica::ordena(vetorInt *_v, bool _c) {
	m_vt1 = _v;
	int candidato = 0;
	int vigente   = 0;
	int contador  = 0;
	bool eh = false;
	while(true) {
		eh = false;
		for(unsigned int i = contador; i < m_vt1->size(); i++) {
			if(_c) { // crescente:
				if(m_vt1->at(i) < m_vt1->at(candidato)) {
					vigente   = i;
					candidato = vigente;
					eh = true;
				}
			} else { // Decrescente:
				if(m_vt1->at(i) > m_vt1->at(candidato)) {
					vigente   = i;
					candidato = vigente;
					eh = true;
				}
			}
		}
		if(eh) troca(vigente, contador);
		contador++;
		vigente   = contador;
		candidato = contador;
		if(contador == (m_vt1->size()-1)) break;
	}
	return m_vt1;
};
// ***************** <<_USAGE_>> *****************
void utils::classificaUsage() {
	using namespace std;
	Classifica lista;
    vetorInt *v1 = new vetorInt();

	for(int i=0; i<10; i++)
		v1->push_back((rand()%100)); // 0~99

    cout << "inteiros desordenados: \n";
    for(unsigned int i=0; i<v1->size()-1; i++)
       cout << " inteiro: " << v1->at(i) << endl;
   
    cout << "inteiros ordenados: \n";
    v1 = lista.ordena(v1);

    for(unsigned int i=0; i<v1->size()-1; i++)
       cout << " inteiro: " << v1->at(i) << endl;

	delete v1;
}

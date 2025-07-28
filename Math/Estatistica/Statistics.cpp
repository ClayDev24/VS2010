#include "statistics.h"

//***********************************************************************
math::Statistics::Statistics(int _sz, ...):m_moda(0), m_media(0), m_mediana(0), m_desvioPadrao(0) {
	va_list args;
	va_start(args, _sz);
	while(_sz--)
		m_valores.push_back(va_arg(args, double));
	va_end(args);
	sort(m_valores.begin(), m_valores.end());
}
//***********************************************************************
double math::Statistics::getModa() {
	std::map<double, double>  repetitions;
	std::map<double, double>::iterator it;
	std::vector<std::map<double, double>> v;

	for(unsigned int i=0; i<m_valores.size(); i++)
		repetitions[m_valores[i]]++;

	for(it = repetitions.begin(); it != repetitions.end(); it++)
		if(it->second > 1) {// Modal
//			v.push_back(static_cast<map<double,double>>(*it));
			std::cout << it->first << "=> " << it->second << std::endl;
		} else // Amodal
			std::cout << "Amodal\n";

	return 0;
}
//***********************************************************************
double math::Statistics::getMedia() {
	for(unsigned int i=0; i<m_valores.size(); i++)
		m_media+=m_valores[i]; // soma de todos os valores
	m_media/=m_valores.size(); // e divide pelo total de valores
	return m_media;
}
//***********************************************************************
double math::Statistics::getMediana() {
	// caso ímpar: O termo central após classificação em ordem.
	// caso par  : a média dos 2 termos centrais.
	int sz = m_valores.size();
	if(sz%2) // se ímpar
		m_mediana = m_valores[(sz/2)];
	else     // se par
		m_mediana = (m_valores[(sz/2)-1] + m_valores[sz/2]) / 2;

	return m_mediana;
}
//***********************************************************************
double math::Statistics::getDesvioPadrao() {
	std::cout << "getDesvioPadrao(): \n";
	int i=0, iMaior=0, iMenor=0;
	int sz=m_valores.size();
	double media = getMedia();
	do {// descobre o maior índice
		if (m_valores[i] > media)//m_valores[iMaior])
			iMaior = i;
		// descobre o menor índice
		if (m_valores[i] < media)//m_valores[iMenor])
			iMenor = i;
	} while(i++ < (sz-1));
	P_(m_valores[iMenor])
	P_(m_valores[iMaior])

	return 0;
}
// **************<<_USAGE_>>****************
void math::_statisticsUsage() {

	utils::dicShow("mathematics", "Estatística");

	Statistics s1(10, 2.0, 2.0, 11.0, 4.0, 7.0, 3.0, 3.0, 5.0, 5.0, 5.0);

	std::cout << s1 << std::endl;

	s1.getModa();
	P_(s1.getMedia())
	P_(s1.getMediana())
	s1.getDesvioPadrao();
}
#pragma once
#include "capacitor.h"

//Special initialization point: The constructor initializer list (occurs only in definition):
elect::CCapacitor::CCapacitor(int &_Value, int _sz):pValue(&_Value), m_size(_sz) {
	m_val1  = pValue[0];	
	m_val2  = pValue[1];
	m_multiplier = pValue[2];
	m_tolerance  = 0;

	m_capacitance = ((m_val1*10)+(m_val2));// * pow(10.0, m_multiplier);
	if(m_size == 3)
		m_capacitance *= pow(10.0, m_multiplier);
} // The list runs bfore any of the main constructor code is executed.

void elect::CCapacitor::print() { 

#ifdef _DEBUG_ON_
	PRINT(m_val1)
		PRINT(m_val2)
		PRINT(m_multiplier)
		PRINT(m_tolerance)		
#endif 

		printf("%0.0f pF\n", m_capacitance);
	printf("%f uF\n", (m_capacitance / 1000000.0)); //<=It's common to represent caps values in microFarads, rather than picoFarads.
}

void elect::CCapacitor::tolerance(float t) {
	char ch;
	char digit=0;
	float *p;
	do {
		puts("\nEntre com o dígito da tolerância: ");
		//gets(word);
		std::cin >> digit;
		p = (float*)toleranceTABLE;
		/* encontra a palavra e imprime seu significado */
		do {
			if((char)*p==digit) {
				puts("significado:");
				printf("%1.2f%% \n", *(p + 1));
				break;
			}
			p += 3; /* avança na lista */
		} while(*p);
		if(!*p)
			puts("a palavra nao esta no dicionario");
		printf("outra? (y/n): ");
		ch = getche();
	} while (toupper(ch) != 'N');
}

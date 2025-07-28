#pragma once
#include <windows.h>
#include <iostream>
#include <stdio.h> // exit()
#include <vector>

typedef void (*funcPtr)();
typedef std::vector<funcPtr>  vfPtr;
// NOT Implemented yet!
//typedef void (*funcPtr1Var)(int);

static void DelayInMilliseconds() {
	Sleep(3000);  // pausa para comer tempo
}

namespace utils {

	static double _chronometer(funcPtr _fPtr) {

#define LARGINT_TO_DOUBLE(LARGINT) LARGINT.HighPart * 4294967296.0 + LARGINT.LowPart
		LARGE_INTEGER cnt0, cnt1, freq;

		double ElapsedTime;
		if (!(QueryPerformanceFrequency(&freq))) {
			fprintf(stderr, "Timer de alta precisao nao disponivel\n\n");
			exit(EXIT_FAILURE);
		}
		QueryPerformanceCounter(&cnt0);	
		// colocar o codigo a cronometrar aqui
		//Sleep(3000);  // pausa para comer tempo
		_fPtr();
		//(*_fPtr)();
		QueryPerformanceCounter(&cnt1);	

//#define NOCURIOUS
#ifndef NOCURIOUS
		/* Informacoes para curiosos... */
		printf("Contador0 = %x%x\n", cnt0.HighPart, cnt0.LowPart);
		printf("Contador1 = %x%x\n", cnt1.HighPart, cnt1.LowPart);
		printf("Frequencia= %x%x (%.0lf_Hz)\n", freq.HighPart, freq.LowPart, LARGINT_TO_DOUBLE(freq));
#endif
		/* ElapsedTime= (cnt1-cnt0)/freq */
		ElapsedTime  = LARGINT_TO_DOUBLE(cnt1);
		ElapsedTime -= LARGINT_TO_DOUBLE(cnt0);
		ElapsedTime /= LARGINT_TO_DOUBLE(freq);
		//printf("Tempo decorrido= %lf_s milisegundos..\n\n", ElapsedTime);
		return ElapsedTime;
	}
	// ***************** <<_USAGE_>> *****************
	static void _chronometerUsage() {
		//void (*fp)();
		//funcPtr fp = &DelayInMiliseconds;
		std::cout << _chronometer(&DelayInMilliseconds) << std::endl;
	}

} // utils
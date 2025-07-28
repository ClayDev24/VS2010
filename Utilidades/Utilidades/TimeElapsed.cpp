//#include <windows.h> // srand();
#include <stdio.h>
#include <time.h>
//#include <dos.h>   // delay()
#include "TimeElapsed.h"
#include "_chronometer.h"

void utils::TimeElapsed(funcPtr2 _fPtr2) {
	clock_t startTime = clock();
	//Sleep(4444);
	_fPtr2();
	//(*_fPtr2)();
	int milliseconds = clock() - startTime;
	int minutes = (milliseconds/(CLOCKS_PER_SEC))/60;
	int seconds = (milliseconds/(CLOCKS_PER_SEC))-(minutes*60);
	int hours   = minutes/60;

	printf("time %02i:%02i:%02i \n", hours, minutes, seconds);
	printf("ms  = %i \n", milliseconds);
}

// ***************** <<_USAGE_>> *****************
void utils::TimeElapsedUsage() {
	utils::TimeElapsed(&DelayInMilliseconds);
	std::cout << utils::_chronometer(&DelayInMilliseconds) << std::endl;
}
//F:\Pewter\Programming\C++\Tuts\C++ Reference Guide\www.cplusplus.com\reference\clibrary\ctime\asctime.html
#include <stdio.h>	// Standard C lib.
#include <time.h>	// Standard C lib.
//#include <cstdio>	// Standard C lib in C++ header.
//#include <ctime>	// Standard C lib in C++ header.
//using namespace std; // Use C++ compiler (not VS) when usin' C++ header versions instead.
#define MST (-7)
#define UTC (0)
#define CCT (+8)

void wait(int seconds);

char *weekday[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

int main() {
	int i;
	time_t rawtime, start, end;
	struct tm *timeinfo;
	char buffer[80];
	double dif;
	
// ASCTIME / CTIME:
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	printf("asctime: %s", asctime(timeinfo));
	printf("ctime  : %s", ctime(&rawtime));
	strftime(buffer, 80, "Now is %I:%M%p.", timeinfo);
	puts(buffer);

// DIFFERENCE TIME:	
	time(&start);
	printf("Start measurin' difference time...\n");

// CLOCK TICKS:
	for(i=5; i>0; i--, wait(1))
		printf("%d\n", i);

// difftime continue:
	time(&end);
	dif = difftime(end, start);
	printf("It took %.2lf seconds...\n", dif);

// GMTIME:
	timeinfo = gmtime(&rawtime);
	puts("Current time around the World:");
	printf("Phoenix, AZ (U.S.) : %2d:%02d\n", (timeinfo->tm_hour+MST)%24, timeinfo->tm_min);
	printf("Reykjavik (Iceland): %2d:%02d\n", (timeinfo->tm_hour+UTC)%24, timeinfo->tm_min);
	printf("Beijing (China)    : %2d:%02d\n", (timeinfo->tm_hour+CCT)%24, timeinfo->tm_min);

// MAKE TIME:
	/* get current timeinfo and modify it to the user's choice */
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	timeinfo->tm_year = 1973  - 1900;
	timeinfo->tm_mon  = 8     - 1; // index from zero
	timeinfo->tm_mday = 29;
	/* mktime sets timeinfo->tm_wday */
	mktime(timeinfo);
	printf("My birthday was a %s.\n", weekday[timeinfo->tm_wday]);

	return(0);
}

void wait(int seconds) {
	clock_t endwait;
	endwait = clock() + seconds *CLOCKS_PER_SEC;
	while(clock() < endwait);
}

#if!defined __ENUMERATOR_H__
#define     __ENUMERATOR_H__

enum colors { red, blue=20, yellow };

void _enumerator() {
	//int i;
	enum colors cor = red;
	// C = weak type checkin. How does it know to incremente a color?
	//for(i=t; i<=rut; i++)				// C/C++.  =>Cast to an int => incremente an int
	for(cor=red; cor<=yellow; cor++)	// C only. =>Incremented enum pass through non collors values (bug)
		printf("%d\n", cor);//i);
	
	printf("%d, %d, %d \n", red, blue, yellow);
}

#endif // __ENUMERATOR_H__
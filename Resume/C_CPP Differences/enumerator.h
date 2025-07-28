#pragma once

enum colors { red, blue/*=20*/, yellow };

static void _enumerator() {
	//int i;
	enum colors cor = red;
	// C = weak type checkin. How does it know to incremente a color?
	for(int i=cor; i<=yellow; i++) // C/C++.  =>Cast to an int => incremente an int
	//for(cor=red; cor<=yellow; cor++)	// C only. =>Incremented enum pass through non collors values (bug)
		printf("%d\n", i);
	
	printf("%d, %d, %d \n", red, blue, yellow);
}
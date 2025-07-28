#pragma once

static void _while_loop() {
	int i = 0;
	while(i < 5) {// Also allow definition var inside control expression
		std::cout << "The value is: " << i++ << std::endl;
	}
}

static void _do_while() {
	int i = 6;
	do { // will execute at least once:
		std::cout << "The value is: " << i << std::endl;
	} while(i < 5);
}

static void _for_loop() {
	for(int i = 5; i < 10; i++)
		std::cout << i << std::endl;
	//i = 0; ERROR: 
	// An earlier iteration o'C++ draft standard said the var lifetime extended to the end
	// scope that enclosed the for loop. Some compilers still implement that
	// Be ware not to use it. It's not portable!
}
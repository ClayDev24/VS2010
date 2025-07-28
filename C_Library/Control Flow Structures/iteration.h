void while_loop() {
	int i=0;
	while(i<5)
		printf("The value is: %i\n", i++);
}

void do_while() {
	int i=5;
	do { // will execute at least once:
		printf("The value is: %i\n", i--);
	} while(i>0);
}

void for_loop() {
	int n=0;
	int i_loop_counter = 5; // for readability
	// empty initialization and increase statement;
	for(; i_loop_counter < 10;)
		printf("%i\n", i_loop_counter++);
	// Complete:
	for(i_loop_counter = 5; i_loop_counter < 10; i_loop_counter++)
		printf("%i\n", i_loop_counter);
	// 2 increase statements:
	for(i_loop_counter = 5; i_loop_counter < 10; i_loop_counter++, n++)
		printf("%i\n", i_loop_counter);
}
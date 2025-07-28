
void if_else() {
	int i=5;
	if(i>5) {
		printf(">5\n");
	} else if(i<5) 
		printf("<5\n");
	else
		printf("=5\n");
}

void if_ternario() {
	int p, i;
	i = 5;
	p = i>0?i*i:-(i*i);
	printf("It's pontency: %i\n", p);
}

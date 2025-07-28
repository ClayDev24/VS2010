void _break() {
  int i=10;
  while(1)
    if(--i==0)
      break;
    else
      printf(".");
}

void _continue() {
	int i;
	printf("Printin' 1..10 (5 skeeped):\n");
	for(i=1; i<=10; i++) {
		if(i==5)
			continue;
		printf("%i ", i);
	}
}

void _goto() {
	int i=10;
loop: // A for loop implemented as goto:
	printf("%i, ", i);
	i--;
	if(i>0) goto loop;

	printf("FIRE\n");
}
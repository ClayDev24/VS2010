typedef enum { sun, mon, tue, wed, thu, fri, sat } week;
week today;

void switch_case() {
	today = sat;
	switch(today) { // Expression that produces any integral value at compile-time.
	case mon: // can only compare values agaist constants, not variables.
	case tue:
	case wed:
	case thu:
	case fri:
		printf("Go get a job!\n");
		break;
	case sat:
		printf("Clean the garden and ");
	case sun:
		printf("relax.\n");
		break;
	default: printf("Erro, day not defined yet..."); // Optional
	}
}

void switch_case2() {
	char ch = 'A';
	switch(ch) {
		case 'A': printf("Snap\n"          ); break;
	    case 'B': printf("Crackle\n"       ); break;
		case 'C': printf("Pop\n"           ); break;
		default:  printf("Not A, B or C!\n"); // Optional
	}
}

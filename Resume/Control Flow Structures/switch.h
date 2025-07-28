#pragma once

enum days {sun, mon, tue, wed, thu, fri, sat};
days today;

static void switch_case() {
	today = sat;
	switch(today) { // just accept integer types at compile-time.
	case mon:
	case tue:
	case wed:
	case thu:
	case fri:
		std::cout << "Gobbbb get a job!\n";
		break;
	case sat:
		std::cout << "Clean the garden and ";
	case sun:
		std::cout << "relax.\n";
		break;
	default: std::cout << "Erro, day not defined yet...";
	}
}

static void switch_case2() {
	using std::cout; // Function Scope
	cout << "Press a, b or c: ";
	switch(int i = std::cin.get()) {
		case 'a': cout << "Snap\n";		break;
		case 'b': cout << "Crackle\n";	break;
		case 'c': cout << "Pop\n";		break;
		default:  cout << "Not a, b or c!\n";
	}
}

/* Copy Cat below
switch(int i = std::cin.get()) { // just accept integer types at compile-time.
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
}
default: std::cout << "Error. Default msg";
*/
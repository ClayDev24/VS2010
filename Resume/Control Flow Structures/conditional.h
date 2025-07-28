#pragma once

static void _if_else() {
	int n=6;

	if(n > 5) {
		std::cout << n << " > 5\n";
	} else if(n < 5) 
		std::cout << n << " < 5\n";
	else
		std::cout << n << " = 5\n";
}

static void _if_ternario() {
	int p, i=5;
	p = i > 0 ? i * i : -(i * i);
	std::cout << "It's pontency: " << p << std::endl;
}

#include <iostream>

/* Define um tipo de estrutura. */
struct struct_type {
	int a, b;
	char ch;
} typedef struct1;

//void f1(struct struct_type parm) {
void f1(struct1 parm) {       
	std::cout << parm.a << std::endl;
}

void _structAsParameters() {
    // without typedef:
	//struct struct_type arg;
	//with typedef:
    struct1 arg;
	arg.a = 100;
	f1(arg);
}
#pragma once
// Function to a pointer. Pág 198 TICPP v2
#include <iostream>
#include <vector>

typedef void (*fPtr1)(); // no args for this func.
typedef void (*fPtr2)(int, int); // no args for this func.
typedef std::vector<fPtr1> vPtr1;
typedef std::vector<fPtr2> vPtr2;

static void func1() {
	std::cout << "No argments function.\n";
}

static void func2(int _i, int _i2) {
	std::cout << "args sum=>  " << (_i + _i2)  << std::endl;
}

static void _vetor() {
	/*
	void (*fp1)(int, int);	// Define a function pointer
	fp1 = func1;	    // Pointin' to a func syntax.
	(*fp1)(1, 2);		// Dereferencin' ptr to call the func syntax 1
	fp1(2, 3);			// Dereferencin' ptr to call the func syntax 2
	*/
	vPtr1 vetor1;
	fPtr1 fp1 = &func1;
	vetor1.push_back(fp1);
	vetor1.push_back(func1);
	vetor1[0]();
	vetor1[1]();
	fp1 = vetor1[0];
	fp1();
	fp1 = vetor1[1];
	fp1();

	vPtr2 vetor2;
	fPtr2 fp2 = &func2;
	vetor2.push_back(fp2);
	vetor2.push_back(func2);
	vetor2[0](1, 1);
	vetor2[1](2, 2);
	fp2 = vetor2[0];
	fp2(3, 3);
	fp2 = vetor2[1];
	fp2(4, 4);
}
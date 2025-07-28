#pragma once
#include <iostream>
#include <vector>

typedef void (*fPtr1)(); // no args for this func.
typedef void (*fPtr2)(int, int); // no args for this func.

static void function1() {
	std::cout << "No argments function.\n";
}

static void function2(int _i, int _i2) {
	std::cout << "args sum=>  " << (_i + _i2)  << std::endl;
}

static void function3(fPtr1 _fp1) {
	std::cout << "__<<inside function BEGIN>>__\n";
	_fp1();
	(*_fp1)();
	std::cout << "__<<inside function END>>__\n\n";
}

static void function4(fPtr2 _fp2) {
	std::cout << "__<<inside function BEGIN>>__\n";
	_fp2(5, 5);
	(*_fp2)(5, 5);
	std::cout << "__<<inside function END>>__\n\n";
}

static void _passAsArguments() {
	fPtr1 fp1 = &function1;
	function3(&function1);
	function3(function1);
	function3(fp1);

	fPtr2 fp2 = &function2;
	function4(&function2);
	function4(function2);
	function4(fp2);
}
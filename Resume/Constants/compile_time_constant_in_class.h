#pragma once
#include <string>
#include <iostream>
// Using static const to create a compile-time constant inside a class

class StringStack {
	static const int size = 100;
	const std::string* stack[size];
	int index;
public:
	StringStack();
	void push(const std::string* s);
	const std::string* pop();
};

StringStack::StringStack() : index(0) {
	memset(stack, 0, size * sizeof(std::string*));
}

void StringStack::push(const std::string* s) {
	if(index < size )
		stack[index++] = s;
}

const std::string* StringStack::pop() {
	if(index > 0) {
		const std::string* rv = stack[--index];
		stack[index] = 0;
		return rv;
	}
	return 0;
}

static std::string iceCream[] = {
	"pralines & cream",
	"fudge ripple",
	"jamocha almond fudge",
	"wild mountain blackberry",
	"rapsberry sorbet",
	"lemon swirl",
	"rocky road",
	"deep chocolate fudge"
};

const int iCsz = sizeof iceCream / sizeof *iceCream;

static void _compile_time_constant_in_class() {
	StringStack ss;
	for(int i = 0; i < iCsz; i++)
		ss.push(&iceCream[i]);
	const std::string* cp;
	while((cp = ss.pop()) != 0)
		std::cout << *cp << std::endl;
}
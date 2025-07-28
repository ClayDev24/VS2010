//: C01:BadException.cpp
// WORKS ONLY IN BCC32 COMPILER!
#pragma once
#include <exception>    // for std::bad_exception
#include <iostream>
#include <cstdio>
// Exception classes:
class C {};
class D {};
// terminate() handler
static void my_thandler() {
	std::cout << "terminate called\n";
	std::exit(0);
}
// unexpected() handlers
static void my_uhandler1() {
	throw C();
}
static void my_uhandler2() {
	throw;
}
// If we embed this throw statement in f or g,
// the compiler detects the violation and reports
// an error, so we put it in its own function.
static void t() {
	throw D();
}

void j() throw(C) { t(); }
void h() throw(C, std::bad_exception) { t(); }

static void _bad_exception() {
	using namespace std;
	set_terminate(my_thandler);
	set_unexpected(my_uhandler1);
	try {
		j();
	} catch(C&) {
		cout << "caught an A from f\n";
	}
	set_unexpected(my_uhandler2);
	try {
		h();
	} catch(bad_exception&) {
		cout << "caught a bad_exception from g\n";
	}
	try {
		j();
	} catch (...) {
		cout << "This will never print\n";
	}
}
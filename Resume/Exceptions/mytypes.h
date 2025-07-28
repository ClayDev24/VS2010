#pragma once
#include <iostream>
#include "MyError.h"
using namespace std;

enum mytypes {
	myexp1 = 1,
	myexp2,
	myexp3,
	myexp4,
	myexp5,
	myexp6,
	myexp7,
	myexp8,
	myexp9,
	myexp10
};

static void _mytypes() {
    try {
		throw myexp5;
    }
	// Exception Handlers
    catch(const char *msg) { // Catches string types
        cout << msg;
	} catch(const mytypes &ex) { // Exception type usually gives you enough info to deal with it.
		cout << "Exception type:" << ex << endl;
	} catch(...) { // Catches everything didn't catched so far. Put it at the end o'catch clauses.
        cout << "Caught unknown exception!\n";
    }
}
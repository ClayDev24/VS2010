#pragma once
#include <iostream>
#include "mytypes.h"

static void _rethrowing() {
    try {
		throw myexp5;
    } // Rethrow exceptions is usually used when ya got some resouces ta be released.
	catch(...) { // Catches everything didn't catched so far. Put it at the end o'catch clauses.
		std::cout << "Deallocatin' some resources...\n";
		throw; // To be catched by higher up context in the chain. Obj is preserved as it is.
    }
}
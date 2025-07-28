#pragma once
// Accessing external global variables
extern int globe;  
// (The linker resolves the reference)
static void func() {
	globe = 47;
} 

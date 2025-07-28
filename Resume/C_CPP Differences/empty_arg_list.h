#pragma once

// Empty arg list: C = any number args. C++ = Zero args
static void empty_arg_list() {};	// C: Any number and type of arguments. C++ = void
// To avoid misusse use void keyword in C:
static void void_arg_list(void) {};	// C/C++ void arg = nothing

static void _empty_arg_list() {
	
	// Leads to misuse in C:
//	empty_arg_list(5);
//	empty_arg_list(5.5);
//	empty_arg_list(5, 5);
//	empty_arg_list(5, 5.5);
//	empty_arg_list(5.5, 5);
//	/*i = */void_arg_list(5);
}
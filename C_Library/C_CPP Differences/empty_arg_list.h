#ifndef __EMPTY_ARG_LIST_H__
#define __EMPTY_ARG_LIST_H__

// Empty arg list:
// C = any number args. C++ = Zero args
void empty_arg_list() {};	// C: Any number and type of arguments. C++ = void
// To avoid misusse use void keyword in C:
void void_arg_list(void){};	// C/C++ void arg = nothing

void _empty_arg_list() {
	int i;
	// Leads to misuse in C:
	empty_arg_list(5);
	empty_arg_list(5.5);
	empty_arg_list(5, 5);
	empty_arg_list(5, 5.5);
	empty_arg_list(5.5, 5);
	/*i = */void_arg_list(5);
}

#endif // __EMPTY_ARG_LIST_H__
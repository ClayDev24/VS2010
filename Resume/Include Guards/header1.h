#ifndef HEADER_FILE_H // Prevents multiple definition error (for vars, structs/classes)
#define HEADER_FILE_H // in a single compilation unit (file.cpp)
// Basic rule: Put only declarations in a header file (nothin'that allocates storage):
// Only matters for several inclusions across translation units in a project.
// C++ definition rule: Multiple declarations, one definition.
static int global  = 0; // static var has visibility only within a file (scoped): Multiple instances (storage) across the project (memory). Prevents liker collision.
//	   int global2 = 0; // Redefition ERROR: Name linker collision.

struct strc { // type redefinition ERROR!
	int i;
};

// C/C++  Multiple declarations allowed as long as the parameters match:
void function1();
void function1();
void function1();

#endif // HEADER_FILE_H => Leadin' underscores are reserved for system names.
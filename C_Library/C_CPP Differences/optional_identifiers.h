#ifndef __OPTIONAL_IDENTIFIERS_H__
#define __OPTIONAL_IDENTIFIERS_H__

int func2(int);		// C/C++ Optional identifiers arg list declaration.
// The identifiers w/out usage in def. C(required)/C++(optional)
// 1-They reserves space 4 future inclusions. 2-Removes the annoyin msg o'unused var
int func2(int i) { return 2; }
//int func2(int) { return 2; } // C++

void _optional_identifiers() {

}

#endif // __OPTIONAL_IDENTIFIERS_H__
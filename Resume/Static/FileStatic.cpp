//: C03:FileStatic2.cpp {O}
// Trying to reference fs in compilation unit main.obj
extern int fs;
extern void func();
int localExt = 115;

static void func2() {
//	fs = 100; // ERROR: Unresolved external, 'cuz fs has internal linkage (static) in Static.cpp
	func();
}

// Assembly.cpp
// Compile as follow: bcc32 -S Assembly
// To view .asm file the generated assembly COMPILER FUNCTIONS NAME DECORATED:
#include <iostream>
using namespace std;

// Global Function overloadin':
void func() {}
void func(int i) {}
void func(int i, double d) {}
void func(int i, double d, char c) {}

// Class Scoped function overloadin':
class ClassExample {
public:
	void func();
	void func(int i);
	void func(int i, double d);
	void func(int i, double d, char c);
};

void ClassExample::func() {}
void ClassExample::func(int i) {}
void ClassExample::func(int i, double d) {}
void ClassExample::func(int i, double d, char c) {}

int main(void) {
	func();			 //@@func$qv
	func(0);		 //@@func$qi
	func(0, 0);		 //@@func$qid
	func(0, 0, 'a'); //@@func$qidc
	
	ClassExample *ce = new ClassExample(); // Compiler calls default constructor
	ce->func();			//@@ClassExample@func$qv
	ce->func(0);		//@@ClassExample@func$qi
	ce->func(0, 0);		//@@ClassExample@func$qid
	ce->func(0, 0, 'a');//@@ClassExample@func$qidc
	
	system("pause");
	return(0);
}
#include <iostream>
// compile with: bcc32 -S main.cpp to generate main.asm file.
// CANNOT overload by return values
int   ret_val(int) {return 0;}		// @@ret_val$qi
// Errors:
//char  ret_val(int) {return 'c';}	// @@ret_val$qi
//float ret_val(int) {return 5.5f;}	// @@ret_val$qi

// Class Scope Asm Name Decoration:
class A {
	void func1();				// @@A@func1$qv
	void func1(char);			// @@A@func1$qc
	void func1(unsigned char);	// @@A@func1$quc
	void func1(signed char);	// @@A@func1$qzc
	void func1(bool);			// @@A@func1$qo
	void func1(short);			// @@A@func1$qs
	void func2(short int);		// @@A@func2$qs
	void func1(int);			// @@A@func1$qi
	void func1(long);			// @@A@func1$ql
	void func2(long int);		// @@A@func2$ql
	void func1(float);			// @@A@func1$qf
	void func1(double);			// @@A@func1$qd
	//void func1(long float);	// Not works in bcc32 compiler
	void func1(long double);	// @@A@func1$qg
};
void A::func1() {}
void A::func1(char) {}
void A::func1(unsigned char) {}
void A::func1(signed char) {}
void A::func1(bool) {}
void A::func1(short) {}
void A::func2(short int) {}
void A::func1(int) {}
void A::func1(long) {}
void A::func2(long int) {}
void A::func1(float) {}
void A::func1(double) {}
//void A::func1(long float) {}
void A::func1(long double) {}

// Namespace Scoped Asm Name Decoration:
namespace res {
	void func1() {}					// @@clb@func1$qv
	void func1(char) {}				// @@clb@func1$qc
	void func1(unsigned char) {}	// @@clb@func1$quc
	void func1(signed char) {}		// @@clb@func1$qzc
	void func1(bool) {}				// @@clb@func1$qo
	void func1(short) {}			// @@clb@func1$qs
	void func2(short int) {}		// @@clb@func2$qs
	void func1(int) {}				// @@clb@func1$qi
	void func1(long) {}				// @@clb@func1$ql
	void func2(long int) {}			// @@clb@func2$ql
	void func1(float) {}			// @@clb@func1$qf
	void func1(double) {}			// @@clb@func1$qd
	//void func1(long float) {}		// Not works in bcc32 compiler
	void func1(long double) {}		// @@clb@func1$qg
} // res
// Global Space Asm Name Decoration:
void func1() {}					// @@func1$qv
void func1(char) {}				// @@func1$qc
void func1(unsigned char) {}	// @@func1$quc
void func1(signed char) {}		// @@func1$qzc
void func1(bool) {}				// @@func1$qo
void func1(short) {}			// @@func1$qs
void func2(short int) {}		// @@func2$qs
void func1(int) {}				// @@func1$qi
void func1(long) {}				// @@func1$ql
void func2(long int) {}			// @@func2$ql
void func1(float) {}			// @@func1$qf
void func1(double) {}			// @@func1$qd
//void func1(long float) {}	
void func1(long double) {}		// @@func1$qg

// Name decoration provides a safety net called "Type-safe linkage".
int main() {

	system("pause");
	return 0;
}
//#include "vld.h" // No memory leaks DETECTED!
#include <iostream>
using namespace std;
//***DEFINES***
#define P(EX)   cout << #EX ": " << EX << endl;
#define ABS(a)  ((a)<0?-(a):(a))
#define mkstr(s) #s
#define concat(a,b) a##b
#define MAX 100 // Tipical C way to define constants (no type checking)
#define TED		// In either case the label has been defined and can be tested with #ifdef
// elif: Equivalent to "if else if" C++ Statements:

#define TABLE_SIZE 350

#if     TABLE_SIZE>200
#undef  TABLE_SIZE	// The complement (opposite) o' #define
#define TABLE_SIZE 200

#elif   TABLE_SIZE<50
#undef  TABLE_SIZE
#define TABLE_SIZE 50

#else
#undef  TABLE_SIZE
#define TABLE_SIZE 100
#endif
//
#ifndef __cplusplus // The complement o' #ifdef
#error A C++ compiler is required! // Abort compilation process when reaches this line.
#endif 
// Macros side effects:
#define BAND(x) (((x)>5 && (x)<10) ? (x) : 0)
// Stringizing op(#)(Std C): Takes a identifier n'turns it in2 a char array(string literal).
#define PRINT(x) cout << #x " = " << x << endl;
// Token pasting:
#define FIELD(a) char* a##_string; int a##_size;

#ifdef NDEBUG
#define assert(cond) ((void)0)
#else
void assertImpl(const char* file, long line){ cout << file << ", line: " << line << endl; };
#define assert(cond) \
	((cond) ? (void)0 : assertImpl(__FILE__, __LINE__))
#endif

class Record {
public:
	FIELD(one);
	FIELD(two);
	FIELD(three);
};
// Creating classes:
#define CLASS(ID) class ID { \
public: \
	ID(int) { cout <<     #ID "()\n"; } \
	~ID()   { cout << "~" #ID "()\n"; } \
};

CLASS(Base1);
CLASS(Member1);
CLASS(Member2);

int main() {
	cout << "ABS(-1):" << ABS(-1) << endl;
	cout << "ABS(1) :" << ABS(1)  << endl;
	// Conditional Inclusions:
#if MAX > 99
	cout << "MAX > 99\n";
#else
	cout << "MAX <= 99" << endl;
#endif

#ifdef TED
	cout << "Oi Ted\n";
#else
	cout << "Oi qualquer um" << endl;
#endif

#ifndef RALPH
	cout << "RALPH's out\n";
#endif
	//#line 47	"Preprocessor.cpp"			// inicializes __LINE__ and __FILE__ predefined macros
	// Predefined MACROS:
	cout << "line: " << __LINE__    << endl;
	cout << "file: " << __FILE__    << endl;
	cout << "date: " << __DATE__    << endl;
	cout << "time: " << __TIME__    << endl;
	cout << "c++ : " << __cplusplus << endl;
	// # - String Literal replacement:
	cout << mkstr(Eu gosto de CPP\n);
	// ## - Concatenates 2 arguments w/o spaces between them:
	int xy = 10;
	cout << concat(x, y) << endl;

	int i = 44;
	PRINT(i);
	PRINT(i + 6);

	Record rec;
	rec.one_size   = 0;
	rec.one_string = "zero";
	{
		Base1   b1(1);
		Member1 m1(1);
		Member2 m2(1);
	}
	//Macro side effects:
	for(i=4; i<11; i++) {
		int a = i;
		cout << "a        : " << a         << endl;
		cout << "BAND(++a): " << BAND(++a) << endl;
		cout << "a        : " << a         << endl;
	}

	system("pause");
	return(0);
}
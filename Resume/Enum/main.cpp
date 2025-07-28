//#include "vld.h" // No memory leaks DETECTED!
#include <iostream>
#include "anonymous.h"
#include "save_space.h"
#include "untagged.h"
using namespace std;

// Enumerated data type = A way o'attachin'names to numbers givin'em meaning'to any reader.
typedef enum collors  { red,  blue =20, yellow  } collors;	// typedef named enum
typedef enum          { red2, blue2=20, yellow2 } collors2;	// typedef unnamed enum
		enum collors3 { red3, blue3=20, yellow3 } cor;		// Declarin'a global var cor

int main() {
	collors		  c1; // C/C++ Clean   typedef
	enum collors  c2; // C/C++ Awkward enum
	collors2	  c3; // C/C++ Clean   typedef
	enum collors2 c4; // C/C++ Awkward enum
	collors3	  c5; // C++   Clean   enum
	enum collors3 c6; // C/C++ Awkward enum

	//for(cor=red3; cor<=yellow3; cor++) // C only. Incremented enum
	for(int i=cor; i<=yellow3; i++) {
		switch(i) {
		case red3:
			cout << "red3   : " << red3    << endl; break;
		case blue3:
			cout << "blue3  : " << blue3   << endl; break;
		case yellow3:
			cout << "yellow3: " << yellow3 << endl; break;
		}
	}
	//_anonymous();
	//_untagged();
	_save_space();

	system("pause");
	return(0);
}
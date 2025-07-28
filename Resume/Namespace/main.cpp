// NEVER USE using namespace directibe in header files. This will thrown open that namespace
// to all the translation units that imports tha header file! (and header files can include other header files).
// Doin' so you'll pollyte the global namespace and trhow yourself back into the pre-namespace world of C.
// Use instead Scope resolution or Scoped using directive.
//#include "vld.h" // No memory leaks DETECTED!
#include <iostream>
#include <string>
using namespace std; // Using directive to introduce all std namespace at once GLOBALLY (in this compilation unit)
using std::cout;	 // Scoped using directive to introduce funcs & vars alones.
using std::endl;

void func2() {
	using namespace std; // Open std namespace LOCALLY in this function!
	cout << "func2()..." << endl;
}; // end of std namespace appearence.

namespace ns1 {
	void func1() {
		cout << "ns1::func1()..." << endl;
	}
}

namespace ns2 {
	void func1() {
		cout << "ns2::func1()..." << endl;
	}
	void normal() {
		cout << "ns2::normal()..." << endl;
	}
}

namespace ns1 { // continuation of ns1
	void otherFun() {
		cout << "ns1::otherFun()..." << endl;
	}
}

// Big weird namespace name:
namespace abcdefghijklmnopq {
	//...
}

// Unnamed namespace. Internal linkage. Needless to use static keyword.
// C++ deprecates the use of file statics in favor of the unnamed namespace:
namespace {
	class Arm {};
	class Leg {};
	class Head {};
	class Robot {
		Arm arm[4];
		Leg leg[16];
		Head head[3];
		//...
	} xanthan;
	int i, j, k;
}

// Friend func in namespace:
namespace Me {
	class Us {
	public:
		//...
		friend void you() { cout << "you()..." << endl; }; // you() is a member of the namespace Me.
	};
}

int main() {
	using namespace ns1;
	using namespace ns2;
	using std::string;
	// oo 
	typedef std::string String;
	string n1 = "name";
	String n2 = "name";
	//func1(); //ERROR: ambiguous call to overloaded function
	ns1::func1(); // scope resolution
	ns2::func1();
	normal();
	otherFun();

	// Aliasin' namespace name:
	namespace abc = abcdefghijklmnopq;

	//Me::you();

	system("pause");
	return(0);
}
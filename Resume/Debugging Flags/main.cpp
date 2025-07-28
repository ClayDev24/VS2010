//#include "vld.h" // No memory leaks DETECTED!
#include <iostream>
#include <string>
using namespace std;

// Statically (compile-time) Debugging flags:
//#define _DEBUG_
//..
//#ifdef _DEBUG_ // Check to see if flag is defined
/* debugging code here */
//#endif // _DEBUG_

int main(int argc, char* argv[]) {
	// Dynamically (run-time) debugging:
	bool debug = false;
	for(int i=0; i<argc; i++)
		if(string(argv[i]) == "--debug=on")
			debug = true;
	bool go = true;
	while(go) {
		if(debug) {
			// Debugging code here
			cout << "Debugger is now on!\n";
		} else
			cout << "Debugger is now off.\n";  
		cout << "Turn debugger [on/off/quit]: ";
		string reply;
		cin >> reply;
		if(reply == "on")  debug = true;
		if(reply == "off") debug = false;
		if(reply == "quit") break;
	}

	system("pause");
	return(0);
}
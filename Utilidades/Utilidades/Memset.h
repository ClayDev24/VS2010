#pragma once

#define MEMSET(OP, SZ) \
	memset(OP,0,SZ*sizeof(OP[0]));
// shows selected (I)ndex:

#define PARRAY(X, SZ, TYPE) \
	for(int i=0; i<SZ; i++) \
		std::cout << #X "[" << i << "]=> " << (TYPE)X[i] << std::endl;

namespace utils {

	static void _memsetUsage() {
		using namespace std;
		const int  SZ = 10;
		cout << "<<_Fast Initialization_>>\n";
		char  pc1[SZ]={'a'}; // Initializes first 'a' and the following with zeros.
		PARRAY(pc1, SZ, char)
		int  pc2[SZ]={0};   // Initializes ALL with zeros.
		PARRAY(pc2, SZ, int)

		cout << "<<_Garbage bfore proper initialization:\n";
		// Array of chars: 
		char pChar[SZ];
		PARRAY(pChar, SZ, char)

		memset(pChar, 'a', SZ*sizeof(char));
		cout << "<<_Proper initialization to zero with memset():\n";
		PARRAY(pChar, SZ, char)
		// Array of ints:
		int pInt[SZ];
		cout << "<<_Garbage bfore proper initialization:\n";
		PARRAY(pInt, SZ, int)

		memset(pInt, 0, SZ*sizeof(int));
		cout << "<<_Proper initialization to zero with memset():\n";
		PARRAY(pInt, SZ, int)
	}

} // utils
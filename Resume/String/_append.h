#pragma once
#include <iostream>
#include <fstream>
#include <string>

namespace resume {

	static void _append() { // Append at the end o'str.
		using namespace std;
		string str;
		string name = "claybom ";
		// used in the same order as described above:
		str.append(name);							// claybom 
		str.append("is ");							// is
		str.append(name, 4, 3);						// bom
		str.append(", dots are cool", 6);			// , dots
		str.append(10, '.');						//  ..........
		str.append(name.begin(), name.begin()+4);	// clay
		str.append<int>(5, 0x2E);					// .....
		cout << str << endl;
	}

}// resume
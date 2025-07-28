#pragma once
#include <iostream>
#include <string>
#include "typedefs.h"
#include "_colour.h"
#include "_conversions.h"

namespace utils {

	template <typename T>
	static void _showVetor(T &vt, std::string end="\n") {
		for(unsigned int i=0; i<vt.size(); i++)
			std::cout << i+1 << "=> " << vt[i] << end;
		//P_(vt[i])
	}
	// ***************** <<_USAGE_>> *****************
	static void _showVetorUsage() {
		PrintColour_("\n<<_Printing INTeger vetor_>>", BRI);
		vetorInt vi;
		for(int i=0; i< 10; i++)
			vi.push_back(i);
		_showVetor(vi);

		PrintColour_("\n<<_Printing CHAR vetor_>>", BRI);
		vetorChr vc;
		for(int i=97; i< 107; i++)
			vc.push_back(static_cast<char>(i));
		_showVetor(vc);

		PrintColour_("\n<<_Printing STRING vetor_>>", BRI);
		vetorStr vs;
		for(int i=97; i< 107; i++)
			vs.push_back(_toStr(i));
		_showVetor(vs);
	}

} // utils
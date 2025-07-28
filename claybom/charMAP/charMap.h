#pragma once
#include "utils.h"
//#define DEBUG

namespace clb {

	vetorInt* charMAP(const int &_sz) {
		vetorInt *vi = new vetorInt();
		for(int i=0; i<=_sz; i++)
			//if (i != 26)  // ANSI Terminal Clear screen
				vi->push_back(i);
		return vi;
	}
	// **************<<_USAGE_>>****************
	void _charMAPUsage(const int &_x, const int &_y, const WORD &_cor) {
		utils::Console cmd(_x, _y, TEXT("<<_CharMAP_>>"));
		const int MAX = 256;
		vetorInt *v = charMAP(MAX);
		int x=0;
		int y=0;

		cmd.fillConsole(_cor);
		cmd.gotoxy(0, 0);
		utils::PrintColour_("******<<_CHARACTER_MAP_>>******\n");

		for(int i=0; i<=MAX; i++) {
			utils::PrintColour(" ", _cor);
			cmd.gotoxy(x, y);

			std::cout.width(3);
			//std::cout << std::hex << i << " " << (unsigned char)i << std::flush;
			std::cout << i << "-" << (unsigned char)v->at(i) << std::flush;

			if(++y > 31) {
				y  = 0;
				x += 6;
			}
		}
		cmd.gotoxy(0, 32);			
		delete v;
	}
}
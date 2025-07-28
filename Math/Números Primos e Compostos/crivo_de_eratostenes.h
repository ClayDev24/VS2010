#pragma once
#include "utils.h"
#include "..\..\Utilidades\Console\virtualKeyCodes.h" // Events()
namespace math {

// O Crivo de Eratóstenes é um algoritmo e um método simples e prático p/ encontrar números primos até um certo valor limite.
// Segundo a tradição, foi criado pelo matemático grego Eratóstene.
static void MouseMatrix(int _x=80, int _y=60, const char *_msg="<<_MATRIX_>>") { // Columns x Lines
	using namespace std;
	utils::Console cmd(_x, _y, "<<_Crivo de Aritóstenes_>>");

	DWORD events = 0;
	DWORD read   = 0;
	bool  run	 = true;
	while(run) {
		GetNumberOfConsoleInputEvents(cmd.GetHandleIn(), &events);
		if(events) {
			INPUT_RECORD *evt = new INPUT_RECORD[events];
			ReadConsoleInput(cmd.GetHandleIn(), evt, events, &read);

			for(DWORD i = 0; i < read; i++) {
				if(evt[i].EventType == MOUSE_EVENT) {
					COORD pos = evt[i].Event.MouseEvent.dwMousePosition;

					for(int h = 0; h < (sizeof(mouseButtons)/sizeof(WORD)); h++) {
						if(evt[i].Event.MouseEvent.dwButtonState & mouseButtons[h]) {
							//cout << mouseButtonStrs[h] << endl;
							cmd.cursor(pos.X, pos.Y);
							cmd.write2Console("HH", pos.X, pos.Y, FRI);
						}
					}
				}
			}
			delete[] evt;
		}
	}
}
	static void _crivo_de_eratostenes() {
		utils::Console cmd(80, 60, TEXT("<<_Crivo de Eratóstenes_>>"));
		//cmd.fillConsole(FWI);
		//cmd.gotoxy(0, 0);
		TAB utils::PrintColour_("******<<_Crivo de Eratóstenes_>>******\n", FRI);
		utils::PrintColour_("Riscar todo múltiplo de 2, 3, 5 e 7...", FY);

		for(int x=1; x<=100; x++) {
			utils::PrintColour(" ", BGI);

			std::cout.width(3);
			std::cout << x << "-";
			if(!(x%10)) {N N}
		}
		for(int y=1; y<=10; y++) {
			for(int x=0; x<=9; x++) {
				// coluna x linha
				cmd.gotoxy((x*5)+1, (y*2)+1);
				std::cout.width(3);
			}
		}
		MouseMatrix(56, 25, "<<_Crivo de Aritóstenes_>>");
	}
}
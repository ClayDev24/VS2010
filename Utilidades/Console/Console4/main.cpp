//#include "vld.h"
#include <conio.h> // getche()
#include <iostream>
#include "colour.h"
#include "console.h"
#include "graphical.h"
#include "component.h"
#include "framework.h"
using namespace std;
using namespace clb;

int main() {

	Framework f1("Framework1", 90, 25, BGI);

//	Console cmd(100, 60, "Console Main");
/*	cmd.setWindowSize(40, 40);
	cmd.info();
	cmd.setBufferSize(55, 55);
	cmd.cls();

	cmd.doubleBuffering("=", BB |FRI, 0, true, 15, 15, 39, 39);
	cmd.doubleBuffering("=", BB |FRI, 0, true, 0,  0,  14, 14);
	cmd.doubleBuffering("=", BRI|FYI, 0, true, 7,  7);
	cmd.doubleBuffering(" ",       0, 0, true, 12, 12, 17, 17);

	cmd.doubleBuffering(" claybom",  0,  0, false, 0, 0, 14, 14);
	cmd.doubleBuffering(" claybom2", 0,  0, false, 15, 15);
	cmd.doubleBuffering(" hahaha",   0,  0, false, 7, 7, 22, 22);
	cmd.doubleBuffering(" Mary Loou", 0, 0, false, 5, 12, 17, 17);

	cmd.doubleBuffering(" ", BGI, 0, false, 12, 12);
	//cmd.cls();
//	cmd.printConsole("Teclado habilitado para o porguguês!", 10, 10);
	cmd.write2Console("Maria Ap. da Silva", 5, 13, FY);
	cmd.write2Console("Maria Ap. da Silva", 4, 6, 0);
	_getche();
	cmd.write2Console("Hey I'm here! hahaha", 1, 1);
	cmd.gotoxy(120,120);
	//cmd.cls();
	_getche();*/
	//cmd.fillConsole(BRI,'_', 0, 0, 0);
//	cmd.canvas('x', BR|FRI, 5, 5);

	//cmd.cursor(0,0);
	//cmd.colourSamples();
	
//	Graphical gr(90,50, "Graphical Console");
//	_getche();
	//cmd.info();

	//cmd.title(TEXT("<<_Title Test_>>"));
	// Cleans only the foreground stuff:
	//cmd.cls('*', 10, 10, 800, true);
	//cmd.cls();
	//PrintColour("Hello World!", FRI);
	//cmd.colourSamples();
	//cmd.mouse();
	//cmd.cursor(100);
	//cmd.error();
	//cmd.scrolling();
	//_readConsole();
	//cmd.events();
	//cmd.movingSize(5, 5, 5);

	_getche();
	return(0);
}
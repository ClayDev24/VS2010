#pragma once
#include "D3DGraphics.h"
#include "Keyboard.h"

class Game {
public:
	Game(HWND hWnd,const KeyboardServer& kServer);
	void Go();
private:
	void ComposeFrame();
	/*******_User Functions_*********/
	/*                */
	// TODO: User functions go here
	/********************************/
private:
	D3DGraphics    gfx;
	KeyboardClient kbd;
	/*******_User Variables_*********/
	/*                */
	// TODO: User variables go here
	/********************************/
};
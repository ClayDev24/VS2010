#include "Game.h"

Game::Game(HWND hWnd,const KeyboardServer& kServer)
:	gfx ( hWnd ),
	kbd( kServer )
{}

void Game::Go() {
	gfx.BeginFrame();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::ComposeFrame() {
	//for(int x=0; x<800; x++)
	//	for(int y=0; y<200; y++)
			gfx.PutPixel(10,10,255,255,255);
}
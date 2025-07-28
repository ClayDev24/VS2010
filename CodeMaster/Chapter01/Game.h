#pragma once
#include "SDL/SDL.h"
// Vector2 struct just stores x/y coordinates
// (for now)
struct Point {
	float x;
	float y;
};
// Game class
class Game {
private:
	SDL_Window   *mWindow;	 // SDL Window
	SDL_Renderer *mRenderer; // Renderer for 2D drawing
	Uint32 mTicksCount;		 // Number of ticks since start of game
	bool mIsRunning;		 // Game should continue to run
	// Pong specific
	int mPaddleDir;		// Direction of paddle
	Point mPaddlePos;	// Position of paddle
	Point mBallPos;	// Position of ball
	Point mBallVel;	// Velocity of ball
	// Helper functions for the game loop
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();
public:
	Game();
	bool Initialize();	// Initialize the game
	void RunLoop();		// Runs the game loop until the game is over
	void Shutdown();	// Shutdown the game
};

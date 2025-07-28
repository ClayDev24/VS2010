#include "Game.h"

int main(int argc, char *args[]) {
	Game game;
	bool success = game.Initialize();
	if(success)
		game.RunLoop();
	game.Shutdown();

	system("pause");
	return(0);
}

#include "Game.h"

int main(int argc, void** argv[])
{
	// Program entry point.
	Game game;
	while (game.GetWindow()->IsRunning())
	{
		game.HandleInput();
		game.Update();
		game.Render();
		game.RestartClock();
	}
	
	return 0;
}
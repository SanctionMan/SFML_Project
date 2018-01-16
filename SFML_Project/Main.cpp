#include "Game.h"

int main(int argc, void** argv[])
{
	// Program entry point.
	Game game;
	while (game.GetWindow()->IsRunning())
	{
		game.Update();
		game.Render();
		game.LateUpdate();
	}
	
	return 0;
}
#include <iostream>
#include "raylib.h"
#include "Game.h"


const int FPS{ 60 };

int main()
{
	InitWindow(1280, 900, "platformer");
	SetTargetFPS(FPS);

	Game game;

	while (!WindowShouldClose())
	{
		game.update();
		game.draw();
	}
	CloseWindow();
	game.unload();
	return 0;
}
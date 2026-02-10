#include "Game.h"

Game::Game()
{
}

void Game::update()
{
	player.update(gravity, map);
}

void Game::draw()
{
	BeginDrawing();
		ClearBackground(DARKGRAY);
		bg.draw();
		map.draw();
		player.draw();
	EndDrawing();
}

void Game::unload()
{
	player.unload();
}
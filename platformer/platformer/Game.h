#pragma once
#include "raylib.h"
#include "Player.h"
#include "Background.h"
#include "Map.h"
#include <iostream>
#include <vector>
struct Game
{
	//classes
	Player player;
	Background bg;
	Map map;

	//consts
	const float gravity{ 1500 };

	//methods
	Game();
	void update();
	void draw();
	void unload();
};


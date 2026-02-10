#pragma once
#include "raylib.h"
#include <iostream>
class Map
{
private:
	Texture2D tiles_texture;
	float tile_size;
	float original_size{ 16.0f };
	const static int rows{6};
	const static int cols{10};

	int map[rows][cols]
	{
		{0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,},
		{1,1,1,1,1,1,1,1,1,1,}
	};

public:
	Map();

	void draw();
	void drawHelper(float xindex, float yindex, int i, int j);
	void unload();

	int getTile(int row, int col);
	int getTileSize() { return tile_size; }

};


#include "Map.h"


Map::Map()
{
	tile_size = 128.0f;
	tiles_texture = LoadTexture("assets/tiles/terrain/Terrain.png");
}

void Map::draw()
{
	for (int i{ 0 }; i < rows; i++)
	{
		for (int j{ 0 }; j < cols; j++)
		{
			if (map[i][j] == 1)
			{
				if (i == rows - 1 && j == 0)
				{
					drawHelper(6, 0, i, j);
				}
				else if (i == rows - 1 && j == cols - 1)
				{
					drawHelper(8, 0, i, j);
				}
				else
				{
					drawHelper(7, 0, i, j);
				}
			}
		}
	}
}

void Map::drawHelper(float xindex, float yindex, int i, int j)
{
	Rectangle source{ xindex * original_size , yindex * original_size , original_size,original_size };
	Rectangle dest{ float(j * tile_size), float(i * tile_size), tile_size, tile_size};
	Vector2 origin{ 0,0 };
	float rotation{ 0.0f };
	DrawTexturePro(tiles_texture, source, dest, origin, rotation, WHITE);
}

int Map::getTile(int row, int col)
{
	if (row >= 0 && row < rows && col >= 0 && col < cols) return map[row][col];
	return 0;
}
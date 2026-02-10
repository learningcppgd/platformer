#pragma once
#include "raylib.h"
#include "raymath.h"
#include "Map.h"
class Player
{
private:
	Vector2 position;
	Texture2D texture;
	Vector2 speed{ 0,0 };
	float jump_force{ -600.0f };
	float original_size{ 32 };
	float scale{ original_size * 4 };
	float ground{ (float)GetScreenHeight() * 3 / 4 };
	bool is_grounded{ true };

public:
	Player();

	void update(float gravity, Map& game_map);
	void draw();
	void unload();
	bool checkGrounded(float& groundY, Map& game_map);
};


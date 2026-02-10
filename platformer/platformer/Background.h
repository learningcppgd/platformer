#pragma once
#include "raylib.h"
class Background
{
private:
	Vector2 background_pos{0,0};
	Texture2D background;
	float scale{ 100.0f };

public:
	Background();

	void draw();
};


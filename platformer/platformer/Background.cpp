#include "Background.h"

Background::Background()
{
	background = LoadTexture("assets/tiles/background/Yellow.png");
}

void Background::draw()
{
	Vector2 origin{ 0,0 };
	Rectangle source{background_pos.x, background_pos.y, (float)background.width, (float)background.height};
	Rectangle dest{background_pos.x, background_pos.y, background.width * scale, background.height * scale};
	float rotation{ 0.0f };
	DrawTexturePro(background, source, dest, origin, rotation, WHITE);
}
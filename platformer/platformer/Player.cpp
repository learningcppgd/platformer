#include "Player.h"

Player::Player()
{
	position = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
	texture = LoadTexture("assets/player/idle.png");
}

void Player::draw()
{
	Vector2 origin{ 0,0 };
	int Xindex{ 0 };
	int Yindex{ 0 };
	Rectangle sourceRect{ Xindex * original_size, Yindex * original_size, original_size, original_size };
	Rectangle destRect{ position.x, position.y, scale, scale };
	DrawTexturePro(texture, sourceRect, destRect, origin, 0.0f, WHITE);
}


void Player::update(float gravity, Map& game_map)
{
	speed.x = 0;
	float groundY{ 0 };

	if (IsKeyDown(KEY_A)) speed.x -= 200.0f;
	if (IsKeyDown(KEY_D)) speed.x += 200.0f;

	position.x += speed.x * GetFrameTime();

	if (IsKeyPressed(KEY_SPACE) && is_grounded)
	{
		speed.y = jump_force;
		is_grounded = false;
	}

	speed.y += gravity * GetFrameTime();
	position.y += speed.y * GetFrameTime();

	if (checkGrounded(groundY, game_map))
	{
		position.y = groundY - scale;
		speed.y = 0;
		is_grounded = true;
	}
}

void Player::unload()
{
	UnloadTexture(texture);
}

bool Player::checkGrounded(float& groundY, Map& game_map)
{
	int left_col = position.x / game_map.getTileSize();
	int right_col = (position.x + scale - 1) / game_map.getTileSize();
	int row_below = (position.y + scale) / game_map.getTileSize();
	if (game_map.getTile(row_below, left_col) == 1 || game_map.getTile(row_below, right_col) == 1) // chekcing if below is tile
	{
		groundY = row_below * game_map.getTileSize();
		return true;
	}
	return false;
}

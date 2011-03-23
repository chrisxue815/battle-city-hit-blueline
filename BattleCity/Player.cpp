#include "Game.h"
#include "Player.h"
using namespace BattleCity;


Player::Player(const Game & game)
	: Entity(game)
{
}


Player::Player(const Game & game, const Point & point)
	: Entity(game, point)
{
}


Player::~Player(void)
{
}


// @override
void Player::init(const ResourceManager & resource)
{
	int milliseconds = 0;
	int lastKey = 0;
	image.init(resource, "texture\\player.bmp");
}


// @override
void Player::update(void)
{
	const GameTime & gameTime = game.getGameTime();

	// move
	int xOffset = 0;
	int yOffset = 0;

	if (key[KEY_LEFT]) {
		xOffset -= 1;
	}
	if (key[KEY_RIGHT]) {
		xOffset += 1;
	}
	if (key[KEY_UP]) {
		yOffset -= 1;
	}
	if (key[KEY_DOWN]) {
		yOffset += 1;
	}

	if (xOffset != 0 && yOffset != 0)
	{
		if (lastMove == UP_DOWN)
			yOffset = 0;
		else
			xOffset = 0;
	}

	if (xOffset != 0)
		lastMove = LEFT_RIGHT;
	else if (yOffset != 0)
		lastMove = UP_DOWN;
	else
		lastMove = NONE;

	if (lastMove == NONE)
	{
		milliseconds = 0;
	}
	else
	{
		milliseconds += gameTime.getInterval().getMilliseconds();
		if (milliseconds >= 500)
		{
			milliseconds -= 500;
			point += Point(xOffset, yOffset);
		}
	}
}


// @override
void Player::draw(DrawingManager & drawing)
{
	//image.draw(
}

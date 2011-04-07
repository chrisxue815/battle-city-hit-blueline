#include "Player.h"
#include "Level.h"
using namespace BattleCity;


Player::Player(Level & level)
	: Tank(level)
{
	init();
}


Player::Player(Level & level, const Point & point)
	: Tank(level, point)
{
	init();
}


void Player::init( void )
{
	lastKeyLeft = 0;
	lastKeyRight = 0;
	lastKeyUp = 0;
	lastKeyDown = 0;

	loadContent();
}


void Player::loadContent(void)
{
	const ResourceManager & resource = level.getResourceManager();

	upTexture = resource.getBitmap(PLAYER1_UP_FRAME);
	downTexture = resource.getBitmap(PLAYER1_DOWN_FRAME);
	leftTexture = resource.getBitmap(PLAYER1_LEFT_FRAME);
	rightTexture = resource.getBitmap(PLAYER1_RIGHT_FRAME);

	current = upTexture;
}


// @override
void Player::update(void)
{
	int milliseconds = level.getMilliseconds();	

	updateMoving(milliseconds);
	updateShooting(milliseconds);
}


void Player::updateMoving(int milliseconds)
{
	int xMove = 0;
	int yMove = 0;

	if (key[KEY_LEFT]) {
		xMove -= 1;
	}
	if (key[KEY_RIGHT]) {
		xMove += 1;
	}
	if (key[KEY_UP]) {
		yMove -= 1;
	}
	if (key[KEY_DOWN]) {
		yMove += 1;
	}

	// 只能向一个运动
	if (xMove != 0 && yMove != 0)
	{
		if (key[KEY_LEFT] && !lastKeyLeft || key[KEY_RIGHT] && !lastKeyRight)
			yMove = 0;
		else if(key[KEY_UP] && !lastKeyUp || key[KEY_DOWN] && !lastKeyDown)
			xMove = 0;
		else if (current == leftTexture || current == rightTexture)
			yMove = 0;
		else
			xMove = 0;
	}

	if (xMove == -1)
		direction = LEFT;
	else if (xMove == 1)
		direction = RIGHT;
	else if (yMove == -1)
		direction = UP;
	else if (yMove == 1)
		direction = DOWN;
	else
		direction = NO_DIRECTION;

	move(milliseconds);

	lastKeyLeft = key[KEY_LEFT];
	lastKeyRight = key[KEY_RIGHT];
	lastKeyUp = key[KEY_UP];
	lastKeyDown = key[KEY_DOWN];
}


void Player::updateShooting(int milliseconds)
{
	if (shootingCooldown > 0)
	{
		shootingCooldown -= milliseconds;
	}
	else if (key[KEY_SPACE])
	{
		shootingCooldown = SHOOTING_COOLDOWN;
		shoot(milliseconds);
	}
}

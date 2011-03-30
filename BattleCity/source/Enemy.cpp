#include "Enemy.h"
#include "Level.h"
using namespace BattleCity;


Enemy::Enemy(Level & level)
	: Tank(level)
{
	init();
}


Enemy::Enemy(Level & level, const Point & point)
	: Tank(level, point)
{
	init();
}


void Enemy::init( void )
{
	msPerGrid = 150;
	xOffset = 0;
	yOffset = 0;
	shootingCooldown = 0;

	loadContent();
}


void Enemy::loadContent(void)
{
	const ResourceManager & resource = level.getResourceManager();

	upTexture = resource.getBitmap(PLAYER1_UP_FRAME);
	downTexture = resource.getBitmap(PLAYER1_DOWN_FRAME);
	leftTexture = resource.getBitmap(PLAYER1_LEFT_FRAME);
	rightTexture = resource.getBitmap(PLAYER1_RIGHT_FRAME);

	current = upTexture;
}


void Enemy::update(void)
{
	int milliseconds = level.getMilliseconds();	

	if (movingCooldown > 0)
	{
		movingCooldown -= milliseconds;
	}
	else
	{
		movingCooldown = MOVING_COOLDOWN;

		switch (rand() % 4)
		{
		case 0:
			direction = LEFT;
			break;
		case 1:
			direction = RIGHT;
			break;
		case 2:
			direction = UP;
			break;
		case 3:
			direction = DOWN;
			break;
		}
	}

	move(milliseconds);

	if (direction == NO_DIRECTION)
		movingCooldown = 0;
	
	if (shootingCooldown > 0)
	{
		shootingCooldown -= milliseconds;
	}
	else
	{
		shootingCooldown = SHOOTING_COOLDOWN;

		if (rand() % 2)
			shoot(milliseconds);
	}
}


void Enemy::updateMoving(int milliseconds)
{

}


void Enemy::updateShooting(int milliseconds)
{

}

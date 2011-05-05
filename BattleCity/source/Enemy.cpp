#include "Enemy.h"
#include "Level.h"
using namespace BattleCity;


Enemy::Enemy(Level & level, EnemyType enemyType)
	: Tank(level)
{
	init(enemyType);
}


Enemy::Enemy(Level & level, const Point & point, EnemyType enemyType)
	: Tank(level, point)
{
	init(enemyType);
}


void Enemy::init(EnemyType enemyType)
{
	this->enemyType = enemyType;

	MS_PER_GRID = 150;
	MOVING_COOLDOWN = 1000;
	SHOOTING_COOLDOWN = 1000;

	switch (enemyType)
	{
	case ENEMY_HIGH_SPEED:
		MS_PER_GRID = 75;
		MOVING_COOLDOWN = 500;
		break;
	case ENEMY_HIGH_ARMOR:
		lives = 4;
		break;
	case ENEMY_HIGH_DAMAGE:
		SHOOTING_COOLDOWN = 500;
		break;
	}

	xOffset = 0;
	yOffset = 0;
	movingCooldown = 0;
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

	updateMoving(milliseconds);
	updateShooting(milliseconds);
}


void Enemy::updateMoving(int milliseconds)
{
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
}


void Enemy::updateShooting(int milliseconds)
{
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

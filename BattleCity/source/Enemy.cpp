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

	BitmapFrame upFrame;
	BitmapFrame downFrame;
	BitmapFrame leftFrame;
	BitmapFrame rightFrame;

	switch (enemyType)
	{
	case ENEMY_HIGH_SPEED:
		upFrame = ENEMY2_UP_FRAME;
		downFrame = ENEMY2_DOWN_FRAME;
		leftFrame = ENEMY2_LEFT_FRAME;
		rightFrame = ENEMY2_RIGHT_FRAME;
		break;
	case ENEMY_HIGH_ARMOR:
		upFrame = ENEMY3_UP_FRAME;
		downFrame = ENEMY3_DOWN_FRAME;
		leftFrame = ENEMY3_LEFT_FRAME;
		rightFrame = ENEMY3_RIGHT_FRAME;
		break;
	case ENEMY_HIGH_DAMAGE:
		upFrame = ENEMY4_UP_FRAME;
		downFrame = ENEMY4_DOWN_FRAME;
		leftFrame = ENEMY4_LEFT_FRAME;
		rightFrame = ENEMY4_RIGHT_FRAME;
		break;
	case ENEMY_NORMAL:
		upFrame = ENEMY1_UP_FRAME;
		downFrame = ENEMY1_DOWN_FRAME;
		leftFrame = ENEMY1_LEFT_FRAME;
		rightFrame = ENEMY1_RIGHT_FRAME;
	}

	upTexture = resource.getBitmap(upFrame);
	downTexture = resource.getBitmap(downFrame);
	leftTexture = resource.getBitmap(leftFrame);
	rightTexture = resource.getBitmap(rightFrame);

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

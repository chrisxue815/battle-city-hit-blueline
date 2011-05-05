#include "Entity.h"
#include "Level.h"
#include "Player.h"
#include "Enemy.h"  //TODO:
#include "Tile.h"
using namespace BattleCity;


Entity::Entity(Level & level)
	: LevelComponent(level), rect(0, 0, 0, 0)
{
	lives = 0;
}


Entity::Entity(Level & level, const Rectangle & rect)
	: LevelComponent(level), rect(rect)
{
}


bool Entity::cannotGoLeft()
{
	Rectangle collisionRect(rect.getLeft() - 1, rect.getTop(), 1, rect.getHeight());

	return level.collidedWithTile(collisionRect)
		|| level.collidedWithTank(collisionRect);
}


bool Entity::cannotGoRight()
{
	Rectangle collisionRect(rect.getRight() + 1, rect.getTop(), 1, rect.getHeight());

	return level.collidedWithTile(collisionRect)
		|| level.collidedWithTank(collisionRect);
}


bool Entity::cannotGoUp()
{
	Rectangle collisionRect(rect.getLeft(), rect.getTop() - 1, rect.getWidth(), 1);

	return level.collidedWithTile(collisionRect)
		|| level.collidedWithTank(collisionRect);
}


bool Entity::cannotGoDown()
{
	Rectangle collisionRect(rect.getLeft(), rect.getBottom() + 1, rect.getWidth(), 1);

	return level.collidedWithTile(collisionRect)
		|| level.collidedWithTank(collisionRect);
}

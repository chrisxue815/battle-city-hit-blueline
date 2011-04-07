#include "Entity.h"
#include "Level.h"
using namespace BattleCity;


Entity::Entity(Level & level)
	: level(level), rect(0, 0, 0, 0)
{
	lives = 0;
}


Entity::Entity(Level & level, const Rectangle & rect)
	: level(level), rect(rect)
{
}


bool Entity::cannotGoLeft()
{
	Rectangle collisionRect(rect.getLeft() - 1, rect.getTop(), 1, rect.getHeight());

	return tileCollision(collisionRect) || tankCollision(collisionRect);
}


bool Entity::cannotGoRight()
{
	Rectangle collisionRect(rect.getRight(), rect.getTop(), 1, rect.getHeight());

	return tileCollision(collisionRect) || tankCollision(collisionRect);
}


bool Entity::cannotGoUp()
{
	Rectangle collisionRect(rect.getLeft(), rect.getTop() - 1, rect.getWidth(), 1);

	return tileCollision(collisionRect) || tankCollision(collisionRect);
}


bool Entity::cannotGoDown()
{
	Rectangle collisionRect(rect.getLeft(), rect.getBottom(), rect.getWidth(), 1);

	return tileCollision(collisionRect) || tankCollision(collisionRect);
}


bool Entity::tileCollision( Rectangle rect )
{
	for (int x = rect.getLeft(); x < rect.getRight(); ++x)
	{
		for (int y = rect.getTop(); y < rect.getBottom(); ++y)
		{
			const Tile * tile = level.getTile(x, y);
			if (tile == NULL || ! tile->canPlayerGoThrough())
				return true;
		}
	}
	return false;
}


bool Entity::tankCollision( Rectangle rect )
{
	const Player * player = level.getPlayer();
	if (rect.intersects(player->getRect()))
		return true;

	const list<Enemy> & enemies = level.getEnemies();
	for (list<Enemy>::const_iterator it = enemies.begin(); it != enemies.end(); ++it)
	{
		if (rect.intersects(it->getRect()))
			return true;
	}

	return false;
}

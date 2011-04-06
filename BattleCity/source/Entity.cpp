#include "Entity.h"
#include "Level.h"
using namespace BattleCity;


Entity::Entity(Level & level)
	: level(level), rect(0, 0, 0, 0)
{
}


Entity::Entity(Level & level, const Rectangle & rect)
	: level(level), rect(rect)
{
}


bool Entity::cannotGoLeft()
{
	int x = rect.getLeft() - 1;

	for (int y = rect.getTop(); y < rect.getBottom(); ++y)
	{
		const Tile * grid = level.getTile(x, y);
		if (grid == NULL || ! grid->canPlayerGoThrough())
			return true;
	}

	return false;
}


bool Entity::cannotGoRight()
{
	int x = rect.getRight();

	for (int y = rect.getTop(); y < rect.getBottom(); ++y)
	{
		const Tile * grid = level.getTile(x, y);
		if (grid == NULL || ! grid->canPlayerGoThrough())
			return true;
	}

	return false;
}


bool Entity::cannotGoUp()
{
	int y = rect.getTop() - 1;

	for (int x = rect.getLeft(); x < rect.getRight(); ++x)
	{
		const Tile * grid = level.getTile(x, y);
		if (grid == NULL || ! grid->canPlayerGoThrough())
			return true;
	}

	return false;
}


bool Entity::cannotGoDown()
{
	int y = rect.getBottom();

	for (int x = rect.getLeft(); x < rect.getRight(); ++x)
	{
		const Tile * grid = level.getTile(x, y);
		if (grid == NULL || ! grid->canPlayerGoThrough())
			return true;
	}

	return false;
}

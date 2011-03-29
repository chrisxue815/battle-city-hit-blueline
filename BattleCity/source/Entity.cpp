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
	int x = rect.getX() - 1;
	int y = rect.getY();
	int yRange = y + rect.getWidth();

	for (; y < yRange; y++)
	{
		const Tile * grid = level.getGrid(x, y);
		if (grid == NULL || ! grid->canPlayerGoThrough())
			return true;
	}

	return false;
}


bool Entity::cannotGoRight()
{
	int x = rect.getX() + rect.getWidth();
	int y = rect.getY();
	int yRange = y + rect.getWidth();

	for (; y < yRange; y++)
	{
		const Tile * grid = level.getGrid(x, y);
		if (grid == NULL || ! grid->canPlayerGoThrough())
			return true;
	}

	return false;
}


bool Entity::cannotGoUp()
{
	int x = rect.getX();
	int y = rect.getY() - 1;
	int xRange = x + rect.getHeight();

	for (; x < xRange; x++)
	{
		const Tile * grid = level.getGrid(x, y);
		if (grid == NULL || ! grid->canPlayerGoThrough())
			return true;
	}

	return false;
}


bool Entity::cannotGoDown()
{
	int x = rect.getX();
	int y = rect.getY() + rect.getHeight();
	int xRange = x + rect.getHeight();

	for (; x < xRange; x++)
	{
		const Tile * grid = level.getGrid(x, y);
		if (grid == NULL || ! grid->canPlayerGoThrough())
			return true;
	}

	return false;
}

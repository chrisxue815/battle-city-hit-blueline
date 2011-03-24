#include "Entity.h"
#include "Level.h"
using namespace BattleCity;


Entity::Entity(Level & level)
	: level(level)
{
}


Entity::Entity(Level & level, const Point & point)
	: level(level), point(point)
{
}

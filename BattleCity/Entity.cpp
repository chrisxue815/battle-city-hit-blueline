#include "Entity.h"
using namespace BattleCity;


Entity::Entity(void)
{
}


Entity::Entity(const Coordinate & value)
{
	this->coor = value;
}


Entity::~Entity(void)
{
}


inline Coordinate Entity::getCoordinate(void)
{
	return coor;
}


inline void Entity::setCoordinate(const Coordinate & value)
{
	this->coor = value;
}

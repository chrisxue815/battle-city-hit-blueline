#include "Coordinate.h"
using namespace BattleCity;


Coordinate::Coordinate(void)
{
	this->x = 0;
	this->y = 0;
}


Coordinate::Coordinate(int x, int y)
{
	this->x = x;
	this->y = y;
}


Coordinate::~Coordinate(void)
{
}


inline int Coordinate::getX(void)
{
	return x;
}


inline void Coordinate::setX(int x)
{
	this->x = x;
}


inline int Coordinate::getY(void)
{
	return y;
}


inline void Coordinate::setY(int y)
{
	this->y = y;
}


inline Coordinate Coordinate::operator + (const Coordinate & value)
{
	return Coordinate(x + value.x, y + value.y);
}


inline Coordinate Coordinate::operator - (const Coordinate & value)
{
	return Coordinate(x - value.x, y - value.y);
}


inline Coordinate Coordinate::operator * (int value)
{
	return Coordinate(x * value, y + y * value);
}


inline Coordinate Coordinate::operator / (int value)
{
	return Coordinate(x / value, y / value);
}


inline bool Coordinate::operator == (const Coordinate & value)
{
	return x == value.x && y == value.y;
}


inline bool Coordinate::operator != (const Coordinate & value)
{
	return !(*this == value);
}

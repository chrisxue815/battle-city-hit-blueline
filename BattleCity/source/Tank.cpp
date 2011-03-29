#include "Tank.h"
using namespace BattleCity;


Tank::Tank(Level & level)
	: Entity(level, Rectangle(0, 0, TANK_GRID_WIDTH, TANK_GRID_HEIGHT))
{
}


Tank::Tank(Level & level, const Point & point)
	: Entity(level, Rectangle(point, TANK_GRID_WIDTH, TANK_GRID_HEIGHT))
{
}

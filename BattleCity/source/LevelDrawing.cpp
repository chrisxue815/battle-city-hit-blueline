#include "LevelDrawing.h"
using namespace BattleCity;


LevelDrawing::LevelDrawing(void)
	: gridSize(0, 0), levelPoint(0, 0)
{
	scale = 1.0f;
}


LevelDrawing::LevelDrawing(const Point & gridSize, const Point & levelPoint, float scale)
{
	this->gridSize = gridSize;
	this->levelPoint = levelPoint;
	this->scale = scale;
}


Point LevelDrawing::getScreenPoint(const Point & point) const
{
	int x = point.getX() * gridSize.getX() * scale + levelPoint.getX();
	int y = point.getY() * gridSize.getY() * scale + levelPoint.getY();
	return Point(x, y);
}

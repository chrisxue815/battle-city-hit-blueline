#include "Tank.h"
#include "Level.h"
using namespace BattleCity;


const float Tank::ICE_COEFFICIENT = 2.0f;


Tank::Tank(Level & level)
	: Entity(level, Rectangle(0, 0, TANK_GRID_WIDTH, TANK_GRID_HEIGHT))
{
	init();
}


Tank::Tank(Level & level, const Point & point)
	: Entity(level, Rectangle(point, TANK_GRID_WIDTH, TANK_GRID_HEIGHT))
{
	init();
}


void Tank::init(void)
{
	alive = true;

	msPerGrid = 150;
	xOffset = 0;
	yOffset = 0;

	shootingCooldown = 0;

	current = NULL;
	upTexture = NULL;
	downTexture = NULL;
	leftTexture = NULL;
	rightTexture = NULL;
}


void Tank::move(int milliseconds)
{
	// 改变朝向
	switch (direction)
	{
	case LEFT:
		current = leftTexture;
		break;
	case RIGHT:
		current = rightTexture;
		break;
	case UP:
		current = upTexture;
		break;
	case DOWN:
		current = downTexture;
		break;
	default:
		return;
	}

	// 碰撞检测
	if (direction == LEFT && xOffset <= 0 && cannotGoLeft() ||
		direction == RIGHT && xOffset >= 0 && cannotGoRight() ||
		direction == UP && yOffset <= 0 && cannotGoUp() ||
		direction == DOWN && yOffset >= 0 && cannotGoDown())
	{
		direction = NO_DIRECTION;
	}

	// 踩到冰会加速
	if (direction != NO_DIRECTION && onIce())
		milliseconds *= ICE_COEFFICIENT;

	// 移动
	switch (direction)
	{
	case LEFT:
		xOffset -= milliseconds;
		yOffset = 0;
		if (xOffset <= -msPerGrid / 2) {
			xOffset += msPerGrid;
			rect -= Point(1, 0);
		}
		break;
	case RIGHT:
		xOffset += milliseconds;
		yOffset = 0;
		if (xOffset >= msPerGrid / 2) {
			xOffset -= msPerGrid;
			rect += Point(1, 0);
		}
		break;
	case UP:
		yOffset -= milliseconds;
		xOffset = 0;
		if (yOffset <= -msPerGrid / 2) {
			yOffset += msPerGrid;
			rect -= Point(0, 1);
		}
		break;
	case DOWN:
		yOffset += milliseconds;
		xOffset = 0;
		if (yOffset >= msPerGrid / 2) {
			yOffset -= msPerGrid;
			rect += Point(0, 1);
		}
		break;
	}
}


void Tank::shoot(int milliseconds)
{
	Point position = rect.getLeftTop();
	Point direction;

	if (current == upTexture) {
		position += Point(0, -1);
		direction = Point(0, -1);
	}
	else if (current == downTexture) {
		position += Point(0, rect.getHeight());
		direction = Point(0, 1);
	}
	else if (current == leftTexture) {
		position += Point(-1, 0);
		direction = Point(-1, 0);
	}
	else if (current == rightTexture) {
		position += Point(rect.getWidth(), 0);
		direction = Point(1, 0);
	}

	Bullet bullet(level, position, direction);
	level.addBullet(bullet);
}


bool Tank::onIce(void)
{
	int xRange = rect.getLeft() + rect.getWidth();
	int yRange = rect.getTop() + rect.getHeight();

	for (int x = rect.getLeft(); x < xRange; x++)
	{
		for (int y = rect.getTop(); y < yRange; y++)
		{
			if (level.getTile(x, y)->speedUpPlayer())
			{
				return true;
			}
		}
	}

	return false;
}


// @override
void Tank::draw(void)
{
	const LevelDrawing & levelDrawing = level.getLevelDrawing();
	Point screenPoint = levelDrawing.getScreenPoint(rect.getLeftTop());
	const Point & gridSize = levelDrawing.getGridSize();

	int x = Math::floorDiv(xOffset * gridSize.getX(), msPerGrid) + screenPoint.getX();
	screenPoint.setX(x);
	int y = Math::floorDiv(yOffset * gridSize.getY(), msPerGrid) + screenPoint.getY();
	screenPoint.setY(y);

	DrawingManager & drawing = level.getDrawingManager();

	draw_sprite(drawing.getBuffer(), current, screenPoint.getX(), screenPoint.getY());
}

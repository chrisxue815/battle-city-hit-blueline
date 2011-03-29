#include "Bullet.h"
#include "Level.h"
using namespace BattleCity;


Bullet::Bullet(Level & level, const Point & point, const Point & direction)
	: Entity(level, Rectangle(point, 0, 0)), direction(direction)
{
	offset = 0;

	const ResourceManager & resource = level.getResourceManager();
	texture = resource.getBitmap(BULLET_FRAME);

	if (direction.getX() != 0) {
		rect.setWidth(1);
		rect.setHeight(2);
	}
	else {
		rect.setWidth(2);
		rect.setHeight(1);
	}
}


void Bullet::update(void)
{
	const TimeManager & timeManager = level.getTimeManager();
	int milliseconds = timeManager.getInterval().getMilliseconds();

	updateMoving(milliseconds);
	collisionDetection();
}


void Bullet::draw(void)
{
	const LevelDrawing & levelDrawing = level.getLevelDrawing();
	Point screenPoint = levelDrawing.getScreenPoint(rect.getLeftTop());
	Point gridSize = levelDrawing.getGridSize();

	screenPoint += gridSize * rect.getSize() / 2;
	screenPoint.setX(screenPoint.getX() - texture->w / 2);
	screenPoint.setY(screenPoint.getY() - texture->h / 2);
	
	int rectOffset = Math::floorDiv(offset * gridSize.getX(), MS_PER_GRID);
	Point p = direction;
	p *= rectOffset;
	screenPoint += p;

	DrawingManager & drawing = level.getDrawingManager();

	set_alpha_blender();
	draw_trans_sprite(drawing.getBuffer(), texture, screenPoint.getX(), screenPoint.getY());
}


void Bullet::updateMoving(int milliseconds)
{
	offset += milliseconds;

	if (offset >= MS_PER_GRID)
	{
		offset -= MS_PER_GRID;
		rect += direction;
	}
}


void Bullet::collisionDetection(void)
{
	int xRange = rect.getLeft() + rect.getWidth();
	int yRange = rect.getTop() + rect.getHeight();

	for (int x = rect.getLeft(); x < xRange; x++)
	{
		for (int y = rect.getTop(); y < yRange; y++)
		{
			const Tile * tile = level.getGrid(x, y);
			if (tile == NULL)
				alive = false;
			else if (tile->getSolid()) {
				alive = false;
				level.bulletHit(x, y);
			}
		}
	}
}

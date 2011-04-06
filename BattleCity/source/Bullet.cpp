#include "Bullet.h"
#include "Level.h"
using namespace BattleCity;


Bullet::Bullet(Level & level, const Entity * shooter, const Point & point, Direction direction)
	: Entity(level, Rectangle(point, 0, 0))
{
	this->shooter = shooter;
	this->direction = direction;
	offset = 0;

	if (direction == LEFT) {
		directionVector = Point(-1, 0);
		rect.setWidth(1);
		rect.setHeight(2);
	}
	else if (direction == RIGHT) {
		directionVector = Point(1, 0);
		rect.setWidth(1);
		rect.setHeight(2);
	}
	else if (direction == UP) {
		directionVector = Point(0, -1);
		rect.setWidth(2);
		rect.setHeight(1);
	}
	else if (direction == DOWN) {
		directionVector = Point(0, 1);
		rect.setWidth(2);
		rect.setHeight(1);
	}

	const ResourceManager & resource = level.getResourceManager();
	texture = resource.getBitmap(BULLET_FRAME);
}


void Bullet::update(void)
{
	int milliseconds = level.getMilliseconds();	

	updateMoving(milliseconds);
	collisionDetection();
}


void Bullet::draw(void)
{
	const LevelDrawing & levelDrawing = level.getLevelDrawing();
	Point screenPoint = levelDrawing.getScreenPoint(rect.getLeftTop());
	Point gridSize = levelDrawing.getGridSize();
	int rectOffset = Math::floorDiv(offset * gridSize.getX(), MS_PER_GRID);
	
	//TODO: fix this hard code
	if (direction == LEFT)
		screenPoint += Point(gridSize.getX() - rectOffset, rect.getHeight() * gridSize.getY() / 2 - texture->h / 2);
	else if (direction == RIGHT)
		screenPoint += Point(rectOffset, rect.getHeight() * gridSize.getY() / 2 - texture->h / 2);
	else if (direction == UP)
		screenPoint += Point(rect.getWidth() * gridSize.getX() / 2 - texture->w / 2, gridSize.getY() - rectOffset);
	else if (direction == DOWN)
		screenPoint += Point(rect.getWidth() * gridSize.getX() / 2 - texture->w / 2, rectOffset);

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
		rect += directionVector;
	}
}


void Bullet::collisionDetection(void)
{
	// tiles
	{
		for (int x = rect.getLeft(); x < rect.getRight(); ++x)
		{
			for (int y = rect.getTop(); y < rect.getBottom(); ++y)
			{
				const Tile * tile = level.getTile(x, y);

				if (tile == NULL)
					alive = false;
				else if (tile->getBulletEvent() == BULLET_CANNOT_HIT) {
					alive = false;
				}
				else if (tile->getBulletEvent() == BULLET_CAN_HIT) {
					alive = false;
					level.bulletHitTile(x, y);
				}
			}
		}
	}

	// player
	{
		const Player * player = level.getPlayer();
		const Rectangle & playerRect = player->getRect();

		if (player != shooter && rect.intersects(playerRect))
		{
			level.bulletHitPlayer();
			alive = false;
		}
	}

	// enemies
	{
		const list<Enemy> & enemies  = level.getEnemies();

		//TODO: fix this hard code
		for (list<Enemy>::const_iterator it = enemies.begin(); it != enemies.end(); ++it)
		{
			if (&(*it) != shooter && rect.intersects(it->getRect()))
			{
				level.bulletHitEnemy(*it);
				alive = false;
			}
		}
	}
}

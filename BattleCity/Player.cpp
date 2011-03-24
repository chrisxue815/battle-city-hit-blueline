#include "Player.h"
#include "Level.h"
using namespace BattleCity;


Player::Player(Level & level)
	: Entity(level)
{
	xOffset = 0;
	yOffset = 0;
	texture = NULL;
}


Player::Player(Level & level, const Point & point)
	: Entity(level, point)
{
	xOffset = 0;
	yOffset = 0;
	texture = NULL;
}


Player::~Player(void)
{
	if (texture != NULL)
		destroy_bitmap(texture);
}


// @override
void Player::init(void)
{
	lastMove = NONE;

	const ResourceManager & resource = level.getResourceManager();
	texture = resource.loadBitmap("texture\\player.bmp");
}


// @override
void Player::update(void)
{
	const TimeManager * timeManager = level.getTimeManager();
	int milliseconds = timeManager->getInterval().getMilliseconds();

	// move
	int xMove = 0;
	int yMove = 0;

	if (key[KEY_LEFT]) {
		xMove -= 1;
	}
	if (key[KEY_RIGHT]) {
		xMove += 1;
	}
	if (key[KEY_UP]) {
		yMove -= 1;
	}
	if (key[KEY_DOWN]) {
		yMove += 1;
	}

	if (xMove != 0 && yMove != 0)
	{
		if (lastMove == UP || lastMove == DOWN)
			yMove = 0;
		else
			xMove = 0;
	}

	if (xMove > 0)
	{
		lastMove = LEFT;
		xOffset += milliseconds;
		yOffset = 0;
		if (xOffset >= MS_PER_GRID / 2)
		{
			xOffset -= MS_PER_GRID;
			point += Point(1, 0);
		}
	}
	else if (xMove < 0)
	{
		lastMove = RIGHT;
		xOffset -= milliseconds;
		yOffset = 0;
		if (xOffset <= -MS_PER_GRID / 2)
		{
			xOffset += MS_PER_GRID;
			point -= Point(1, 0);
		}
	}
	else if (yMove > 0)
	{
		lastMove = UP;
		yOffset += milliseconds;
		if (yOffset >= MS_PER_GRID / 2)
		{
			yOffset -= MS_PER_GRID;
			point += Point(0, 1);
		}
	}
	else if (yMove < 0)
	{
		lastMove = DOWN;
		yOffset -= milliseconds;
		if (yOffset <= -MS_PER_GRID / 2)
		{
			yOffset += MS_PER_GRID;
			point -= Point(0, 1);
		}
	}
	else
	{
		lastMove = NONE;
	}
}


// @override
void Player::draw(void)
{
	const LevelDrawing & levelDrawing = level.getLevelDrawing();
	Point screenPoint = levelDrawing.getScreenPoint(point);
	const Point & gridSize = levelDrawing.getGridSize();
	
	int x = Math::floorDiv(xOffset * gridSize.getX(), MS_PER_GRID) + screenPoint.getX();
	screenPoint.setX(x);
	int y = Math::floorDiv(yOffset * gridSize.getY(), MS_PER_GRID) + screenPoint.getY();
	screenPoint.setY(y);

	DrawingManager & drawing = level.getDrawingManager();

	draw_sprite(drawing.getBuffer(), texture, screenPoint.getX(), screenPoint.getY());
}

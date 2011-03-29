#include "Player.h"
#include "Level.h"
using namespace BattleCity;


Player::Player(Level & level)
	: Tank(level)
{
	loadContent();

	xOffset = 0;
	yOffset = 0;
	shootingCooldown = 0;
}


Player::Player(Level & level, const Point & point)
	: Tank(level, point)
{
	loadContent();

	xOffset = 0;
	yOffset = 0;
	shootingCooldown = 0;
}


void Player::loadContent(void)
{
	const ResourceManager & resource = level.getResourceManager();

	upTexture = resource.getBitmap(PLAYER1_UP_FRAME);
	downTexture = resource.getBitmap(PLAYER1_DOWN_FRAME);
	leftTexture = resource.getBitmap(PLAYER1_LEFT_FRAME);
	rightTexture = resource.getBitmap(PLAYER1_RIGHT_FRAME);

	current = upTexture;
}


// @override
void Player::update(void)
{
	const TimeManager & timeManager = level.getTimeManager();
	int milliseconds = timeManager.getInterval().getMilliseconds();

	updateMoving(milliseconds);
	updateShooting(milliseconds);
}


void Player::updateMoving(int milliseconds)
{
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

	// 只能向一个运动
	if (xMove != 0 && yMove != 0)
	{
		if (key[KEY_LEFT] && !lastKeyDown[LEFT] || key[KEY_RIGHT] && !lastKeyDown[RIGHT])
			yMove = 0;
		else if (key[KEY_UP] && !lastKeyDown[UP] || key[KEY_DOWN] && !lastKeyDown[DOWN])
			xMove = 0;
		else
		{
			if (current == leftTexture || current == rightTexture)
				yMove = 0;
			else
				xMove = 0;
		}
	}

	// 改变朝向
	if (xMove < 0)
		current = leftTexture;
	else if (xMove > 0)
		current = rightTexture;
	else if (yMove < 0)
		current = upTexture;
	else if (yMove > 0)
		current = downTexture;

	// 碰撞检测
	if (xMove == -1 && cannotGoLeft() && xOffset <= 0 || xMove == 1 && cannotGoRight() && xOffset >= 0)
		xMove = 0;
	if (yMove == -1 && cannotGoUp() && yOffset <= 0 || yMove == 1 && cannotGoDown() && yOffset >= 0)
		yMove = 0;

	// 踩到冰会加速
	int xRange = rect.getLeft() + rect.getWidth();
	int yRange = rect.getTop() + rect.getHeight();
	for (int x = rect.getLeft(); x < xRange; x++)
	{
		for (int y = rect.getTop(); y < yRange; y++)
		{
			const Tile * tile = level.getGrid(x, y);
			if (tile->speedUpPlayer())
			{
				milliseconds *= ICE_COEFFICIENT;
				break;
			}
		}
	}
	
	if (xMove > 0)
	{
		xOffset += milliseconds;
		yOffset = 0;
		if (xOffset >= MS_PER_GRID / 2)
		{
			xOffset -= MS_PER_GRID;
			rect += Point(1, 0);
		}
	}
	else if (xMove < 0)
	{
		xOffset -= milliseconds;
		yOffset = 0;
		if (xOffset <= -MS_PER_GRID / 2)
		{
			xOffset += MS_PER_GRID;
			rect -= Point(1, 0);
		}
	}
	else if (yMove > 0)
	{
		yOffset += milliseconds;
		xOffset = 0;
		if (yOffset >= MS_PER_GRID / 2)
		{
			yOffset -= MS_PER_GRID;
			rect += Point(0, 1);
		}
	}
	else if (yMove < 0)
	{
		yOffset -= milliseconds;
		xOffset = 0;
		if (yOffset <= -MS_PER_GRID / 2)
		{
			yOffset += MS_PER_GRID;
			rect -= Point(0, 1);
		}
	}

	lastKeyDown[LEFT] = key[KEY_LEFT];
	lastKeyDown[RIGHT] = key[KEY_RIGHT];
	lastKeyDown[UP] = key[KEY_UP];
	lastKeyDown[DOWN] = key[KEY_DOWN];
}


void Player::updateShooting(int milliseconds)
{
	if (shootingCooldown > 0)
		shootingCooldown -= milliseconds;

	if (key[KEY_SPACE] && shootingCooldown <= 0)
	{
		shootingCooldown = SHOOTING_COOLDOWN;

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
}


// @override
void Player::draw(void)
{
	const LevelDrawing & levelDrawing = level.getLevelDrawing();
	Point screenPoint = levelDrawing.getScreenPoint(rect.getLeftTop());
	const Point & gridSize = levelDrawing.getGridSize();
	
	int x = Math::floorDiv(xOffset * gridSize.getX(), MS_PER_GRID) + screenPoint.getX();
	screenPoint.setX(x);
	int y = Math::floorDiv(yOffset * gridSize.getY(), MS_PER_GRID) + screenPoint.getY();
	screenPoint.setY(y);

	DrawingManager & drawing = level.getDrawingManager();

	draw_sprite(drawing.getBuffer(), current, screenPoint.getX(), screenPoint.getY());
}

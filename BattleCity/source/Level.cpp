#include "Level.h"
using namespace BattleCity;


Level::Level(Game & game)
	: Component(game),
	levelDrawing(Point(GRID_WIDTH, GRID_HEIGHT), Point(0, 0), 1.0f)
{
	player = new Player(*this);

	const ResourceManager & resource = game.getResourceManager();

	grids.reserve(LEVEL_GRID_WIDTH);
	for (int i = 0; i < LEVEL_GRID_WIDTH; i++)
	{
		vector<Tile*> vt;
		vt.reserve(LEVEL_GRID_HEIGHT);
		for (int j = 0; j < LEVEL_GRID_HEIGHT; j++)
		{
			vt.push_back(new EmptySpace());
		}
		grids.push_back(vt);
	}

	for (int i = 0; i < LEVEL_GRID_WIDTH; i++)
	{
		delete grids[i][10];
		delete grids[i][11];
		grids[i][10] = new Brick(resource);
		grids[i][11] = new Brick(resource);
	}
}


Level::~Level(void)
{
	delete player;
	for (int i = 0; i < LEVEL_GRID_WIDTH; i++)
	{
		for (int j = 0; j < LEVEL_GRID_HEIGHT; j++)
		{
			delete grids[i][j];
		}
	}
}


void Level::update(void)
{
	player->update();
	
	for (list<Bullet>::iterator it = bullets.begin(); it != bullets.end();)
	{
		it->update();

		if (! it->getAlive())
		{
			it = bullets.erase(it);
		}
		else
			++it;
	}
}


void Level::draw(void)
{
	DrawingManager & drawing = game.getDrawingManager();
	for (int i = 0; i < LEVEL_GRID_WIDTH; i++)
	{
		for (int j = 0; j < LEVEL_GRID_HEIGHT; j++)
		{
			Tile * tile = grids[i][j];
			if (tile->getTexture() != NULL)
			{
				DrawingManager & drawing = game.getDrawingManager();
				Point screenPoint = levelDrawing.getScreenPoint(Point(i, j));
				draw_sprite(drawing.getBuffer(), tile->getTexture(), screenPoint.getX(), screenPoint.getY());
			}
		}
	}

	player->draw();
	for (list<Bullet>::iterator it = bullets.begin(); it != bullets.end(); ++it) {
		it->draw();
	}
}


void Level::bulletHit(int x, int y)
{
	delete grids[x][y];
	grids[x][y] = new EmptySpace();
}

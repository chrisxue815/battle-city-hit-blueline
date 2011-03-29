#include "Level.h"
#include "Brick.h"
#include "Steel.h"
#include "Pool.h"
#include "Ice.h"
#include "Bush.h"
#include "EmptySpace.h"
using namespace BattleCity;


Level::Level(Game & game)
	: Component(game)
	, levelDrawing(Point(GRID_WIDTH, GRID_HEIGHT), Point(LEVEL_X, LEVEL_Y), 1.0f)
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

	for (int i = 0; i < 10; i++)
	{
		delete grids[i][10];
		delete grids[i][11];
		grids[i][10] = new Brick(resource);
		grids[i][11] = new Brick(resource);
		delete grids[i + 10][10];
		delete grids[i + 10][11];
		grids[i + 10][10] = new Steel(resource);
		grids[i + 10][11] = new Steel(resource);
		delete grids[i + 20][10];
		delete grids[i + 20][11];
		grids[i + 20][10] = new Pool(resource);
		grids[i + 20][11] = new Pool(resource);
		delete grids[i][12];
		delete grids[i][13];
		grids[i][12] = new Ice(resource);
		grids[i][13] = new Ice(resource);
		delete grids[i + 10][12];
		delete grids[i + 10][13];
		grids[i + 10][12] = new Bush(resource);
		grids[i + 10][13] = new Bush(resource);
		bushTiles.push_back(Point(i + 10, 12));
		bushTiles.push_back(Point(i + 10, 13));
	}

	background = resource.getBitmap(BACKGROUND_FRAME);
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

	// update bullets
	for (list<Bullet>::iterator it = bullets.begin(); it != bullets.end();)
	{
		it->update();

		if (! it->getAlive())
			it = bullets.erase(it);
		else
			++it;
	}
}


void Level::draw(void)
{
	DrawingManager & drawing = game.getDrawingManager();

	draw_sprite(drawing.getBuffer(), background, LEVEL_X, LEVEL_Y);

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

	// 把Bush显示在最上面
	for (list<Point>::iterator it = bushTiles.begin(); it != bushTiles.end(); ++it) {
		Tile * tile = grids[it->getX()][it->getY()];
		DrawingManager & drawing = game.getDrawingManager();
		Point screenPoint = levelDrawing.getScreenPoint(*it);
		draw_sprite(drawing.getBuffer(), tile->getTexture(), screenPoint.getX(), screenPoint.getY());
	}
}


void Level::bulletHit(int x, int y)
{
	delete grids[x][y];
	grids[x][y] = new EmptySpace();
}

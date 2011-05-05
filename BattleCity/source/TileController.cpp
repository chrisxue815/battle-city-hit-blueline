#include "TileController.h"
#include "Brick.h"
#include "Steel.h"
#include "Pool.h"
#include "Ice.h"
#include "Bush.h"
#include "EmptySpace.h"
using namespace BattleCity;


TileController::TileController(Level & level)
	: LevelComponent(level)
{
	const ResourceManager & resource = level.getResourceManager();

	tiles.reserve(LEVEL_GRID_WIDTH);
	for (int i = 0; i < LEVEL_GRID_WIDTH; i++)
	{
		vector<Tile*> vt;
		vt.reserve(LEVEL_GRID_HEIGHT);
		for (int j = 0; j < LEVEL_GRID_HEIGHT; j++)
		{
			vt.push_back(new EmptySpace());
		}
		tiles.push_back(vt);
	}

	for (int i = 0; i < 10; i++)
	{
		delete tiles[i][10];
		delete tiles[i][11];
		tiles[i][10] = new Brick(resource);
		tiles[i][11] = new Brick(resource);
		delete tiles[i + 10][10];
		delete tiles[i + 10][11];
		tiles[i + 10][10] = new Steel(resource);
		tiles[i + 10][11] = new Steel(resource);
		delete tiles[i + 20][10];
		delete tiles[i + 20][11];
		tiles[i + 20][10] = new Pool(resource);
		tiles[i + 20][11] = new Pool(resource);
		delete tiles[i][12];
		delete tiles[i][13];
		tiles[i][12] = new Ice(resource);
		tiles[i][13] = new Ice(resource);
		delete tiles[i + 10][12];
		delete tiles[i + 10][13];
		tiles[i + 10][12] = new Bush(resource);
		tiles[i + 10][13] = new Bush(resource);
		bushTiles.push_back(Point(i + 10, 12));
		bushTiles.push_back(Point(i + 10, 13));
	}
}


TileController::~TileController()
{
	for (int i = 0; i < tiles.size(); i++) {
		for (int j = 0; j < tiles[i].size(); j++) {
			delete tiles[i][j];
		}
	}
}


void TileController::update( void )
{
}


void TileController::draw( void )
{
	DrawingManager & drawing = level.getDrawingManager();
	const LevelDrawing & levelDrawing = level.getLevelDrawing();

	for (int i = 0; i < LEVEL_GRID_WIDTH; i++)
	{
		for (int j = 0; j < LEVEL_GRID_HEIGHT; j++)
		{
			Tile * tile = tiles[i][j];
			if (tile->getTexture() != NULL)
			{
				Point screenPoint = levelDrawing.getScreenPoint(Point(i, j));
				draw_sprite(drawing.getBuffer(), tile->getTexture(), screenPoint.getX(), screenPoint.getY());
			}
		}
	}
}


void TileController::bulletHitTile( int x, int y )
{
	delete tiles[x][y];
	tiles[x][y] = new EmptySpace();
}


const Tile * TileController::getTile(int x, int y) const
{
	if (x >= 0 && x < LEVEL_GRID_WIDTH &&
		y >= 0 && y < LEVEL_GRID_HEIGHT)
		return tiles[x][y];
	else
		return NULL;
}


void TileController::drawBushTiles( void )
{
	DrawingManager & drawing = level.getDrawingManager();
	const LevelDrawing & levelDrawing = level.getLevelDrawing();

	// 把Bush显示在最上面
	for (list<Point>::iterator it = bushTiles.begin(); it != bushTiles.end(); ++it)
	{
		Tile * tile = tiles[it->getX()][it->getY()];
		
		Point screenPoint = levelDrawing.getScreenPoint(*it);
		draw_sprite(drawing.getBuffer(), tile->getTexture(), screenPoint.getX(), screenPoint.getY());
	}
}

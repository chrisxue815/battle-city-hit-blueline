#include "Level.h"
#include "Player.h"
#include "Enemy.h"
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
	initTanks();
	initTiles();

	const ResourceManager & resource = game.getResourceManager();
	background = resource.getBitmap(BACKGROUND_FRAME);
}


Level::~Level(void)
{
	delete player;

	for (int i = 0; i < tiles.size(); i++) {
		for (int j = 0; j < tiles[i].size(); j++) {
			delete tiles[i][j];
		}
	}
}


void Level::initTanks(void)
{
	player = new Player(*this, Point(10, 20));
	enemyBirthplace.push_back(Point(0, 0));
	enemyBirthplace.push_back(Point(10, 0));
	enemyBirthplace.push_back(Point(20, 0));
	enemyBirthplace.push_back(Point(30, 0));
	enemyBirth = true;
	enemyBirthCooldown = 1000;
}


void Level::initTiles(void)
{
	const ResourceManager & resource = game.getResourceManager();

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


void Level::update(void)
{
	// update bullets
	for (list<Bullet>::iterator it = bullets.begin(); it != bullets.end();)
	{
		it->update();

		if (! it->getAlive())
			it = bullets.erase(it);
		else
			++it;
	}

	player->update();

	// update enemies
	for (list<Enemy>::iterator it = enemies.begin(); it != enemies.end();)
	{
		it->update();

		if (! it->getAlive())
		{
			it = enemies.erase(it);
			enemyBirth = true;
			enemyBirthCooldown = 500;
		}
		else
			++it;
	}

	generateEnemy();
}


void Level::draw(void)
{
	DrawingManager & drawing = game.getDrawingManager();

	draw_sprite(drawing.getBuffer(), background, LEVEL_X, LEVEL_Y);

	for (int i = 0; i < LEVEL_GRID_WIDTH; i++)
	{
		for (int j = 0; j < LEVEL_GRID_HEIGHT; j++)
		{
			Tile * tile = tiles[i][j];
			if (tile->getTexture() != NULL)
			{
				DrawingManager & drawing = game.getDrawingManager();
				Point screenPoint = levelDrawing.getScreenPoint(Point(i, j));
				draw_sprite(drawing.getBuffer(), tile->getTexture(), screenPoint.getX(), screenPoint.getY());
			}
		}
	}

	for (list<Enemy>::iterator it = enemies.begin(); it != enemies.end(); ++it) {
		it->draw();
	}

	player->draw();

	for (list<Bullet>::iterator it = bullets.begin(); it != bullets.end(); ++it) {
		it->draw();
	}

	// 把Bush显示在最上面
	for (list<Point>::iterator it = bushTiles.begin(); it != bushTiles.end(); ++it) {
		Tile * tile = tiles[it->getX()][it->getY()];
		DrawingManager & drawing = game.getDrawingManager();
		Point screenPoint = levelDrawing.getScreenPoint(*it);
		draw_sprite(drawing.getBuffer(), tile->getTexture(), screenPoint.getX(), screenPoint.getY());
	}
}


void Level::bulletHitTile(int x, int y)
{
	delete tiles[x][y];
	tiles[x][y] = new EmptySpace();
}


void Level::bulletHitEnemy(const Enemy & entity)
{
	for (list<Enemy>::iterator it = enemies.begin(); it != enemies.end(); ++it)
	{
		if (&(*it) == &entity)
		{
			it->setAlive(false);
			break;
		}
	}
}


void Level::bulletHitPlayer( void )
{
	player->setAlive(false);
}


void Level::generateEnemy( void )
{
	int milliseconds = getMilliseconds();

	if (enemyBirth)
	{
		enemyBirthCooldown -= milliseconds;
		if (enemyBirthCooldown <= 0)
		{
			enemyBirth = false;
			int birthplace = rand() % enemyBirthplace.size();
			enemies.push_back(Enemy(*this, enemyBirthplace[birthplace]));
		}
	}
}

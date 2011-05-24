#include "Level.h"
#include "Player.h"
#include "EnemyController.h"
#include "BulletController.h"
#include "TileController.h"
using namespace BattleCity;


Level::Level(Game & game)
	: GameComponent(game)
	, levelDrawing(Point(GRID_WIDTH, GRID_HEIGHT), Point(LEVEL_X, LEVEL_Y), 1.0f)
{
	player = new Player(*this, Point(10, 20));
	enemies = new EnemyController(*this);
	bullets = new BulletController(*this);
	tiles = new TileController(*this);

	const ResourceManager & resource = game.getResourceManager();
	background = resource.getBitmap(BACKGROUND_FRAME);
}


Level::~Level(void)
{
	delete player;
	delete enemies;
	delete bullets;
	delete tiles;
}


void Level::update(void)
{
	bullets->update();
	player->update();
	enemies->update();
}


void Level::draw(void)
{
	// 画背景图
	DrawingManager & drawing = game.getDrawingManager();
	draw_sprite(drawing.getBuffer(), background, LEVEL_X, LEVEL_Y);

	tiles->draw();
	enemies->draw();
	player->draw();
	bullets->draw();

	// 把Bush画在最上面
	tiles->drawBushTiles();
}


void Level::addBullet(Bullet & bullet) {
	bullets->add(bullet);
}


void Level::bulletHitTile(int x, int y)
{
	tiles->bulletHitTile(x, y);
}


void Level::bulletHitEnemy(const Enemy & enemy)
{
	enemies->bulletHitEnemy(enemy);
}


void Level::bulletHitPlayer( void )
{
	player->loseALife();
}


bool Level::collidedWithTile( Rectangle & rect )
{
	for (int x = rect.getLeft(); x <= rect.getRight(); ++x)
	{
		for (int y = rect.getTop(); y <= rect.getBottom(); ++y)
		{
			const Tile * tile = getTile(x, y);
			if (tile == NULL || ! tile->canPlayerGoThrough())
				return true;
		}
	}
	return false;
}


bool Level::collidedWithTank( Rectangle & rect )
{
	if (rect.intersects(player->getRect()))
		return true;

	//TODO:
	const list<Enemy> & enemies = getEnemies();
	for (list<Enemy>::const_iterator it = enemies.begin(); it != enemies.end(); ++it)
	{
		if (rect.intersects(it->getRect()))
			return true;
	}

	return false;
}


const list<Enemy> & Level::getEnemies( void ) const
{
	return enemies->getEnemies();
}


const Tile * Level::getTile(int x, int y) const
{
	return tiles->getTile(x, y);
}


const Tile * Level::getTile(const Point & point) const
{
	int x = point.getX();
	int y = point.getY();
	return tiles->getTile(x, y);
}

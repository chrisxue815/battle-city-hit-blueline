#pragma once

#include "Game.h"
#include "TimeManager.h"
#include "LevelDrawing.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Tile.h"
#include <allegro.h>
#include <vector>
#include <list>


namespace BattleCity
{
	/**
	 * 游戏的关卡。
	 *
	 * 主要变量：
	 * <ul>
	 * <li> #player 玩家；</li>
	 * <li> #enemies 敌人；</li>
	 * <li> #bullets 子弹；</li>
	 * <li> #tiles 地面。</li>
	 * </ul>
	 */
	class Level : public Component
	{
	protected:
		Player * player;
		list<Enemy> enemies;
		list<Bullet> bullets;
		vector<vector<Tile*>> tiles;

		vector<Point> enemyBirthplace;
		bool enemyBirth;
		int enemyBirthCooldown;
		list<Point> bushTiles;

		LevelDrawing levelDrawing;
		BITMAP * background;

	public:
		void addBullet(Bullet & bullet);
		void bulletHitTile(int x, int y);
		void bulletHitEnemy(const Enemy & entity);
		void bulletHitPlayer(void);

	public:
		int getRefreshRate(void) const;
		const TimeManager & getTimeManager(void) const;
		const ResourceManager & getResourceManager(void) const;
		DrawingManager & getDrawingManager(void);
		int getMilliseconds(void) const;

		const LevelDrawing & getLevelDrawing(void) const;

	public:
		const Player * getPlayer(void) const;
		const list<Enemy> & getEnemies(void) const;
		const Tile * getTile(int x, int y) const;
		const Tile * getTile(const Point & point) const;

	public:
		Level(Game & game);
		~Level(void);

		// @override
		void update(void);
		// @override
		void draw(void);

	protected:
		void initTanks(void);
		void initTiles(void);
		void generateEnemy(void);
	};


	inline int Level::getRefreshRate(void) const {
		return game.getRefreshRate();
	}

	inline const TimeManager & Level::getTimeManager(void) const {
		return game.getTimeManager();
	}

	inline const ResourceManager & Level::getResourceManager(void) const {
		return game.getResourceManager();
	}

	inline DrawingManager & Level::getDrawingManager(void) {
		return game.getDrawingManager();
	}

	inline int Level::getMilliseconds(void) const {
		return game.getMilliseconds();
	}

	inline const Player * Level::getPlayer(void) const {
		return player;
	}

	inline const list<Enemy> & Level::getEnemies( void ) const {
		return enemies;
	}

	inline const Tile * Level::getTile(int x, int y) const
	{
		if (x >= 0 && x < LEVEL_GRID_WIDTH &&
			y >= 0 && y < LEVEL_GRID_HEIGHT)
			return tiles[x][y];
		else
			return NULL;
	}

	inline const Tile * Level::getTile(const Point & point) const
	{
		int x = point.getX();
		int y = point.getY();
		return getTile(x, y);
	}

	inline const LevelDrawing & Level::getLevelDrawing(void) const {
		return levelDrawing;
	}

	inline void Level::addBullet(Bullet & bullet) {
		bullets.push_back(bullet);
	}
}

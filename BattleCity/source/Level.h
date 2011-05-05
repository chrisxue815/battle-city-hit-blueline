#pragma once

#include "Game.h"
#include "GameComponent.h"
#include "TimeManager.h"
#include "LevelDrawing.h"
#include "Rectangle.h"
#include <allegro.h>
#include <vector>
#include <list>


namespace BattleCity
{
	class Player;
	class Enemy;
	class Bullet;
	class Tile;
	class EnemyController;
	class BulletController;
	class TileController;

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
	class Level : public GameComponent
	{
	protected:
		Player * player;
		EnemyController * enemies;
		BulletController * bullets;
		TileController * tiles;

		LevelDrawing levelDrawing;
		BITMAP * background;

	public:
		Level(Game & game);
		~Level(void);

	public:
		// @override
		void update(void);
		// @override
		void draw(void);

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

		bool collidedWithTile(Rectangle & rect);
		bool collidedWithTank(Rectangle & rect);

	public:
		const Player * getPlayer(void) const;
		const list<Enemy> & getEnemies(void) const;
		const Tile * getTile(int x, int y) const;
		const Tile * getTile(const Point & point) const;
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

	inline const LevelDrawing & Level::getLevelDrawing(void) const {
		return levelDrawing;
	}
}

#pragma once

#include "Game.h"
#include "TimeManager.h"
#include "LevelDrawing.h"
#include "Player.h"
#include "Bullet.h"
#include "Tile.h"
#include <allegro.h>
#include <vector>
#include <list>


namespace BattleCity
{
	class Level : public Component
	{
	protected:
		vector<vector<Tile*>> grids;
		list<Point> bushTiles;

		Player * player;
		list<Bullet> bullets;

		LevelDrawing levelDrawing;
		BITMAP * background;

	public:
		int getRefreshRate(void) const;
		const TimeManager & getTimeManager(void) const;
		const ResourceManager & getResourceManager(void) const;
		DrawingManager & getDrawingManager(void);

		const LevelDrawing & getLevelDrawing(void) const;

	public:
		const Player * getPlayer(void) const;
		const Tile * getGrid(int x, int y) const;
		const Tile * getGrid(const Point & point) const;

		void addBullet(Bullet & bullet);
		void bulletHit(int x, int y);
		//void bulletHit(const Entity * entity);

	public:
		Level(Game & game);
		~Level(void);

		// @override
		void update(void);
		// @override
		void draw(void);
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

	inline const Player * Level::getPlayer(void) const {
		return player;
	}

	inline const LevelDrawing & Level::getLevelDrawing(void) const {
		return levelDrawing;
	}

	inline const Tile * Level::getGrid(int x, int y) const
	{
		if (x >= 0 && x < LEVEL_GRID_WIDTH &&
			y >= 0 && y < LEVEL_GRID_HEIGHT)
			return grids[x][y];
		else
			return NULL;
	}

	inline const Tile * Level::getGrid(const Point & point) const
	{
		int x = point.getX();
		int y = point.getY();
		return getGrid(x, y);
	}

	inline void Level::addBullet(Bullet & bullet) {
		bullets.push_back(bullet);
	}
}

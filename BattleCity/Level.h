#pragma once

#include "Game.h"
#include "Player.h"
#include "TimeManager.h"
#include "LevelDrawing.h"
#include <allegro.h>
#include <vector>


namespace BattleCity
{
	class Level : public Component
	{
	protected:
		typedef vector<int> vector1;
		typedef vector<vector1> vector2;

		vector2 board;

		Player * player;

		LevelDrawing levelDrawing;

	public:
		int getRefreshRate(void) const;
		const TimeManager * getTimeManager(void) const;
		const ResourceManager & getResourceManager(void) const;
		DrawingManager & getDrawingManager(void);

		const LevelDrawing & getLevelDrawing(void) const;

	public:
		const Player * getPlayer(void) const;

	public:
		Level(Game & game);
		~Level(void);

		// @override
		void init(void);
		// @override
		void update(void);
		// @override
		void draw(void);
	};


	inline int Level::getRefreshRate(void) const {
		return game.getRefreshRate();
	}

	inline const TimeManager * Level::getTimeManager(void) const {
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
}

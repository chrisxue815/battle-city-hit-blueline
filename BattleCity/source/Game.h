#pragma once

#include "GameException.h"
#include "ResourceManager.h"
#include "DrawingManager.h"
#include "TimeManager.h"
#include "TimeSpan.h"
#include <allegro.h>


namespace BattleCity
{
	class Level;
	class GameStateMonitor;

	class Game
	{
	protected:
		char exePath[MAX_PATH_SIZE];
		char dirPath[MAX_PATH_SIZE];

		int width;
		int height;

		int refreshRate;

		bool running;

		TimeManager * timeManager;
		ResourceManager * resource;
		DrawingManager * drawing;

		Level * level;
		GameStateMonitor * monitor;

	public:
		int getRefreshRate(void) const;
		const TimeManager & getTimeManager(void) const;
		const ResourceManager & getResourceManager(void) const;
		DrawingManager & getDrawingManager(void);
		int getMilliseconds(void) const;

	public:
		Game(void);
		~Game(void);

		void execute(void);

		void update(void);
		void draw(void);

	private:
		void initGraphics(void);
		void initManager(void);
	};


	inline int Game::getRefreshRate(void) const {
		return refreshRate;
	}

	inline const TimeManager & Game::getTimeManager(void) const {
		return *timeManager;
	}

	inline const ResourceManager & Game::getResourceManager(void) const {
		return *resource;
	}

	inline DrawingManager & Game::getDrawingManager(void) {
		return *drawing;
	}

	inline int Game::getMilliseconds(void) const {
		return timeManager->getInterval().getMilliseconds();
	}
}

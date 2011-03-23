#pragma once

#include "GameException.h"
#include "ResourceManager.h"
#include "DrawingManager.h"
#include "GameTime.h"
#include "TimeSpan.h"
#include "Level.h"
#include "GameStateMonitor.h"
#include <allegro.h>


namespace BattleCity
{
	class Game
	{
	protected:
		char exePath[MAX_PATH_SIZE];
		char dirPath[MAX_PATH_SIZE];

		int width;
		int height;

		int refreshRate;

		bool running;

		ResourceManager resource;
		DrawingManager drawing;
		GameTime * gameTime;

		Level * level;
		GameStateMonitor monitor;

	public:
		int getFreshRate(void) const;
		const GameTime & getGameTime(void) const;

	public:
		Game(void);
		~Game(void);

		void init();
		void execute(void);

		void update(void);
		void draw(void);

	private:
		void initGraphics(void);
		void initData(void);
	};


	inline int Game::getFreshRate(void) const {
		return refreshRate;
	}

	inline const GameTime & Game::getGameTime(void) const {
		return *gameTime;
	}
}

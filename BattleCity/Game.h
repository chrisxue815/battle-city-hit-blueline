#pragma once

#include "GameException.h"
#include "ContentManager.h"
#include "GameTime.h"
#include "TimeSpan.h"
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

		BITMAP * buffer;

		ContentManager content;

	public:
		Game(void);
		~Game(void);

		void init();
		void execute(void);

		void update(const GameTime & gameTime);
		void draw(const GameTime & gameTime);

		int getFreshRate(void) const;

	private:
		void initGraphics(void);
		void initData(void);
	};


	inline int Game::getFreshRate(void) const
	{
		return refreshRate;
	}
}

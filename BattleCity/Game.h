#pragma once

#include "GameException.h"
#include "ContentManager.h"
#include <allegro.h>


namespace BattleCity
{
	class Game
	{
	private:
		char exePath[MAX_PATH_SIZE];
		char dirPath[MAX_PATH_SIZE];

		int width;
		int height;

		BITMAP * buffer;

		ContentManager content;

	public:
		Game(void);
		~Game(void);

		void init();
		void execute(void);

	private:
		void initGraphics(void);
		void initData(void);
	};
}

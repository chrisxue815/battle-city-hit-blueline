#pragma once

#include "GameException.h"
#include "Macro.h"
#include <allegro.h>


namespace BattleCity
{
	class ContentManager
	{
	private:
		char dirPath[MAX_PATH_SIZE];
		char rootPath[MAX_PATH_SIZE];

	public:
		ContentManager(void);
		~ContentManager(void);

		void init(char * dirPath);
		void setRootDirectory(char * rootPath);

		BITMAP * loadBitmap(const char * fileName);
	};
}

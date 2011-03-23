#pragma once

#include "GameException.h"
#include "Macro.h"
#include <allegro.h>


namespace BattleCity
{
	class ResourceManager
	{
	private:
		char dirPath[MAX_PATH_SIZE];
		char rootPath[MAX_PATH_SIZE];

	public:
		ResourceManager(void);
		~ResourceManager(void);

		void init(char * dirPath);
		void setRootDirectory(char * rootPath);

		BITMAP * loadBitmap(const char * fileName) const;
	};
}

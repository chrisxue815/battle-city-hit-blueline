#pragma once

#include "GameException.h"
#include "Macro.h"
#include <allegro.h>
#include <alpng.h>


namespace BattleCity
{
	class ResourceManager
	{
	protected:
		char dirPath[MAX_PATH_SIZE];
		char rootPath[MAX_PATH_SIZE];
		BITMAP * texture[END_FRAME];

	public:
		ResourceManager(char * dirPath, char * rootPath);
	protected:
		~ResourceManager(void);

	public:
		BITMAP * getBitmap(BitmapFrame frame) const;

	protected:
		BITMAP * loadBitmap(const char * fileName) const;
	};
}

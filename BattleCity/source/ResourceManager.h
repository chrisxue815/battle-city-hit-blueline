#pragma once

#include "GameException.h"
#include "Macro.h"
#include <allegro.h>
#include <alpng.h>


namespace BattleCity
{
	enum BitmapFrame
	{
		PLAYER1_UP_FRAME,
		PLAYER1_DOWN_FRAME,
		PLAYER1_LEFT_FRAME,
		PLAYER1_RIGHT_FRAME,
		BULLET_FRAME,
		BRICK_FRAME,
		STEEL_FRAME,
		POOL_FRAME,
		ICE_FRAME,
		BUSH_FRAME,
		ENEMY_BIRTHPLACE,
		BACKGROUND_FRAME,

		END_FRAME
	};

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

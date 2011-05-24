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

		ENEMY1_UP_FRAME,
		ENEMY1_DOWN_FRAME,
		ENEMY1_LEFT_FRAME,
		ENEMY1_RIGHT_FRAME,

		ENEMY2_UP_FRAME,
		ENEMY2_DOWN_FRAME,
		ENEMY2_LEFT_FRAME,
		ENEMY2_RIGHT_FRAME,

		ENEMY3_UP_FRAME,
		ENEMY3_DOWN_FRAME,
		ENEMY3_LEFT_FRAME,
		ENEMY3_RIGHT_FRAME,

		ENEMY4_UP_FRAME,
		ENEMY4_DOWN_FRAME,
		ENEMY4_LEFT_FRAME,
		ENEMY4_RIGHT_FRAME,

		ENEMY_BIRTHPLACE_FRAME,

		BULLET_FRAME,

		BRICK_FRAME,
		STEEL_FRAME,
		POOL_FRAME,
		ICE_FRAME,
		BUSH_FRAME,

		BACKGROUND_FRAME,

		END_FRAME
	};

	class ResourceManager
	{
	protected:
		char * rootPath;

		BITMAP * texture[END_FRAME];

	public:
		ResourceManager(void);
	protected:
		~ResourceManager(void);

	public:
		BITMAP * getBitmap(BitmapFrame frame) const;

	protected:
		BITMAP * loadBitmap(const char * fileName) const;
	};
}

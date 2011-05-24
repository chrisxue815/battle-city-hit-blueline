#include "ResourceManager.h"
using namespace BattleCity;


ResourceManager::ResourceManager(void)
{
	alpng_init();

	rootPath = "resource/";

	texture[PLAYER1_UP_FRAME] = loadBitmap("texture/player/player1-up.bmp");
	texture[PLAYER1_DOWN_FRAME] = loadBitmap("texture/player/player1-down.bmp");
	texture[PLAYER1_LEFT_FRAME] = loadBitmap("texture/player/player1-left.bmp");
	texture[PLAYER1_RIGHT_FRAME] = loadBitmap("texture/player/player1-right.bmp");

	texture[ENEMY1_UP_FRAME] = loadBitmap("texture/enemy/enemy1-up.bmp");
	texture[ENEMY1_DOWN_FRAME] = loadBitmap("texture/enemy/enemy1-DOWN.bmp");
	texture[ENEMY1_LEFT_FRAME] = loadBitmap("texture/enemy/enemy1-LEFT.bmp");
	texture[ENEMY1_RIGHT_FRAME] = loadBitmap("texture/enemy/enemy1-RIGHT.bmp");

	texture[ENEMY2_UP_FRAME] = loadBitmap("texture/enemy/enemy2-up.bmp");
	texture[ENEMY2_DOWN_FRAME] = loadBitmap("texture/enemy/enemy2-DOWN.bmp");
	texture[ENEMY2_LEFT_FRAME] = loadBitmap("texture/enemy/enemy2-LEFT.bmp");
	texture[ENEMY2_RIGHT_FRAME] = loadBitmap("texture/enemy/enemy2-RIGHT.bmp");

	texture[ENEMY3_UP_FRAME] = loadBitmap("texture/enemy/enemy3-up.bmp");
	texture[ENEMY3_DOWN_FRAME] = loadBitmap("texture/enemy/enemy3-DOWN.bmp");
	texture[ENEMY3_LEFT_FRAME] = loadBitmap("texture/enemy/enemy3-LEFT.bmp");
	texture[ENEMY3_RIGHT_FRAME] = loadBitmap("texture/enemy/enemy3-RIGHT.bmp");

	texture[ENEMY4_UP_FRAME] = loadBitmap("texture/enemy/enemy4-up.bmp");
	texture[ENEMY4_DOWN_FRAME] = loadBitmap("texture/enemy/enemy4-DOWN.bmp");
	texture[ENEMY4_LEFT_FRAME] = loadBitmap("texture/enemy/enemy4-LEFT.bmp");
	texture[ENEMY4_RIGHT_FRAME] = loadBitmap("texture/enemy/enemy4-RIGHT.bmp");

	texture[ENEMY_BIRTHPLACE_FRAME] = loadBitmap("texture/scene1/enemyBirthplace.bmp");

	texture[BULLET_FRAME] = loadBitmap("texture/bullet.png");

	texture[BRICK_FRAME] = loadBitmap("texture/scene1/brick.bmp");
	texture[STEEL_FRAME] = loadBitmap("texture/scene1/steel.bmp");
	texture[POOL_FRAME] = loadBitmap("texture/scene1/pool.bmp");
	texture[ICE_FRAME] = loadBitmap("texture/scene1/ice.bmp");
	texture[BUSH_FRAME] = loadBitmap("texture/scene1/bush.bmp");
	
	texture[BACKGROUND_FRAME] = loadBitmap("texture/scene1/background.bmp");
}


ResourceManager::~ResourceManager(void)
{
	for (int i = 0; i < END_FRAME; i++)
	{
		if (texture[i] != NULL)
			destroy_bitmap(texture[i]);
	}

	delete rootPath;
}


BITMAP * ResourceManager::getBitmap(BitmapFrame frame) const
{
	if (frame >= 0 && frame < END_FRAME)
		return texture[frame];
	else
		return NULL;
}


BITMAP * ResourceManager::loadBitmap(const char * fileName) const
{
	char filePath[MAX_PATH_SIZE];

	// filePath = rootPath + fileName
	append_filename(filePath, rootPath, fileName, sizeof(filePath));

	//    resource/a.bmp
	// => resource/a.bmp  (UNIX)
	// => resource\a.bmp  (WINDOWS)
	fix_filename_slashes(filePath);

	BITMAP * bmp = load_bitmap(filePath, NULL);

	if (!bmp)
		throw GameException("File not exist.", LOAD_BITMAP_EXCEPTION);

	return bmp;
}

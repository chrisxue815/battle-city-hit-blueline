#include "ResourceManager.h"
using namespace BattleCity;


ResourceManager::ResourceManager(void)
{
	alpng_init();

	// unicode and safe strcpy
	ustrzcpy(rootPath, sizeof(rootPath), "resource/");

	texture[PLAYER1_UP_FRAME] = loadBitmap("texture/player/player1-up.bmp");
	texture[PLAYER1_DOWN_FRAME] = loadBitmap("texture/player/player1-down.bmp");
	texture[PLAYER1_LEFT_FRAME] = loadBitmap("texture/player/player1-left.bmp");
	texture[PLAYER1_RIGHT_FRAME] = loadBitmap("texture/player/player1-right.bmp");
	texture[BULLET_FRAME] = loadBitmap("texture/player/bullet.png");
	texture[BRICK_FRAME] = loadBitmap("texture/scene1/brick.bmp");
	texture[STEEL_FRAME] = loadBitmap("texture/scene1/steel.bmp");
	texture[POOL_FRAME] = loadBitmap("texture/scene1/pool.bmp");
	texture[ICE_FRAME] = loadBitmap("texture/scene1/ice.bmp");
	texture[BUSH_FRAME] = loadBitmap("texture/scene1/bush.bmp");
	texture[ENEMY_BIRTHPLACE] = loadBitmap("texture/scene1/enemyBirthplace.bmp");
	texture[BACKGROUND_FRAME] = loadBitmap("texture/scene1/background.bmp");
}


ResourceManager::~ResourceManager(void)
{
	for (int i = 0; i < END_FRAME; i++)
	{
		if (texture[i] != NULL)
			destroy_bitmap(texture[i]);
	}
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

	// resource/a.bmp
	//   => resource/a.bmp  (UNIX)
	//   => resource\a.bmp  (WINDOWS)
	fix_filename_slashes(filePath);

	BITMAP * bmp = load_bitmap(filePath, NULL);

	if (!bmp)
		throw GameException("File not exist.", LOAD_BITMAP_EXCEPTION);

	return bmp;
}

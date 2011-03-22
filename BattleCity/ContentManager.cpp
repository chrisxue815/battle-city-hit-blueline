#include "ContentManager.h"
using namespace BattleCity;


ContentManager::ContentManager(void)
{
}


ContentManager::~ContentManager(void)
{
}


void ContentManager::init(char * dirPath)
{
	strcpy(this->dirPath, dirPath);
}


void ContentManager::setRootDirectory(char * rootPath)
{
	append_filename(this->rootPath, dirPath, rootPath, sizeof(this->rootPath));
}


BITMAP * ContentManager::loadBitmap(const char * fileName)
{
	char filePath[MAX_PATH_SIZE];
	append_filename(filePath, rootPath, fileName, sizeof(filePath));

	BITMAP * bmp = load_bitmap(filePath, NULL);

	if (!bmp)
		throw GameException("File not exist.", LOAD_BITMAP_EXCEPTION);

	return bmp;
}

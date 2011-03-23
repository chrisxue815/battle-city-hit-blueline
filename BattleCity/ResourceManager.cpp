#include "ResourceManager.h"
using namespace BattleCity;


ResourceManager::ResourceManager(void)
{
}


ResourceManager::~ResourceManager(void)
{
}


void ResourceManager::init(char * dirPath)
{
	ustrzncpy(this->dirPath, sizeof(this->dirPath), dirPath, sizeof(this->dirPath));
}


void ResourceManager::setRootDirectory(char * rootPath)
{
	append_filename(this->rootPath, dirPath, rootPath, sizeof(this->rootPath));
}


BITMAP * ResourceManager::loadBitmap(const char * fileName) const
{
	char filePath[MAX_PATH_SIZE];
	append_filename(filePath, rootPath, fileName, sizeof(filePath));

	BITMAP * bmp = load_bitmap(filePath, NULL);

	if (!bmp)
		throw GameException("File not exist.", LOAD_BITMAP_EXCEPTION);

	return bmp;
}

#include "ImageDrawing.h"
using namespace BattleCity;


ImageDrawing::ImageDrawing(void)
{
	texture = NULL;
}


ImageDrawing::~ImageDrawing(void)
{
	if (texture != NULL)
		destroy_bitmap(texture);
}


// @override
void ImageDrawing::init(const ResourceManager & resource, const char fileName[MAX_PATH_SIZE])
{
	texture = resource.loadBitmap(fileName);
}


// @override
void ImageDrawing::draw(const LevelDrawing & levelDrawing)
{
	//levelDrawing.getScreenPoint(
}

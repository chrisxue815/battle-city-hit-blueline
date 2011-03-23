#include "DrawingManager.h"
using namespace BattleCity;


DrawingManager::DrawingManager(void)
{
	buffer = NULL;
}


DrawingManager::~DrawingManager(void)
{
	if (buffer != NULL)
		destroy_bitmap(buffer);
}


void DrawingManager::init(void)
{
	buffer = create_bitmap(SCREEN_W, SCREEN_H);
}


void DrawingManager::clear(void)
{
	clear_to_color(buffer, makecol(117,117,117));
}


void DrawingManager::flush(void)
{
	acquire_screen();
	blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	release_screen();
}

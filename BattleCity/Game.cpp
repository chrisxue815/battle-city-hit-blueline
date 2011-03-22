#include "Game.h"
using namespace BattleCity;


Game::Game(void)
{
	buffer = NULL;
}


Game::~Game(void)
{
	if (buffer != NULL)
		destroy_bitmap(buffer);
}


void Game::execute(void)
{
	while (true)
	{
		acquire_screen();
		blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
		release_screen();

		if (keypressed())
			break;
	}
}


void Game::init()
{
	initGraphics();
	install_keyboard();
	install_timer();
	retrace_count;
	initData();
}


void Game::initGraphics(void)
{
	int depth = desktop_color_depth();
    if (depth != 0) {
        set_color_depth(depth);
    }

	PALETTE palette;
	generate_332_palette(palette);
	set_palette(palette);

	width = 640;
	height = 480;

	if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, width, height, 0, 0) != 0) {
		if (set_gfx_mode(GFX_SAFE, 640, 480, 0, 0) != 0) {
			throw GameException("Unable to set any graphic mode.", SET_GFX_MODE_EXCEPTION);
		}
	}
}


void Game::initData(void)
{
	//buffer = create_bitmap(SCREEN_W, SCREEN_H);

	get_executable_name(exePath, sizeof(exePath));
	replace_filename(dirPath, exePath, "", sizeof(dirPath));

	content.init(dirPath);
	content.setRootDirectory("content");
	buffer = content.loadBitmap("texture\\test.bmp");
}

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
	GameTime gameTime = GameTime::begin(refreshRate);

	while (running)
	{
		if (gameTime.next())
		{
			update(gameTime);
			draw(gameTime);
		}
	}
}


void Game::update(const GameTime & gameTime)
{
	if (keypressed())
		running = false;
}


void Game::draw(const GameTime & gameTime)
{
	char buf[100];
	uszprintf(buf, sizeof(buf), "%d", gameTime.getFps());

	acquire_screen();
	textout_ex(buffer, font, buf, 10, 10, makecol(255,255,255), makecol(0,0,0));
	blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	release_screen();
}


void Game::init()
{
	initGraphics();
	install_keyboard();
	install_timer();
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
	get_executable_name(exePath, sizeof(exePath));
	replace_filename(dirPath, exePath, "", sizeof(dirPath));

	content.init(dirPath);
	content.setRootDirectory("content");

	buffer = create_bitmap(SCREEN_W, SCREEN_H);

	refreshRate = get_refresh_rate();

	running = true;
}

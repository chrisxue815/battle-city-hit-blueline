#include "Game.h"
using namespace BattleCity;


Game::Game(void)
{
	level = new Level(*this);
	gameTime = & GameTime::getInstance();
}


Game::~Game(void)
{
	delete level;
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

	resource.init(dirPath);
	resource.setRootDirectory("resource");
	drawing.init();

	refreshRate = get_refresh_rate();

	running = true;

	level->init(resource);
	monitor.init(resource);
}


void Game::execute(void)
{
	gameTime->begin(refreshRate);

	while (running)
	{
		if (gameTime->next())
		{
			update();
			draw();
		}
	}
}


void Game::update(void)
{
	level->update();
	monitor.update();
	monitor.showFps(*gameTime);
	monitor.showPlayerPoint(level->getPlayer());
	if (keypressed() && key[KEY_ESC])
		running = false;
}


void Game::draw(void)
{
	drawing.clear();
	level->draw(drawing);
	monitor.draw(drawing);
	drawing.flush();
}

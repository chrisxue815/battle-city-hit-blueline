#include "Game.h"
#include "Level.h"
#include "GameStateMonitor.h"
using namespace BattleCity;


Game::Game(void)
{
	initGraphics();
	install_keyboard();
	install_timer();
	initManager();
	srand(unsigned int(time(NULL)));

	level = new Level(*this);
	monitor = new GameStateMonitor(*this);

	refreshRate = get_refresh_rate();
	running = true;
}


Game::~Game(void)
{
	delete level;
	delete monitor;
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

	if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, GAME_WIDTH, GAME_HEIGHT, 0, 0) != 0) {
		throw GameException("Unable to set any graphic mode.", SET_GFX_MODE_EXCEPTION);
	}
}


void Game::initManager(void)
{
	get_executable_name(exePath, sizeof(exePath));
	replace_filename(dirPath, exePath, "", sizeof(dirPath));

	resource = new ResourceManager(dirPath, "resource");
	drawing = new DrawingManager();
	timeManager = & TimeManager::getInstance();
}


void Game::execute(void)
{
	timeManager->begin(refreshRate);

	while (running)
	{
		if (timeManager->next())
		{
			update();
			draw();
		}
	}
}


void Game::update(void)
{
	level->update();

	monitor->update();
	monitor->showFps(*timeManager);

	const Player * player = level->getPlayer();
	if (player != NULL)
		monitor->showPlayerPoint(*player);

	if (keypressed() && key[KEY_ESC])
		running = false;
}


void Game::draw(void)
{
	drawing->clear();
	level->draw();
	monitor->draw();
	drawing->flush();
}

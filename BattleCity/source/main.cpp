#include "Game.h"
#include <allegro.h>
using namespace BattleCity;

int main()
{
	if (allegro_init() != 0) {
		return 1;
    }

	try
	{
		Game game;

		game.execute();
	}
	catch (GameException ex)
	{
		set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
		allegro_message("Error: %d\nDetail: %s\nAllegro Error: %s\n",
			ex.getType(), ex.what(), allegro_error);
	}

	return 0;
}
END_OF_MAIN()

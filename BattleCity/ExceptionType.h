#pragma once


namespace BattleCity
{
	enum ExceptionType
	{
		NO_EXCEPTION,
		ALLEGRO_INIT_EXCEPTION,
		SET_GFX_MODE_EXCEPTION,  // Unable to set any graphic mode
		LOAD_BITMAP_EXCEPTION,
	};
}

#pragma once

#include <allegro.h>


namespace BattleCity
{
	// interface
	class Tile
	{
	protected:
		Tile(void);

	public:
		virtual BITMAP * getTexture(void) = 0;
		virtual bool getSolid(void) const = 0;
	};


	inline Tile::Tile(void) {
	}
}

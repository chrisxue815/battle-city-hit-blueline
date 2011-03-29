#pragma once

#include "Tile.h"
#include "ResourceManager.h"
#include <allegro.h>


namespace BattleCity
{
	class EmptySpace : public Tile
	{
	public:
		EmptySpace(void);

	public:
		// @override
		BITMAP * getTexture(void);
		// @override
		bool getSolid(void) const;

	public:
		void onBulletHit(void);
	};

	inline EmptySpace::EmptySpace(void) {
	}

	inline BITMAP * EmptySpace::getTexture(void) {
		return NULL;
	}

	inline bool EmptySpace::getSolid(void) const {
		return false;
	}
}

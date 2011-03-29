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
		bool canPlayerGoThrough(void) const;
		// @override
		BulletEvent getBulletEvent(void) const;
		// @override
		bool speedUpPlayer(void) const;
	};

	inline EmptySpace::EmptySpace(void) {
	}

	inline BITMAP * EmptySpace::getTexture(void) {
		return NULL;
	}

	inline bool EmptySpace::canPlayerGoThrough(void) const {
		return true;
	}

	inline BulletEvent EmptySpace::getBulletEvent( void ) const {
		return BULLET_CAN_GO_THROUGH;
	}

	inline bool EmptySpace::speedUpPlayer( void ) const {
		return false;
	}
}

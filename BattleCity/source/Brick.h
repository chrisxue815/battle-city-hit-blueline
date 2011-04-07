#pragma once

#include "Tile.h"
#include "ResourceManager.h"
#include <allegro.h>


namespace BattleCity
{
	class Brick : public Tile
	{
	protected:
		BITMAP * texture;

	public:
		Brick(const ResourceManager & resource);

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

	inline Brick::Brick(const ResourceManager & resource)
	{
		texture = resource.getBitmap(BRICK_FRAME);
	}

	inline BITMAP * Brick::getTexture(void) {
		return texture;
	}

	inline bool Brick::canPlayerGoThrough(void) const {
		return false;
	}

	inline BulletEvent Brick::getBulletEvent( void ) const {
		return BULLET_CAN_HIT;
	}

	inline bool Brick::speedUpPlayer( void ) const {
		return false;
	}
}

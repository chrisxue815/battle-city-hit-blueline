#pragma once

#include "Tile.h"
#include "ResourceManager.h"
#include <allegro.h>


namespace BattleCity
{
	class Steel : public Tile
	{
	protected:
		BITMAP * texture;

	public:
		Steel(const ResourceManager & resource);

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

	inline Steel::Steel(const ResourceManager & resource)
	{
		texture = resource.getBitmap(STEEL_FRAME);
	}

	inline BITMAP * Steel::getTexture(void) {
		return texture;
	}

	inline bool Steel::canPlayerGoThrough(void) const {
		return false;
	}

	inline BulletEvent Steel::getBulletEvent( void ) const {
		return BULLET_CANNOT_HIT;
	}

	inline bool Steel::speedUpPlayer( void ) const {
		return false;
	}
}

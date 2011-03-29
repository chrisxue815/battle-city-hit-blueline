#pragma once

#include "Tile.h"
#include "ResourceManager.h"
#include <allegro.h>


namespace BattleCity
{
	class Pool : public Tile
	{
	protected:
		BITMAP * texture;

	public:
		Pool(const ResourceManager & resource);

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

	inline Pool::Pool(const ResourceManager & resource)
	{
		texture = resource.getBitmap(POOL_FRAME);
	}

	inline BITMAP * Pool::getTexture(void) {
		return texture;
	}

	inline bool Pool::canPlayerGoThrough(void) const {
		return false;
	}

	inline BulletEvent Pool::getBulletEvent( void ) const {
		return BULLET_CAN_GO_THROUGH;
	}

	inline bool Pool::speedUpPlayer( void ) const {
		return false;
	}
}

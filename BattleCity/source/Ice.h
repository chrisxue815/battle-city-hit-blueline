#pragma once

#include "Tile.h"
#include "ResourceManager.h"
#include <allegro.h>


namespace BattleCity
{
	class Ice : public Tile
	{
	protected:
		BITMAP * texture;

	public:
		Ice(const ResourceManager & resource);

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

	inline Ice::Ice(const ResourceManager & resource)
	{
		texture = resource.getBitmap(ICE_FRAME);
	}

	inline BITMAP * Ice::getTexture(void) {
		return texture;
	}

	inline bool Ice::canPlayerGoThrough(void) const {
		return true;
	}

	inline BulletEvent Ice::getBulletEvent( void ) const {
		return BULLET_CAN_GO_THROUGH;
	}

	inline bool Ice::speedUpPlayer( void ) const {
		return true;
	}
}

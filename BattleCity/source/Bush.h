#pragma once

#include "Tile.h"
#include "ResourceManager.h"
#include <allegro.h>


namespace BattleCity
{
	class Bush : public Tile
	{
	protected:
		BITMAP * texture;

	public:
		Bush(const ResourceManager & resource);

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

	inline Bush::Bush(const ResourceManager & resource)
	{
		texture = resource.getBitmap(BUSH_FRAME);
	}

	inline BITMAP * Bush::getTexture(void) {
		return texture;
	}

	inline bool Bush::canPlayerGoThrough(void) const {
		return true;
	}

	inline BulletEvent Bush::getBulletEvent( void ) const {
		return BULLET_CAN_GO_THROUGH;
	}

	inline bool Bush::speedUpPlayer( void ) const {
		return false;
	}
}

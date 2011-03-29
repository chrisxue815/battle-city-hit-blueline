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
		bool getSolid(void) const;

	public:
		void onBulletHit(void);
	};

	inline Brick::Brick(const ResourceManager & resource)
	{
		texture = resource.getBitmap(BRICK_FRAME);
	}

	inline BITMAP * Brick::getTexture(void) {
		return texture;
	}

	inline bool Brick::getSolid(void) const {
		return true;
	}
}

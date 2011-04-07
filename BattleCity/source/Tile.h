#pragma once

#include <allegro.h>


namespace BattleCity
{
	enum BulletEvent {
		BULLET_CAN_GO_THROUGH,
		BULLET_CAN_HIT,
		BULLET_CANNOT_HIT
	};

	// interface
	class Tile
	{
	protected:
		Tile(void);

	public:
		virtual BITMAP * getTexture(void) = 0;
		virtual bool canPlayerGoThrough(void) const = 0;
		virtual BulletEvent getBulletEvent(void) const = 0;
		virtual bool speedUpPlayer(void) const = 0;
	};


	inline Tile::Tile(void) {
	}
}

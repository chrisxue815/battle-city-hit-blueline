#pragma once

#include "Entity.h"
#include "Tank.h"
#include "Point.h"
#include "Macro.h"
#include <allegro.h>


namespace BattleCity
{
	class Level;

	class Bullet : public Entity
	{
	protected:
		static const int MS_PER_GRID = 50;
		Point direction;
		int offset;
		bool alive;
		BITMAP * texture;

	public:
		Bullet(Level & level, const Point & point, const Point & direction);

	public:
		// @override
		void update(void);
		// @override
		void draw(void);

	public:
		bool getAlive(void);

	protected:
		void updateMoving(int milliseconds);
		void collisionDetection(void);
	};

	inline bool Bullet::getAlive(void) {
		return alive;
	}
}

#pragma once

#include "BulletType.h"
#include "Entity.h"
#include "Macro.h"
#include <allegro.h>


namespace BattleCity
{
	class Point;

	class Bullet : public Entity
	{
	protected:
		static const int MS_PER_GRID = 50;

		BulletType type;
		Direction direction;
		Point directionVector;
		int offset;

		BITMAP * texture;

	public:
		Bullet(Level & level, BulletType type, const Point & point, Direction direction);

	public:
		// @override
		void update(void);
		// @override
		void draw(void);

	protected:
		void updateMoving(int milliseconds);
		void collisionDetection(void);
	};
}

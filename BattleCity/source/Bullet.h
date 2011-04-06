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
		const Entity * shooter;
		Direction direction;
		Point directionVector;
		int offset;
		BITMAP * texture;

	public:
		Bullet(Level & level, const Entity * shooter, const Point & point, Direction direction);

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

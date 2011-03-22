#pragma once

#include "Entity.h"


namespace BattleCity
{
	class Painter
	{
	protected:
		Entity * owner;

	public:
		Painter(void);
		~Painter(void);

		virtual void draw(int gameTime) = 0;
	};
}

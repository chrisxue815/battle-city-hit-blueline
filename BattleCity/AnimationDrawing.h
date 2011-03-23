#pragma once

#include "IEntityDrawing.h"
#include <allegro.h>


namespace BattleCity
{
	class AnimationDrawing : public IEntityDrawing
	{
	public:
		AnimationDrawing(void);
		~AnimationDrawing(void);
	};
}

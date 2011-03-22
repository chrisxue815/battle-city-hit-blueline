#pragma once

#include "TimeSpan.h"
#include <allegro.h>


namespace BattleCity
{
	// @static
	class GameTime
	{
	protected:
		int ticks;
		int intervalTicks;
		int refreshRate;
		TimeSpan timeSpan;

	protected:
		GameTime(void);

	public:
		static const GameTime & begin(int refreshRate);

	public:
		bool next(void);
		void update(void);

		int getFps(void) const;
		const TimeSpan & getInterval(void) const;

	protected:
		void init(int refreshRate);
	};


	inline const TimeSpan & GameTime::getInterval(void) const
	{
		return timeSpan;
	}
}

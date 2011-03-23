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
		int refreshRate;
		TimeSpan interval;

	protected:
		GameTime(void);

	public:
		static GameTime & getInstance(void);

	public:
		void begin(int refreshRate);
		bool next(void);
		void update(void);

		int getRefreshRate(void) const;
		int getFps(void) const;
		const TimeSpan & getInterval(void) const;
	};


	inline int GameTime::getRefreshRate(void) const
	{
		return refreshRate;
	}

	inline const TimeSpan & GameTime::getInterval(void) const
	{
		return interval;
	}
}

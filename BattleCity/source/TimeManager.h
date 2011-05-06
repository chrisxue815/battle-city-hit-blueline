#pragma once

#include "TimeSpan.h"
#include <allegro.h>


namespace BattleCity
{
	// @static
	class TimeManager
	{
	protected:
		int ticks;
		int refreshRate;
		TimeSpan interval;

	protected:
		TimeManager(void);

	public:
		static TimeManager & getInstance(void);

	public:
		void begin(int refreshRate);
		bool next(void);
		void update(void);

		int getRefreshRate(void) const { return refreshRate; }
		int getFps(void) const;
		const TimeSpan & getInterval(void) const { return interval; }
	};
}

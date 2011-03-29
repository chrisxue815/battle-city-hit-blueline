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

		int getRefreshRate(void) const;
		int getFps(void) const;
		const TimeSpan & getInterval(void) const;
	};


	inline int TimeManager::getRefreshRate(void) const
	{
		return refreshRate;
	}

	inline const TimeSpan & TimeManager::getInterval(void) const
	{
		return interval;
	}
}

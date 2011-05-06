#pragma once


namespace BattleCity
{
	class TimeSpan
	{
	protected:
		int refreshRate;
		int ticks;

	public:
		TimeSpan(int refreshRate);
		TimeSpan(int refreshRate, int ticks);
		TimeSpan(int refreshRate, int seconds, int milliseconds);

		int getTicks(void) const { return ticks; }
		void setTicks(int val) { ticks = val; }

		int getSeconds(void) const { return ticks / refreshRate; }
		void setSeconds(int val) { ticks = refreshRate * val; }

		int getMilliseconds(void) const { return ticks * 1000 / refreshRate; }
		void setMilliseconds(int val) { ticks = refreshRate * val / 1000; }

		int getRefreshRate(void) const { return refreshRate; }
		void setRefreshRate(int val) { refreshRate = val; }
	};
}

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

		int getTicks(void) const;
		void setTicks(int);

		int getSeconds(void) const;
		void setSeconds(int);

		int getMilliseconds(void) const;
		void setMilliseconds(int);
	};


	inline int TimeSpan::getTicks(void) const
	{
		return ticks;
	}

	inline void TimeSpan::setTicks(int ticks)
	{
		this->ticks = ticks;
	}

	inline int TimeSpan::getSeconds(void) const
	{
		return ticks / refreshRate;
	}

	inline void TimeSpan::setSeconds(int seconds)
	{
		this->ticks = refreshRate * seconds;
	}

	inline int TimeSpan::getMilliseconds(void) const
	{
		return ticks * 1000 / refreshRate;
	}

	inline void TimeSpan::setMilliseconds(int milliseconds)
	{
		this->ticks = refreshRate * milliseconds  / 1000;
	}
}

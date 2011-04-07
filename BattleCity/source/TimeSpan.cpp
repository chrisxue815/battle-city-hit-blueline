#include "TimeSpan.h"
using namespace BattleCity;


TimeSpan::TimeSpan(int refreshRate)
{
	this->refreshRate = refreshRate;
	ticks = 0;
}


TimeSpan::TimeSpan(int refreshRate, int ticks)
{
	this->refreshRate = refreshRate;
	this->ticks = ticks;
}


TimeSpan::TimeSpan(int refreshRate, int seconds, int milliseconds)
{
	this->refreshRate = refreshRate;
	milliseconds += seconds * 1000;
	this->ticks = milliseconds * refreshRate / 1000;
}

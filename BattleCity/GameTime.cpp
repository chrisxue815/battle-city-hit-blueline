#include "GameTime.h"
using namespace BattleCity;


// game ticks
static volatile int gameTicks = 0;
static void gameTicks_proc(void)
{
	++gameTicks;
}
END_OF_FUNCTION(gameTicks_proc);

// fps
static volatile int frameCount = 0;
static volatile int fps = 0;
static void fps_proc(void)
{
   fps = frameCount;
   frameCount = 0;
}
END_OF_FUNCTION(fps_proc);


GameTime::GameTime(void)
	: interval(60)
{
	LOCK_VARIABLE(gameTicks);
	LOCK_FUNCTION(gameTicks_proc);

	LOCK_VARIABLE(frameCount);
	LOCK_VARIABLE(fps);
	LOCK_FUNCTION(fps_proc);
	install_int(fps_proc, 1000);

	ticks = 0;
	refreshRate = 0;
}


// @static
GameTime & GameTime::getInstance(void)
{
	static GameTime instance;

	return instance;
}


void GameTime::begin(int refreshRate)
{
	if (this->refreshRate != refreshRate)
	{
		this->refreshRate = refreshRate;
		remove_int(gameTicks_proc);
		install_int_ex(gameTicks_proc, BPS_TO_TIMER(refreshRate));
	}

	this->ticks = gameTicks;
}


bool GameTime::next(void)
{
	int retraceCount = gameTicks;

	int intervalTicks = retraceCount - ticks;

	if (intervalTicks > 0)
	{
		ticks = retraceCount;
		++frameCount;
		interval.setTicks(intervalTicks);
		return true;
	}
	else
	{
		// rest for a short while if we're not in CPU-hog mode and too fast
		rest(1);
		return false;
	}
}


int GameTime::getFps(void) const
{
	return fps;
}

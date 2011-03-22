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
	: timeSpan(60)
{
	LOCK_VARIABLE(gameTicks);
	LOCK_FUNCTION(gameTicks_proc);

	LOCK_VARIABLE(frameCount);
	LOCK_VARIABLE(fps);
	LOCK_FUNCTION(fps_proc);
	install_int(fps_proc, 1000);
}


// @static
const GameTime & GameTime::begin(int refreshRate)
{
	static GameTime instance;

	if (instance.refreshRate != refreshRate)
	{
		instance.init(refreshRate);
	}

	instance.ticks = gameTicks;

	return instance;
}


void GameTime::init(int refreshRate)
{
	this->refreshRate = refreshRate;

	remove_int(gameTicks_proc);

	install_int_ex(gameTicks_proc, BPS_TO_TIMER(refreshRate));
}


bool GameTime::next(void)
{
	int retraceCount = gameTicks;

	if (ticks < retraceCount)
	{
		intervalTicks = ticks - retraceCount;
		ticks = retraceCount;
		++frameCount;
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

#pragma once

#include <allegro.h>


namespace BattleCity
{
	class DrawingManager
	{
	protected:
		BITMAP * buffer;

	public:
		DrawingManager(void);
	protected:
		~DrawingManager(void);

	public:
		void clear(void);
		void flush(void);

	public:
		BITMAP * getBuffer(void);
	};


	inline BITMAP * DrawingManager::getBuffer(void)
	{
		return buffer;
	}
}

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
		~DrawingManager(void);

	public:
		void init(void);
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

#pragma once

#include "GameException.h"
#include "ResourceManager.h"
#include "DrawingManager.h"
#include "TimeManager.h"
#include "TimeSpan.h"
#include <allegro.h>


namespace BattleCity
{
	class Level;
	class GameStateMonitor;

	/**
	 * 游戏的主引擎。
	 *
	 * 拥有3个Manager类（游戏核心机制管理）的对象：
	 * <ul>
	 * <li> TimeManager #timeManager 游戏时间管理；</li>
	 * <li> ResourceManager #resource 资源文件管理；</li>
	 * <li> DrawingManager #drawing 绘图管理。</li>
	 * </ul>
	 *
	 * 拥有2个Component类 (能绘制的组件)的对象：
	 * <ul>
	 * <li> Level #level 关卡；</li>
	 * <li> GameStateMonitor #monitor 游戏状态监视器。</li>
	 * </ul>
	 *
	 * 拥有3个主要函数：
	 * <ul>
	 * <li> execute(void) 游戏的主循环；</li>
	 * <li> update(void) 更新数据，由本类的execute(void)调用，会调用每个Component的update；</li>
	 * <li> draw(void) 绘制图像，由本类execute(void)调用，会调用每个Component的draw。</li>
	 * </ul>
	 */
	class Game
	{
	protected:
		char exePath[MAX_PATH_SIZE];
		char dirPath[MAX_PATH_SIZE];

		int width;
		int height;

		int refreshRate;

		bool running;

		TimeManager * timeManager;
		ResourceManager * resource;
		DrawingManager * drawing;

		Level * level;
		GameStateMonitor * monitor;

	public:
		int getRefreshRate(void) const;
		const TimeManager & getTimeManager(void) const;
		const ResourceManager & getResourceManager(void) const;
		DrawingManager & getDrawingManager(void);
		int getMilliseconds(void) const;

	public:
		Game(void);
		~Game(void);

		void execute(void);

		void update(void);
		void draw(void);

	private:
		void initGraphics(void);
		void initManager(void);
	};


	inline int Game::getRefreshRate(void) const {
		return refreshRate;
	}

	inline const TimeManager & Game::getTimeManager(void) const {
		return *timeManager;
	}

	inline const ResourceManager & Game::getResourceManager(void) const {
		return *resource;
	}

	inline DrawingManager & Game::getDrawingManager(void) {
		return *drawing;
	}

	inline int Game::getMilliseconds(void) const {
		return timeManager->getInterval().getMilliseconds();
	}
}

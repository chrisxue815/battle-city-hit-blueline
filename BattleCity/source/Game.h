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
	 * 拥有2个GameComponent类 (能绘制的组件)的对象：
	 * <ul>
	 * <li> Level #level 关卡；</li>
	 * <li> GameStateMonitor #monitor 游戏状态监视器。</li>
	 * </ul>
	 *
	 * 拥有3个主要函数：
	 * <ul>
	 * <li> execute(void) 游戏的主循环；</li>
	 * <li> update(void) 更新数据，由本类的execute(void)调用，会调用每个GameComponent的update；</li>
	 * <li> draw(void) 绘制图像，由本类execute(void)调用，会调用每个GameComponent的draw。</li>
	 * </ul>
	 */
	class Game
	{
	protected:
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
		int getRefreshRate(void) const { return refreshRate; }
		const TimeManager & getTimeManager(void) const { return *timeManager; }
		const ResourceManager & getResourceManager(void) const { return *resource; }
		DrawingManager & getDrawingManager(void) { return *drawing; }
		int getMilliseconds(void) const { return timeManager->getInterval().getMilliseconds(); }

	public:
		Game(void);
		~Game(void);

		void execute(void);

		void update(void);
		void draw(void);

	private:
		void initGraphics(void);
	};
}

#include "GameStateMonitor.h"
using namespace BattleCity;


void GameStateMonitor::init(void)
{
}


void GameStateMonitor::update(void)
{
	notification[0] = '\0';
}


void GameStateMonitor::draw(void)
{
	DrawingManager & drawing = game.getDrawingManager();
	textout_ex(drawing.getBuffer(), font, notification, 10, 10, makecol(255,255,255), makecol(0,0,0));
}


void GameStateMonitor::showFps(const TimeManager & timeManager)
{
	char str[20];
	uszprintf(str, sizeof(str), "FPS: %d  ", timeManager.getFps());
	ustrzncat(notification, sizeof(notification), str, sizeof(notification));
}


void GameStateMonitor::showPlayerPoint(const Player & player)
{
	char str[20];
	Point point = player.getPoint();
	uszprintf(str, sizeof(str), "Player: %d,%d  ", point.getX(), point.getY());
	ustrzncat(notification, sizeof(notification), str, sizeof(notification));
}

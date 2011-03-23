#include "GameStateMonitor.h"
using namespace BattleCity;


GameStateMonitor::GameStateMonitor(void)
{
}


GameStateMonitor::~GameStateMonitor(void)
{
}


void GameStateMonitor::init(const ResourceManager & resource)
{
}


void GameStateMonitor::update(void)
{
	notification[0] = '\0';
}


void GameStateMonitor::draw(DrawingManager & drawing)
{
	textout_ex(drawing.getBuffer(), font, notification, 10, 10, makecol(255,255,255), makecol(0,0,0));
}


void GameStateMonitor::showFps(const GameTime & gameTime)
{
	char str[20];
	uszprintf(str, sizeof(str), "FPS: %d  ", gameTime.getFps());
	ustrzncat(notification, sizeof(notification), str, sizeof(notification));
}


void GameStateMonitor::showPlayerPoint(const Player & player)
{
	char str[20];
	Point point = player.getPoint();
	uszprintf(str, sizeof(str), "Player: %d,%d  ", point.getX(), point.getY());
	ustrzncat(notification, sizeof(notification), str, sizeof(notification));
}

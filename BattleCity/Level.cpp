#include "Level.h"
using namespace BattleCity;


Level::Level(Game & game)
	: Component(game), levelDrawing(Point(16,16), Point(16,16), 1.0f)
{
	player = new Player(*this);
}


Level::~Level(void)
{
	delete player;
}


void Level::init(void)
{
	player->init();
}


void Level::update(void)
{
	player->update();
}


void Level::draw(void)
{
	player->draw();
}

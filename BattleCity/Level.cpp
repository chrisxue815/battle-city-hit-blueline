#include "Level.h"
using namespace BattleCity;


Level::Level(const Game & game)
	: game(game), player(game)
{
}


void Level::init(const ResourceManager & resource)
{
	player.init(resource);
}


void Level::update(void)
{
	player.update();
}


void Level::draw(DrawingManager & drawing)
{
	player.draw(drawing);
}

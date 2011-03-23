#include "Entity.h"
#include "Game.h"
using namespace BattleCity;


Entity::Entity(const Game & game)
	: game(game)
{
}


Entity::Entity(const Game & game, const Point & point)
	: game(game), point(point)
{
}

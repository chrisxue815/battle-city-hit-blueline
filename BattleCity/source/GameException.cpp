#include "GameException.h"
using namespace BattleCity;

GameException::GameException(void)
	: exception()
{
}


GameException::~GameException(void)
{
}


GameException::GameException(ExceptionType type)
	: exception()
{
	this->type = type;
}


GameException::GameException(const char *const what, ExceptionType type)
	: exception(what)
{
	this->type = type;
}

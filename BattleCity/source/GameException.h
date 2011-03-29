#pragma once

#include "ExceptionType.h"
#include <exception>
using namespace std;


namespace BattleCity
{
	class GameException : public exception
	{
	private:
		ExceptionType type;

	public:
		GameException(void);
		~GameException(void);

		GameException(ExceptionType type);
		GameException(const char *const what, ExceptionType type);

		ExceptionType getType(void) const;
	};


	inline ExceptionType GameException::getType(void) const
	{
		return type;
	}
}

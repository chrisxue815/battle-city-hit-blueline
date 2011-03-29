#include "Math.h"
using namespace BattleCity;


int Math::ceilDiv(int dividend, int divisor)
{
	int quotient = dividend / divisor;

	if (dividend % divisor != 0)
	{
		if (divisor < 0)
			dividend = -dividend;

		if (dividend > 0)
			++quotient;
	}

	return quotient;
}

int Math::floorDiv(int dividend, int divisor)
{
	int quotient = dividend / divisor;

	if (dividend % divisor != 0)
	{
		if (divisor < 0)
			dividend = -dividend;

		if (dividend < 0)
			--quotient;
	}

	return quotient;
}

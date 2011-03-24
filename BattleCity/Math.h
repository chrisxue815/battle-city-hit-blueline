#pragma once


namespace BattleCity
{
	class Math
	{
	protected:
		Math(void);

	public:
		static int ceilDiv(int dividend, int divisor);
		static int floorDiv(int dividend, int divisor);
	};

	inline Math::Math(void)
	{
	}
}

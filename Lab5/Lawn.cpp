#include "Lawn.h"

namespace lab5
{
	Lawn::Lawn()
	{
	}

	Lawn::~Lawn()
	{
	}

	unsigned int Lawn::GetGrassPrice(eGrassType grassType) const
	{
		double tem = GetArea() * grassType;
		tem /= 100;
		if ((tem - (int)tem > 0))
		{
			return (int)++tem;
		}
		return tem;

	}

	unsigned int Lawn::GetMinimumSodRollsCount() const
	{
		unsigned int answer;
		double tem = (GetArea() * 10) % 3;
		if (tem == 0)
		{
			tem = (GetArea() * 10) / 3;
			answer = tem;
		}
		else
		{
			tem = (GetArea() * 10) / 3;
			answer = tem;
			answer++;
		}
		return answer;
	}
}
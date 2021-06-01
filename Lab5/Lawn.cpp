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
		if ((tem - static_cast<int>(tem) > 0))
		{
			return  static_cast<int>(++tem);
		}
		return  static_cast<int>(tem);

	}

	unsigned int Lawn::GetMinimumSodRollsCount() const
	{
		unsigned int answer;
		double tem = (GetArea() * 10) % 3;
		if (tem == 0)
		{
			tem = (GetArea() * 10) / 3;
			answer = static_cast<int>(tem);
		}
		else
		{
			tem = (GetArea() * 10) / 3;
			answer = static_cast<int>(tem);
			answer++;
		}
		return answer;
	}
}
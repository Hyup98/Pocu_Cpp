#include "Boatplane.h"

namespace assignment2
{
	Boatplane::Boatplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
	}

	Boatplane::~Boatplane()
	{
	}

	unsigned int Boatplane::GetSailSpeed() const
	{
		unsigned int tem = 800 - 1.7 * (GetTotalWeight());
		if (tem > 20)
		{
			return tem;
		}
		else
		{
			return 20;
		}
	}
	void Boatplane::SetMoveCount()
	{
		mMoveCount = 0;
	}


	void Boatplane::Move()
	{
		if (mMoveCount == 0)
		{
			mMoveCount++;
		}
		else
		{
			if (mRestCount < 3)
			{
				mRestCount++;
			}
			else
			{
				mRestCount = 0;
				mMoveCount++;
			}
		}
	}

	unsigned int Boatplane::GetTraveledDistance()
	{
		unsigned int tem = GetMaxSpeed() * mMoveCount;
		return tem;
	}

	unsigned int Boatplane::GetMaxSpeed() const
	{
		unsigned int tem_1 = GetSailSpeed();
		unsigned int tem_2 = GetFlySpeed();
		if (tem_1 > tem_2)
		{
			return tem_1;
		}

		else
		{
			return tem_2;
		}
	}

	unsigned int Boatplane::GetFlySpeed() const
	{
		unsigned int temNum = 500 - GetTotalWeight();
		float temNumber = temNum / 300.0;
		float tem = pow(2.71, temNumber);
		unsigned int answer = tem * 150;
		return answer;
	}
}
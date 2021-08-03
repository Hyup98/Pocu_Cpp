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
		/*
		double tem = 800 - 1.7 * (GetTotalWeight());
		if (tem > 20)
		{
			return static_cast<unsigned int>(round(tem));
		}
		else
		{
			return 20;
		}
		*/
		return std::max(static_cast<int>(round(800.0 - 1.7 * GetTotalWeight())), 20);
	}
	void Boatplane::SetMoveCount()
	{
		mMoveCount = 0;
	}


	void Boatplane::Move()
	{
		if (mMoveCount == 0)
		{
		}
		else
			mMoveCount++;
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
		unsigned int tem1 = GetSailSpeed();
		unsigned int tem2 = GetFlySpeed();
		if (tem1 > tem2)
		{
			return tem1;
		}

		else
		{
			return tem2;
		}
	}

	unsigned int Boatplane::GetFlySpeed() const
	{
		double temNum = 500 - GetTotalWeight();
		if (temNum <= 0)
		{
			return 0;
		}
		double temNumber = temNum / 300.0;
		double tem = pow(2.71, temNumber);
		double answer = tem * 150;
		return static_cast<unsigned int>(round(answer));
	}
}
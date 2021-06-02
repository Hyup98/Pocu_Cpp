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
		double tem = 800 - 1.7 * (GetTotalWeight());
		if (tem > 20)
		{
			return static_cast<unsigned int>(tem);
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
		double temNum = 500 - GetTotalWeight();
		double temNumber = temNum / 300.0;
		double tem = pow(2.71, temNumber);
		double answer = tem * 150;
		return static_cast<unsigned int>(answer);
	}
}
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
		unsigned int tem = pow(2.71, (500 - GetTotalWeight() / 300));
		tem *= 150;
		return tem;
	}
	/*

	Boatplane& Boatplane::operator=(Boatplane& other)
	{
		if (&other == this)
		{
			return *this;
		}
		for (size_t i = 0; i < GetPassengersCount(); i++)
		{
			delete mPassenger[i];
		}
	}
	*/
}
#include "Boat.h"

namespace assignment2
{
	Boat::Boat(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)

	{
	}

	Boat::~Boat()
	{
	}

	void Boat::Move()
	{
		if (mMoveCount == 0)
		{
			mMoveCount++;
		}

		else
		{
			if (mRestCount == 1)
			{
				mMoveCount++;
				mRestCount = 0;
			}
			else if (mMoveCount % 2 != 0)
			{
				mMoveCount++;
			}
			else
			{
				mRestCount++;
			}
		}
	}
	void Boat::SetMoveCount()
	{
		mMoveCount = 0;
	}

	unsigned int Boat::GetTraveledDistance()
	{
		unsigned int tem = GetMaxSpeed() * mMoveCount;
		return tem;
	}

	unsigned int Boat::GetSailSpeed() const
	{
		unsigned int tem = 800 - 10 * (GetTotalWeight());
		if (tem > 20)
		{
			return tem;
		}
		else
		{
			return 20;
		}
	}

	unsigned int Boat::GetMaxSpeed() const
	{
		return GetSailSpeed();
	}

	Boatplane Boat::operator+(Airplane& plane)
	{
		Boatplane bp(GetMaxPassengersCount() + plane.GetMaxPassengersCount());

		unsigned int i = 0;
		for (i; i < plane.GetPassengersCount(); i++)
		{
			bp.AddPassenger(plane.GetPassenger(i));

		}
		plane.QuitAll();

		unsigned int tem = 0;
		i++;
		unsigned int temI = i + GetPassengersCount();
		for (i; i < temI; i++)
		{
			bp.AddPassenger(GetPassenger(tem));
			tem++;
		}
		QuitAll();


		return bp;
	}
}
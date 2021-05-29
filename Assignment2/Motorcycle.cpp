#include "Motorcycle.h"
#include "math.h"

namespace assignment2
{
	Motorcycle::Motorcycle()
		: Vehicle(2)

	{
	}

	Motorcycle::~Motorcycle()
	{
	}

	unsigned int Motorcycle::GetDriveSpeed() const
	{
		unsigned int tem = (2 * GetTotalWeight()) + 400 - pow(GetTotalWeight(), 3);
		if (tem > 0)
		{
			return tem;
		}
		else
		{
			return 0;
		}
	}

	unsigned int Motorcycle::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}
	void Motorcycle::SetMoveCount()
	{
		mMoveCount = 0;
	}


	void Motorcycle::Move()
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
			else if (mMoveCount % 5 != 0)
			{
				mMoveCount++;
			}
			else
			{
				mRestCount++;
			}
		}
		
	}

	unsigned int Motorcycle::GetTraveledDistance()
	{
		unsigned int tem = GetMaxSpeed() * mMoveCount;
		return tem;
	}

}
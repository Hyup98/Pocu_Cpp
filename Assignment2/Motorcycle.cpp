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
		double tem = pow(GetTotalWeight(), 3);
		unsigned int temNum = 2 * GetTotalWeight() + 400;
		temNum -= static_cast<unsigned int>(tem);
		if (temNum > 0)
		{
			return static_cast<unsigned int>(temNum);
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
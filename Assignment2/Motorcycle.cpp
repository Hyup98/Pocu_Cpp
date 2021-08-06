#include "Motorcycle.h"
#include "math.h"
#include<cassert>

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
		int speed = static_cast<int>(round(-(pow((GetTotalWeight() / 15.0), 3)) + GetTotalWeight() * 2.0 + 400.0));
		return speed > 0 ? speed : 0;
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
		switch (mMoveCount)
		{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
			mMovedLength += GetMaxSpeed();
			mMoveCount++;
			break;
		case 5:
			mMoveCount = 0;
			break;
		default:
			assert(false);
			break;
		}
		
	}

	unsigned int Motorcycle::GetTraveledDistance()
	{
		unsigned int tem = GetMaxSpeed() * mMoveCount;
		return tem;
	}

}
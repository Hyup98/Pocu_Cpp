#include "UBoat.h"

namespace assignment2
{
	UBoat::UBoat()
		: Vehicle(50)

	{
	}

	UBoat::~UBoat()
	{
	}

	unsigned int UBoat::GetDiveSpeed() const
	{
		float tem = 550 - (GetTotalWeight() / 10);
		if (tem > 200)
		{
			return tem;
		}
		else
		{
			return 200;
		}
	}

	void UBoat::SetMoveCount()
	{
		mMoveCount = 0;
	}

	unsigned int UBoat::GetSailSpeed() const
	{
		float tem = (GetTotalWeight() + 150);
		tem /= 150;
		tem = log(tem);
		tem *= 500;
		tem += 30;
		return tem;

	}
	void UBoat::Move()
	{
		if (mMoveCount == 0)
		{
			mMoveCount++;
		}
		else
		{
			if (mMoveCount % 2 != 0)
			{
				mMoveCount++;
			}
			else if (mRestCount < 4)
			{
				mRestCount++;
			}
			else if (mRestCount == 4)
			{
				mRestCount = 0;
				mMoveCount++;
			}
		}
	}

	unsigned int UBoat::GetTraveledDistance()
	{
		unsigned int tem = GetMaxSpeed() * mMoveCount;
		return tem;
	}

	unsigned UBoat::GetMaxSpeed() const
	{
		unsigned int tem_1 = GetDiveSpeed();
		unsigned int tem_2 = GetSailSpeed();
		if (tem_1 > tem_2)
		{
			return tem_1;
		}
		else
		{
			return tem_2;
		}
	}
}
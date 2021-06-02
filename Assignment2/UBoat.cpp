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
		double temNum = GetTotalWeight();
		double tem = temNum / 10.0;
		temNum = 550 - tem;
		if (temNum > 200)
		{
			unsigned int answer = static_cast<unsigned int>(round(temNum));
			return answer;
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
		unsigned int temNum = GetTotalWeight() + 150;
		double tem = temNum / 150;
		tem = log(tem);
		tem *= 500;
		tem += 30;
		unsigned int answer = static_cast<unsigned int>(round(tem));
		return answer;
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
		unsigned int tem1 = GetDiveSpeed();
		unsigned int tem2 = GetSailSpeed();
		if (tem1 > tem2)
		{
			return tem1;
		}
		else
		{
			return tem2;
		}
	}
}
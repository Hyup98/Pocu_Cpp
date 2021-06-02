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
		double tem = temNum / 10;
		temNum = 550 - tem;
		if (temNum > 200)
		{
			unsigned int answer = static_cast<unsigned int>(temNum);
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
		unsigned int answer = static_cast<unsigned int>(tem);
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
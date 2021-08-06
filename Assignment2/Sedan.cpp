#include "Sedan.h"
#include "Trailer.h"
#include<cassert>

namespace assignment2
{
	Sedan::Sedan()
		: Vehicle(4)
		, mBIsConect(false)
	{
		mTrailer = nullptr;
	}

	Sedan::~Sedan()
	{
	}

	unsigned int Sedan::GetDriveSpeed() const
	{
		unsigned int totalWeight = 0;
		if (mBIsConect)
		{
			totalWeight += GetTotalWeight();
			totalWeight += mTrailer->GetWeight();

			if (totalWeight <= 80)
			{
				return 480;
			}
			else if (totalWeight <= 160)
			{
				return 458;
			}
			else if (totalWeight <= 260)
			{
				return 400;
			}
			else if (totalWeight <= 350)
			{
				return 380;
			}
			else
			{
				return 300;
			}

		}
		else
		{
			totalWeight += GetTotalWeight();
			if (totalWeight <= 80)
			{
				return 480;
			}
			if (totalWeight <= 80)
			{
				return 480;
			}
			else if (totalWeight <= 160)
			{
				return 458;
			}
			else if (totalWeight <= 260)
			{
				return 400;
			}
			else if (totalWeight <= 350)
			{
				return 380;
			}
			else
			{
				return 300;
			}

		}
	}

	bool Sedan::AddTrailer(const Trailer* trailer)
	{
		if (mBIsConect)
		{
			return false;
		}
		if (!trailer->IsConect())
		{
			trailer->IsConect();
			mTrailer = trailer;
			mBIsConect = true;
			return true;
		}
		else
		{
			return false;
		}
	}
	void Sedan::SetMoveCount()
	{
		mMoveCount = 0;
	}

	void Sedan::Move()
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
			mTrailer == nullptr ? mMoveCount = 0 : mMoveCount = 6;
			break;
		case 6:
			mMoveCount = 0;
			break;
		default:
			assert(false);
			break;
		}
	}

	unsigned int Sedan::GetTraveledDistance()
	{
		unsigned int tem = GetMaxSpeed() * mMoveCount;
		return tem;
	}

	bool Sedan::RemoveTrailer()
	{
		if (mBIsConect)
		{
			delete mTrailer;
			mBIsConect = false;
			return true;
		}
		else
		{
			return false;
		}
	}
	unsigned int Sedan::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}
}
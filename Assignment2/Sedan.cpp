#include "Sedan.h"
#include "Trailer.h"

namespace assignment2
{
	Sedan::Sedan()
		:Vehicle(4)
		, bIsConect(false)
	{
		mTrailer = nullptr;
	}

	Sedan::~Sedan()
	{
	}

	unsigned int Sedan::GetDriveSpeed() const
	{
		unsigned int totalWeight = 0;
		if (bIsConect)
		{
			totalWeight += GetTotalWeight();
			totalWeight += mTrailer->GetWeight();
			if (totalWeight <= 80)
			{
				return 480;
			}
			else 
			{
				if (totalWeight > 160)
				{
					if (totalWeight > 260)
					{
						if (totalWeight > 350)
						{
							return 400;
						}
						return 400;
					}
					return 400;
				}
				return 458;
			}
		}
		else
		{
			totalWeight += GetTotalWeight();
			if (totalWeight <= 80)
			{
				return 480;
			}
			else
			{
				if (totalWeight > 160)
				{
					if (totalWeight > 260)
					{
						if (totalWeight > 350)
						{
							return 400;
						}
						return 400;
					}
					return 400;
				}
				return 458;
			}

		}
	}

	bool Sedan::AddTrailer(const Trailer* trailer)
	{
		if (bIsConect)
		{
			return false;
		}
		if (!trailer->IsConect())
		{
			trailer->IsConect();
			mTrailer = trailer;
			bIsConect = true;
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
		if (bIsConect)
		{
			if (mMoveCount == 0)
			{
				mMoveCount++;
			}

			else
			{
				if (mRestCount == 2)
				{
					mRestCount = 0;
					mMoveCount++;
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
		else
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
	}

	unsigned int Sedan::GetTraveledDistance()
	{
		unsigned int tem = GetMaxSpeed() * mMoveCount;
		return tem;
	}

	bool Sedan::RemoveTrailer()
	{
		if (bIsConect)
		{
			delete mTrailer;
			bIsConect = false;
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
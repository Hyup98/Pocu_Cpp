#include "Vehicle.h"

namespace assignment2
{
	Vehicle::Vehicle(unsigned int maxPassengersCount)
		: mMaxPassengersCount(maxPassengersCount)
		, onBoardNum(0)
		, mRestCount(0)
		, mMoveCount(0)
	{
		mPassenger = new const Person * [mMaxPassengersCount];
	}
	void Vehicle::SetMoveCount()
	{
		mMoveCount = 0;
		mRestCount = 0;
	}

	void Vehicle::Move()
	{

	}

	unsigned int Vehicle::GetMaxSpeed() const
	{
		return 0;
	}

	unsigned int Vehicle::GetTraveledDistance()
	{
		return 0;
	}

	Vehicle::~Vehicle()
	{
		for (size_t i = 0; i < onBoardNum; i++)
		{
			delete mPassenger[i];
		}

		delete[] mPassenger;
	}

	Vehicle::Vehicle(Vehicle& rhs)
		: mMaxPassengersCount(rhs.mMaxPassengersCount)
		, onBoardNum(rhs.onBoardNum)
		, mMoveCount(0)
		, mRestCount(0)
	{
		mPassenger = new const Person * [mMaxPassengersCount];
		for (size_t i = 0; i < rhs.onBoardNum; i++)
		{
			mPassenger[i] = new const Person(rhs.mPassenger[i]->GetName(), rhs.mPassenger[i]->GetWeight());
		}
	}

	bool Vehicle::AddPassenger(const Person* person)
	{
		if (person != nullptr)
		{
			for (size_t i = 0; i < onBoardNum; i++)
			{
				if (mPassenger[i] == person)
				{
					return false;
				}
			}
			if (onBoardNum < mMaxPassengersCount)
			{
				mPassenger[onBoardNum] = person;
				onBoardNum++;
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}

	bool Vehicle::RemovePassenger(unsigned int i)
	{
		if (onBoardNum == 0)
		{
			return false;
		}

		if (i < onBoardNum && i >= 0)
		{
			for (size_t j = i; j < onBoardNum - 1; j++)
			{
				mPassenger[j] = mPassenger[j + 1];
			}
			mPassenger[onBoardNum - 1] = nullptr;
			onBoardNum--;
			return true;
		}
		else
		{
			return false;
		}
	}

	unsigned int Vehicle::GetTotalWeight() const
	{
		unsigned int tem = 0;
		for (size_t i = 0; i < GetPassengersCount(); i++)
		{
			tem += mPassenger[i]->GetWeight();
		}
		return tem;
	}

	unsigned int Vehicle::GetPassengersCount() const
	{
		return onBoardNum;
	}

	unsigned int Vehicle::GetMaxPassengersCount() const
	{
		return mMaxPassengersCount;
	}

	const Person* Vehicle::GetPassenger(unsigned int i) const
	{
		return mPassenger[i];
	}

	void Vehicle::QuitAll()
	{
		for (size_t i = 0; i < onBoardNum; i++)
		{
			mPassenger[i] = nullptr;
		}
		onBoardNum = 0;
	}

	void Vehicle::SetonBoardNum(unsigned int i)
	{
		onBoardNum = i;
	}
}
#include "Vehicle.h"

namespace assignment2
{
	Vehicle::Vehicle(unsigned int maxPassengersCount)
		: mMaxPassengersCount(maxPassengersCount)
		, onBoardNum(0)
	{
		mPassenger = new const Person * [mMaxPassengersCount];
	}

	Vehicle::~Vehicle()
	{
		for (size_t i = 0; i < onBoardNum; i++)
		{
			delete mPassenger[i];
		}

		delete[] mPassenger;
	}

	bool Vehicle::AddPassenger(const Person* person)
	{
		if (person != nullptr)
		{
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

		if (i < onBoardNum)
		{
			delete mPassenger[i];
			for (size_t j = i; j < onBoardNum - 1; j++)
			{
				mPassenger[j] = mPassenger[j + 1];
			}
			mPassenger[onBoardNum - 1] = nullptr;
			onBoardNum--;
		}
		else
		{
			return false;
		}
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
}
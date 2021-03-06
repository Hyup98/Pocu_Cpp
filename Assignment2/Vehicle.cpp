#include "Vehicle.h"
#include "Person.h"

namespace assignment2
{
	Vehicle::Vehicle(unsigned int maxPassengersCount)
		: mMaxPassengersCount(maxPassengersCount)
		, mOnBoardNum(0)
		, mMovedLength(0)
		, mMoveCount(0)
	{
		mPassenger = new const Person * [mMaxPassengersCount];
		for (size_t i = 0; i < mMaxPassengersCount; i++)
		{
			mPassenger[i] = nullptr;
		}
	}
	void Vehicle::SetMoveCount()
	{
		mMoveCount = 0;
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
		for (size_t i = 0; i < mOnBoardNum; i++)
		{
			delete mPassenger[i];
		}

		delete[] mPassenger;
	}

	Vehicle::Vehicle(Vehicle& rhs)
		: mMaxPassengersCount(rhs.mMaxPassengersCount)
		, mOnBoardNum(rhs.mOnBoardNum)
		, mMoveCount(0)
		, mMovedLength(0)
	{
		mPassenger = new const Person * [rhs.mMaxPassengersCount];
		for (size_t i = 0; i < rhs.mOnBoardNum; i++)
		{
			mPassenger[i] = new const Person(rhs.mPassenger[i]->GetName(), rhs.mPassenger[i]->GetWeight());
		}
	}

	Vehicle& Vehicle::operator=(const Vehicle& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}

		for (size_t i = 0; i < mMaxPassengersCount; i++)
		{
			delete mPassenger[i];
			mPassenger[i] = nullptr;
		}
		
		mMaxPassengersCount = rhs.mMaxPassengersCount;
		mOnBoardNum = rhs.mOnBoardNum;
		mMoveCount = rhs.mMoveCount;
		mMovedLength = rhs.mMovedLength;
		mPassenger = new const Person * [rhs.mMaxPassengersCount];
		for (size_t i = 0; i < rhs.mOnBoardNum; i++)
		{
			mPassenger[i] = new const Person(rhs.mPassenger[i]->GetName(), rhs.mPassenger[i]->GetWeight());
		}

	}


	bool Vehicle::AddPassenger(const Person* person)
	{
		if (person != nullptr)
		{
			if (person->GetBoardVehicle() == nullptr)
			{
				for (size_t i = 0; i < mOnBoardNum; i++)
				{
					if (mPassenger[i] == person)
					{
						return false;
					}
				}
				if (mOnBoardNum < mMaxPassengersCount)
				{
					mPassenger[mOnBoardNum] = person;
					mOnBoardNum++;
					return true;
				}
				else
				{
					return false;
				}
			}
						
			else
			{
				person->GetBoardVehicle()->OutPassenger(person);
				for (size_t i = 0; i < mOnBoardNum; i++)
				{
					if (mPassenger[i] == person)
					{
						return false;
					}
				}
				if (mOnBoardNum < mMaxPassengersCount)
				{
					mPassenger[mOnBoardNum] = person;
					mOnBoardNum++;
					return true;
				}
				else
				{
					return false;
				}
			}
			
		}
		else
		{
			return false;
		}
	}

	void Vehicle::OutPassenger(const Person* person)
	{
		for (size_t i = 0; i < mOnBoardNum; i++)
		{
			if (mPassenger[i] == person)
			{
				RemovePassenger(i);
				return;
			}
		}
		
	}

	bool Vehicle::RemovePassenger(unsigned int i)
	{
		if (mOnBoardNum == 0)
		{
			return false;
		}

		if (i < mOnBoardNum && i >= 0)
		{
			for (size_t j = i; j < mOnBoardNum - 1; j++)
			{
				mPassenger[j] = mPassenger[j + 1];
			}
			mPassenger[mOnBoardNum - 1] = nullptr;
			mOnBoardNum--;
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
		return mOnBoardNum;
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
		for (size_t i = 0; i < mOnBoardNum; i++)
		{
			mPassenger[i] = nullptr;
		}
		mOnBoardNum = 0;
		
	}

	void Vehicle::SetonBoardNum(unsigned int i)
	{
		mOnBoardNum = i;
	}

	unsigned int Vehicle::GetMovedLength() const
	{
		return mMovedLength;
	}
}
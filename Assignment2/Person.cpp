#include "Person.h"
#include "Vehicle.h"

namespace assignment2
{
	Person::Person(const char* name, unsigned int weight)
		: mWeight(weight)
		, mOnBoardVechicle(nullptr)
	{
		mName = name;
		//mOnBoardVechicle = nullptr;
	}

	Person::Person(std::string name, unsigned int weight)
		: mWeight(weight)
	{
		mName = name;
	}


	Person::~Person()
	{
	}

	Vehicle* Person::GetBoardVehicle() const
	{
		return mOnBoardVechicle;
	}

	const std::string& Person::GetName() const
	{
		return mName;
	}

	unsigned int Person::GetWeight() const
	{
		return mWeight;
	}

	void Person::SetBoardVehicle(Vehicle* i) 
	{
		if (i != nullptr)
		{
			mOnBoardVechicle = i;
		}
	}

}
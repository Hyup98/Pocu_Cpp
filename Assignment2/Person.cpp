#include "Person.h"

namespace assignment2
{
	Person::Person(const char* name, unsigned int weight)
		: mWeight(weight)
	{
		unsigned int count = 0;
		while (true)
		{
			if (name[count] == '\0')
			{
				break;
			}
			count++;
		}
		mName = new char[count + 1];
		for (size_t i = 0; i < count; i++)
		{
			mName[i] = name[i];
		}
		mName[count] = '\0';
	}

	Person::~Person()
	{
	}

	const std::string& Person::GetName() const
	{
		return mName;
	}

	const char* Person::GetNameP() const
	{
		return mName;
	}

	unsigned int Person::GetWeight() const
	{
		return mWeight;
	}
}
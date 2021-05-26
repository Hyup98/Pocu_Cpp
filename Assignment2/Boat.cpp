#include "Boat.h"

namespace assignment2
{
	Boat::Boat(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
	}

	Boat::~Boat()
	{
	}

	unsigned int Boat::GetDiveSpeed() const
	{
		return 0;
	}

	unsigned int Boat::GetMaxSpeed() const
	{
		return 0;
	}

	Boatplane Boat::operator+(Airplane& plane)
	{
		Boatplane bp(GetMaxPassengersCount() + plane.GetMaxPassengersCount());
		unsigned int i = 0;
		for (i; i < GetPassengersCount(); i++)
		{
			bp.AddPassenger(GetPassenger(i));

		}
		QuitAll();
		delete this;
		unsigned int tem = 0;

		for (i; i < bp.GetMaxPassengersCount(); i++)
		{
			bp.AddPassenger(plane.GetPassenger(tem));
			tem++;
		}
		plane.QuitAll();
		delete& plane;

		return bp;
	
	}
}
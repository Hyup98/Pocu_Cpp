#include "Boat.h"

namespace assignment2
{
	Boat::Boat(unsigned int maxPassengersCount)
	{
	}

	Boat::~Boat()
	{
	}

	Boatplane Boat::operator+(Airplane& plane)
	{
		Boatplane bp(5);
		return bp;
	}
}
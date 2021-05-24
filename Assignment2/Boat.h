#pragma once

#include "Boatplane.h"

namespace assignment2
{
	class Airplane;

	class Boat
	{
	public:
		Boat(unsigned int maxPassengersCount);
		~Boat();

		Boatplane operator+(Airplane& plane);
	};
}
#pragma once

#include "Boatplane.h"

namespace assignment2
{
	class Boat;

	class Airplane
	{
	public:
		Airplane(unsigned int maxPassengersCount);
		~Airplane();

		Boatplane operator+(Boat& boat);
	};
}
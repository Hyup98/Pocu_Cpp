#pragma once

#include "Boatplane.h"
#include "Vehicle.h"
#include "IDivable.h"
#include "Airplane.h"

namespace assignment2
{
	class Airplane;

	class Boat : public Vehicle, public IDivable
	{
	public:
		Boat(unsigned int maxPassengersCount);
		~Boat();
		unsigned int GetMaxSpeed() const;
		unsigned int GetDiveSpeed() const;

		Boatplane operator+(Airplane& plane);
	};
}
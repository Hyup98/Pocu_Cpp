#pragma once

#include "IFlyable.h"
#include "IDrivable.h"
#include "IDivable.h"
#include "Vehicle.h"

namespace assignment2
{
	class Boatplane : public Vehicle, public IFlyable, public IDrivable, public IDivable
	{
	public:
		Boatplane(unsigned int maxPassengersCount);
		~Boatplane();
		unsigned int GetFlySpeed() const;
		unsigned int GetMaxSpeed() const;
		unsigned int GetDriveSpeed() const;
		unsigned int GetDiveSpeed() const;
	};
}
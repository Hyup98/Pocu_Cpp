#pragma once

#include "Boatplane.h"
#include "IFlyable.h"
#include "IDrivable.h"
#include "Vehicle.h"
#include "Boat.h"

namespace assignment2
{
	class Boat;

	class Airplane : public Vehicle, public IFlyable, public IDrivable
	{
		friend Boatplane;
	public:
		Airplane(unsigned int maxPassengersCount);
		~Airplane();
		unsigned int GetFlySpeed() const;
	    unsigned int GetMaxSpeed() const;
		unsigned int GetDriveSpeed() const;
		void Move();
		unsigned int GetTraveledDistance();
		Boatplane operator+(Boat& boat);
	};
}
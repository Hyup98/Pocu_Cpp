#pragma once

#include "IFlyable.h"
#include "IDrivable.h"
#include "ISailable.h"
#include "Vehicle.h"

namespace assignment2
{
	class Boatplane : public Vehicle, public IFlyable, public ISailable
	{
	public:
		Boatplane(unsigned int maxPassengersCount);
		~Boatplane();
		unsigned int GetFlySpeed() const;
		unsigned int GetMaxSpeed() const;
		unsigned int GetSailSpeed() const;
		void Move();
		unsigned int GetTraveledDistance();
		Boatplane& operator=(Boatplane& other);
		void SetMoveCount();
	};
}
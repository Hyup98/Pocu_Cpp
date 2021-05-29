#pragma once

#include "Boatplane.h"
#include "Vehicle.h"
#include "ISailable.h"
#include "Airplane.h"

namespace assignment2
{
	class Airplane;

	class Boat : public Vehicle, public ISailable
	{
	public:
		Boat(unsigned int maxPassengersCount);
		~Boat();
		unsigned int GetMaxSpeed() const;
		unsigned int GetSailSpeed() const;
		void Move();
		unsigned int GetTraveledDistance();
		Boatplane operator+(Airplane& plane);
		void SetMoveCount();

	};
}
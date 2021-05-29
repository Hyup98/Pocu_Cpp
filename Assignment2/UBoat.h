#pragma once

#include"IDivable.h"
#include"ISailable.h"
#include"Vehicle.h"
#include<cmath>

namespace assignment2
{
	class UBoat : public ISailable, public IDivable, public Vehicle
	{
	public:
		UBoat();
		~UBoat();
		unsigned int GetDiveSpeed() const;
		unsigned int GetSailSpeed() const;
		unsigned int GetMaxSpeed() const;
		void Move();
		unsigned int GetTraveledDistance();
		void SetMoveCount();

	};
}
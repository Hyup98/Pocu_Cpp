#pragma once
#include "IDrivable.h"
#include "Vehicle.h"

namespace assignment2
{
	class Motorcycle : public IDrivable, public Vehicle
	{
	public:
		Motorcycle();
		~Motorcycle(); 
		unsigned int GetDriveSpeed() const;
		unsigned int GetMaxSpeed() const;
		void Move();
		unsigned int GetTraveledDistance();
		void SetMoveCount();

	};
}
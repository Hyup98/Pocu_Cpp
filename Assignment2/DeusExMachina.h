#pragma once

#include "Vehicle.h"
#include "Person.h"
#include "Vehicle.h"
#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"
#include "Motorcycle.h"
#include "Sedan.h"
#include "Trailer.h"
#include "UBoat.h"
#include "DeusExMachina.h"
#include "Person.h"

namespace assignment2
{
	class DeusExMachina
	{
	public:
		static DeusExMachina* GetInstance();
		void Travel() const;
		bool AddVehicle(Vehicle* vehicle);
		bool RemoveVehicle(unsigned int i);
		const Vehicle* GetFurthestTravelled() const;
		unsigned int GetIndex(const Vehicle* other);

	private:
		DeusExMachina();
		~DeusExMachina();
		static DeusExMachina* Instance;
		Vehicle** mVehicle;
		unsigned int mVehicleCount;
	};
}
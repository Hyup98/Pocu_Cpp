#include "DeusExMachina.h"

namespace assignment2
{
	DeusExMachina* DeusExMachina::GetInstance()
	{
		return NULL;
	}

	void DeusExMachina::Travel() const
	{
	}

	bool DeusExMachina::AddVehicle(Vehicle* vehicle)
	{
		return false;
	}

	bool DeusExMachina::RemoveVehicle(unsigned int i)
	{
		return false;
	}

	const Vehicle* DeusExMachina::GetFurthestTravelled() const
	{
		return NULL;
	}
}
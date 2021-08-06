#include "DeusExMachina.h"
#include "Vehicle.h"
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
#include <cassert>
#include <iostream>

namespace assignment2
{
	DeusExMachina* DeusExMachina::mInstance = nullptr;

	DeusExMachina::DeusExMachina()
	{
		mVehicle = new Vehicle * [MAX_VEHICLES_COUNT];
		mVehicleCount = 0;
	}
	DeusExMachina::~DeusExMachina()
	{
		for (unsigned int i = 0; i < mVehicleCount; i++)
		{
			delete mVehicle[i];
		}
	}

	DeusExMachina* DeusExMachina::GetInstance()
	{
		if (mInstance == NULL)
		{
			mInstance = new DeusExMachina();
		}
		return mInstance;

	}

	void DeusExMachina::Travel() const
	{
		for (size_t i = 0; i < mVehicleCount; i++)
		{
			mVehicle[i]->Move();
		}
	}

	bool DeusExMachina::AddVehicle(Vehicle* vehicle)
	{
		assert(vehicle != nullptr);
		if (mVehicleCount < 10)
		{
			mVehicle[mVehicleCount] = vehicle;
			mVehicle[mVehicleCount]->SetMoveCount();
			mVehicleCount++;
			return true;
		}
			
		else
		{
			return false;
		}
	}

	bool DeusExMachina::RemoveVehicle(unsigned int i)
	{
		if (i < mVehicleCount && mVehicle[i] != nullptr)
		{
			delete mVehicle[i];
			for (size_t j = i; j < mVehicleCount - 1; j++)
			{
				mVehicle[j] = mVehicle[j + 1];
			}
			mVehicleCount--;
			return true;
		}
		else
		{
			return false;
		}
	}

	const Vehicle* DeusExMachina::GetFurthestTravelled() const
	{
		unsigned int max = 0;
		Vehicle* mostMovedVehicle = nullptr;
		for (unsigned int i = 0; i < mVehicleCount; i++)
		{
			if (max < mVehicle[i]->GetMovedLength())
			{
				max = mVehicle[i]->GetMovedLength();
				mostMovedVehicle = mVehicle[i];
			}
		}
		if (max == 0 && mVehicleCount > 0)
		{
			mostMovedVehicle = mVehicle[0];
		}
		return mostMovedVehicle;
	}
}


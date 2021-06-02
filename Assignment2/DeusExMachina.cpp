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

namespace assignment2
{
	DeusExMachina* DeusExMachina::Instance = nullptr;

	DeusExMachina::DeusExMachina()
	{
		mVehicle = new Vehicle * [10];
		mVehicleCount = 0;
	}
	DeusExMachina::~DeusExMachina()
	{
	}

	DeusExMachina* DeusExMachina::GetInstance()
	{
		if (Instance == NULL)
		{
			Instance = new DeusExMachina();
			return Instance;
		}
		else
		{
			return Instance;
		}
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
		if (i < mVehicleCount)
		{
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
		if (mVehicleCount == 0)
		{
			return NULL;
		}

		unsigned int tem;
		unsigned int index;
		tem = mVehicle[0]->GetTraveledDistance();
		index = 0;
		for (size_t i = 0; i < mVehicleCount; i++)
		{
			if (mVehicle[i]->GetTraveledDistance() > tem)
			{
				index = i;
				tem = mVehicle[i]->GetTraveledDistance();
			}
		}
		return mVehicle[index];
	}

	unsigned int DeusExMachina::GetIndex(const Vehicle* other)
	{
		for (size_t i = 0; i < mVehicleCount; i++)
		{
			if (mVehicle[i] == other )
			{
				return i;
			}
		}
	}
}


#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"
#include<math.h>

namespace assignment2
{
	Airplane::Airplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
	}

	Airplane::~Airplane()
	{
	}

	unsigned int Airplane::GetFlySpeed() const
	{
		unsigned int tem = pow(2.71, (800 - GetPassengersCount() / 500));
		tem *= 200;
		return tem;
	}

	unsigned int Airplane::GetDriveSpeed() const
	{
		unsigned int tem = pow(2.71, (400 - GetPassengersCount() / 70));
		tem *= 4;
		return tem;
	}

	unsigned int Airplane::GetMaxSpeed() const
	{
		unsigned int dSpeed = GetDriveSpeed();
		unsigned int fSpeed = GetFlySpeed();

		if (dSpeed > fSpeed)
		{
			return dSpeed;
		}
		else
		{
			return fSpeed;
		}
	}

	Boatplane& Airplane::operator+(Boat& boat)
	{
		Boatplane bp(GetMaxPassengersCount() + boat.GetMaxPassengersCount());
		unsigned int i = 0;
		for (i; i < GetPassengersCount(); i++)
		{
			bp.AddPassenger(GetPassenger(i));

		}
		QuitAll();
		
		unsigned int tem = 0;

		for (i; i < bp.GetMaxPassengersCount(); i++)
		{
			bp.AddPassenger(boat.GetPassenger(tem));
			tem++;
		}
		boat.QuitAll();


		return bp;
	}
}
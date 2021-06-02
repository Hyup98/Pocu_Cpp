#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"
#include<math.h>
#include<iostream>
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
		unsigned int temNum = 800 - GetTotalWeight();

	 	double temNumber = temNum / 500.0;
		
		double tem = pow(2.718281, temNumber);

		double answer = tem * 200;

		return static_cast<unsigned int>(answer);
	}

	void Airplane::Move()
	{
		if (mMoveCount == 0)
		{
			mMoveCount++;
		}

		else
		{
			if (mRestCount <= 2)
			{
				mRestCount++;
			}
			else if (mRestCount == 3)
			{
				mMoveCount++;
				mRestCount = 0;
			}
		}
	}

	unsigned int Airplane::GetTraveledDistance()
	{
		unsigned int tem = GetMaxSpeed() * mMoveCount;
		return tem;
	}

	unsigned int Airplane::GetDriveSpeed() const
	{
		unsigned int temNum = 400 - GetTotalWeight();
		double temNumber = temNum / 70.0;
		double tem = pow(2.718281,temNumber);
		double answer = tem * 4;
		return static_cast<unsigned int>(round(answer));
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

	Boatplane Airplane::operator+(Boat& boat)
	{
		Boatplane bp(GetMaxPassengersCount() + boat.GetMaxPassengersCount());

		unsigned int i = 0;
		for (i; i < GetPassengersCount(); i++)
		{
			bp.AddPassenger(GetPassenger(i));

		}
		QuitAll();

		unsigned int tem = 0;
		i++;
		unsigned int temI = i + boat.GetPassengersCount();
		for (i; i < temI; i++)
		{
			bp.AddPassenger(boat.GetPassenger(tem));
			tem++;
		}
		boat.QuitAll();


		return bp;;
	}
}
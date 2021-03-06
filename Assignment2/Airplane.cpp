#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"
#include<math.h>
#include<cassert>
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
		/*
		unsigned int temNum = 800 - GetTotalWeight();
		if (temNum <= 0)
		{
			return 0;
		}

		double temNumber = temNum / static_cast<double>(500);
		
		double tem = pow(2.718281, temNumber);

		double answer = tem * 200;

		return static_cast<unsigned int>(round(answer));
		*/
		return static_cast<unsigned int>((200.0 * exp((800.0 - GetTotalWeight()) / 500.0)) + 0.5);
	}

	void Airplane::Move()
	{
		switch (mMoveCount)
		{
		case 0:
			mMovedLength += GetMaxSpeed();
			[[fallthrough]];
		case 1:
		case 2:
			mMoveCount++;
			break;
		case 3:
			mMoveCount = 0;
			break;
		default:
			assert(false);
			break;
		}
	}

	unsigned int Airplane::GetTraveledDistance()
	{
		unsigned int tem = GetMaxSpeed() * mMoveCount;
		return tem;
	}

	unsigned int Airplane::GetDriveSpeed() const
	{
		/*
		unsigned int temNum = 400 - GetTotalWeight();
		if (temNum <= 0)
		{
			return 0;
		}
		double temNumber = temNum / 70.0;
		double tem = pow(2.718281, temNumber);
		double answer = tem * 4;
		return static_cast<unsigned int>(round(answer));
		*/
		return static_cast<unsigned int>(4.0 * exp(((400.0 - GetTotalWeight()) / 70.0)) + 0.5);
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
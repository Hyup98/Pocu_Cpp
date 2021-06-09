#pragma once
#include "Vehicle.h"
#include "IDrivable.h"

namespace assignment2
{
	class Trailer;

	class Sedan: public Vehicle, public IDrivable
	{
	public:
		Sedan();
		Sedan(Sedan* other);
		~Sedan();

		bool AddTrailer(const Trailer* trailer);
		bool RemoveTrailer();
		unsigned int GetMaxSpeed() const;
		unsigned int GetDriveSpeed() const;
		void Move();
		unsigned int GetTraveledDistance();
		void SetMoveCount();
	private:
		const Trailer* mTrailer;
		bool mBIsConect;

	};
}
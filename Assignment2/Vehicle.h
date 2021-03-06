#pragma once

#include "Person.h"


namespace assignment2
{
	class Person;

	class Vehicle 
	{
	public:
		Vehicle(unsigned int maxPassengersCount);
		virtual ~Vehicle();
		Vehicle(Vehicle& rhs);
		virtual unsigned int GetMaxSpeed() const;
		virtual void Move() = 0;
		virtual unsigned int GetTraveledDistance();
		bool AddPassenger(const Person* person);
		bool RemovePassenger(unsigned int i);
		void OutPassenger(const Person* person);
		const Person* GetPassenger(unsigned int i) const;
		unsigned int GetPassengersCount() const;
		unsigned int GetMaxPassengersCount() const;
		unsigned int GetTotalWeight() const;
		void SetonBoardNum(unsigned int i);
		void QuitAll();
		void SetMoveCount();
		Vehicle& operator=(const Vehicle& rhs);
		unsigned int GetMovedLength() const;

	protected:
		unsigned int mMoveCount;
		//unsigned int mRestCount;
		unsigned int mMovedLength;

	private:
		unsigned int mMaxPassengersCount;
		unsigned int mOnBoardNum;
		const Person** mPassenger; 

	};
}
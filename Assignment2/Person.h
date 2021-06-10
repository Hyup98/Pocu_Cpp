#pragma once

#include "Vehicle.h"
#include <string>

namespace assignment2
{
	class Vehicle;

	class Person
	{
	public:
		Person(const char* name, unsigned int weight);
		~Person();
		Person(std::string name, unsigned int weight);
		Vehicle* GetBoardVehicle() const;
		void SetBoardVehicle(Vehicle* t);
		const std::string& GetName() const;
		unsigned int GetWeight() const;
	private:
		Vehicle* mOnBoardVechicle;
		std::string mName;
		unsigned int mWeight;
		
	};
}
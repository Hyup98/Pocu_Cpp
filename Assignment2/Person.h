#pragma once

#include <string>

namespace assignment2
{
	class Person
	{
	public:
		Person(const char* name, unsigned int weight);
		~Person();
		Person(std::string name, unsigned int weight);

		const std::string& GetName() const;
		unsigned int GetWeight() const;
	private:
		std::string mName;
		unsigned int mWeight;
	};
}
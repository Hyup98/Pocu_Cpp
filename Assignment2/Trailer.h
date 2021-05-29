#pragma once

namespace assignment2
{
	class Trailer
	{
	public:
		Trailer(unsigned int weight);
		~Trailer();
		bool IsConect() const;
		void Conect();

		unsigned int GetWeight() const;
	private:
		unsigned int mWeight;
		bool bIsConect;
	};
}
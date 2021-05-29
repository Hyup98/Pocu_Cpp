#include "Trailer.h"

namespace assignment2
{
	Trailer::Trailer(unsigned int weight)
		: mWeight(weight)
	{
		bIsConect = false;
	}

	Trailer::~Trailer()
	{
	}

	bool Trailer::IsConect() const
	{
		return bIsConect;
	}

	void Trailer::Conect()
	{
		bIsConect = true;
	}

	unsigned int Trailer::GetWeight() const
	{
		return mWeight;
	}
}
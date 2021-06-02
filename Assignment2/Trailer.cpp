#include "Trailer.h"

namespace assignment2
{
	Trailer::Trailer(unsigned int weight)
		: mWeight(weight)
	{
		mBIsConect = false;
	}

	Trailer::~Trailer()
	{
	}

	bool Trailer::IsConect() const
	{
		return mBIsConect;
	}

	void Trailer::Conect()
	{
		mBIsConect = true;
	}

	unsigned int Trailer::GetWeight() const
	{
		return mWeight;
	}
}
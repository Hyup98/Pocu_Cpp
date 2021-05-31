#pragma once

#include "Lawn.h"
#include "IFenceable.h"
#include "eGrassType.h"

namespace lab5
{
	class SquareLawn : public Lawn, public IFenceable
	{
	public:
		SquareLawn(unsigned int width);
		unsigned int GetMinimumFencesCount() const;
		unsigned int GetFencePrice(eFenceType fenceType) const;
		unsigned int GetArea() const;

	private:
		unsigned int mWidth;
	};
}

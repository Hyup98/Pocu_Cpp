#pragma once

#include "RectangleLawn.h"
#include "eGrassType.h"

namespace lab5
{
	class SquareLawn : public RectangleLawn
	{
	public:
		SquareLawn(unsigned int width);
		/*
		unsigned int GetMinimumFencesCount() const;
		unsigned int GetFencePrice(eFenceType fenceType) const;
		unsigned int GetArea() const;
		*/

	};
}

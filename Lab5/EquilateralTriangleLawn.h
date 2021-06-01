#pragma once

#include"Lawn.h"
#include"IFenceable.h"

namespace lab5
{
	class EquilateralTriangleLawn : public Lawn, public IFenceable
	{
	public:
		EquilateralTriangleLawn(unsigned int width);
		~EquilateralTriangleLawn();
		unsigned int GetMinimumFencesCount() const;
		unsigned int GetFencePrice(eFenceType fenceType) const;
		unsigned int GetArea() const;

	private:
		unsigned int mWidth;
	};

}


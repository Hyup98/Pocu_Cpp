#pragma once

#include "Lawn.h"
#include "IFenceable.h"
#include "eGrassType.h"

namespace lab5
{
	class RectangleLawn : public Lawn, public IFenceable
	{
	public:
		RectangleLawn(unsigned int width, unsigned int height);
		~RectangleLawn();
		unsigned int GetMinimumFencesCount() const;
		unsigned int GetFencePrice(eFenceType fenceType) const;
		unsigned int GetArea() const;

	private:
		unsigned int mWidth;
		unsigned int mHeight;		
	};
}


#include "RectangleLawn.h"

namespace lab5
{
	RectangleLawn::RectangleLawn(unsigned int width, unsigned int height)
		: mWidth(width)
		, mHeight(height)
	{
	}

	RectangleLawn::~RectangleLawn()
	{
	}

	unsigned int RectangleLawn::GetArea() const
	{
		return mWidth * mHeight;
	}

	unsigned int RectangleLawn::GetMinimumFencesCount() const
	{
		
		unsigned int widthTem = mWidth * 4 * 2;
		unsigned int heightTem = mHeight * 4 * 2;
		
		return widthTem + heightTem;
	}

	unsigned int RectangleLawn::GetFencePrice(eFenceType fenceType) const
	{
		//6//
		if (fenceType == RED_CEDAR)
		{
			return GetMinimumFencesCount() / 4 * RED_CEDAR;
		}
		//7//
		else
		{
			return GetMinimumFencesCount() / 4 * SPRUCE;
		}
	}
}
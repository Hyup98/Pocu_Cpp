#pragma once

#include "SquareLawn.h"

using namespace lab5;

SquareLawn::SquareLawn(unsigned int width) 
	: mWidth(width)
{
}
unsigned int SquareLawn::GetMinimumFencesCount() const
{
	unsigned int widthTem = mWidth * 4 * 2 * 2;
	return widthTem;
}
unsigned int SquareLawn::GetFencePrice(eFenceType fenceType) const
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
unsigned int SquareLawn::GetArea() const
{
	return mWidth * mWidth;
}



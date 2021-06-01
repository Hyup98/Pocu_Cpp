#include "EquilateralTriangleLawn.h"
#include<cmath>

using namespace lab5;

EquilateralTriangleLawn::EquilateralTriangleLawn(unsigned int width)
	: mWidth(width)
{
}

EquilateralTriangleLawn::~EquilateralTriangleLawn()
{
}
unsigned int EquilateralTriangleLawn::GetMinimumFencesCount() const
{
	unsigned int widthTem = mWidth * 4 * 3;

	return widthTem;
}
unsigned int EquilateralTriangleLawn::GetFencePrice(eFenceType fenceType) const
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
unsigned int EquilateralTriangleLawn::GetArea() const
{
	unsigned int area;
	double tem;
	double temc;

	temc = sqrt(3.0);
	tem = temc * mWidth * mWidth / 4;
	area = static_cast<int>(round(tem));

	return area;

	
}


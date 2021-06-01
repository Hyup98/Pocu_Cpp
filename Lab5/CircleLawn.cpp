#include "CircleLawn.h"
namespace lab5
{

	CircleLawn::CircleLawn(unsigned int radius)
		: mRadius(radius)
	{
	}

	CircleLawn::~CircleLawn() 
	{
	}

	unsigned int CircleLawn::GetArea() const
	{
		double tem = 3.14 * mRadius * mRadius;
		if ((tem - (int)tem) > 0)
		{
			return (int)++tem;
		}
		return (int)tem;
		
	}
}


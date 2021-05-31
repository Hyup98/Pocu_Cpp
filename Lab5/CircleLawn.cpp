#include "CircleLawn.h"
namespace lab5
{

	CircleLawn::CircleLawn(unsigned int radius)
		: mRadius(radius)
	{
	}

	unsigned int CircleLawn::GetArea() const
	{
		double tem = 3.14 * mRadius * mRadius;
		return (int)tem;
		
	}
}


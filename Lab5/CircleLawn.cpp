#include "CircleLawn.h"
#include <cmath>
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
		
		return  static_cast<int>(round(tem));
		
	}
}

 
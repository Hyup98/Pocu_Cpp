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
		if ((tem - static_cast<int>(tem)) > 0)
		{
			return  static_cast<int>(++tem);
		}
		return  static_cast<int>(tem);
		
	}
}


#pragma once

#include "Lawn.h"

namespace lab5
{
	class CircleLawn : public Lawn
	{
	public:
		CircleLawn(unsigned intradius);
		unsigned int GetArea() const;

	private:
		unsigned int mRadius;
	};

}



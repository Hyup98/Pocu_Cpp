#pragma once

#include "Lawn.h"

namespace lab5
{
	class CircleLawn : public Lawn
	{
	public:
		CircleLawn(unsigned intradius);
		~CircleLawn();
		unsigned int GetArea() const;

	private:
		unsigned int mRadius;
	};

}



#include "IceCube.h"

namespace lab9
{
	IceCube::IceCube()
		: mFrameCountToLive(0)
	{
	}

	IceCube::~IceCube()
	{
	}

	void IceCube::Initialize(unsigned int frameCountToLive)
	{
		mFrameCountToLive = frameCountToLive;
	}

	void IceCube::Reset()
	{
		mFrameCountToLive = 0;
	}

	void IceCube::Animate()
	{
		if (mFrameCountToLive == 0)
		{
			return;
		}

		mFrameCountToLive--;
	}

	bool IceCube::IsActive() const
	{
		return mFrameCountToLive > 0;
	}
}
#pragma once

namespace lab9
{
	class IceCube final
	{
	public:
		IceCube();
		~IceCube();

		void Initialize(unsigned int frameCountToLive);
		void Reset();
		void Animate();
		bool IsActive() const;

	private:
		unsigned int mFrameCountToLive;
	};
}
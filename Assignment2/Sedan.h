#pragma once

namespace assignment2
{
	class Trailer;

	class Sedan
	{
	public:
		Sedan();
		~Sedan();

		bool AddTrailer(const Trailer* trailer);
		bool RemoveTrailer();

	};
}
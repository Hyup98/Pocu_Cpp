#include <cassert>
#include "Lab6.h"

int main()
{
	std::vector<int> v;



	for (int i = 0; i < (int)v.size() - 1; ++i)
	{
		assert(v[i] >= v[i + 1]);
	}

	return 0;
}
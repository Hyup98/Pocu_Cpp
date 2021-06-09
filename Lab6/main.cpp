#include <cassert>
#include "Lab6.h"

int main()
{
	std::vector<int> v;
	v.push_back(4);
	v.push_back(3);
	v.push_back(4);
	v.push_back(12);
	v.push_back(7);
	v.push_back(11);

	int sum = lab6::Sum(v);
	int max = lab6::Max(v);
	int min = lab6::Min(v);
	float average = lab6::Average(v);
	int numWithMaxOccurence = lab6::NumberWithMaxOccurrence(v);
	lab6::SortDescending(v);

	assert(sum == 41);
	assert(max == 12);
	assert(min == 3);
	assert(average == 6.83333349f);
	assert(numWithMaxOccurence == 4);

	for (int i = 0; i < (int)v.size() - 1; ++i)
	{
		assert(v[i] >= v[i + 1]);
	}

	return 0;
}
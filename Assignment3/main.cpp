#include <cassert>
#include <cmath>

#include "SmartStack.h"

using namespace assignment3;

int main()
{
	const double EPSILON = 0.0009765625;

	SmartStack<float> ss;

	ss.Push(3.4999f);
	ss.Push(1.2f);
	ss.Push(4.6555f);
	ss.Push(3.3299f);
	ss.Push(10.2f);
	ss.Push(1.1f);
	ss.Push(-5.9f);
	ss.Push(1.1f);
	ss.Push(-12.4f);
	ss.Push(9.2f);

	assert(ss.GetCount() == 10U);
	assert(ss.Peek() == 9.2f);
	assert(ss.GetMax() == 10.2f);
	assert(ss.GetMin() == -12.4f);
	assert(std::abs(ss.GetSum() - 15.985301f) <= EPSILON);
	assert(std::abs(ss.GetAverage() - 1.599) <= EPSILON);
	assert(std::abs(ss.GetVariance() - 40.057) <= EPSILON);
	assert(std::abs(ss.GetStandardDeviation() - 6.329) <= EPSILON);
	assert(ss.Peek() == 9.2f);

	float popped1 = ss.Pop();
	float popped2 = ss.Pop();

	assert(popped1 == 9.2f);
	assert(popped2 == -12.4f);
	assert(ss.GetCount() == 8U);
	assert(ss.Peek() == 1.1f);
	assert(ss.GetMax() == 10.2f);
	assert(ss.GetMin() == -5.9f);
	assert(std::abs(ss.GetSum() - 19.1853008f) <= EPSILON);
	assert(std::abs(ss.GetAverage() - 2.398) <= EPSILON);
	assert(std::abs(ss.GetVariance() - 17.714) <= EPSILON);
	assert(std::abs(ss.GetStandardDeviation() - 4.209) <= EPSILON);

	return 0;
}
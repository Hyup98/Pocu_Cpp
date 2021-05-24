#include <cassert>
#include <cmath>

#include "Point.h"
#include "PolyLine.h"

using namespace lab4;

int main()
{
	const double EPSILON = 0.0009765625;

	Point p1(2, 3);
	Point p2(-1, 4);

	Point p3 = p1 + p2;

	assert(std::abs(p3.GetX() - 1) <= EPSILON);
	assert(std::abs(p3.GetY() - 7) <= EPSILON);

	Point p4 = p2 - p1;

	assert(std::abs(p4.GetX() - (-3)) <= EPSILON);
	assert(std::abs(p4.GetY() - 1) <= EPSILON);

	float dotProduct = p1.Dot(p2);

	assert(std::abs(dotProduct - 10) <= EPSILON);

	Point p5 = p1 * 5;

	assert(std::abs(p5.GetX() - 10) <= EPSILON);
	assert(std::abs(p5.GetY() - 15) <= EPSILON);

	Point p6 = 2 * p2;

	assert(std::abs(p6.GetX() - (-2)) <= EPSILON);
	assert(std::abs(p6.GetY() - 8) <= EPSILON);

	/* ----------------------- */

	PolyLine pl1;
	pl1.AddPoint(1, 2);
	pl1.AddPoint(3, 2);
	pl1.AddPoint(5, 5);
	pl1.AddPoint(-2, 4);
	pl1.AddPoint(4, -1);
	pl1.AddPoint(6, 4);

	bool bRemoved = pl1.RemovePoint(4);

	assert(bRemoved);

	Point minP(0.f, 0.f);
	Point maxP(0.f, 0.f);

	pl1.TryGetMinBoundingRectangle(&minP, &maxP);

	assert(minP.GetX() == -2);
	assert(minP.GetY() == 2);
	assert(maxP.GetX() == 6);
	assert(maxP.GetY() == 5);

	return 0;
}
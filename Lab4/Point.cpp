#include "Point.h"

namespace lab4
{
	Point::Point(float x, float y)
	{
		mXpoint = x;
		mYpoint = y;
	}

	Point::~Point()
	{
	}

	void Point::SetX(float x)
	{
		mXpoint = x;
	}

	void Point::SetY(float y)
	{
		mYpoint = y;
	}

	void Point::SetPoint(float x, float y)
	{
		mXpoint = x;
		mYpoint = y;
	}

	Point Point::operator+(const Point& other) const
	{
		return Point(mXpoint + other.mXpoint, mYpoint + other.mYpoint);
	}

	Point Point::operator-(const Point& other) const
	{
		return Point(mXpoint - other.mXpoint, mYpoint - other.mYpoint);
	}

	float Point::Dot(const Point& other) const
	{
		return (mXpoint * other.mXpoint + mYpoint * other.mYpoint);
	}

	Point Point::operator*(float operand) const
	{
		return Point(mXpoint * operand, mYpoint * operand);
	}

	float Point::GetX() const
	{
		return mXpoint;
	}

	float Point::GetY() const
	{
		return mYpoint;
	}
	Point operator*(float lhs, const Point& rhs)
	{
		return Point(rhs.GetX() * lhs, rhs.GetY() * lhs);
	}
}
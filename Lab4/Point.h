#pragma once

namespace lab4
{
	class Point
	{
		friend Point operator*(float lhs, const Point& rhs);
	public:
		Point(float x, float y);
		~Point();

		void SetX(float x);
		void SetY(float y);
		void SetPoint(float x, float y);
		Point operator+(const Point& other) const;
		Point operator-(const Point& other) const;
		float Dot(const Point& other) const;
		Point operator*(float operand) const;
		float GetX() const;
		float GetY() const;

	private:
		float mXpoint;
		float mYpoint;
	};
}
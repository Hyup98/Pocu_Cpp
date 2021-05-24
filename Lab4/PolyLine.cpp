#include <cstring>
#include <cmath>
#include "PolyLine.h"
#include<iostream>

namespace lab4
{
	PolyLine::PolyLine()
		:mCapacity(0)
	{
		 mPointArray = new Point*[mMaximumCapacity];
	}

	PolyLine::PolyLine(const PolyLine& other)
	{
		if (&other != nullptr)
		{
			mCapacity = other.mCapacity;
			mPointArray = new Point * [mMaximumCapacity];
			for (size_t i = 0; i < mCapacity; i++)
			{
				mPointArray[i] = new Point(other.mPointArray[i]->GetX(), other.mPointArray[i]->GetY());
			}
		}
	
	}

	PolyLine::~PolyLine()
	{
		for (size_t i = 0; i < mCapacity; i++)
		{
			delete mPointArray[i];
		}
		delete[] mPointArray;
	}

	bool PolyLine::AddPoint(float x, float y)
	{
		if (mCapacity == 10)
		{
			return false;
		}

		else 
		{
			mPointArray[mCapacity] = new Point(x, y);
			mCapacity++;
			return true;
		}

	}

	PolyLine& PolyLine::operator=(const PolyLine& other)
	{
		if (&other == this)
		{
			return *this;
		}
		mCapacity = other.mCapacity;
		mPointArray = new Point*[10];
		for (size_t i = 0; i < mCapacity; i++)
		{
			mPointArray[i] = new Point(other.mPointArray[i]->GetX(), other.mPointArray[i]->GetY());
		}
	}

	bool PolyLine::AddPoint(const Point* point)
	{
		if (point != nullptr)
		{
			if (mCapacity == 10)
			{
				return false;
			}

			else
			{
				//생각이 필요함!
				mPointArray[mCapacity] = new Point(point->GetX(), point->GetY());
				mCapacity++;
				std::cout << mCapacity<<"\n";
				return true;

			}
		}
		else
		{
			return false;
		}
		
	}

	bool PolyLine::RemovePoint(unsigned int i)
	{
		if (i >= mCapacity) 
		{
			return false;
		}
		if (i < 0)
		{
			return false;
		}
		if (mCapacity == 0)
		{
			return false;
		}

		else
		{
			for (unsigned int j = i; j < mCapacity - 1 ; j++)
			{
				mPointArray[j]->setPoint(mPointArray[j + 1]->GetX(), mPointArray[j + 1]->GetY());
			}
			mCapacity--;
			delete mPointArray[mCapacity];
			mPointArray[mCapacity] = nullptr;
			std::cout << mCapacity << "\n";
			return true;

		}
	}

	bool PolyLine::TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const
	{
		if (outMax != nullptr && outMin != nullptr)
		{
			bool answer = true;
			if (mCapacity != 0)
			{
				float maxX = mPointArray[0]->GetX();
				float minX = mPointArray[0]->GetX();
				float maxY = mPointArray[0]->GetY();
				float minY = mPointArray[0]->GetY();

				for (size_t i = 0; i < mCapacity; i++)
				{
					if (maxX < mPointArray[i]->GetX())
					{
						maxX = mPointArray[i]->GetX();
					}

					if (maxY < mPointArray[i]->GetY())
					{
						maxY = mPointArray[i]->GetY();
					}

					if (minX > mPointArray[i]->GetX())
					{
						minX = mPointArray[i]->GetX();
					}

					if (minY > mPointArray[i]->GetY())
					{
						minY = mPointArray[i]->GetY();
					}

				}

				outMin->setPoint(minX, minY);
				outMax->setPoint(maxX, maxY);


				return answer;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
		
	}

	const Point* PolyLine::operator[](unsigned int i) const
	{
		//return new Point(mPointArray[i]->GetX(),mPointArray[i]->GetY());
		if (i < mCapacity)
		{
			return mPointArray[i];
		}
		else
		{
			return nullptr;
		}

	}
}
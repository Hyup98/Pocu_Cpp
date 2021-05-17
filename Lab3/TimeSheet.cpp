#include "TimeSheet.h"
#include <cmath>

namespace lab3
{
	TimeSheet::TimeSheet(const char* name, unsigned int maxEntries)
	{
		mMaxWorkingDay = maxEntries;
		mEmployee = name;
		mWorkedDay = 0;
		mWorkingHours = new int[maxEntries];
	}

	TimeSheet::TimeSheet(const TimeSheet& rhs)
	{
		mEmployee = rhs.mEmployee;
		mMaxWorkingDay = rhs.mMaxWorkingDay;
		mWorkedDay = rhs.mWorkedDay;
		mWorkingHours = new int[mMaxWorkingDay];
		if (mWorkedDay != 0)
		{
			for (size_t i = 0; i < mMaxWorkingDay; i++)
			{
				mWorkingHours[i] = rhs.mWorkingHours[i];
			}
		}
	}

	TimeSheet& TimeSheet::operator=(const TimeSheet& rhs)
	{
		delete[] mWorkingHours;
		mEmployee = rhs.mEmployee;
		mMaxWorkingDay = rhs.mMaxWorkingDay;
		mWorkedDay = rhs.mWorkedDay;
		mWorkingHours = new int[mMaxWorkingDay];
		if (mWorkedDay != 0)
		{
			for (size_t i = 0; i < mMaxWorkingDay; i++)
			{
				mWorkingHours[i] = rhs.mWorkingHours[i];
			}
		}
		return *this;
	}

	TimeSheet::~TimeSheet()
	{
		delete[] mWorkingHours;
	}

	void TimeSheet::AddTime(int timeInHours)
	{
		if (timeInHours <= 10)
		{
			if (timeInHours > 0)
			{
				if (mWorkedDay < mMaxWorkingDay)
				{
					mWorkingHours[mWorkedDay] = timeInHours;
					mWorkedDay++;
				}
			}
		}

		return;
	}

	int TimeSheet::GetTimeEntry(unsigned int index) const
	{
		unsigned int answer = -1;

		if (index < mWorkedDay)
		{
			if (index >= 0)
			{
				answer = mWorkingHours[index];
				return answer;
			}
		}




		return answer;
	}

	int TimeSheet::GetTotalTime() const
	{
		int answer = 0
			;
		if (mWorkedDay == 0)
		{
			return answer;
		}

		for (unsigned int i = 0; i < mWorkedDay; i++)
		{
			answer += mWorkingHours[i];
		}

		return answer;
	}

	float TimeSheet::GetAverageTime() const
	{
		float answer = 0;
		if (mWorkedDay == 0)
		{
			return answer;
		}
		answer = GetTotalTime() / static_cast<float>(mWorkedDay);
		answer *= 1.0f;
		return answer;
	}

	float TimeSheet::GetStandardDeviation() const
	{
		float average = GetAverageTime();
		float answer = 0;
		float tem = 0;

		if (mWorkedDay == 0)
		{
			return answer;
		}
		//step)1
		for (size_t i = 0; i < mWorkedDay; i++)
		{
			tem += (mWorkingHours[i] - average) * (mWorkingHours[i] - average);
		}

		//step)2
		tem /= mWorkedDay;

		//step)3
		tem = sqrt(tem);

		answer = tem;
		return answer;
	}

	const std::string& TimeSheet::GetName() const
	{
		return mEmployee;
	}
}
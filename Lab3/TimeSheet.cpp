#include "TimeSheet.h"
#include <cmath>

namespace lab3
{
    TimeSheet::TimeSheet(const char* name, unsigned int maxEntries)
        :mEmployee(name)
        ,maxWorkingDay(maxEntries)
    {
        workedDay = 0;
        workingHours = new int[maxEntries];
    }
    TimeSheet::~TimeSheet()
    {
        delete[] workingHours;
    }

    void TimeSheet::AddTime(int timeInHours)
    {
        if (timeInHours <= 10 && timeInHours >= 1) 
        {
            if (workedDay < maxWorkingDay)
            {
                workingHours[workedDay] = timeInHours;
                workedDay++;
            }
        }

        else
        {
            return;
        }
    }

    int TimeSheet::GetTimeEntry(unsigned int index) const
    {
        unsigned int answer = -1;

        if (index > workedDay || index < 0)
        {
            return answer;
        }

        answer = workingHours[index];


        return answer;
    }

    int TimeSheet::GetTotalTime() const
    {
        int answer = 0
            ;
        if (workedDay == 0)
        {
            return answer;
        }

        for (size_t i = 0; i < workedDay; i++)
        {
            answer += workingHours[i];
        }

        return answer;
    }

    float TimeSheet::GetAverageTime() const
    {
        float answer = 0;
        answer = GetTotalTime() / (float)workedDay;
        return answer;
    }

    float TimeSheet::GetStandardDeviation() const
    {
        float average = GetAverageTime();
        float answer = 0;
        float tem = 0;

        //step)1
        for (size_t i = 0; i < workedDay; i++)
        {
            tem += (workingHours[i] - average) * (workingHours[i] - average);
        }

        //step)2
        tem /= workedDay;

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
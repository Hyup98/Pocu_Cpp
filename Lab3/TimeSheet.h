#pragma once
#include <string>

namespace lab3
{
    class TimeSheet
    {
    public:
        TimeSheet(const char* name, unsigned int maxEntries);
        ~TimeSheet();
        TimeSheet(const TimeSheet& rhs);
        void AddTime(int timeInHours);
        int GetTimeEntry(unsigned int index) const;
        int GetTotalTime() const;
        float GetAverageTime() const;
        float GetStandardDeviation() const;
        const std::string& GetName() const;

    private:
        std::string mEmployee;
        int* workingHours;
        unsigned int workedDay;
        unsigned int maxWorkingDay;
    };
}
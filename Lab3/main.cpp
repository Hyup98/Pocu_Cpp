#include <iostream>

#include "TimeSheet.h"

using namespace lab3;
using namespace std;
int main()
{
    TimeSheet p("Pope", 10);

    p.AddTime(4);
    p.AddTime(7);
    p.AddTime(6);
    p.AddTime(5);
    p.AddTime(1);
    p.AddTime(2);

    cout<< p.GetStandardDeviation(); // 2.11476 ¹ÝÈ¯
    int a;
    std::cin >> a;
    return 0;
}
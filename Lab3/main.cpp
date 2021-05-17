#include <iostream>

#include "TimeSheet.h"

using namespace lab3;
using namespace std;
void test()
{
	lab3::TimeSheet employee1("John", 5);
	employee1.AddTime(1);    // ok
	employee1.AddTime(5);    // ok  
	employee1.AddTime(-1);   // Not ok
	employee1.AddTime(7);    // ok
	employee1.AddTime(10);   // ok
	employee1.AddTime(15);   // Not ok
	employee1.AddTime(3);    // ok
	employee1.AddTime(8);    // Not ok

	std::cout << employee1.GetTimeEntry(0) << std::endl;    // 1
	std::cout << employee1.GetTimeEntry(-1) << std::endl;   // -1
	std::cout << employee1.GetTimeEntry(5) << std::endl;    // -1
	std::cout << employee1.GetTimeEntry(4) << std::endl;    // 3
	std::cout << employee1.GetTimeEntry(1) << std::endl;    // 5
	std::cout << employee1.GetTimeEntry(7) << std::endl;    // -1

	std::cout << employee1.GetTotalTime() << std::endl;         // 26
	std::cout << employee1.GetAverageTime() << std::endl;       // 5.2
	std::cout << employee1.GetStandardDeviation() << std::endl; // 3.1241
	std::cout << employee1.GetName() << std::endl;              // John

	lab3::TimeSheet employee2("Pope", 10);
	employee2.AddTime(4);    // ok
	employee2.AddTime(7);    // ok
	employee2.AddTime(6);    // ok

	std::cout << employee2.GetTotalTime() << std::endl;          // 17
	std::cout << employee2.GetAverageTime() << std::endl;        // 5.66667

	lab3::TimeSheet pope(employee2);

	pope.AddTime(5);    // ok
	pope.AddTime(1);    // ok
	pope.AddTime(2);    // ok

	std::cout << pope.GetTotalTime() << std::endl;          // 25
	std::cout << pope.GetAverageTime() << std::endl;        // 4.16667
	std::cout << pope.GetStandardDeviation() << std::endl;  // 2.11476(모집단의 표준편차)
	std::cout << pope.GetName() << std::endl;               // Pope


	lab3::TimeSheet hyup = employee1;
	std::cout << hyup.GetTotalTime() << std::endl;         // 26
	std::cout << hyup.GetAverageTime() << std::endl;       // 5.2
	std::cout << hyup.GetStandardDeviation() << std::endl; // 3.1241
	std::cout << hyup.GetName() << std::endl;

	cout << "asdfasdf";
	hyup = hyup;
	std::cout << employee1.GetTotalTime() << std::endl;         // 26
	std::cout << employee1.GetAverageTime() << std::endl;       // 5.2
	std::cout << employee1.GetStandardDeviation() << std::endl; // 3.1241
	std::cout << employee1.GetName() << std::endl;              // John



	lab3::TimeSheet hulk("HULK", 10);
	std::cout << hulk.GetStandardDeviation() << std::endl;//0.0
}
int main()
{
	test();
    int a;
    std::cin >> a;
    return 0;
}
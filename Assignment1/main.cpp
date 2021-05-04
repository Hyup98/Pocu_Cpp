#include "MyString.h"
#include <iostream>
using namespace std;
using namespace assignment1;
int main()
{
	MyString s1("HEllo 123K");
	s1.ToUpper(); // s1: "HELLO 123K"
	cout << s1.GetCString();

	int a;
	cin >> a;
}

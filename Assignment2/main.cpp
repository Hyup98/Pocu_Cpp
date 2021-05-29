#include <cassert>
#include<iostream>

#include "Vehicle.h"
#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"
#include "Motorcycle.h"
#include "Sedan.h"
#include "Trailer.h"
#include "UBoat.h"
#include "DeusExMachina.h"
#include "Person.h"

using namespace assignment2;

int main()
{
	Person* p = new Person("Bob", 85);
	Person* p2 = new Person("James", 75);
	Person* p3 = new Person("Tina", 52);

	Airplane a(5);
	a.AddPassenger(p);
	a.AddPassenger(p2);
	a.AddPassenger(p3);

	std::cout<<a.GetMaxSpeed(); // ���� �ӵ��� ���� ���� �ӵ����� ������ ������ 648�� ��ȯ(���� 2.4 ����)
	int t;
	std::cin >> t;
	return 0;
}
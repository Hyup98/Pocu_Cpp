#pragma once
#include <cassert>
#include <iostream>

#include "Lawn.h"
#include "RectangleLawn.h"
#include "CircleLawn.h"
#include "SquareLawn.h"
#include "EquilateralTriangleLawn.h"

using namespace lab5;
using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Lawn* lawn = new RectangleLawn(4, 5);
	RectangleLawn* rectangleLawn = (RectangleLawn*)lawn;
	unsigned int area = lawn->GetArea();
	unsigned int grassPrice = lawn->GetGrassPrice(PERENNIAL_RYEGRASS);
	unsigned int sodRollsCount = lawn->GetMinimumSodRollsCount();
	unsigned int fencePrice = rectangleLawn->GetFencePrice(SPRUCE);
	unsigned int fencesCount = rectangleLawn->GetMinimumFencesCount();
	assert(area == 20);
	assert(grassPrice == 50);
	assert(sodRollsCount == 67);
	assert(fencePrice == 126);
	assert(fencesCount == 72);
	rectangleLawn = nullptr;
	delete lawn;
	cout << "RectangleLawn Clear!" << endl;

	lawn = new EquilateralTriangleLawn(7);
	EquilateralTriangleLawn* equilateralTriangleLawn = (EquilateralTriangleLawn*)lawn;
	area = lawn->GetArea();
	grassPrice = lawn->GetGrassPrice(ST_AUGUSTINE);
	sodRollsCount = lawn->GetMinimumSodRollsCount();
	fencePrice = equilateralTriangleLawn->GetFencePrice(RED_CEDAR);
	fencesCount = equilateralTriangleLawn->GetMinimumFencesCount();
	assert(area == 21);
	assert(grassPrice == 95);
	assert(sodRollsCount == 70);
	assert(fencePrice == 126);
	assert(fencesCount == 84);
	equilateralTriangleLawn = nullptr;
	delete lawn;

	lawn = new EquilateralTriangleLawn(4);
	equilateralTriangleLawn = (EquilateralTriangleLawn*)lawn;
	area = lawn->GetArea();
	grassPrice = lawn->GetGrassPrice(BAHIA);
	sodRollsCount = lawn->GetMinimumSodRollsCount();
	fencePrice = equilateralTriangleLawn->GetFencePrice(RED_CEDAR);
	fencesCount = equilateralTriangleLawn->GetMinimumFencesCount();
	assert(area == 7);
	assert(grassPrice == 35);
	assert(sodRollsCount == 24);
	assert(fencePrice == 72);
	assert(fencesCount == 48);
	equilateralTriangleLawn = nullptr;
	delete lawn;
	cout << "EquilateralTriangleLawn Clear!" << endl;

	lawn = new SquareLawn(5);
	SquareLawn* squareLawn = (SquareLawn*)lawn;
	area = lawn->GetArea();
	grassPrice = lawn->GetGrassPrice(BENTGRASS);
	sodRollsCount = lawn->GetMinimumSodRollsCount();
	fencePrice = squareLawn->GetFencePrice(SPRUCE);
	fencesCount = squareLawn->GetMinimumFencesCount();
	assert(area == 25);
	assert(grassPrice == 75);
	assert(sodRollsCount == 84);
	assert(fencePrice == 140);
	assert(fencesCount == 80);
	squareLawn = nullptr;
	delete lawn;
	cout << "SquareLawn Clear!" << endl;

	lawn = new CircleLawn(2);
	area = lawn->GetArea();
	grassPrice = lawn->GetGrassPrice(PERENNIAL_RYEGRASS);
	sodRollsCount = lawn->GetMinimumSodRollsCount();
	assert(area == 13);
	assert(grassPrice == 33);
	assert(sodRollsCount == 44);
	delete lawn;
	lawn = new CircleLawn(6);
	area = lawn->GetArea();
	grassPrice = lawn->GetGrassPrice(ST_AUGUSTINE);
	sodRollsCount = lawn->GetMinimumSodRollsCount();
	assert(area == 113);
	assert(grassPrice == 509);
	assert(sodRollsCount == 377);
	delete lawn;
	cout << "CircleLawn Clear!" << endl;

	return 0;
}
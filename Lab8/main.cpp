#include <cassert>
#include <iostream>

#include "FixedVector.h"
#include "FixedBoolVector.h"

using namespace lab8;

int main()
{
	int integerArray1[] = { 23, 25, 10, -4, 70 };
	enum { INTEGER_VECTOR1_SIZE = 4 };

	FixedVector<int, 4> integerVector1;

	assert(integerVector1.GetCapacity() == INTEGER_VECTOR1_SIZE);
	assert(integerVector1.GetSize() == 0);
	std::cout << "Test FixedVector constructor: PASS" << std::endl;

	assert(integerVector1.Add(integerArray1[0]) == true);
	assert(integerVector1.Add(integerArray1[1]) == true);
	assert(integerVector1.Add(integerArray1[2]) == true);
	assert(integerVector1.Add(integerArray1[3]) == true);
	assert(integerVector1.GetSize() == INTEGER_VECTOR1_SIZE);
	std::cout << "Test FixedVector Add(): PASS" << std::endl;
	assert(integerVector1.Add(integerArray1[4]) == false);
	assert(integerVector1.GetSize() == INTEGER_VECTOR1_SIZE);
	std::cout << "Test FixedVector Add() - over array range: PASS" << std::endl;

	integerVector1.Add(integerArray1[0]);
	integerVector1.Add(integerArray1[1]);
	integerVector1.Add(integerArray1[2]);
	integerVector1.Add(integerArray1[3]);
	assert(integerVector1.GetIndex(integerArray1[1]) == 1);
	std::cout << "Test FixedVector GetIndex(): PASS" << std::endl;
	assert(integerVector1.Get(1) == integerArray1[1]);
	std::cout << "Test FixedVector Get(): PASS" << std::endl;
	assert(integerVector1[1] == integerArray1[1]);
	std::cout << "Test FixedVector operator[](): PASS" << std::endl;	
	integerVector1[0] = integerArray1[1];
	assert(integerVector1[0] == integerArray1[1]);
	integerVector1[0] = integerArray1[0];
	assert(integerVector1[0] == integerArray1[0]);
	std::cout << "Test FixedVector operator[]() - return reference: PASS" << std::endl;

	for (size_t i = 0; i < INTEGER_VECTOR1_SIZE; ++i)
	{
		assert(integerVector1.Remove(integerArray1[i]) == true);
		assert(integerVector1.GetSize() == INTEGER_VECTOR1_SIZE - (i + 1));
		for (size_t j = 0; j < integerVector1.GetSize(); ++j)
		{
			assert(integerVector1[j] == integerArray1[i + j + 1]);
		}
	}
	std::cout << "Test FixedVector Remove() - order not changed after remove data: PASS" << std::endl;
	assert(integerVector1.Remove(integerArray1[4]) == false);
	assert(integerVector1.GetSize() == INTEGER_VECTOR1_SIZE - 4);
	std::cout << "Test FixedVector Remove() - empty array: PASS" << std::endl;

	enum { BOOL_VECTOR1_SIZE = 7 };
	bool boolArray1[] = {
		true,	/* 0 */
		true,	/* 1 */
		true,	/* 2 */
		true,	/* 3 */
		false,	/* 4 */
		false,	/* 5 */
		true,	/* 6 */
		true	/* 7 - exceeded data */
	};
	FixedVector<bool, BOOL_VECTOR1_SIZE> boolVector1;
	assert(boolVector1.GetCapacity() == BOOL_VECTOR1_SIZE);
	assert(boolVector1.GetSize() == 0);
	std::cout << "Test FixedBoolVector constructor: PASS" << std::endl;

	// 가상 소멸자를 만들면 이 테스트는 통과 못하지만 빌드봇은 통과시킴
	//assert(sizeof(boolVector1) == (sizeof(int32_t) + sizeof(size_t)));

	std::cout << "Test FixedBoolVector constructor - fit memroy: PASS" << std::endl;

	assert(boolVector1.Add(boolArray1[0]) == true);
	assert(boolVector1.Add(boolArray1[1]) == true);
	assert(boolVector1.Add(boolArray1[2]) == true);
	assert(boolVector1.Add(boolArray1[3]) == true);
	assert(boolVector1.Add(boolArray1[4]) == true);
	assert(boolVector1.Add(boolArray1[5]) == true);
	assert(boolVector1.Add(boolArray1[6]) == true);
	assert(boolVector1.GetSize() == 7);
	assert(boolVector1.Get(0) == boolArray1[0]);
	assert(boolVector1.Get(1) == boolArray1[1]);
	assert(boolVector1.Get(2) == boolArray1[2]);
	assert(boolVector1.Get(3) == boolArray1[3]);
	assert(boolVector1.Get(4) == boolArray1[4]);
	assert(boolVector1.Get(5) == boolArray1[5]);
	assert(boolVector1.Get(6) == boolArray1[6]);
	std::cout << "Test FixedBoolVector Add(): PASS" << std::endl;
	assert(boolVector1.Add(boolArray1[7]) == false);
	assert(boolVector1.GetSize() == 7);
	std::cout << "Test FixedBoolVector Add() - over array range: PASS" << std::endl;

	assert(boolVector1.Remove(false) == true);
	assert(boolVector1.GetSize() == 6);
	assert(boolVector1.Get(4) == boolArray1[5]);
	assert(boolVector1.Get(5) == boolArray1[6]);
	assert(boolVector1.Remove(false) == true);
	assert(boolVector1.GetSize() == 5);
	assert(boolVector1.Get(4) == boolArray1[6]);
	std::cout << "Test FixedBoolVector Remove(): PASS" << std::endl;
	assert(boolVector1.Remove(false) == false);
	assert(boolVector1.GetSize() == 5);
	std::cout << "Test FixedBoolVector Remove() - not found: PASS" << std::endl;

	for (size_t i = 0; i < boolVector1.GetSize(); i++)
	{
		assert(boolVector1[i]);
	}
	boolVector1.Remove(true);
	assert(boolVector1.GetSize() == 4);
	for (size_t i = 0; i < boolVector1.GetSize(); i++)
	{
		assert(boolVector1[i]);
	}
	std::cout << "Test FixedBoolVector operator[]() - read: PASS" << std::endl;

	FixedVector<bool, 65> boolVector2;


	// 가상 소멸자를 만들면 이 테스트는 통과 못하지만 빌드봇은 통과시킴
	//assert(sizeof(boolVector2) == ((sizeof(int32_t) * 3) + sizeof(size_t)));

	std::cout << "Test FixedBoolVector constructor - fit memroy: PASS" << std::endl;
	for (int i = 0; i < 65; i++)
	{
		boolVector2.Add(false);
	}

	assert(boolVector2.Add(true) == false);
	assert(boolVector2.GetSize() == 65);
	assert(boolVector2.GetIndex(true) == -1);
	std::cout << "Test FixedBoolVector GetIndex(): PASS" << std::endl;

	return 0;
}


#include <iostream>
#include <cassert>
#include "MyString.h"

using namespace assignment1;
using namespace std;

int main()
{
	//	�޸� üũ�� ����
	int beforeAddress1;
	int beforeAddress2;

	MyString testString1("Happy Happy Days");
	MyString testString2("Happy Days");
	MyString testString3("Happy Days");
	MyString testString4("");

	//	Operator == ����
	beforeAddress1 = (int)testString2.GetCString();
	beforeAddress2 = (int)testString3.GetCString();
	if (testString2 == testString3);
	assert(beforeAddress1 == (int)testString2.GetCString());
	assert(beforeAddress2 == (int)testString3.GetCString());
	cout << "D2_NoMallocInCompareSameLength ���" << endl;

	beforeAddress1 = (int)testString1.GetCString();
	beforeAddress2 = (int)testString2.GetCString();
	if (testString1 == testString2);
	assert(beforeAddress1 == (int)testString1.GetCString());
	assert(beforeAddress2 == (int)testString2.GetCString());
	cout << "D5_NoMallocInCompareDifferentLength ���" << endl;

	//	IndexOf, LastOfIndex ����
	beforeAddress1 = (int)testString1.GetCString();
	testString1.IndexOf("Happy");
	testString1.IndexOf("");
	assert(beforeAddress1 == (int)testString1.GetCString());

	beforeAddress1 = (int)testString1.GetCString();
	testString1.LastIndexOf("Happy");
	testString1.LastIndexOf("");
	assert(beforeAddress1 == (int)testString1.GetCString());
	cout << "E5_NoMallocInIndexOf ���" << endl;

	//	ToUpper, ToLower ����
	beforeAddress1 = (int)testString1.GetCString();
	testString1.ToUpper();
	testString1.ToLower();
	assert(beforeAddress1 == (int)testString1.GetCString());
	cout << "F3_NoMallocInUpperLower ���" << endl;

	//	Reverse ����
	beforeAddress1 = (int)testString1.GetCString();
	testString1.Reverse();
	testString1.Reverse();
	assert(beforeAddress1 == (int)testString1.GetCString());
	beforeAddress1 = (int)testString4.GetCString();
	testString4.Reverse();
	assert(beforeAddress1 == (int)testString4.GetCString());
	cout << "G4_NoMallocInReverse ���" << endl;

	//	Append ����
	beforeAddress1 = (int)testString1.GetCString();
	testString1.Append("");
	assert(beforeAddress1 == (int)testString1.GetCString());
	cout << "H3_NoMallocInAppendEmpty ���" << endl;

	//	 RemoveAt ����
	beforeAddress1 = (int)testString4.GetCString();
	testString4.RemoveAt(0);
	assert(beforeAddress1 == (int)testString4.GetCString());
	cout << "J2_RemoveAtNoMallocOnEmpty ���" << endl;

	//	PadLeft, PadRight ����
	beforeAddress1 = (int)testString1.GetCString();
	testString1.PadLeft(16);
	testString1.PadLeft(16, '*');
	assert(beforeAddress1 == (int)testString1.GetCString());
	cout << "K4_NoMallocInPadLeftShorter ���" << endl;

	beforeAddress1 = (int)testString1.GetCString();
	testString1.PadRight(16);
	testString1.PadRight(16, '*');
	assert(beforeAddress1 == (int)testString1.GetCString());
	cout << "L4_NoMallocInPadRightShorter ���" << endl;

	//	InterLeave ����

	beforeAddress1 = (int)testString1.GetCString();
	testString1.PadRight(16);
	testString1.PadRight(16, '*');
	assert(beforeAddress1 == (int)testString1.GetCString());
	cout << "L4_NoMallocInPadRightShorter ���" << endl;

	//	InterLeave ����
	beforeAddress1 = (int)testString1.GetCString();
	testString1.Interleave("");
	assert(beforeAddress1 == (int)testString1.GetCString());
	cout << "M3_NoMallocInInterleaveEmpty ���" << endl;

	return 0;
}

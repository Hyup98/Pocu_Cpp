#include <iostream>
#include <cassert>
#include "MyString.h"

using namespace assignment1;
using namespace std;

void test() {
	/* GetLength() Ex */
	cout << "-----------------------" << endl;
	cout << "GetLength()" << endl;
	MyString s1("Hello");
	cout << s1.GetLength() << endl;   // 5

	/* GetCString() Ex */
	cout << "-----------------------" << endl;
	cout << "GetCString()" << endl;
	MyString s2("Hello");
	cout << s2.GetCString() << endl;  // Hello

	/* Append() Ex */
	cout << "-----------------------" << endl;
	cout << "Append()" << endl;
	MyString s3("Hello");
	s3.Append(" World");
	cout << s3.GetCString() << endl;  // Hello World
	s3.Append("\n\tWorld\n");
	cout << s3.GetCString() << endl;

	/* operator+ Ex */
	cout << "-----------------------" << endl;
	cout << "operator+" << endl;
	MyString s41("Hello");
	MyString s42(" World");
	MyString s43 = s41 + s42;
	//s2 = s2 + s1;  소멸자 오류(이번 과제에서는 체크하지 않음)
	cout << s43.GetCString() << endl;   //Hello World

	/* IndexOf() Ex */
	cout << "-----------------------" << endl;
	cout << "IndexOf()" << endl;
	MyString s5("Hello");
	cout << s5.IndexOf("ell") << endl;   // 1
	cout << s5.IndexOf("l") << endl;     // 2
	cout << s5.IndexOf("This") << endl;  // -1
	cout << s5.IndexOf("") << endl;   // 0
	cout << s5.IndexOf("lo") << endl;   // 3

	MyString s52("");
	cout << s52.IndexOf("") << endl;   // 0
	cout << s52.IndexOf("A") << endl; // -1

	MyString s53("Hellello");
	MyString s54("Heloo");
	cout << s53.IndexOf("ell") << endl;   // 1
	cout << s54.IndexOf("ell") << endl;   // -1

	/* LastIndexOf() Ex */
	cout << "-----------------------" << endl;
	cout << "LastIndexOf()" << endl;
	MyString s6("Hello");
	cout << s6.LastIndexOf("ell") << endl;   // 1
	cout << s6.LastIndexOf("l") << endl;     // 3
	cout << s6.LastIndexOf("This") << endl;  // -1
	cout << s6.LastIndexOf("") << endl;   // 5
	cout << s6.LastIndexOf("He") << endl;   // 0

	MyString s62("");
	cout << s62.LastIndexOf("") << endl;  // 0
	cout << s62.LastIndexOf("A") << endl; // -1

	MyString s63("Hellello");
	MyString s64("Heloo");
	cout << s63.LastIndexOf("ell") << endl;   // 4
	cout << s64.LastIndexOf("ell") << endl;   // -1

	/* Interleave() Ex */
	cout << "-----------------------" << endl;
	cout << "Interleave()" << endl;
	MyString s7("Hello");
	s7.Interleave(" World");
	cout << s7.GetCString() << endl;  //H eWlolrold

	MyString s72("A");
	s72.Interleave("BCDEF");
	cout << s72.GetCString() << endl;  // ABCDEF

	MyString s73("bcdef");
	s73.Interleave("a");
	cout << s73.GetCString() << endl;  // bacdef

	/* RemoveAt() Ex */
	cout << "-----------------------" << endl;
	cout << "RemoveAt()" << endl;
	MyString s8("Hello");
	cout << boolalpha << s8.RemoveAt(0) << ", ";   // true,
	cout << s8.GetCString() << endl;               // ello
	cout << boolalpha << s8.RemoveAt(2) << ", ";   // true,
	cout << s8.GetCString() << endl;               // elo
	cout << boolalpha << s8.RemoveAt(4) << ", ";   // false,
	cout << s8.GetCString() << endl;               // elo

	MyString s82("");
	cout << boolalpha << s82.RemoveAt(0) << endl;  //false

	/* PadLeft() Ex */
	cout << "-----------------------" << endl;
	cout << "PadLeft()" << endl;
	MyString s9("Hello");
	s9.PadLeft(2);  // "Hello"
	cout << s9.GetCString() << endl;
	s9.PadLeft(8);  // "   Hello"
	cout << s9.GetCString() << endl;

	MyString s92("World");
	s92.PadLeft(3, '-');  // "World"
	cout << s92.GetCString() << endl;
	s92.PadLeft(7, '-');  // "--World"
	cout << s92.GetCString() << endl;

	/* PadRight() Ex */
	cout << "-----------------------" << endl;
	cout << "PadRight()" << endl;
	MyString s10("Hello");
	s10.PadRight(2);  // "Hello"
	cout << s10.GetCString() << endl;
	s10.PadRight(8);  // "Hello   "
	cout << s10.GetCString() << '|' << endl;// 공백 확인 위한 |

	MyString s102("World");
	s102.PadRight(3, '-');  // "World"
	cout << s102.GetCString() << endl;
	s102.PadRight(7, '-');  // "World--"
	cout << s102.GetCString() << endl;

	/* Reverse() Ex */
	cout << "-----------------------" << endl;
	cout << "Reverse()" << endl;
	MyString s11("Hello");
	s11.Reverse();  // olleH
	cout << s11.GetCString() << endl;

	MyString s112("Banana");
	s112.Reverse();   // ananaB
	cout << s112.GetCString() << endl;

	MyString s113("A");
	s113.Reverse();   // A
	cout << s113.GetCString() << endl;

	MyString s114("");
	s114.Reverse();   // 
	cout << s114.GetCString() << endl;

	/* operator== Ex */
	cout << "-----------------------" << endl;
	cout << "operator==" << endl;
	MyString s121("Hello");
	MyString s122("Hello");
	MyString s123("World");
	MyString s124("Hello ");

	cout << boolalpha << (s121 == s122) << endl;   // true
	cout << boolalpha << (s121 == s123) << endl;   // false
	cout << boolalpha << (s121 == s124) << endl;   // false

	/* ToLower() Ex */
	cout << "-----------------------" << endl;
	cout << "ToLower()" << endl;
	MyString s131("HEllo 123K");
	MyString s132("A To z");
	s131.ToLower();   // "hello 123k"
	s132.ToLower();   // "a to z"
	cout << s131.GetCString() << endl;
	cout << s132.GetCString() << endl;

	/* ToUpper() Ex */
	cout << "-----------------------" << endl;
	cout << "ToUpper()" << endl;
	MyString s141("HEllo 123K");
	MyString s142("A To z");
	s141.ToUpper();   // "HELLO 123K"
	s142.ToUpper();   // "A TO Z"
	cout << s141.GetCString() << endl;
	cout << s142.GetCString() << endl;
}

int main()
{
	test();

	//	메모리 체크용 변수
	int beforeAddress1;
	int beforeAddress2;

	MyString testString1("Happy Happy Days");
	MyString testString2("Happy Days");
	MyString testString3("Happy Days");
	MyString testString4("");

	//	Operator == 관련
	beforeAddress1 = (int)testString2.GetCString();
	beforeAddress2 = (int)testString3.GetCString();
	if (testString2 == testString3);
	assert(beforeAddress1 == (int)testString2.GetCString());
	assert(beforeAddress2 == (int)testString3.GetCString());
	cout << "D2_NoMallocInCompareSameLength 통과" << endl;

	beforeAddress1 = (int)testString1.GetCString();
	beforeAddress2 = (int)testString2.GetCString();
	if (testString1 == testString2);
	assert(beforeAddress1 == (int)testString1.GetCString());
	assert(beforeAddress2 == (int)testString2.GetCString());
	cout << "D5_NoMallocInCompareDifferentLength 통과" << endl;

	//	IndexOf, LastOfIndex 관련
	beforeAddress1 = (int)testString1.GetCString();
	testString1.IndexOf("Happy");
	testString1.IndexOf("");
	assert(beforeAddress1 == (int)testString1.GetCString());

	beforeAddress1 = (int)testString1.GetCString();
	testString1.LastIndexOf("Happy");
	testString1.LastIndexOf("");
	assert(beforeAddress1 == (int)testString1.GetCString());
	cout << "E5_NoMallocInIndexOf 통과" << endl;

	//	ToUpper, ToLower 관련
	beforeAddress1 = (int)testString1.GetCString();
	testString1.ToUpper();
	testString1.ToLower();
	assert(beforeAddress1 == (int)testString1.GetCString());
	cout << "F3_NoMallocInUpperLower 통과" << endl;

	//	Reverse 관련
	beforeAddress1 = (int)testString1.GetCString();
	testString1.Reverse();
	testString1.Reverse();
	assert(beforeAddress1 == (int)testString1.GetCString());
	beforeAddress1 = (int)testString4.GetCString();
	testString4.Reverse();
	assert(beforeAddress1 == (int)testString4.GetCString());
	cout << "G4_NoMallocInReverse 통과" << endl;

	//	Append 관련
	beforeAddress1 = (int)testString1.GetCString();
	testString1.Append("");
	assert(beforeAddress1 == (int)testString1.GetCString());
	cout << "H3_NoMallocInAppendEmpty 통과" << endl;

	//	 RemoveAt 관련
	beforeAddress1 = (int)testString4.GetCString();
	testString4.RemoveAt(0);
	assert(beforeAddress1 == (int)testString4.GetCString());
	cout << "J2_RemoveAtNoMallocOnEmpty 통과" << endl;

	//	PadLeft, PadRight 관련
	beforeAddress1 = (int)testString1.GetCString();
	testString1.PadLeft(16);
	testString1.PadLeft(16, '*');
	assert(beforeAddress1 == (int)testString1.GetCString());
	cout << "K4_NoMallocInPadLeftShorter 통과" << endl;

	beforeAddress1 = (int)testString1.GetCString();
	testString1.PadRight(16);
	testString1.PadRight(16, '*');
	assert(beforeAddress1 == (int)testString1.GetCString());
	cout << "L4_NoMallocInPadRightShorter 통과" << endl;

	//	InterLeave 관련

	beforeAddress1 = (int)testString1.GetCString();
	testString1.PadRight(16);
	testString1.PadRight(16, '*');
	assert(beforeAddress1 == (int)testString1.GetCString());
	cout << "L4_NoMallocInPadRightShorter 통과" << endl;

	//	InterLeave 관련
	beforeAddress1 = (int)testString1.GetCString();
	testString1.Interleave("");
	assert(beforeAddress1 == (int)testString1.GetCString());
	cout << "M3_NoMallocInInterleaveEmpty 통과" << endl;

	int a;
	std::cin >> a;
	return 0;
}

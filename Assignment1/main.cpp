#include "MyString.h"
#include <iostream>
using namespace std;
using namespace assignment1;
void test()
{
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


};
int main(void)
{
	test();
	int a,b;
	cin >> a;
	cin >> b;
	return 0;
}


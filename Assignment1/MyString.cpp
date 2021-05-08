#include "MyString.h"

namespace assignment1
{
	MyString::MyString(const char* s)
	{
		unsigned int flag = 0;
		while (1)//길이 확인
		{
			if (s[flag] == '\0')
			{
				break;
			}

			flag++;
		}
		mString = new char[flag + 1];

		for (unsigned int i = 0; i < flag; i++)
		{
			mString[i] = s[i];
		}

		mString[flag] = '\0';
		mLength = flag;

	}

	MyString::MyString(const MyString& other)
	{
		mLength = other.mLength;
		mString = new char[mLength + 1];

		for (unsigned int i = 0; i <= other.mLength; i++)
		{
			mString[i] = other.mString[i];
		}
	}

	MyString::~MyString()
	{
		delete[] mString;
	}

	unsigned int MyString::GetLength() const
	{
		return mLength;
	}

	const char* MyString::GetCString() const
	{
		return mString;
	}

	void MyString::Append(const char* s)
	{
		int flag = 0;//s의 문자열 개수 널문자 제외

		while (1)
		{
			if (s[flag] == '\0')
			{
				break;
			}

			flag++;
		}

		if (flag == 0)
		{
			return;
		}

		char* tem = new char[mLength + 1];

		for (size_t i = 0; i <= mLength; i++)
		{
			tem[i] = mString[i];
		}

		delete[] mString;

		mString = new char[mLength + flag + 1];

		for (size_t i = 0; i < mLength; i++)
		{
			mString[i] = tem[i];
		}

		for (size_t i = mLength; i < mLength + flag; i++)
		{
			mString[i] = s[i - mLength];
		}

		mString[mLength + flag] = '\0';

		delete[] tem;

		mLength = flag + mLength;

	}

	MyString MyString::operator+(const MyString& other) const
	{
		char* temArry = new char[other.mLength + mLength + 1];
		unsigned int totalSize = other.mLength + mLength;

		for (size_t i = 0; i < mLength; i++)
		{
			temArry[i] = mString[i];
		}

		for (size_t i = mLength; i < totalSize; i++)
		{
			temArry[i] = other.mString[i - mLength];
		}

		temArry[totalSize] = '\0';

		MyString str = MyString(temArry);
		delete[] temArry;
		return str;
	}

	int MyString::IndexOf(const char* s)
	{
		unsigned int sSize = 0;//문자 갯수

		while (1)
		{
			if (s[sSize] == '\0')
			{
				break;
			}

			sSize++;
		}

		if (sSize == 0)
		{
			return 0;
		}


		int flag = 0;

		for (size_t i = 0; i < mLength; i++)
		{
			if (s[0] == mString[i])
			{
				for (size_t j = 0; j < sSize; j++)
				{
					if (mString[i + j] != s[j])
					{
						flag = -1;
						break;
					}

				}

				if (flag != -1)
				{
					return i;
				}

				flag = 0;
			}
		}

		return -1;
	}

	int MyString::LastIndexOf(const char* s)
	{
		unsigned int sSize = 0;//문자 갯수

		while (1)
		{
			if (s[sSize] == '\0')
			{
				break;
			}
			sSize++;
		}

		if (sSize == 0)
		{
			return mLength;
		}

		int checkSIndexNum = -1;
		int flag = 0;

		for (size_t i = 0; i < mLength; i++)
		{
			if (s[0] == mString[i])
			{
				for (size_t j = 0; j < sSize; j++)
				{
					if (mString[i + j] != s[j])
					{
						flag = -1;
						break;
					}
				}

				if (flag != -1)
				{
					checkSIndexNum = i;
				}
				flag = 0;
			}
		}

		if (checkSIndexNum != -1)
		{
			return checkSIndexNum;
		}

		return -1;
	}

	void MyString::Interleave(const char* s)
	{

		unsigned int sSize = 0;//문자 갯수
		while (1)
		{
			if (s[sSize] == '\0')
			{
				break;
			}
			sSize++;
		}

		if (sSize == 0)
		{
			return;
		}

		if (mLength == 0)
		{
			mLength = sSize;
			mString = new char[sSize + 1];
			for (size_t i = 0; i <= sSize; i++)
			{
				mString[i] = s[i];
			}
			return;
		}


		char* tem = new char[mLength + 1];

		for (size_t i = 0; i <= mLength; i++)
		{
			tem[i] = mString[i];
		}

		delete[] mString;
		unsigned int totalSize = mLength + sSize;
		mString = new char[totalSize + 1];
		unsigned int temIndex = 0;
		unsigned int sIndex = 0;

		for (size_t i = 0; i < totalSize; i++)
		{
			if (i % 2 == 0)//짝수번에는 mString이 들어가야됨
			{
				if (temIndex <= mLength - 1)
				{
					mString[i] = tem[temIndex];
					temIndex++;
				}
				else
				{
					mString[i] = s[sIndex];
					sIndex++;
				}
			}

			else//s가 들어간다 단 개수가 안맞으면 딴거
			{
				if (sIndex < sSize)
				{
					mString[i] = s[sIndex];
					sIndex++;
				}
				else
				{
					mString[i] = tem[temIndex];
					temIndex++;
				}

			}
		}

		mString[totalSize] = '\0';
		delete[] tem;
		mLength = totalSize;





	}

	bool MyString::RemoveAt(unsigned int i)
	{
		if (i >= mLength)
		{
			return false;
		}

		char* tem = new char[mLength + 1];

		for (size_t i = 0; i <= mLength; i++)
		{
			tem[i] = mString[i];
		}

		delete[] mString;

		for (unsigned int j = 0; j < mLength - 1; j++)
		{
			if (j >= i)
			{
				tem[j] = tem[j + 1];
			}
		}

		mLength--;
		mString = new char[mLength + 1];

		for (size_t i = 0; i < mLength; i++)
		{
			mString[i] = tem[i];
		}

		mString[mLength] = '\0';
		delete[] tem;

		return true;
	}

	void MyString::PadLeft(unsigned int totalLength)
	{
		if (mLength < totalLength)
		{
			char* tem = new char[mLength];

			for (unsigned int i = 0; i < mLength; i++)
			{
				tem[i] = mString[i];
			}

			delete[] mString;

			mString = new char[totalLength + 1];

			for (unsigned int i = 0; i < totalLength - mLength; i++)
			{
				mString[i] = ' ';
			}
			int sNum = 0;

			for (unsigned int i = totalLength - mLength; i < totalLength; i++)
			{
				mString[i] = tem[sNum];
				sNum++;
			}

			mString[totalLength] = '\0';
			mLength = totalLength;
			delete[] tem;
		}
		else
			return;
	}

	void MyString::PadLeft(unsigned int totalLength, const char c)
	{
		if (mLength < totalLength)
		{
			char* tem = new char[mLength];

			for (unsigned int i = 0; i < mLength; i++)
			{
				tem[i] = mString[i];
			}
			delete[] mString;

			mString = new char[totalLength + 1];

			for (unsigned int i = 0; i < totalLength - mLength; i++)
			{
				mString[i] = c;
			}

			int sNum = 0;

			for (unsigned int i = totalLength - mLength; i < totalLength; i++)
			{
				mString[i] = tem[sNum];
				sNum++;
			}

			mString[totalLength] = '\0';
			mLength = totalLength;
			delete[] tem;
		}
		else
			return;
	}

	void MyString::PadRight(unsigned int totalLength)
	{
		if (mLength < totalLength)
		{
			char* tem = new char[mLength + 1];

			for (unsigned int i = 0; i <= mLength; i++)
			{
				tem[i] = mString[i];
			}
			delete[] mString;
			mString = new char[totalLength + 1];
			int gap = totalLength - mLength;

			for (unsigned int i = totalLength - 1; i >= totalLength - gap; i--)
			{
				mString[i] = ' ';
			}
			int sNum = mLength - 1;

			for (int i = totalLength - gap - 1; i >= 0; i--)
			{
				mString[i] = tem[sNum];
				sNum--;
			}

			mString[totalLength] = '\0';
			mLength = totalLength;
			delete[] tem;
		}
		else
			return;

	}

	void MyString::PadRight(unsigned int totalLength, const char c)
	{
		if (mLength < totalLength)
		{
			char* tem = new char[mLength + 1];

			for (unsigned int i = 0; i <= mLength; i++)
			{
				tem[i] = mString[i];
			}

			delete[] mString;
			mString = new char[totalLength + 1];
			int gap = totalLength - mLength;

			for (unsigned int i = totalLength - 1; i >= totalLength - gap; i--)
			{
				mString[i] = c;
			}
			int sNum = mLength - 1;

			for (int i = totalLength - gap - 1; i >= 0; i--)
			{
				mString[i] = tem[sNum];
				sNum--;
			}

			mString[totalLength] = '\0';
			mLength = totalLength;
			delete[] tem;
		}
		else
			return;

	}

	void MyString::Reverse()
	{
		int endIndex = mLength - 1;
		int startIndex = 0;
		while (1)
		{
			char tem;

			if (endIndex <= startIndex)
			{
				break;
			}

			tem = mString[startIndex];
			mString[startIndex] = mString[endIndex];
			mString[endIndex] = tem;
			startIndex++;
			endIndex--;

		}
	}

	bool MyString::operator==(const MyString& rhs) const
	{
		bool bAnswer = true;

		if (mLength != rhs.mLength)
		{
			return false;
		}

		for (unsigned int i = 0; i < mLength; i++)
		{
			if (mString[i] != rhs.mString[i])
			{
				bAnswer = false;
				break;
			}
		}
		return bAnswer;
	}

	MyString& MyString::operator=(const MyString& rhs)
	{
		if (*this == rhs)
		{
			return *this;
		}

		delete[] mString;
		mLength = rhs.mLength;
		mString = new char[mLength + 1];

		for (size_t i = 0; i <= mLength; i++)
		{
			mString[i] = rhs.mString[i];
		}

		return *this;
	}

	void MyString::ToLower()
	{
		for (unsigned int i = 0; i < mLength; i++)
		{
			if (mString[i] >= 65 && mString[i] <= 90)
			{
				mString[i] = mString[i] + 32;
			}
		}
	}

	void MyString::ToUpper()
	{
		for (unsigned int i = 0; i < mLength; i++)
		{
			if (mString[i] >= 97 && mString[i] <= 122)
			{
				mString[i] = mString[i] - 32;
			}
		}
	}
}


#include "MyString.h"
#include<iostream>

using namespace std;
namespace assignment1
{
    MyString::MyString(const char* s)
    {
        unsigned int flage = 0;
        while (1)//길이 확인
        {
            if (s[flage] == '\0')
            {
                break;
            }

            flage++;
        }
        mString = new char[flage+1];

        for (unsigned int i = 0; i <= flage; i++)
        {
            mString[i] = s[i];
        }

        mLength = flage;
   
    }

    MyString::MyString(const MyString& other)
    {
        mLength = other.mLength;
        mString = new char[other.mLength + 1];
        for (unsigned int i = 0; i < other.mLength; i++)
        {
            mString[i] = other.mString[i];
        }
        mString[mLength] = other.mString[mLength];
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
        char* tem = new char[mLength+1];//널 문자 빼고 복사본
        for (unsigned int i = 0; i < mLength; i++)
        {
            tem[i] = mString[i];
        }
        tem[mLength] = '\0';

   
        delete[] mString;

        int flage = 0;//s의 문자열 개수 널문자 제외
        while (1)
        {
            if (s[flage] == '\0')
                break;

            flage++;
        }
         
        mString = new char[flage + mLength + 1];
        unsigned int i;

        for (i = 0; i < mLength; i++)
        {
            mString[i] = tem[i];
        }

        unsigned int j = 0;
        for (i = mLength; i < flage + mLength ; i++)
        {
            mString[i] = s[j];
            j++;
        }
 
        mString[flage + mLength] = '\0';
        mLength = flage + mLength;

        delete[] tem;

    }

    MyString MyString::operator+(const MyString& other) const
    {
   
        const int size = mLength + other.mLength + 1;
        char* tem = new char[size];
        int flage = mLength - 1;
        for (unsigned int i = 0; i < mLength; i++)
        {
            tem[i] = mString[i];
        }
        for (int i = mLength; i < size; i++)
        {
            tem[i] = other.mString[i - mLength];
        }

        tem[size] = '\0';
        char* fTem = tem;
        delete[] tem;
        return MyString(fTem);
    }

    int MyString::IndexOf(const char* s)
    {
        int answer = -1;
        int size = 0;
        while (1)//길이 확인
        {
            if (s[size] == '\0')
            {
                break;
            }
            size++;
        }
        int sNum = 0;

        for(unsigned int i = 0; i < mLength; i++)
        {
            if (mString[i] == s[sNum])
            {
                sNum = 0;
                for (unsigned int j = i; j < i + size; j++)
                {
                    if (mString[j] != s[sNum])
                    {
                        break;
                    }
                    if (j == (i + size - 1))
                    {
                        answer = i;
                        break;
                    }
                    sNum++;
                }
            }

            if (answer != -1)
                break;
        }

        return answer;
    }

    int MyString::LastIndexOf(const char* s)
    {
        int answer = -1;
        int size = 0;//s 문자열의 문자 갯수
        while (1)//길이 확인
        {
            if (s[size] == '\0')
            {
                break;
            }

            size++;
        }
        
 
        int sNum = size - 1;//s문자열의 마지막 문자 인덱스


        for (int i = mLength - 1; i >= 0; i--)//뒤에서부터 찾아 들어가
        {
            if (mString[i] == s[sNum])//젤 뒷 문자가 같으면 내부탐색 시작
            {
                sNum = size - 1;
                for (int j = i; j > (i - size); j--)
                {
                    if (s[sNum] != mString[j])
                    {
                        break;
                    }

                    if (sNum == 0)
                    {
                        answer = j;
                        break;
                    }
                    sNum--;
                }

            }
            if (answer != -1)
                break;
        }
        return answer;
    }

    void MyString::Interleave(const char* s)
    {
        char* tem = new char[mLength];//널 문자 빼고 복사본
        for (unsigned int i = 0; i < mLength; i++)
        {
            tem[i] = mString[i];
        }
        delete[] mString;

        unsigned int sSize = 0;//s의 문자열 개수 널문자 제외
        while (1)
        {
            if (s[sSize] == '\0')
                break;

            sSize++;
        }

        unsigned int size = mLength + sSize + 1;
        mString = new char[size];
        unsigned int mNum = 0;
        unsigned int sNum = 0;
        for (unsigned int i = 0; i < size + 2 ; i++)
        {
            if (i % 2 == 0)//짝수
            {
                if (mNum > mLength - 1)
                {
                    mString[i] = s[sNum];
                    sNum++;
                }
                else
                {
                    mString[i] = tem[mNum];
                    mNum++;
                }
            }
            else//홀수
            {
                if (sNum > sSize - 1)
                {
                    mString[i] = tem[mNum];
                    mNum++ ;
                }
                else
                {
                    mString[i] = s[sNum];
                    sNum++;
                }
            }
        }
        mLength = size - 1;
        mString[size - 1] = '\0';
    }

    bool MyString::RemoveAt(unsigned int i)
    {
        if (i >=  mLength)
            return false;

        for (unsigned int j = 0; j < mLength - 1; j++)
        {
            if (j >= i)
            {
                mString[j] = mString[j + 1];
            }
        }

        char* tem = new char[mLength];

        for (unsigned int i = 0; i < mLength - 1; i++)
        {
            tem[i] = mString[i];
        }
        tem[mLength - 1] = '\0';

        delete[] mString;
        mLength--;
        mString = new char[mLength + 1];
        for (unsigned int i = 0; i < mLength; i++)
        {
            mString[i] = tem[i];
        }
        mString[mLength] = '\0';
        delete[] tem;

        return false;
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

            unsigned int sNum = 0;
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
            char* tem = new char[mLength];
            for (unsigned int i = 0; i < mLength; i++)
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
            char* tem = new char[mLength];
            for (unsigned int i = 0; i < mLength; i++)
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
        bool answer = true;
        if (mLength != rhs.mLength)
            return false;
        for (unsigned int i = 0; i < mLength; i++)
        {
            if (mString[i] != rhs.mString[i])
            {
                answer = false;
                break;
            }
        }
        return answer;
    }

    MyString& MyString::operator=(const MyString& rhs)
    {
        delete[] mString;
        mLength = rhs.mLength;
        mString = new char[mLength];

        for (size_t i = 0; i < mLength; i++)
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
            if (mString[i] >= 97 && mString[i] <= 122 )
            {
                mString[i] = mString[i] - 32;
            }
        }
    }
}
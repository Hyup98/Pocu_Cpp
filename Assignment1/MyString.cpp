#include "MyString.h"
#include <stdlib.h>

using namespace std;
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
                break;

            flag++;
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
    /* +연산자는 한번 더 확인 필요함 반환형에 대한 이해 부족*/
    MyString MyString::operator+(const MyString& other) const
    {
        unsigned int size = mLength + other.mLength + 1;
        char* string = (char*)malloc(sizeof(char) * size);

        for (size_t i = 0; i < mLength ; i++)
        {
            string[i] = mString[i];
        }

        for (size_t i = mLength; i < size - 1; i++)
        {
            string[i] = other.mString[i];
        }
   
        string[size - 1] = '\0';
        
        return MyString(string);
    }

    int MyString::IndexOf(const char* s)
    {
        int answer = -1;
        unsigned int size = 0;
        while (1)//길이 확인
        {
            if (s[size] == '\0')
            {
                break;
            }
            size++;
        }

        if (size == 0)
            return 0;

        unsigned int sNum = 0;

        for(unsigned int i = 0; i < mLength; i++)
        {
            if (mString[i] == s[sNum])
            {
                for (unsigned int j = i; j < i + size; j++)
                {
                    if (mString[j] != s[sNum])
                    {
                        sNum = 0;
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
        unsigned int size = 0;//s 문자열의 문자 갯수
        while (1)//길이 확인
        {
            if (s[size] == '\0')
            {
                break;
            }

            size++;
        }
        
        if (size == 0)
        {
            return -1;
        }
 
        unsigned int sNum = size - 1;//s문자열의 마지막 문자 인덱스


        for (int i = mLength - 1; i >= 0; i--)//뒤에서부터 찾아 들어가
        {
            if (mString[i] == s[sNum])//젤 뒷 문자가 같으면 내부탐색 시작
            {
                sNum = size - 1;
                for (unsigned int j = i; j > (i - size); j--)
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
        unsigned int sSize = 0;//s의 문자열 개수 널문자 제외
        while (1)
        {
            if (s[sSize] == '\0')
                break;

            sSize++;
        }

        if (sSize == 0)
        {
            return;
        }

        char* tem = new char[mLength + 1];//널 문자 빼고 복사본

        for (unsigned int i = 0; i <= mLength; i++)
        {
            tem[i] = mString[i];
        }

        unsigned int size = mLength + sSize + 1;
        mString = new char[size];
        unsigned int mNum = 0;
        unsigned int sNum = 0;

        for (unsigned int i = 0; i < size - 1  ; i++)
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
        delete[] tem;
    }

    bool MyString::RemoveAt(unsigned int i)
    {
        if (i >= mLength)
            return false;

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

        for (size_t i = 0; i < mLength ; i++)
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
            char* tem =new char[mLength + 1];
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
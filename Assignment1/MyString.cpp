#include "MyString.h"
#include <stdlib.h>

using namespace std;
namespace assignment1
{
    MyString::MyString(const char* s)
    {
        unsigned int flag = 0;
        while (1)//���� Ȯ��
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
        int flag = 0;//s�� ���ڿ� ���� �ι��� ����
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
    /* +�����ڴ� �ѹ� �� Ȯ�� �ʿ��� ��ȯ���� ���� ���� ����*/
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

        unsigned int sSize = 0;//���� ����
        while (1)
        {
            if (s[sSize] == '\0')
                break;

            sSize++;
        }

        if (sSize == 0)
            return 0;


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
        unsigned int sSize = 0;//���� ����
        while (1)
        {
            if (s[sSize] == '\0')
                break;

            sSize++;
        }

        if (sSize == 0)
            return mLength;

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
            return checkSIndexNum;

        return -1;
    }

    void MyString::Interleave(const char* s)
    {
        unsigned int sSize = 0;//s�� ���ڿ� ���� �ι��� ����
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

        char* tem = new char[mLength + 1];//�� ���� ���� ���纻

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
            if (i % 2 == 0)//¦��
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
            else//Ȧ��
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
            if (mString[i] >= 97 && mString[i] <= 122 )
            {
                mString[i] = mString[i] - 32;
            }
        }
    }
}
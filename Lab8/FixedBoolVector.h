#pragma once

#include<cmath>
#include <iostream>
#include<bitset>
#include"FixedVector.h"

using namespace std;

namespace lab8
{
	
	template<size_t N>
	class FixedVector<bool, N>
	{
	public:
		FixedVector();
		bool Add(bool data);
		bool Remove(bool data);
		const bool& Get(unsigned  int i);
		int GetIndex(bool data);
		const bool& operator[](unsigned int i);
		size_t GetSize() const;
		size_t GetCapacity() const;

	private:
		size_t mSize;
		uint32_t mArray[N / 32 + 1] = { 0, };
	};

	template<size_t N>
	FixedVector<bool, N>::FixedVector()
		: mSize(0)
	{
	}

	template<size_t N>
	size_t FixedVector<bool, N>::GetCapacity() const
	{
		return N;
	}

	template<size_t N>
	size_t FixedVector<bool, N>::GetSize() const
	{
		return mSize;
	}

	template<size_t N>
	bool FixedVector<bool, N>::Add(bool data)
	{
		if (mSize < N)
		{
			unsigned int tem = (mSize) / 32;
			if (data)
			{
				mArray[tem] |= (1 << mSize++%32);
				cout << mSize << "   ->" << bitset<32>(mArray[tem]) << endl;
			}
			else
			{
				mArray[tem] &= ~(1 << mSize++&32);
				cout << mSize << "   ->" << bitset<32>(mArray[tem]) << endl;
			}
			return true;
		}
		else
		{
			return false;
		}
	}

	template<size_t N>
	bool FixedVector<bool, N>::Remove(bool data)
	{
		if (data == true)
		{
			int tem = 1;
		}
		else
		{
			int tem = 0;
		}

		if (data == true)
		{
			unsigned int index = (mSize) % 32;

			for (size_t i = 0; i <= mSize; i++)
			{
				if ((mArray[index] &= (1 << i)) != 0)
				{
					FixedVector save;
					for (size_t k = 0; k < i; k++)
					{
						save.Add(Get(k));
					}
					mArray[index] >> (i + 1);
					for (size_t j = 0; j < i; j++)
					{
						Add(save.Get(i - j - 1));
					}
					return true;
				}
			}
			return false;
		}
		else
		{
			unsigned int index = (mSize) % 32;
			for (size_t i = 0; i <= mSize; i++)
			{
				if ((mArray[index] &= (1 << i)) == 0)
				{
					FixedVector save;
					for (size_t k = 0; k < i; k++)
					{
						save.Add(Get(k));
					}
					mArray[index] >> (i + 1);
					for (size_t j = 0; j < i; j++)
					{
						Add(save.Get(i - j - 1));
					}
					return true;
				}
			}
		}
		return false;
	}

	template<size_t N>
	const bool& FixedVector<bool, N>::Get(unsigned  int i)
	{
		unsigned int index = (mSize) / 32;
		if ((mArray[index] & (1 << i)) == 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	template<size_t N>
	const bool& FixedVector<bool, N>::operator[](unsigned  int i)
	{
		unsigned int index = (mSize) / 32;
		if ((mArray[index] &= (1 << i)) == 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	template<size_t N>
	int FixedVector<bool, N>::GetIndex(bool data) 
	{
		int index = 0;
		for (int i = mSize / 32; i >= 0; i--)
		{
			if (data == true)
			{
				for (size_t j = 0; j <= mSize; j++)
				{
					if ((mArray[i] &= (1 << j)) != 0)
					{
						return index;
					}
					index++;
				}
			}
			else
			{
				for (size_t j = 0; j <= mSize; j++)
				{
					if ((mArray[i] &= (1 << j)) == 0)
					{
						return index;
					}
					index++;
				}
			}
		}
		return -1;
	}
};

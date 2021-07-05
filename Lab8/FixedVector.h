#pragma once

#include <iostream>

namespace lab8
{
	template<typename T, size_t N>
	class FixedVector
	{
	public:
		FixedVector();
		bool Add(const T& data);
		bool Remove(const T& data);
		const T& Get(unsigned  int i) const;
		int GetIndex(const T& data) const;
		T& operator[](unsigned int i);
		size_t GetSize() const;
		size_t GetCapacity() const;

	private:
		size_t mSize;
		T mArray[N];
	};

	template<typename T, size_t N>
	FixedVector<T, N>::FixedVector()
		: mSize(0)
	{
	}

	template<typename T, size_t N>
	size_t FixedVector<T, N>::GetCapacity() const
	{
		return N;
	}

	template<typename T, size_t N>
	size_t FixedVector<T, N>::GetSize() const
	{
		return mSize;
	}

	template<typename T, size_t N>
	bool FixedVector<T, N>::Add(const T& data)
	{
		if (mSize < N)
		{
			mArray[mSize] = data;
			mSize++;
			return true;
		}
		else
		{
			return false;
		}
	}

	template<typename T, size_t N>
	bool FixedVector<T, N>::Remove(const T& data)
	{
		for (size_t i = 0; i < mSize; i++)
		{
			if (mArray[i] == data)
			{
				for (size_t j = i; j < mSize - 1; j++)
				{
					mArray[j] = mArray[j + 1];
				}
				mSize--;
				return true;
			}
		}
		return false;
	}

	template<typename T, size_t N>
	const T& FixedVector<T, N>::Get(unsigned  int i) const
	{

		return mArray[i];
	}

	template<typename T, size_t N>
	T& FixedVector<T, N>::operator[](unsigned  int i)
	{
		return mArray[i];
	}

	template<typename T, size_t N>
	int FixedVector<T, N>::GetIndex(const T& data) const
	{
		for (size_t i = 0; i <= mSize; i++)
		{
			if (mArray[i] == data)
			{
				return i;
			}
		}
		return -1;
	}

}
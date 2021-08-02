#pragma once

#include <bitset>


namespace lab8
{
	template<size_t N>
	class FixedVector<bool, N>
	{
	public:
		FixedVector();

		bool Add(const bool& b);
		bool Remove(const bool& b);
		const bool Get(unsigned int index) const;
		const bool operator[](unsigned int index) const;
		int GetIndex(const bool& b) const;
		size_t GetSize() const;
		size_t GetCapacity() const;

	private:
		size_t mSize;
		std::bitset<N> mArray;
	};

	template<size_t N>
	FixedVector<bool, N>::FixedVector()
		: mSize(0)
	{
	}

	template<size_t N>
	bool FixedVector<bool, N>::Add(const bool& b)
	{
		if (mSize >= N)
		{
			return false;
		}
		else
		{
			mArray[mSize++] = b;
			return true;
		}
	}

	template<size_t N>
	bool FixedVector<bool, N>::Remove(const bool& b)
	{
		for (unsigned int i = 0; i < mSize; i++)
		{
			if (mArray[i] == b)
			{
				for (; i < mSize - 1; i++)
				{
					mArray[i] = mArray[i + 1];
				}
				--mSize;
				return true;
			}
		}
		return false;
	}

	template<size_t N>
	const bool FixedVector<bool, N>::Get(unsigned int index) const
	{
		return mArray[index];
	}

	template<size_t N>
	const bool FixedVector<bool, N>::operator[](unsigned int index) const
	{
		return mArray[index];
	}

	template<size_t N>
	int FixedVector<bool, N>::GetIndex(const bool& b) const
	{
		for (unsigned int i = 0; i < mSize; i++)
		{
			if (mArray[i] == b)
			{
				return i;
			}
		}
		return -1;
	}

	template<size_t N>
	size_t FixedVector<bool, N>::GetSize() const
	{
		return mSize;
	}

	template<size_t N>
	size_t FixedVector<bool, N>::GetCapacity() const
	{
		return N;
	}
}
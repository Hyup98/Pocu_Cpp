#pragma once

#include <iostream>

namespace lab8
{
	template<typename T, size_t N>
	class FixedBoolVector
	{
	public:
		FixedBoolVector();
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

	template<size_t N>
	class FixedBoolVector<bool, N>
	{
	public:
		FixedBoolVector();
		bool Add(bool data);
		bool Remove(bool data);
		const bool& Get(unsigned  int i) const;
		int GetIndex(bool data) const;
		const bool& operator[](unsigned int i);
		size_t GetSize() const;
		size_t GetCapacity() const;

	private:
		size_t mSize;
		int mArray;
	};

	template<size_t N>
	FixedBoolVector<bool, N>::FixedBoolVector()
		: mSize(0)
		, mArray(0)
	{
	}

	template<size_t N>
	size_t FixedBoolVector<bool, N>::GetCapacity() const
	{
		return N;
	}

	template<size_t N>
	size_t FixedBoolVector<bool, N>::GetSize() const
	{
		return mSize;
	}

	template<size_t N>
	bool FixedBoolVector<bool, N>::Add(bool data)
	{
		if (mSize < N)
		{
			if (data)
			{
				mArray |= (1 << mSize++);
			}
			else
			{
				mArray &= ~(1 << mSize++);
			}
			return true;
		}
		else
		{
			return false;
		}
	}

	template<size_t N>
	bool FixedBoolVector<bool, N>::Remove(bool data)
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
			for (size_t i = 0; i <= mSize; i++)
			{
				if ((mArray &= (1 << i)) != 0)
				{
					FixedBoolVector save;
					for (size_t k = 0; k < i; k++)
					{
						save.Add(Get(k));
					}
					mArray >> (i + 1);
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
			for (size_t i = 0; i <= mSize; i++)
			{
				if ((mArray &= (1 << i)) == 0)
				{
					FixedBoolVector save;
					for (size_t k = 0; k < i; k++)
					{
						save.Add(Get(k));
					}
					mArray >> (i + 1);
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
	const bool& FixedBoolVector<bool, N>::Get(unsigned  int i) const
	{
		if ((mArray &= (1 << i)) == 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	template<size_t N>
	const bool& FixedBoolVector<bool, N>::operator[](unsigned  int i)
	{
		if ((mArray &= (1 << i)) == 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	template<size_t N>
	int FixedBoolVector<bool, N>::GetIndex(bool data) const
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
			for (size_t i = 0; i <= mSize; i++)
			{
				if ((mArray &= (1 << i)) != 0)
				{
					return i;
				}
			}
			return -1;
		}
		else
		{
			for (size_t i = 0; i <= mSize; i++)
			{
				if ((mArray &= (1 << i)) == 0)
				{
					return i;
				}
			}
		}
		return -1;
	}
};

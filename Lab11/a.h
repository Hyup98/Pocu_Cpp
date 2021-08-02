#pragma once
//
// Created by Dongsun Kim on 2021-07-31.
//

#pragma once

#include <memory>

namespace lab11
{
	template<typename T>
	class Storage
	{
	public:
		Storage(unsigned int length);
		Storage(unsigned int length, const T& initialValue);
		Storage(const Storage<T>& other);
		Storage(Storage<T>&& other);

		Storage<T>& operator=(const Storage<T>& other);
		Storage<T>& operator=(Storage<T>&& other);
		bool Update(unsigned int index, const T& data);
		const std::unique_ptr<T[]>& GetData() const;
		unsigned int GetSize() const;
		std::unique_ptr<T[]> mArray;
	private:

		size_t mLength;
	};

	template<typename T>
	Storage<T>::Storage(unsigned int length)
		: mLength(length)
	{
		mArray = std::make_unique<T[]>(length);
	}

	template<typename T>
	Storage<T>::Storage(unsigned int length, const T& initialValue)
		: mLength(length)
	{
		mArray = std::make_unique<T[]>(length);
		for (unsigned int i = 0; i < mLength; ++i)
		{
			mArray[i] = initialValue;
		}
	}

	template<typename T>
	Storage<T>::Storage(const Storage<T>& other)
		: mLength(other.GetSize())
		, mArray(other.GetSize() ? std::make_unique<T[]>(other.GetSize()) : nullptr)
	{
		if (mArray)
		{
			for (unsigned int i = 0; i < mLength; ++i)
			{
				mArray[i] = other.mArray[i];
			}
		}
	}

	template<typename T>
	Storage<T>::Storage(Storage<T>&& other)
		: mLength(other.GetSize())
		, mArray(std::move(other.mArray))
	{
		other.mArray = nullptr;
		other.mLength = 0;
	}

	template<typename T>
	Storage<T>& Storage<T>::operator=(const Storage<T>& other)
	{
		if (this != &other)
		{
			mArray.reset();
			mArray = std::make_unique<T[]>(other.GetSize());
			mLength = other.GetSize();
			for (unsigned int i = 0; i < mLength; ++i)
			{
				mArray[i] = other.mArray[i];
			}
		}
		return *this;
	}

	template<typename T>
	Storage<T>& Storage<T>::operator=(Storage<T>&& other)
	{
		if (this != &other)
		{
			mArray.reset();
			mArray = std::move(other.mArray);
			mLength = other.GetSize();
			other.mArray = nullptr;
			other.mLength = 0;
		}
		return *this;
	}

	template<typename T>
	bool Storage<T>::Update(unsigned int index, const T& data)
	{
		if (index < this->GetSize())
		{
			mArray[index] = data;
			return true;
		}
		return false;
	}

	template<typename T>
	const std::unique_ptr<T[]>& Storage<T>::GetData() const
	{
		return std::move(mArray);
	}

	template<typename T>
	unsigned int Storage<T>::GetSize() const
	{
		return mLength;
	}
}
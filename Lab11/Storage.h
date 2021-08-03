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
		Storage(Storage&& other);
		Storage(const Storage& storage);

		Storage<T>& operator=(Storage&& other);
		Storage<T>& operator=(const Storage& other);
		bool Update(unsigned int index, const T& data);
		const std::unique_ptr<T[]>& GetData() const;
		unsigned int GetSize() const;

	private:
		std::unique_ptr<T[]> mArray;
		unsigned int mArraySize;
	};

	template<typename T>
	Storage<T>::Storage(unsigned int length)
		: mArraySize(length)
	{
		mArray = std::make_unique<T[]>(mArraySize);
	}

	template<typename T>
	Storage<T>::Storage(unsigned int length, const T& initialValue)
		: mArraySize(length)
	{
		
		mArray = std::make_unique<T[]>(mArraySize);
		for (int i = 0; i < mArraySize; i++)
		{
			mArray[i] = initialValue;
		}

	}

	template<typename T>
	Storage<T>::Storage(const Storage& storage)
		:mArraySize(storage.mArraySize)
	{
		mArray = std::make_unique<T[]>(mArraySize);
		for (size_t i = 0; i < mArraySize; i++)
		{
			mArray[i] = storage.mArray[i];
		}
	}
	
	
	template<typename T>
	Storage<T>::Storage(Storage<T>&& other)
	{
		mArray = std::move(other.mArray);
		mArraySize = other.mArraySize;
		other.mArraySize = 0;
	}

	template<typename T>
	Storage<T>& Storage<T>::operator=(Storage&& other)
	{
		if (this == &other)
		{
			return *this;
		}

		mArray.reset();

		mArray = std::move(other.mArray);
		
		mArraySize = other.mArraySize;
		other.mArraySize = 0;
		return this;
	}

	template<typename T>
	Storage<T>& Storage<T>::operator=(const Storage& other)
	{
		if (this == &other)
		{
			return *this;
		}

		mArray.reset();

		mArraySize = other.mArraySize;
		mArray = std::move(other.mArray);

		other.mArraySize = 0;

		return *this;
	}

	template<typename T>
	bool Storage<T>::Update(unsigned int index, const T& data)
	{
		if (index < mArraySize)
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
		return mArraySize;
	}
}
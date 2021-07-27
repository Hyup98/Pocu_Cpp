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

		void operator=(Storage&& other);
		bool Update(unsigned int index, const T& data);
		const std::unique_ptr<T[]>& GetData() const;
		unsigned int GetSize() const;
		std::unique_ptr<T[]> mArray;
		//std::unique_ptr<T[]> temp = std::make_unique<T[]>(mArraySize);
		//T* mArray;
		unsigned int mArraySize;
	};

	template<typename T>
	Storage<T>::Storage(unsigned int length)
		: mArraySize(length)
	{
		mArray = std::make_unique<T[]>(mArraySize);
		for (int i = 0; i < mArraySize; i++)
		{
			mArray[i] = 0;
		}
		//memset(mArray, 0, length * sizeof(T));
	}

	template<typename T>
	Storage<T>::Storage(unsigned int length, const T& initialValue)
		: mArraySize(length)
	{
		/*
		mArray = new T[length];
		memset(mArray, initialValue, length * sizeof(T));
		*/
		mArray = std::make_unique<T[]>(mArraySize);
		for (int i = 0; i < mArraySize; i++)
		{
			mArray[i] = initialValue;
		}

	}
	
	/*
	template<typename T>
	Storage<T>::Storage(Storage&& other)
		: mArray(other.mArray)
		, mArraySize(other.mArraySize)
	{
		/*
		other.mArray = nullptr;
		other.mArraySize = 0;
		
		mArray = std::move(other.mArray)
		for (int i = 0; i < mArraySize; i++)
		{
			mArray[i] = 0;
		}
	}
	*/
	
	template<typename T>
	Storage<T>::Storage(Storage&& other)
	{
		mArray = std::move(other.mArray);
		mArraySize = other.mArraySize;
		other.mArraySize = 0;
	}

	/*
	template<typename T>
	void Storage<T>::operator=(Storage&& other)
	{
		mArraySize = other.GetSize;
		delete mArray;
		mArray = other.mArray;
		other.mArray = nullptr;
		other.mArraySize = 0;
	}
	*/
	template<typename T>
	void Storage<T>::operator=(Storage&& other)
	{
		mArray = std::move(other.mArray);
		mArraySize = other.mArraySize;
		other.mArraySize = 0;
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

	/*
	template<typename T>
	const std::unique_ptr<T[]>& Storage<T>::GetData() const
	{
		std::unique_ptr<T[]> temp = std::make_unique<T[]>(mArraySize);
		for (int i = 0; i < mArraySize; i++)
		{
			temp[i] = mArray[i];
		}
		
		return std::move(temp);
	}
	*/
	template<typename T>
	const std::unique_ptr<T[]>& Storage<T>::GetData() const
	{
		return mArray;
	}

	template<typename T>
	unsigned int Storage<T>::GetSize() const
	{
		return mArraySize;
	}
}
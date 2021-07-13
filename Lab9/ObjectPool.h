#pragma once
#include<memory>
#include<queue>

namespace lab9
{
	template<class T>
	class ObjectPool
	{
	public:
		ObjectPool(size_t maxPoolSize);
		~ObjectPool();
		T* Get();
		void Return(T* input);
		size_t GetFreeObjectCount();
		size_t GetMaxFreeObjectCount();

	private:
		size_t mMaxPoolSize;
		std::queue<T*> mObjects;
		unsigned int mObjectSize;
	};



	template<class T>
	ObjectPool<T>::ObjectPool(size_t maxPoolSize)
		: mMaxPoolSize(maxPoolSize)
		, mObjectSize(0)
	{
	}

	template<class T>
	ObjectPool<T>::~ObjectPool()
	{
		for (size_t i = 0; i < mObjects.size(); i++)
		{
			delete mObjects.front();
			mObjects.pop();
		}
	}

	template<class  T>
	T* ObjectPool<T>::Get()
	{
		if (mObjectSize == 0)
		{
			T* tem = new T();
			return tem;
		}
		else
		{
			mObjectSize--;
			T* tem = mObjects.front();
			mObjects.pop();
			return tem;
		}
	}

	template<class T>
	void ObjectPool<T>::Return(T* input)
	{
		if (mObjectSize == mMaxPoolSize)
		{
			delete input;
		}
		else
		{
			mObjectSize++;
			mObjects.push(input);
		}
	}

	template<class T>
	size_t ObjectPool<T>::GetFreeObjectCount()
	{
		return mObjectSize;
	}

	template<class T>
	size_t ObjectPool<T>::GetMaxFreeObjectCount()
	{
		return mMaxPoolSize;
	}


}
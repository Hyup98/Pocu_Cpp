#pragma once
#include<queue>
#include<cmath>
#include<limits>


using namespace std;

namespace assignment3
{
	template<typename T>
	class SmartQueue
	{
	public:
		SmartQueue();
		//대입연산자 소멸자 대입연산자 작성 보류
		void Enqueue(T data);
		T Dequeue();
		T Peek();
		T GetMax();
		T GetMin();
		double GetAverage();
		T GetSum();
		double GetVariance();
		T GetStandardDeviation();
		unsigned int GetCount();

	private:
		queue<T> mQueue;
		T mMax;
		T mMin;
	};

	template<typename T>
	SmartQueue<T>::SmartQueue()
	{
	}

	template<typename T>
	void SmartQueue<T>::Enqueue(T data)
	{
		if (mQueue.size() == 0)
		{
			mMax = data;
			mMin = data;
		}
		if (data > mMax)
		{
			mMax = data;
		}
		if (data < mMin)
		{
			mMin = data;
		}
		mQueue.push(data);
	}

	template<typename T>
	T SmartQueue<T>::Dequeue()
	{
		T tem = mQueue.front();
		mQueue.pop();

		queue<T> temQueue;
		while (!mQueue.empty())
		{
			temQueue.push(mQueue.front());
			mQueue.pop();
		}

		while (!temQueue.empty())
		{
			if (mQueue.size() == 0)
			{
				mMax = temQueue.front();
				mMin = temQueue.front();
			}
			if (temQueue.front() > mMax)
			{
				mMax = temQueue.front();
			}
			if (temQueue.front() < mMin)
			{
				mMin = temQueue.front();
			}
			mQueue.push(temQueue.front());
			temQueue.pop();
		}
		return tem;
	}

	template<typename T>
	T SmartQueue<T>::Peek()
	{
		return mQueue.front();
	}

	template<typename T>
	T SmartQueue<T>::GetMax()
	{
		if (mQueue.empty())
		{
			return std::numeric_limits<T>::lowest();
		}
		else
		{
			return mMax;
		}
	}
	template<typename T>
	T SmartQueue<T>::GetMin()
	{
		if (mQueue.empty())
		{
			return std::numeric_limits<T>::max();
		}
		else
		{
			return mMin;
		}
	}

	template<typename T>
	double SmartQueue<T>::GetAverage()
	{
		T tem = GetSum();
		tem /= mQueue.size();
		return static_cast<double>(tem);
	}

	template<typename T>
	T SmartQueue<T>::GetSum()
	{
		T tem = 0;
		queue<T> temQueue;
		while (!mQueue.empty())
		{
			tem += mQueue.front();
			temQueue.push(mQueue.front());
			mQueue.pop();
		}

		while (!temQueue.empty())
		{
			mQueue.push(temQueue.front());
			temQueue.pop();
		}

		return static_cast<double>(tem);
	}

	template<typename T>
	double SmartQueue<T>::GetVariance()
	{
		queue<T> temQueue;
		T tem = 0;
		while (!mQueue.empty())
		{
			tem += mQueue.front() * mQueue.front();
			temQueue.push(mQueue.front());
			mQueue.pop();
		}
		while (!temQueue.empty())
		{
			mQueue.push(temQueue.front());
			temQueue.pop();
		}
		tem /= mQueue.size();
		tem -= GetAverage() * GetAverage();
		return static_cast<double>(tem);
	}

	template<typename T>
	T SmartQueue<T>::GetStandardDeviation()
	{
		return sqrt(GetVariance());
	}

	template<typename T>
	unsigned int SmartQueue<T>::GetCount()
	{
		return mQueue.size();
	}


}
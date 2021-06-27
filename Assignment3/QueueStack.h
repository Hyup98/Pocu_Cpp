#pragma once
#include<queue>
#include<stack>
#include<limits>
#include<cmath>

using namespace std;

namespace assignment3
{
	template<typename T>
	class QueueStack
	{
	public:
		QueueStack(unsigned int size);
		void Enqueue(T data);
		T Peek();
		T Dequeue();
		T GetMax();
		T GetMin();
		double GetAverage();
		T GetSum();
		unsigned int GetCount();
		unsigned int GetStackCount();

	private:
		unsigned int mStackSize;
		stack<T> t;
		queue<stack<T>> mQueue;
		unsigned int mCount;
		unsigned int mStackCount;
		T mMax;
		T mMin;
	};

	template<typename T>
	QueueStack<T>::QueueStack(unsigned int size)
		: mStackSize(size)
		, mCount(0)
		, mStackCount(0)
	{
	}

	template<typename T>
	void QueueStack<T>::Enqueue(T data)
	{
		if (mQueue.size() == 0)
		{
			stack<T> tem;
			mQueue.push(tem);
			mQueue.back().push(data);
			mMax = data;
			mMin = data;
			mStackCount++;
		}
		else
		{
			if (mQueue.back().size() == mStackSize)
			{
				if (data > mMax)
				{
					mMax = data;
				}
				if (data < mMin)
				{
					mMin = data;
				}
				stack<T> tem;
				mQueue.push(tem);
				mQueue.back().push(data);
				mStackCount++;
				mCount++;
			}
			else
			{
				mQueue.back().push(data);
				mCount++;
			}
		}
	}

	template<typename T>
	T QueueStack<T>::Peek()
	{
		return mQueue.front().top();
	}

	template<typename T>
	T QueueStack<T>::Dequeue()
	{
		mStackCount = 0;
		mCount = 0;
		T tem = mQueue.front().top();
		mQueue.front().pop();
		
		queue<t> temQueue;

		while (!mQueue.empty())
		{
			stack<T> temStack;
			temQueue.push(temStack);
			while (!mQueue.front().empty())
			{
				temQueue.back().push(mQueue.front().top());
				mQueue.front().pop();
			}
			mQueue.front.pop();

		}

		while (!temQueue.empty())
		{
			if (mQueue.size() == 0)
			{
				mMax = temQueue.front().top();
				mMin = temQueue.front().top();
			}
			mStackCount++;
			stack<T> temStack;
			temQueue.push(temStack);
			
			while (!mQueue.front().empty())
			{
				if (temQueue.front().top() > mMax)
				{
					mMax = temQueue.front().top();
				}
				if (temQueue.front().top() < mMin)
				{
					mMin = temQueue.front().top();
				}
				mCount++;
				temQueue.back().push()(mQueue.front().top());
				mQueue.front().pop();
			}
		}

		return tem;

	}

	template<typename T>
	T QueueStack<T>::GetMax()
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
	T QueueStack<T>::GetMin()
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
	double QueueStack<T>::GetAverage()
	{
		T tem = GetSum();
		tem /= mCount;
		double a = static_cast<double>(tem);
		return a;
	}

	template<typename T>
	T QueueStack<T>::GetSum()
	{
		T tem = 0;
		queue<t> temQueue;

		while (!mQueue.empty())
		{
			stack<T> temStack;
			temQueue.push(temStack);
			while (!mQueue.front().empty())
			{
				tem += mQueue.front().top();
				temQueue.back().push(mQueue.front().top());
				mQueue.front().pop();
			}
			mQueue.front.pop();

		}

		while (!temQueue.empty())
		{
			stack<T> temStack;
			temQueue.push(temStack);
			while (!mQueue.front().empty())
			{
				temQueue.back().push()(mQueue.front().top());
				mQueue.front().pop();
			}
		}

		double a = static_cast<double>(tem);
		return a;
	}

	template<typename T>
	unsigned int QueueStack<T>::GetCount()
	{
		return mCount;
	}

	template<typename T>
	unsigned int QueueStack<T>::GetStackCount()
	{
		return mStackCount;
	}
}
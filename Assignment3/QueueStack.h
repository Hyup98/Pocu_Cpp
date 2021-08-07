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
		unsigned int mStackCount;
		queue<stack<T>> mQueue;
		unsigned int mCount;
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
			tem.push(data);
			mQueue.push(tem);
			mMax = data;
			mMin = data;
			mStackCount++;
			mCount++;
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
				tem.push(data);
				mQueue.push(tem);
				mCount++;
			}
			else
			{
				if (data > mMax)
				{
					mMax = data;
				}
				if (data < mMin)
				{
					mMin = data;
				}
				mQueue.back().push(data);
				mCount++;
				mStackCount++;
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
		/*
		mStackCount = 0;
		mCount = 0;
		T tem = mQueue.front().top();
		mQueue.front().pop();

		queue<stack<T>> temQueue;

		while (!mQueue.empty())
		{
			stack<T> temStack;
			temQueue.push(temStack);
			while (!mQueue.front().empty())
			{
				temQueue.back().push(mQueue.front().top());
				mQueue.front().pop();
			}
			mQueue.front().pop();

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
					mMax = static_cast<float>(temQueue.front().top());
				}
				if (temQueue.front().top() < mMin)
				{
					mMin = static_cast<float>(temQueue.front().top());
				}
				mCount++;
				temQueue.back().push(mQueue.front().top());
				mQueue.front().pop();
			}
		}
		*/
		T tem = mQueue.front().top();
		if (mQueue.front().size() == 1)
		{
			mStackCount--;
			mCount--;
			mQueue.pop();
			queue<stack<T>> temQueue;
			while (!mQueue.empty())
			{
				stack<T> temStack;
				temQueue.push(temStack);
				while (!mQueue.front().empty())
				{
					temQueue.back().push(mQueue.front().top());
					mQueue.front().pop();
				}
				mQueue.pop();

			}

			while (!temQueue.empty())
			{
				if (mQueue.size() == 0)
				{
					mMax = temQueue.front().top();
					mMin = temQueue.front().top();
				}

				stack<T> temStack;
				mQueue.push(temStack);

				while (!temQueue.front().empty())
				{
					if (temQueue.front().top() > mMax)
					{
						mMax = static_cast<float>(temQueue.front().top());
					}
					if (temQueue.front().top() < mMin)
					{
						mMin = static_cast<float>(temQueue.front().top());
					}
					mQueue.back().push(temQueue.front().top());
					temQueue.front().pop();
				}
				temQueue.pop();
			}
		}
		else
		{
			mCount--;
			mQueue.front().pop();
			queue<stack<T>> temQueue;
			while (!mQueue.empty())
			{
				stack<T> temStack;
				temQueue.push(temStack);
				while (!mQueue.front().empty())
				{
					temQueue.back().push(mQueue.front().top());
					mQueue.front().pop();
				}
				mQueue.pop();

			}


			while (!temQueue.empty())
			{
				if (mQueue.size() == 0)
				{
					mMax = temQueue.front().top();
					mMin = temQueue.front().top();
				}

				stack<T> temStack;
				mQueue.push(temStack);

				while (!temQueue.front().empty())
				{
					if (temQueue.front().top() > mMax)
					{
						mMax = static_cast<float>(temQueue.front().top());
					}
					if (temQueue.front().top() < mMin)
					{
						mMin = static_cast<float>(temQueue.front().top());
					}
					mQueue.back().push(temQueue.front().top());
					temQueue.front().pop();
				}
				temQueue.pop();
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
		double tem = GetSum();
		tem /= mCount;
		double a = static_cast<double>(tem);
		return a;
	}

	template<typename T>
	T QueueStack<T>::GetSum()
	{
		T tem = 0.0f;
		queue<stack<T>> temQueue;

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
			mQueue.pop();
		}

		while (!temQueue.empty())
		{
			stack<T> temStack;
			mQueue.push(temStack);
			while (!temQueue.front().empty())
			{
				mQueue.back().push(temQueue.front().top());
				temQueue.front().pop();
			}
			temQueue.pop();
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

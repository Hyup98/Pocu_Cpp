#pragma once
#include<stack>
#include<limits>
#include<cmath>

using namespace std;

namespace assignment3
{
	template<typename T>
	class SmartStack
	{
	public:
		SmartStack();
		//대입연산자 소멸자 대입연산자 작성 보류
		void Push(T data);
		T Pop();
		T Peek();
		T GetMax();
		T GetMin();
		double GetAverage();
		T GetSum();
		double GetVariance();
		T GetStandardDeviation();
		unsigned int GetCount();

	private:
		stack<T> mStack;
		T mMax;
		T mMin;
	};

	template<typename T>
	SmartStack<T>::SmartStack()
	{
	}

	template<typename T>
	void SmartStack<T>::Push(T data)
	{
		if (mStack.size() == 0)
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
		mStack.push(data);
	}

	template<typename T>
	T SmartStack<T>::Pop()
	{
		T tem = mStack.top();
		mStack.pop();

		stack<T> temStack;
		while (!mStack.empty())
		{
			temStack.push(mStack.top());
			mStack.pop();
		}
		while (!temStack.empty())
		{
			if (mStack.size() == 0)
			{
				mMax = temStack.top();
				mMin = temStack.top();
			}

			if (temStack.top() > mMax)
			{
				mMax = temStack.top();
			}

			if (temStack.top() < mMin)
			{
				mMin = temStack.top();
			}

			mStack.push(temStack.top());
			temStack.pop();
		}

		return tem;
	}

	template<typename T>
	T SmartStack<T>::Peek()
	{
		return mStack.top();
	}

	template<typename T>
	T SmartStack<T>::GetMax()
	{
		if (mStack.size() == 0)
		{
			return std::numeric_limits<T>::lowest();
		}
		else
		{
			return mMax;
		}
	}

	template<typename T>
	T SmartStack<T>::GetMin()
	{
		if (mStack.size() == 0)
		{
			return std::numeric_limits<T>::max();
		}
		else
		{
			return mMin;
		}
	}

	template<typename T>
	T SmartStack<T>::GetSum()
	{
		stack<T> temStack;
		T tem = 0;
		while (!mStack.empty())
		{
			tem += mStack.top();
			temStack.push(mStack.top());
			mStack.pop();
		}
		while (!temStack.empty())
		{
			mStack.push(temStack.top());
			temStack.pop();
		}

		double a = static_cast<double>(tem);
		return a;
	}

	template<typename T>
	double SmartStack<T>::GetAverage()
	{
		T tem = GetSum();
		tem /= mStack.size();
		double a = static_cast<double>(tem);
		return a;
	}

	

	template<typename T>
	double SmartStack<T>::GetVariance()
	{
		stack<T> temStack;
		T tem = 0;
		while (!mStack.empty())
		{
			tem += mStack.top() * mStack.top();
			temStack.push(mStack.top());
			mStack.pop();
		}
		while (!temStack.empty())
		{
			mStack.push(temStack.top());
			temStack.pop();
		}
		tem /= mStack.size();
		tem -= GetAverage() * GetAverage();
		double a = static_cast<double>(tem);
		return a;
	}

	template<typename T>
	T SmartStack<T>::GetStandardDeviation()
	{
		return sqrt(GetVariance());
	}

	template<typename T>
	unsigned int SmartStack<T>::GetCount()
	{
		return mStack.size();
	}
}
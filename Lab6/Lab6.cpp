#include "Lab6.h"

namespace lab6
{
	int Sum(const std::vector<int>& v)
	{
		if (v.size() == 0)
		{
			return 0;
		}
		int sum = 0;
		for (unsigned int i = 0; i < v.size(); i++)
		{
			sum += v[i];
		}
		return sum;
	}

	int Min(const std::vector<int>& v)
	{
		if (v.size() == 0)
		{
			return INT_MAX;
		}

		int min = v[0];

		for (unsigned int i = 0; i < v.size(); i++)
		{
			if (v[i] < min)
			{
				min = v[i];
			}
		}

		return min;
	}

	int Max(const std::vector<int>& v)
	{
		if (v.size() == 0)
		{
			return INT_MIN;
		}
		int max = v[0];

		for (unsigned int i = 0; i < v.size(); i++)
		{
			if (v[i] > max)
			{
				max = v[i];
			}
		}

		return max;
	}

	float Average(const std::vector<int>& v)
	{
		if (v.size() == 0)
		{
			return 0;
		}
		float ave = 0;

		for (unsigned int i = 0; i < v.size(); i++)
		{
			ave += v[i];
		}

		ave /= v.size();

		return ave;
	}

	int NumberWithMaxOccurrence(const std::vector<int>& v)
	{
		if (v.size() == 0)
		{
			return 0;
		}
		int* count = new int[v.size()]();
		
		for (unsigned int i = 0; i < v.size(); i++)
		{
			for (unsigned int j = 0; j < v.size(); j++)
			{
				if (v[i] == v[j])
				{
					count[i]++;
				}
			}
		}

		int index = 0;
		for (unsigned int i = 0; i < v.size(); i++)
		{
			if (count[i] > count[index])
			{
				index = i;
			}
		}

		delete[] count;
		return v[index];
	}

	void SortDescending(std::vector<int>& v)
	{
		/*
		if (v.size() == 0)
		{
			return;
		}
		*/
		int tem;
		for (unsigned int i = 0; i < v.size() - 1; i++)
		{
			for (unsigned int j = i + 1; j < v.size(); j++)
			{
				if (v[i] < v[j])
				{
					tem = v[i];
					v[i] = v[j];
					v[j] = tem;
				}
			}
		}
	}

}
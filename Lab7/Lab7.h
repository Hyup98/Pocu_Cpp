#pragma once

#include <iostream>
#include <vector>
#include <map>

namespace lab7
{
	template <typename K, class V>
	std::map<K, V> ConvertVectorsToMap(const std::vector<K>& keys, const std::vector<V>& values)
	{
		std::map<K, V> m;
		if (keys.size() > values.size())
		{
			for (size_t i = 0; i < values.size(); i++)
			{
				m.insert(std::pair<K, V>(keys[i], values[i]));
			}
			
		}

		else
		{
			for (size_t i = 0; i < keys.size(); i++)
			{
				m.insert(std::pair<K, V>(keys[i], values[i]));
			}
		}

		return m; 
	}

	template <typename K, class V>
	std::vector<K> GetKeys(const std::map<K, V>& m)
	{
		std::vector<K> v;
		for (auto iter = m.begin(); iter != m.end(); ++iter)
		{
			std::cout << iter->first;
			v.push_back(iter->first);
		}
		return v;
	}

	template <typename K, class V>
	std::vector<V> GetValues(const std::map<K, V>& m)
	{
		std::vector<V> v;
		for (auto iter = m.begin(); iter != m.end(); ++iter)
		{
			std::cout << iter->second;
			v.push_back(iter->second);
		}
		return v;
	}

	template <typename T>
	std::vector<T> Reverse(const std::vector<T>& v)
	{
		std::vector<T> rv;
		for (size_t i = v.size() - 1; i >= 0 ; i--)
		{
			rv.push_back(v[i]);
			if (i == 0)
			{
				break;
			}
		}
		return rv;
	}

	template <typename T>
	std::vector<T> operator+(const std::vector<T>& v1, const std::vector<T>& v2)
	{
		std::vector<T> combined;
		for (int i = 0; i < v1.size(); i++)
		{
			bool isThere = false;
			for (int j = i - 1; j >= 0; j--)
			{
				if (v1[i] == v1[j])
				{
					isThere == true;
				}
			}
			if (isThere == false)
			{
				combined.push_back(v1[i]);
			}
		}

		for (size_t i = 0; i < v2.size(); i++)
		{
			bool isThere = false;
			for (int j = i - 1; j >= 0; j--)
			{
				if (v2[i] == v2[j])
				{
					isThere == true;
				}
			}

			for (int k = 0; k < combined.size(); k++)
			{
				if (combined[i] == v2[i])
				{
					isThere = true;
				}
			}
			if (isThere == false)
			{
				combined.push_back(v2[i]);
			}
		}

		return combined;
	}

	template <typename K, class V>
	std::map<K, V> operator+(const std::map<K, V>& m1, const std::map<K, V>& m2)
	{
		std::map<K, V> combined(m1);
		for (auto iter1 = m2.begin(); iter1 != m2.end(); ++iter1)
		{
			bool isThere = false;
			for (auto iter2 = combined.begin(); iter2 != combined.end(); ++iter2)
			{
				if (iter1->first == iter2 -> first)
				{
					isThere = true;
				}
			}
			combined.insert(std::pair<K, V>(iter1->first, iter1->second));

		}

		return combined;
	}

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
	{
		for (size_t i = 0; i < v.size(); i++)
		{
			if (i == 0)
			{
				os << v[i];
			}
			else
			{
				os << ", " << v[i];
			}
		}
		return os;
	}

	template <typename K, class V>
	std::ostream& operator<<(std::ostream& os, const std::map<K, V>& m)
	{
		for (auto it = m.begin(); it != m.end(); ++it)
		{
			os << "{ ";
			os << it->first;
			os << ", ";
			os << it->second;
			os << " }" << std::endl;
		}
		return os;
	}
}
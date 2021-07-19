#pragma once

#include <memory>

namespace lab10
{
	template<typename T>
	class Node;

	template<typename T>
	class DoublyLinkedList
	{
	public:
		DoublyLinkedList();
		void Insert(std::unique_ptr<T> data);
		void Insert(std::unique_ptr<T> data, unsigned int index);
		bool Delete(const T& data);
		bool Search(const T& data) const;


		std::shared_ptr<Node<T>> operator[](unsigned int index) const;
		unsigned int GetLength() const;
	private:
		unsigned int mSize;
		std::shared_ptr<Node<T>> mRoot;
	};

	template<typename T>
	DoublyLinkedList<T>::DoublyLinkedList()
		: mSize(0)
	{
		mRoot = nullptr;
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data)
	{
		std::shared_ptr<Node<T>> temNode = std::make_shared<Node<T>>(std::move(data));
		if (mSize == 0)
		{
			mRoot = temNode;
			mSize++;
		}
		else
		{
			std::shared_ptr<Node<T>> tem = mRoot;
			while (true)
			{
				if (tem->Next == nullptr)
				{
					tem->Next = temNode;
					temNode->Previous = tem;
					mSize++;
					break;
				}
				tem = tem->Next;
			}
		}
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data, unsigned int index)
	{
		std::shared_ptr<Node<T>> temNode = std::make_shared<Node<T>>(std::move(data));
		if (index == 0 && mSize == 0)
		{
			mRoot = temNode;
			mSize++;
			return;
		}
		else if (index == 0)
		{
			std::shared_ptr<Node<T>> tem = mRoot;
			mRoot = temNode;
			mRoot->Next = tem;
			tem->Previous = mRoot;
			tem->Next = nullptr;
			mSize++;
			return;
		}
		else
		{
			std::shared_ptr<Node<T>> tem = mRoot;
			unsigned int count = 0;
			while (true)
			{
				if (count == index)
				{
					mSize++;
					std::shared_ptr<Node<T>> flag = tem;
					tem = temNode;
					tem->Next = flag;
					std::shared_ptr<Node<T>> front = mRoot;
					while (true)
					{
						if (front->Next == flag)
						{
							break;
						}
						front = front->Next;
					}
					front->Next = tem;
					tem->Previous = front;
					flag-> Previous = tem;
					return;
				}
				if (tem->Next == nullptr)
				{
					tem->Next = temNode;
					temNode->Previous = tem;
					mSize++;
					return;
				}
				tem = tem->Next;
				count++;
			}
		}
	}

	template<typename T>
	bool DoublyLinkedList<T>::Delete(const T& data)
	{
		if (mSize == 0)
		{
			return false;
		}
		bool bAnswer = false;
		std::shared_ptr<Node<T>> tem = mRoot;
		while (true)
		{
			if (*tem->Data == data)
			{
				bAnswer = true;
				if (tem == mRoot)
				{
					mRoot = tem->Next;
					tem->Next = nullptr;
					tem.reset();
					mSize--;
					break;
				}
				if (tem->Next == nullptr)
				{
					
					std::shared_ptr<Node<T>> front = mRoot;
					while (true)
					{
						if (front->Next == tem)
						{
							break;
						}
						front = front->Next;
					}
					front->Next = nullptr;
					
					tem.reset();
					mSize--;
					break;
				}
				std::shared_ptr<Node<T>> front = mRoot;
				while (true)
				{
					if (front->Next == tem)
					{
						break;
					}
					front = front->Next;
				}
				front->Next = tem->Next;
				tem->Next->Previous = front;
				tem->Next = nullptr;
				tem.reset();
				mSize--;
				break;
			}
			if (tem->Next == nullptr)
			{
				break;
			}
			tem = tem->Next;
		}
		return bAnswer;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Search(const T& data) const
	{
		if (mSize == 0)
		{
			return false;
		}
		std::shared_ptr<Node<T>> tem = mRoot;
		while (true)
		{
			if (*tem->Data == data)
			{
				return true;
			}

			if (tem->Next == nullptr)
			{
				break;
			}
			tem = tem->Next;
		}
		return false;

	}

	template<typename T>
	std::shared_ptr<Node<T>> DoublyLinkedList<T>::operator[](unsigned int index) const
	{
		if (mSize <= index)
		{
			return nullptr;
		}
		/*
		auto x = std::make_unique<T>();
		std::shared_ptr<Node<T>> temp = std::make_shared<Node<T>>(std::move(x));
		*/
		std::shared_ptr<Node<T>> tem = mRoot;
		int count = 0;
		while (true)
		{			
			if (count == index)
			{
				return tem;
			}
			if (tem->Next == nullptr)
			{
				break;
			}
			tem = tem->Next;
			count++;
		}
		return nullptr;
	}

	template<typename T>
	unsigned int DoublyLinkedList<T>::GetLength() const
	{
		return mSize;
	}
}
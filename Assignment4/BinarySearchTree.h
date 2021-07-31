#pragma once

#include <memory>
#include <vector>
#include <iostream>

namespace assignment4
{
	template<typename T>
	class TreeNode;

	template<typename T>
	class BinarySearchTree final
	{
	public:
		BinarySearchTree();
		void Insert(std::unique_ptr<T> data);
		bool Search(const T& data);
		bool Delete(const T& data);
		const std::weak_ptr<TreeNode<T>> GetRootNode() const;

		static std::vector<T> TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode);
		std::shared_ptr<TreeNode<T>> mRoot;

	};

	template<typename T>
	BinarySearchTree<T>::BinarySearchTree()
	{
		mRoot = nullptr;
	}

	template<typename T>
	void BinarySearchTree<T>::Insert(std::unique_ptr<T> data)
	{
		if (mRoot == nullptr)
		{
			std::shared_ptr<TreeNode<T>> tem = std::make_shared<TreeNode<T>>(std::move(data));
			mRoot = tem;
		}
		else
		{
			std::shared_ptr<TreeNode<T>> search = mRoot;
			while (true)
			{
				if (*search->Data < *data)
				{
					if (search->Right == nullptr)
					{
						std::shared_ptr<TreeNode<T>> tem = std::make_shared<TreeNode<T>>(search, std::move(data));
						search->Right = tem;
						return;
					}
					search = search->Right;
				}
				else if (*search->Data > *data)
				{
					if (search->Left == nullptr)
					{
						std::shared_ptr<TreeNode<T>> tem = std::make_shared<TreeNode<T>>(search, std::move(data));
						search->Left = tem;
						return;
					}
					search = search->Left;
				}
				else if (*search->Data == *data)
				{
					return;
				}
			}
		}
	}


	template<typename T>
	const std::weak_ptr<TreeNode<T>> BinarySearchTree<T>::GetRootNode() const
	{

		return mRoot;
	}

	template<typename T>
	bool BinarySearchTree<T>::Search(const T& data)
	{
		if (mRoot == nullptr)
		{
			return false;
		}
		else
		{
			std::shared_ptr<TreeNode<T>> tem = mRoot;
			while (true)
			{
				if (*tem->Data == data)
				{
					return true;
				}
				else if (*tem->Data > data)
				{
					if (tem->Left == nullptr)
					{
						return false;
					}
					tem = tem->Left;
				}
				else
				{
					if (tem->Right == nullptr)
					{
						return false;
					}
					tem = tem->Right;
				}
			}
		}
	}

	template<typename T>
	bool BinarySearchTree<T>::Delete(const T& data)
	{

		if (mRoot == nullptr)
		{
			return false;
		}

		/////////////////////노드 탐색//////////////////////
		std::shared_ptr<TreeNode<T>> tem = mRoot;
		while (true)
		{
			if (*tem->Data == data)
			{
				break;
			}
			else if (*tem->Data > data)
			{
				if (tem->Left == nullptr)
				{
					return false;
				}
				tem = tem->Left;
			}
			else
			{
				if (tem->Right == nullptr)
				{
					return false;
				}
				tem = tem->Right;
			}
		}
		//////////////////////////////////////////////////////////

		std::shared_ptr<TreeNode<T>> removeNode = tem;

		//root를 지울 경우
		if (tem == mRoot)
		{
			tem = tem->Left;
			while (true)
			{
				if (tem->Right == nullptr)
				{
					break;
				}
				tem = tem->Right;
			}
			std::shared_ptr<TreeNode<T>> grandNode = removeNode->Parent.lock();
			grandNode->Right = nullptr;
			tem->Left = removeNode->Left;
			removeNode->Left->Parent = tem;
			removeNode->Left = nullptr;
			tem->Right = removeNode->Right;
			removeNode->Right->Parent = tem;
			removeNode->Right = nullptr;
			mRoot = tem;
			tem->Parent.reset();
			removeNode.reset();
		}
		/////////////////////////////////////////////////////////
		if (removeNode->Right == nullptr && removeNode->Left == nullptr)
		{
			std::shared_ptr<TreeNode<T>> grandNode = removeNode->Parent.lock();
			if (grandNode->Left == removeNode)
			{
				grandNode->Left = nullptr;
				removeNode.reset();
			}
			else
			{
				grandNode->Right = nullptr;
				removeNode.reset();
			}
		}

		else if (removeNode->Right != nullptr && removeNode->Left == nullptr)
		{
			std::shared_ptr<TreeNode<T>> grandNode = removeNode->Parent.lock();
			if (grandNode->Left == removeNode)
			{
				grandNode->Left = removeNode->Right;
				removeNode->Right->Parent = grandNode;

				removeNode.reset();
			}
			else
			{
				grandNode->Right = removeNode->Right;
				removeNode->Right->Parent = grandNode;
		
				removeNode.reset();
			}

		}
		else if (removeNode->Left != nullptr && removeNode->Right == nullptr)
		{
			std::shared_ptr<TreeNode<T>> grandNode = removeNode->Parent.lock();
			if (grandNode->Left == removeNode)
			{
				grandNode->Left = removeNode->Left;
				removeNode->Left->Parent = grandNode;
				grandNode->Left = removeNode->Right;
				removeNode->Right->Parent = grandNode;

				removeNode.reset();
			}
			else
			{
				grandNode->Right = removeNode->Left;
				removeNode->Left->Parent = grandNode;
				grandNode->Right = removeNode->Right;
				removeNode->Right->Parent = grandNode;

				removeNode.reset();
			}
		}
		else
		{
			tem = tem->Left;
			while (true)
			{
				if (tem->Right == nullptr)
				{
					break;
				}
				tem = tem->Right;
			}
			std::shared_ptr<TreeNode<T>> grandNode = removeNode->Parent.lock();

			if (grandNode->Left == removeNode)
			{
				grandNode->Left = tem;
				tem->Parent = grandNode;
				if (removeNode->Right != tem)
				{
					tem->Right = removeNode->Right;
				}
				std::shared_ptr<TreeNode<T>> par = removeNode->Right->Parent.lock();
				if (par != nullptr && par != tem)
				{
					removeNode->Right->Parent = tem;
				}
				if (removeNode->Left != tem)
				{
					tem->Left = removeNode->Left;
				}
				par = removeNode->Left->Parent.lock();
				if (par != nullptr && par != tem)
				{
					removeNode->Left->Parent = tem;
				}
				removeNode.reset();
				
			}
			else
			{
				grandNode->Right = tem;
				tem->Parent = grandNode;
				if (removeNode->Right != tem)
				{
					tem->Right = removeNode->Right;
				}
				std::shared_ptr<TreeNode<T>> par = removeNode->Right->Parent.lock();
				if (par != nullptr && par != tem)
				{
					removeNode->Right->Parent = tem;
				}
				if (removeNode->Left != tem)
				{
					tem->Left = removeNode->Left;
				}
				par = removeNode->Left->Parent.lock();
				if (par != nullptr && par != tem)
				{
					removeNode->Left->Parent = tem;
				}
				removeNode.reset();
			}

		}
	}

	template<typename T>
	std::vector<T> BinarySearchTree<T>::TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode)
	{
		std::vector<T> v;
		std::vector<T> tem;
		if (startNode != nullptr)
		{
			tem = TraverseInOrder(startNode->Left);
			if (tem.size() > 0)
			{
				for (unsigned int i = 0; i < tem.size(); i++)
				{
					v.push_back(tem[i]);
				}
			}
			v.push_back(*startNode->Data);

			tem = TraverseInOrder(startNode->Right);

			if (tem.size() > 0)
			{
				for (unsigned int i = 0; i < tem.size(); i++)
				{
					v.push_back(tem[i]);
				}
			}

		}
		return v;
	}
}

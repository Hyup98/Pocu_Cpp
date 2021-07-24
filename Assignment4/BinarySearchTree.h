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
			std::shared_ptr search = mRoot;
			while (true)
			{
				if (*search->Data < *data)
				{
					if (search->Right == nullptr)
					{
						std::shared_ptr<TreeNode<T>> tem = std::make_shared<TreeNode<T>>(search,std::move(data));
						search->Right = tem;
						return;
					}
					search = search->Right;
				}
				else if (*search->Data > *data)
				{
					if (search->Left == nullptr)
					{
						std::shared_ptr<TreeNode<T>> tem = std::make_shared<TreeNode<T>>(search,std::move(data));
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
		
		std::shared_ptr<T> removeNode = tem;

		//root를 지울 경우
		if (tem == mRoot)
		{

		}
		
		//지울 노드의 왼쪽에 자식이 존재하지 않는 경우 -> 이어 붙이기만 하면 된다
		else if(tem->Left == nullptr)
		{
			std::shared_ptr grandNode = removeNode->Parent.lock();
			grandNode->Right = removeNode->Right;
			removeNode->Right->Parent = grandNode;
			removeNode->Right = nullptr;
			removeNode.reset();
			return true;
		}

		//지울 노드의 왼쪽에 자식이 존재 -> 
		else if (tem->Left != nullptr)
		{
			tem = tem->Left;
			while (true)
			{
				if (tem->Right == nullptr)
				{
					std::shared_ptr grandNode = tem->Parent.lock();
					//자식이 있을때(왼쪽)
					if (tem->Right != nullptr)
					{
						std::shared_ptr<T> parentNode = tem->Parent.lock();
						parentNode->Right = tem->Left;
						tem->Left->Parent = parentNode;
						tem->Parent = grandNode;
						grandNode->Left = tem;
						tem->Left = 
					}
					//자식이 없을때
					else 
					{
						if(grandNode->Left == removeNode)
						{
							grandNode->Left = tem;
							std::shared_ptr<T> parentNode = tem->Parent.lock();
							parentNode->Right = nullptr;
							tem->Parent = grandNode;
							
						}
						else if (grandNode->Right == removeNode)
						{
							grandNode->Right = tem;
							std::shared_ptr<T> parentNode = tem->Parent.lock();
							parentNode->Right = nullptr;
							tem->Parent = grandNode;
							
						}
						return true;
				}
				tem = tem->Right;
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
				for (int i = 0; i < tem.size(); i++)
				{
					v.push_back(tem[i]);
				}
			}
			v.push_back(*startNode->Data);

			tem = TraverseInOrder(startNode->Right);

			if(tem.size() > 0)
			{
				for (int i = 0; i < tem.size(); i++)
				{
					v.push_back(tem[i]);
				}
			}
			
		}
		return v;
	}
}
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
		/////////////////////노드 탐색//////////////////////
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
			//////////////////////////////////////

			if (tem->Left == nullptr)
			{
				std::shared_ptr check = tem->Parent.lock();
				check->Right = tem;
				tem->Right->Parent = check;
				tem->Right = nullptr;
				tem.reset();

			}

			std::shared_ptr<TreeNode<T>> flag = tem;
			tem = tem->Left;
			while (true)
			{
				if (tem->Right == nullptr)
				{
					//대체 노그가 자식이 없을 경우
					//check ->지울 노드의 조상
					//tem ->가져올 노드
					//flag ->지을 노드
					if (tem->Left == nullptr)
					{
						std::shared_ptr check = tem->Parent.lock();
						
											
						check = flag->Parent.lock();

						if (check->Left == flag)
						{
							check->Left = tem;
							tem->Parent = check;
							if (tem != flag->Left)
							{
								tem->Left = flag->Left;
								flag->Left = nullptr;
							}
							if (tem != flag->Right)
							{
								tem->Right = flag->Right;
								flag->Right = nullptr;
							}
							flag.reset();
						}
						else if (check->Right == flag)
						{
							check->Right = tem;
							tem->Parent = check;
							if (tem != flag->Left)
							{
								tem->Left = flag->Left;
								flag->Left = nullptr;
							}
							if (tem != flag->Right)
							{
								tem->Right = flag->Right;
								flag->Right = nullptr;
							}
							flag.reset();
						}
						return true;
					}
					//대체 노드가 왼쪽 자식이 존재할때
					else
					{
						std::shared_ptr check = tem->Parent.lock();
						
						check->Right = nullptr;

						tem->Left->Parent = check;

						check = flag->Parent.lock();

						if (check->Left == flag)
						{
							check->Left = tem;
							tem->Parent = check;
							if (tem != flag->Left)
							{
								tem->Left = flag->Left;
								flag->Left = nullptr;
							}
							if (tem != flag->Right)
							{
								tem->Right = flag->Right;
								flag->Right = nullptr;
							}
							flag.reset();
						}
						else if (check->Right == flag)
						{
							check->Right = tem;
							tem->Parent = check;
							if (tem != flag->Left)
							{
								tem->Left = flag->Left;
								flag->Left = nullptr;
							}
							if (tem != flag->Right)
							{
								tem->Right = flag->Right;
								flag->Right = nullptr;
							}
							flag.reset();
						}
						return true;
					}
				}
				tem = tem->Right;
			}

		}
		//////////////////////////////////////////////////////////
		
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
#pragma once

#include <memory>
#include <vector>

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
						std::shared_ptr<TreeNode<T>> tem = std::make_shared<TreeNode<T>>(tem,std::move(data));
						search->Right = tem;
						return;
					}
					search = search->Right;
				}
				else if (*search->Data > *data)
				{
					if (search->Left == nullptr)
					{
						std::shared_ptr<TreeNode<T>> tem = std::make_shared<TreeNode<T>>(tem,std::move(data));
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
		/////////////////////³ëµå Å½»ö//////////////////////
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

			std::shared_ptr<TreeNode<T>> flag = tem;

			while (true)
			{
				if (tem->Right == nullptr && tem->Left == nullptr)
				{
					if (flag->Left != nullptr)
					{
						tem->Left = flag->Left;
						tem->Left->Parent = tem;
					}

					if (flag->Right != nullptr)
					{
						tem->Right = flag->Right;
						tem->Right->Parent = tem;
					}
					flag->Left = nullptr;
					flag->Right = nullptr;
					std::shared_ptr<TreeNode<T>>pNode = flag->Parent.lock();
					if (pNode == nullptr)
					{
						flag.reset();
						return true;
					}
					else
					{
						if (pNode->Left == flag)
						{
							pNode->Left = tem;
						}
						else
						{
							pNode->Right = tem;
						}
					}
					flag.reset();
					return true;

				}
				else if (tem->Right != nullptr)
				{
					tem = tem->Right;
				}
				else if (tem->Left != nullptr)
				{
					tem = tem->Left;
				}
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
#include <cassert>
#include "TreeNode.h"
#include "BinarySearchTree.h"
#include<iostream>

using namespace assignment4;

int main()
{
	BinarySearchTree<int> tree;

	tree.Insert(std::make_unique<int>(10));
	tree.Insert(std::make_unique<int>(15));
	tree.Insert(std::make_unique<int>(5));
	tree.Insert(std::make_unique<int>(4));
	tree.Insert(std::make_unique<int>(19));
	tree.Insert(std::make_unique<int>(20));
	tree.Insert(std::make_unique<int>(17));
	tree.Insert(std::make_unique<int>(12));

	std::vector<int> v = tree.TraverseInOrder(tree.GetRootNode().lock());

	assert(v.size() == 8);
	assert(v[0] == 4);
	assert(v[1] == 5);
	assert(v[2] == 10);
	assert(v[3] == 12);
	assert(v[4] == 15);
	assert(v[5] == 17);
	assert(v[6] == 19);
	assert(v[7] == 20);

	bool bSearched = tree.Search(15);
	assert(bSearched);

	bool bDeleted = tree.Delete(6);
	assert(!bDeleted);

	bDeleted = tree.Delete(10);
	//assert(!bDeleted);

	bDeleted = tree.Delete(15);
	//assert(bDeleted);

	v = tree.TraverseInOrder(tree.GetRootNode().lock());

	/*
	assert(v.size() == 7);
	assert(v[0] == 4);
	assert(v[1] == 5);
	assert(v[2] == 10);
	assert(v[3] == 12);
	assert(v[4] == 17);
	assert(v[5] == 19);
	assert(v[6] == 20);

	bSearched = tree.Search(15);
	assert(!bSearched);
	*/
	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << std::endl;
	}

	int a;
	std::cin >> a;
	return 0;
}
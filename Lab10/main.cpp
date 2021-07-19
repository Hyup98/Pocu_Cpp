#include <cassert>
#include "DoublyLinkedList.h"
#include "Node.h"

using namespace lab10;

int main()
{
	DoublyLinkedList<int> list;

	list.Insert(std::make_unique<int>(1));
	list.Insert(std::make_unique<int>(2));
	list.Insert(std::make_unique<int>(3));
	list.Insert(std::make_unique<int>(4));
	list.Insert(std::make_unique<int>(5));
	list.Insert(std::make_unique<int>(6));
	list.Insert(std::make_unique<int>(7));

	bool bSearched = list.Search(4);
	assert(bSearched);

	bSearched = list.Search(10);
	assert(!bSearched);

	unsigned int size = list.GetLength();
	assert(size == 7);

	bool bDeleted = list.Delete(3);
	assert(bDeleted);

	bDeleted = list.Delete(3);
	assert(!bDeleted);

	size = list.GetLength();
	assert(size == 6);

	std::shared_ptr<Node<int>> node = list[2];
	assert(*node->Data == 4);

	list.Insert(std::make_unique<int>(10), 2);

	node = list[2];
	assert(*node->Data == 10);

	return 0;
}
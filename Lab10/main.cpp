#include <cassert>
#include <crtdbg.h>
#include "DoublyLinkedList.h"
#include "Node.h"

#ifdef _DEBUG
#define new new(_CLIENT_BLOCK, __FILE__, __LINE__)
#define malloc(s) _malloc_dbg(s, _NORMAL_BLOCK, __FILE__, __LINE__)
#endif

using namespace lab10;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	DoublyLinkedList<int> list;

	assert(list[0] == nullptr);
	assert(list[3] == nullptr);
	bool bEmptyDeleted = list.Delete(6);
	assert(!bEmptyDeleted);
	bool bEmptySearched = list.Search(7);
	assert(!bEmptySearched);

	list.Insert(std::make_unique<int>(1));
	list.Insert(std::make_unique<int>(2));
	list.Insert(std::make_unique<int>(3));
	list.Insert(std::make_unique<int>(4));
	list.Insert(std::make_unique<int>(5));
	list.Insert(std::make_unique<int>(6));
	list.Insert(std::make_unique<int>(7));

	bool bSearched = list.Search(4);
	assert(bSearched);

	bSearched = list.Search(1);
	assert(bSearched);

	bSearched = list.Search(7);
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

	bDeleted = list.Delete(1);
	assert(bDeleted);
	assert(*list[0]->Data == 2);

	bDeleted = list.Delete(7);
	assert(bDeleted);

	list.Insert(std::make_unique<int>(11), 0);

	node = list[0];
	assert(*node->Data == 11);
	assert(list.GetLength() == 6);

	list.Insert(std::make_unique<int>(12), 6);
	assert(list.GetLength() == 7);
	node = list[6];
	assert(*node->Data == 12);

	list.Insert(std::make_unique<int>(13), 9);
	assert(list.GetLength() == 8);
	node = list[7];
	assert(*node->Data == 13);

	bDeleted = list.Delete(2);
	assert(bDeleted);
	bDeleted = list.Delete(4);
	assert(bDeleted);
	bDeleted = list.Delete(5);
	assert(bDeleted);
	bDeleted = list.Delete(6);
	assert(bDeleted);
	bDeleted = list.Delete(10);
	assert(bDeleted);
	bDeleted = list.Delete(11);
	assert(bDeleted);
	bDeleted = list.Delete(12);
	assert(bDeleted);
	bDeleted = list.Delete(13);
	assert(bDeleted);

	assert(list[0] == nullptr);

	return 0;
}
#include <cassert>
#include"SmartQueue.h"
#include"QueueStack.h"

using namespace assignment3;

int main()
{
    QueueStack<int> qs(3);
    qs.Enqueue(1); // [ [ 1 ] ]
    qs.Enqueue(2); // [ [ 1, 2 ] ]
    qs.Enqueue(3); // [ [ 1, 2, 3 ] ]
    qs.Enqueue(4); // [ [ 1, 2, 3 ], [ 4 ] ]
    qs.Enqueue(5); // [ [ 1, 2, 3 ], [ 4, 5 ] ]

    int peeked = qs.Peek(); // peeked�� ���� 3. qs�� ��Ҵ� ������ [ [ 1, 2, 3 ], [ 4, 5 ] ]);

    return 0;
}

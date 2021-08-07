#include<iostream>
#include <cassert>
#include "QueueStack.h"
#include "SmartStack.h"
#include"SmartQueue.h"


using namespace std;
using namespace assignment3;

int main()
{
    QueueStack<int> qs(3);
    qs.Enqueue(1); // [ [ 1 ] ]
    qs.Enqueue(2); // [ [ 1, 2 ] ]
    qs.Enqueue(3); // [ [ 1, 2, 3 ] ]
    qs.Enqueue(4); // [ [ 1, 2, 3 ], [ 4 ] ]
    qs.Enqueue(5); // [ [ 1, 2, 3 ], [ 4, 5 ] ]

    int dequeued = qs.Dequeue(); // dequeued의 값은 3. qs의 요소: [ [ 1, 2 ], [ 4, 5 ] ]
    
    cout<< qs.GetAverage(); 
    int a;
    cin >> a;
    return 0;
}

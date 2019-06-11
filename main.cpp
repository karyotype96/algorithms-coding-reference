#include <iostream>
#include <vector>

#include "utils.h"
#include "DataStructures/Queue.h"

using namespace std;

int main()
{
    Queue q;
    q.enqueue(5);
    q.enqueue(7);
    q.enqueue(9);

    while (!q.is_empty()){
        cout << q.dequeue() << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>

#include "utils.h"
#include "DLLNode.h"
#include "DoublyLinkedList.h"

using namespace std;

int main()
{
    DoublyLinkedList dll(3);

    dll.append(5);
    dll.append(8);

    dll.insert(2, 11);

    dll.remove(1);

    for (int i = 0; i < dll.getLength(); i++){
        cout << dll.get(i) << endl;
    }

    return 0;
}

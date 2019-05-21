#include <iostream>

#include "utils.h"
#include "DataStructures/SinglyLinkedList.h"

using namespace std;

int main()
{
    SinglyLinkedList s(30);
    s.append(60);
    s.append(90);

    cout << "First list:\t\t";
    for (int i = 0; i < s.getLength(); i++){
        cout << s.get(i) << " ";
    }
    cout << endl;

    s.insert(2, 120);

    cout << "After insertion:\t";
    for (int i = 0; i < s.getLength(); i++){
        cout << s.get(i) << " ";
    }
    cout << endl;

    s.remove(3);

    cout << "After removal:\t\t";
    for (int i = 0; i < s.getLength(); i++){
        cout << s.get(i) << " ";
    }
    cout << endl;

    return 0;
}

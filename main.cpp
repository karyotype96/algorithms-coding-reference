#include <iostream>
#include <vector>

#include "utils.h"
#include "Sorts/Sorts.h"

using namespace std;

int main()
{
    vector<int> v = {81, 99, 43, 18, 63, 11, 34, 80, 39, 79,
                      82, 26, 87, 44,  2, 33, 62, 66, 46, 58,
                      38, 98, 24,  3, 51, 31, 78, 68, 45, 99};

    printVector("Unsorted vector", v);

    v = Sorts::mergeSort(v, 0, v.size() - 1);

    printVector("Sorted vector", v);

    return 0;
}

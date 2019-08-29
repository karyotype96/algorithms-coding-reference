#ifndef SORTS_H
#define SORTS_H

#include <vector>

class Sorts
{
    public:
        // One of the simplest sorting algorithms ever devised. Bubble sort
        // works by running through the list several times, checking each
        // element in the list and comparing it to the next element. If the
        // first element is greater than the second, the elements are
        // swapped. It has a complexity of O(n^2)
        static std::vector<int> bubbleSort(std::vector<int> arr){
            for (int i = 0; i < arr.size() - 1; i++){
                for (int j = 0; j < arr.size() - 1; j++){ // Run through the list several times...
                    if (arr[j] > arr[j+1]){
                        // Swap the elements if the one on the left is greater.
                        std::swap(arr[j], arr[j+1]);
                    }
                }
            }

            return arr;
        }

        // Another simple sorting algorithm. This one starts at the first
        // element, finds the smallest element in the list ahead of it, and
        // swaps the two. Then it does the same for the subsequent elements.
        // Like bubble sort, selection sort has a complexity of O(n^2), but
        // it appears to do marginally better in the average case.
        static std::vector<int> selectionSort(std::vector<int> arr){
            int smallest; // The index of the smallest element in the list.
            for (int i = 0; i < arr.size() - 1; i++){
                smallest = i; // Start at the unsorted section of the list...
                for (int j = i+1; j < arr.size(); j++){ // Advance through it...
                    // ...and store the smallest element position.
                    if (arr[j] < arr[smallest]) smallest = j;
                }
                // Then swap the start of the unsorted section with the smallest item.
                std::swap(arr[i], arr[smallest]);
            }

            return arr;
        }

        // An inefficient sort that starts at element 1 and moves it back
        // to where the element after it is greater, and it does the same
        // for every subsequent element until the list is fully sorted.
        // Insertion sort has a complexity of O(n^2) and lags a lot when
        // lists get bigger.
        static std::vector<int> insertionSort(std::vector<int> arr){
            int i, currentValue;
            for (int j = 1; j < arr.size(); j++){
                currentValue = arr[j];
                i = j - 1;
                while (i >= 0 && arr[i] > currentValue){
                    arr[i+1] = arr[i];
                    i--;
                }
                arr[i+1] = currentValue;
            }
            return arr;
        }

        // A relatively time-efficient but not so space-efficient sorting
        // algorithm that works by recursively calling itself on both halves
        // of the elements in the list, then "merges" them together by starting
        // at the beginning of both lists, adding the shortest element between
        // the two to a new list, and then advancing the index of the chosen
        // list by 1. Rinse and repeat.

        static std::vector<int> mergeSort(std::vector<int> arr, int left, int right){
            int middle = (right - left) / 2 + left;
            if (left < right){
                arr = mergeSort(arr, left, middle);
                arr = mergeSort(arr, middle+1, right);
                arr = mergeArray(arr, left, middle, right);
            }
            return arr;
        }

    private:
        static std::vector<int> mergeArray(std::vector<int> arr, int left, int middle, int right){
            int leftIndex, rightIndex;
            int mergeIndex = left;
            int n1 = middle - left + 1;
            int n2 = right - middle;

            int A1[n1], A2[n2];

            for (int i = 0; i < n1; i++)
                A1[i] = arr[left + i];
            for (int j = 0; j < n2; j++)
                A2[j] = arr[middle + 1 + j];

            leftIndex = rightIndex = 0;
            while (leftIndex < n1 && rightIndex < n2){
                if (A1[leftIndex] < A2[rightIndex])
                    arr[mergeIndex] = A1[leftIndex++];
                else
                    arr[mergeIndex] = A2[rightIndex++];
                mergeIndex++;
            }

            while (leftIndex < n1)
                arr[mergeIndex++] = A1[leftIndex++];

            while (rightIndex < n2)
                arr[mergeIndex++] = A2[rightIndex++];

            return arr;
        }
};

#endif // SORTS_H

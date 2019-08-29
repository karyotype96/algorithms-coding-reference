#include <iostream>
#include <vector>

#include "utils.h"
#include "Crypto/Digests.h"

/*
    Congrats, you've found my algorithms dictionary!
    This is a collection of algorithms that I decided
    to take a stab at DIY-ing. That means that I did
    not use any code written by someone else as a
    reference, though I might use code I've already
    written before.

    I plan to implement the following data structures:

    - Linked List (single and double)
    - Stack
    - Queue
    - Tree
    - Heap
    - Hash table

    Here are the algorithm categories I plan on using:

    - Sorting algorithms
    - Array/vector searches
    - Pathfinding algorithms
    - Compression
    - Cryptographic
    - Mathematical (arithmetic, linear algebra, etc.)

    Check inside the respective folders for each one.
    I also plan on documenting each one in excruciating
    detail, so check that out if you feel like it.
*/

using namespace std;

int main() {

    string msg = "hello dar";

    Digests::MD5(msg);

    return 0;
}

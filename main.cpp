#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>

#include "UserInterface.h"
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"
#include "HighestIndex.h"
#include "BinaryTree.h"

using namespace std;


int main() {
    char command;
    displayMenu();
    command = readInCommand();
    while(command != 9){
        processCommand(command);
        displayMenu();
        command = readInCommand();
    }

    return 0;
}


/* Big O Complexity
 *
 *
 * EXCELLENT
 * Array Sorting Algorithms -
 *      (TIME COMPLEXITY): Bucket sort, radix sort, counting sort
 *      (SPACE COMPLEXITY * Memory Load): Heapsort, bubble sort, insertion sort, selection sort, shell sort
 * O(1) -> Constant Transfer Time -> constant time beats linear (if data is sufficiently big). Doubling data size will continue to yield the original transfer time
 *
 * GOOD
 * Array Sorting Algorithms -
 *      (SPACE COMPLEXITY): Quicksort
 * O(log(n)) -> Logarithmic Transfer Time -> Searching in a Glossary is O(log(n)) because you don't need to search every entry, you alphabetically divide-and-conquer. And of course, a bigger Glossary will take longer, but it grow as quickly as the proportional increase in size
 *
 * FAIR
 * Array Sorting Algorithms -
 *      (SPACE COMPLEXITY): Merge sort, Tim sort, tree sort, bucket sort, radix sort, counting sort, cube sort
 * O(n) -> Linear Transfer Time -> the amount of data is linearly related to the the time it will take -> doubling the data will double the time
 *
 *
 * BAD
 * Array Sorting Algorithms -
 *      (TIME COMPLEXITY): Quicksort, mergesort, Tim sort, heapsort, tree sort, cube sort
 * O(n log(n)) ->
 *
 * HORRIBLE
 * Array Sorting Algorithms -
 *      (TIME COMPLEXITY): Bubble sort, Insertion sort, Selection sort, Shell Sort
 * O(n^2) ->
 * O(2^n) ->
 * O(n!) ->
*/

/*COMMON DATA STRUCTURE OPERATIONS
 *
 * ARRAY -> Access(Excellent)-> Search/Insertion/Deletion(Fair)
 * STACK/QUEUE/SINGLY+DOUBLY LINKED LIST-> Access/Search(Fair) -> Insertion/Deletion(Excellent)
 * SKIP LIST -> Access/Search/Insert/Delete(Good)
 * HASH TABLE -> Access(N/A), Search/Insert/Delete(Excellent)
 * BINARY SEARCH TREE/B-TREE/SPLAY TREE -> Access/Search/Insert/Delete(GOOD)
 *
*/


/* Linear Data Structures - Sequential Data Organization:
 * ARRAY - a collection of data items having the same data types
 * STACK - Last In First Out (LIFO) data structure, where the element which was added last will be deleted first. All operations on stack are performed from an end called TOP.
 * QUEUE - First In First Out (FIFO) data structure, where the element which was added first will be deleted first. In queue, insertion is performed from one end called REAR, and deletion is performed from another end called FRONT.
 * LINKED LIST - A collection of nodes, where each node is made of a data element and a reference to the next node in the sequence.
 *
 * Non Linear Data Structures (Stored data elements of this type cannot be traversed in a single run) - Non sequential Data Organization:
 * GRAPH - a collection of a finite number of vertices and edges that connect these vertices. Edges represent relationships among vertices that store data elements.
 * TREE - a collection of nodes which are arranged hierarchically and form a parent-child relationship.
 *      BINARY TREE - comprised of nodes, each having a data element, 'left' pointer, and 'right' pointer. The "root" pointer points to the topmost node in the tree. The left and right pointers recursively point to smaller "subtrees" on either side.
 *      BINARY SEARCH TREE (ORDERED SEARCH TREE) - For each node, all elements in its left subtree are less than the node (<), and all the elements on the right are greater than the node (>). Example: the "root" node is 5, and it's left subtree nodes are 1, 3, 4 (smaller than root), and it's right subtree nodes are 6 and 9 (bigger than root). Recursively, each subtree must also obey the binary search tree constraint--so in the (1, 3, 4) subtree, the 3 is the root, the left is 1, and the right is 4. (L-Node < ROOT-Node > R-Node)
*/


/*          *NOTES** **BINARY TREE != BINARY SEARCH TREE
 *
 * TREES access/search QUICKER than LINKED LIST but are SLOWER than ARRAYS
 * TREES insert/delete QUICKER than ARRAYS but are SLOWER than UNORDERED LINKED LISTS
 * SELF BALANCING BINARY SEARCH TREE (ex: AVL TREE/RED-BLACK TREE)
 *
*/
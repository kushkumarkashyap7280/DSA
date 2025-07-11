// Demo for CircularList STL: Shows usage of push_back, insert, erase, reverse, rotate, sort, iterators, and cycle traversal.
#include <iostream>
#include "circular_list.h"

void printList(CircularList<int> &list)
{
    std::cout << "List: ";
    for (auto it = list.begin(); it != list.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";
}

void printCycle(CircularList<int> &list, int count)
{
    std::cout << "Cycling (" << count << " steps): ";
    auto it = list.cycle_begin();
    for (int i = 0; i < count; ++i, ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";
}

int main()
{
    CircularList<int> clist;

    std::cout << ">>> Pushing back elements: ";
    for (int i = 1; i <= 5; ++i)
    {
        clist.push_back(i);
        std::cout << i << " ";
    }
    std::cout << "\n";
    printList(clist);

    std::cout << ">>> Insert 99 at position 2\n";
    clist.insert(2, 99);
    printList(clist);

    std::cout << ">>> Erase element at position 3\n";
    clist.erase(3);
    printList(clist);

    std::cout << ">>> Reverse list\n";
    clist.reverse();
    printList(clist);

    std::cout << ">>> Rotate +2\n";
    clist.rotate(2);
    printList(clist);

    std::cout << ">>> Rotate -1\n";
    clist.rotate(-1);
    printList(clist);

    std::cout << ">>> Sorted list\n";
    clist.sort();
    printList(clist);

    std::cout << ">>> Accessing head and tail:\n";
    std::cout << "Head: " << clist.head() << "\n";
    std::cout << "Tail: " << clist.tail() << "\n";

    std::cout << ">>> Size: " << clist.size() << "\n";
    std::cout << ">>> Empty? " << (clist.empty() ? "Yes" : "No") << "\n";

    std::cout << ">>> Iterate from index 2:\n";
    auto it = clist.at(2);
    for (int i = 0; i < clist.size(); ++i, ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    std::cout << ">>> Iterate backward:\n";
    auto rit = clist.at(clist.size() - 1);
    for (int i = 0; i < clist.size(); ++i, --rit)
    {
        std::cout << *rit << " ";
    }
    std::cout << "\n";

    std::cout << ">>> Infinite cycle (10 steps):\n";
    printCycle(clist, 10);

    std::cout << ">>> Clearing list\n";
    clist.clear();
    std::cout << "Size after clear: " << clist.size() << "\n";
    std::cout << "Empty? " << (clist.empty() ? "Yes" : "No") << "\n";

    return 0;
}

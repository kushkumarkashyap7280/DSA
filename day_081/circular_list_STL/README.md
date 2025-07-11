# CircularList STL (Custom Circular Linked List)

This folder contains a custom C++ STL-like container: **CircularList**. It is a doubly-linked circular list with a modern interface, supporting many STL-style operations and iterators.

## Features

- **push_back(value)**: Add element to the end
- **insert(index, value)**: Insert at any position
- **erase(index)**: Remove element at position
- **reverse()**: Reverse the list
- **rotate(k)**: Rotate head/tail by k positions (positive: right, negative: left)
- **sort()**: Sort the list (merge sort)
- **clear()**, **empty()**, **size()**, **head()**, **tail()**: Standard container operations
- **STL-style iterators**: `begin()`, `end()`, bidirectional, random access via `at(index)`
- **cycle_begin()**: Infinite-looping iterator for circular traversal

## Example Usage

```cpp
#include "circular_list.h"
#include <iostream>

int main() {
    CircularList<int> clist;
    clist.push_back(1);
    clist.push_back(2);
    clist.push_back(3);
    clist.rotate(1); // Head is now 2
    for (auto it = clist.begin(); it != clist.end(); ++it) {
        std::cout << *it << " ";
    }
    // Output: 2 3 1
}
```

## Demo

See [`demo.cpp`](demo.cpp) for a showcase of all major features, including:

- Insertion, erasure, reverse, rotate, sort
- Iteration (forward, backward, from index, infinite cycle)
- Accessing head/tail, checking size/empty

## Tests

See [`test_circular_list.cpp`](test_circular_list.cpp) for unit tests covering all major operations.

## Implementation

See [`circular_list.h`](circular_list.h) for the full implementation and documentation of the CircularList class.

---

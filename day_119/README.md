# Heap Implementation in C++

This day covers the basics of the Heap data structure, its properties, and a simple implementation in C++.

## What is a Heap?

- A heap is a complete binary tree-based data structure.
- It can be a Max Heap (parent is always greater than children) or a Min Heap (parent is always less than children).

## Key Properties

- Complete binary tree: All levels are completely filled except possibly the lowest.
- For an array-based heap:
  - Parent of node at index `i` is at `i/2`.
  - Left child is at `2*i`.
  - Right child is at `2*i + 1`.

## Implementation

- The file [`heap.cpp`](heap.cpp) contains a simple Max Heap implementation with insert, delete, and print operations.

## Usage Example

```cpp
heap h;
h.insert(50);
h.insert(55);
h.insert(53);
h.insert(52);
h.insert(54);
h.print();
h.deletion();
h.print();
```

## Output

```
55 -> 54 -> 53 -> 50 -> 52 ->
54 -> 52 -> 53 -> 50 ->
```

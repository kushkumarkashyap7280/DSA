# Day 81: Leetcode 61 - Rotate List

## Problem

Given the head of a linked list, rotate the list to the right by k places.

- [Leetcode 61 - Rotate List](https://leetcode.com/problems/rotate-list/)

## Approach

- Calculate the length of the list.
- Make the list circular by connecting the tail to the head.
- Find the new tail at position (length - k % length - 1).
- Set the new head to newTail->next and break the circle.

## Example

**Input:** head = [1,2,3,4,5], k = 2  
**Output:** [4,5,1,2,3]

## Usage

Compile and run `Leetcode_61.cpp` to see the rotation in action:

```sh
g++ Leetcode_61.cpp -o rotate_list
./rotate_list
```

## Output

```
Original list: 1 2 3 4 5
Rotated list: 4 5 1 2 3
```

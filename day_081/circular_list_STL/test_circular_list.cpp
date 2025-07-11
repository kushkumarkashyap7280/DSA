// Unit tests for CircularList STL: Tests push_back, insert, erase, reverse, rotate, sort, clear, iterators, and cycle traversal.
#include <cassert>
#include <iostream>
#include "circular_list.h"

void test_push_back()
{
    CircularList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    assert(list.size() == 3);
    assert(list.head() == 1);
    assert(list.tail() == 3);
}

void test_insert_erase()
{
    CircularList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(4);
    list.insert(2, 3);
    assert(list.size() == 4);

    auto it = list.at(2);
    assert(*it == 3);

    list.erase(2);
    assert(list.size() == 3);
    it = list.at(2);
    assert(*it == 4);
}

void test_reverse()
{
    CircularList<int> list;
    for (int i = 1; i <= 3; ++i)
        list.push_back(i);
    list.reverse();

    auto it = list.begin();
    assert(*it == 3);
    ++it;
    assert(*it == 2);
    ++it;
    assert(*it == 1);
}

void test_rotate()
{
    CircularList<int> list;
    for (int i = 1; i <= 3; ++i)
        list.push_back(i);
    list.rotate(1);
    assert(list.head() == 2);
    list.rotate(-1);
    assert(list.head() == 1);
}

void test_sort()
{
    CircularList<int> list;
    list.push_back(3);
    list.push_back(1);
    list.push_back(2);
    list.sort();

    auto it = list.begin();
    assert(*it == 1);
    ++it;
    assert(*it == 2);
    ++it;
    assert(*it == 3);
}

void test_clear_empty()
{
    CircularList<int> list;
    assert(list.empty());
    list.push_back(1);
    list.clear();
    assert(list.empty());
}

void test_cycle_iterator()
{
    CircularList<int> list;
    list.push_back(10);
    list.push_back(20);
    auto it = list.cycle_begin();
    for (int i = 0; i < 5; ++i, ++it)
    {
        assert((*it == 10) || (*it == 20));
    }
}

void test_at_and_backward_iter()
{
    CircularList<int> list;
    for (int i = 1; i <= 5; ++i)
        list.push_back(i);

    auto it = list.at(3);
    assert(*it == 4);

    for (int i = 0; i < 3; ++i)
        --it;
    assert(*it == 1);
}

int main()
{
    std::cout << "Running CircularList tests...\n";

    test_push_back();
    std::cout << "✅ test_push_back passed\n";
    test_insert_erase();
    std::cout << "✅ test_insert_erase passed\n";
    test_reverse();
    std::cout << "✅ test_reverse passed\n";
    test_rotate();
    std::cout << "✅ test_rotate passed\n";
    test_sort();
    std::cout << "✅ test_sort passed\n";
    test_clear_empty();
    std::cout << "✅ test_clear_empty passed\n";
    test_cycle_iterator();
    std::cout << "✅ test_cycle_iterator passed\n";
    test_at_and_backward_iter();
    std::cout << "✅ test_at_and_backward_iter passed\n";

    std::cout << "🎉 All tests passed!\n";
    return 0;
}

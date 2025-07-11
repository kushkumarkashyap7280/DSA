// CircularList: A C++ STL-like doubly-linked circular list container.
// Features: push_back, insert, erase, reverse, rotate, sort, clear, size, empty, head, tail, STL-style iterators, cycle_begin for infinite traversal.
// See README.md for usage and examples.
#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H

#include <iostream>
#include <iterator>
#include <stdexcept>

template <typename T>
class CircularList
{
private:
    struct Node
    {
        T data;
        Node *next, *prev;
        Node(const T &d) : data(d), next(nullptr), prev(nullptr) {}
    };

    Node *head_, *tail_;
    int size_;

public:
    CircularList();
    ~CircularList();

    void push_back(const T &value);
    void clear();

    T &head();
    T &tail();
    int size() const;
    bool empty() const;

    void insert(int index, const T &value);
    void erase(int index);
    void reverse();
    void sort();        // still uses merge sort internally
    void rotate(int k); // NEW: rotate head/tail
    class iterator;

    iterator begin() const;
    iterator end() const;

    iterator at(int index) const; // NEW: get iterator at index
    iterator cycle_begin() const; // NEW: infinite-looping iterator

    class iterator
    {
    private:
        Node *current_;
        Node *start_;
        bool first_pass_;
        bool infinite_;

    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T *;
        using reference = T &;

        iterator(Node *current, Node *start, bool inf = false)
            : current_(current), start_(start), first_pass_(true), infinite_(inf) {}

        T &operator*() const { return current_->data; }

        iterator &operator++()
        {
            if (!current_)
                return *this;
            current_ = current_->next;
            if (current_ == start_)
            {
                if (infinite_)
                {
                    return *this; // keep cycling
                }
                else
                {
                    current_ = nullptr; // stop
                }
            }
            return *this;
        }

        iterator &operator--()
        {
            if (!start_)
                return *this;
            if (!current_)
            {
                // If at end(), wrap to tail (last node before start_)
                current_ = start_->prev;
                return *this;
            }
            current_ = current_->prev;
            if (current_ == start_)
            {
                if (infinite_)
                {
                    return *this;
                }
                else
                {
                    current_ = nullptr;
                }
            }
            return *this;
        }

        bool operator!=(const iterator &other) const
        {
            return current_ != other.current_;
        }
    };

private:
    template <typename Node>
    static Node *split(Node *head, int size)
    {
        Node *mid = head;
        for (int i = 0; i < size / 2 - 1; ++i)
            mid = mid->next;
        Node *second = mid->next;
        mid->next = nullptr;
        if (second)
            second->prev = nullptr;
        return second;
    }
    template <typename Node, typename Compare>
    static Node *merge(Node *l, Node *r, Compare cmp)
    {
        Node dummy{l ? l->data : r->data};
        Node *tail = &dummy;
        while (l && r)
        {
            if (cmp(l->data, r->data))
            {
                tail->next = l;
                l->prev = tail;
                l = l->next;
            }
            else
            {
                tail->next = r;
                r->prev = tail;
                r = r->next;
            }
            tail = tail->next;
        }
        while (l)
        {
            tail->next = l;
            l->prev = tail;
            tail = l;
            l = l->next;
        }
        while (r)
        {
            tail->next = r;
            r->prev = tail;
            tail = r;
            r = r->next;
        }
        dummy.next->prev = nullptr;
        return dummy.next;
    }
    template <typename Compare>
    static Node *mergeSort(Node *head, int size, Compare cmp)
    {
        if (size == 1)
        {
            head->next = nullptr;
            head->prev = nullptr;
            return head;
        }
        int mid = size / 2;
        Node *second = head;
        for (int i = 0; i < mid; ++i)
            second = second->next;
        Node *left = head;
        Node *right = second;
        // Break the list
        if (second && second->prev)
            second->prev->next = nullptr;
        if (second)
            second->prev = nullptr;
        Node *l = mergeSort(left, mid, cmp);
        Node *r = mergeSort(right, size - mid, cmp);
        return merge(l, r, cmp);
    }
};

// CONSTRUCTOR
template <typename T>
CircularList<T>::CircularList() : head_(nullptr), tail_(nullptr), size_(0) {}

// DESTRUCTOR
template <typename T>
CircularList<T>::~CircularList() { clear(); }

// CLEAR
template <typename T>
void CircularList<T>::clear()
{
    if (!head_)
        return;
    Node *curr = head_;
    do
    {
        Node *next = curr->next;
        delete curr;
        curr = next;
    } while (curr != head_);
    head_ = tail_ = nullptr;
    size_ = 0;
}

// PUSH_BACK
template <typename T>
void CircularList<T>::push_back(const T &value)
{
    Node *newNode = new Node(value);
    if (!head_)
    {
        head_ = tail_ = newNode;
        head_->next = head_->prev = head_;
    }
    else
    {
        newNode->prev = tail_;
        newNode->next = head_;
        tail_->next = newNode;
        head_->prev = newNode;
        tail_ = newNode;
    }
    size_++;
}

// HEAD & TAIL
template <typename T>
T &CircularList<T>::head()
{
    if (!head_)
        throw std::runtime_error("List is empty");
    return head_->data;
}

template <typename T>
T &CircularList<T>::tail()
{
    if (!tail_)
        throw std::runtime_error("List is empty");
    return tail_->data;
}

// SIZE & EMPTY
template <typename T>
int CircularList<T>::size() const { return size_; }

template <typename T>
bool CircularList<T>::empty() const { return size_ == 0; }

// INSERT
template <typename T>
void CircularList<T>::insert(int index, const T &value)
{
    if (index < 0 || index > size_)
        throw std::out_of_range("Index out of range");
    if (index == size_)
    {
        push_back(value);
        return;
    }
    Node *newNode = new Node(value);
    Node *curr = head_;
    for (int i = 0; i < index; ++i)
        curr = curr->next;

    newNode->prev = curr->prev;
    newNode->next = curr;
    curr->prev->next = newNode;
    curr->prev = newNode;

    if (index == 0)
        head_ = newNode;
    size_++;
}

// ERASE
template <typename T>
void CircularList<T>::erase(int index)
{
    if (index < 0 || index >= size_)
        throw std::out_of_range("Index out of range");
    Node *curr = head_;
    for (int i = 0; i < index; ++i)
        curr = curr->next;

    if (size_ == 1)
    {
        delete curr;
        head_ = tail_ = nullptr;
    }
    else
    {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        if (curr == head_)
            head_ = curr->next;
        if (curr == tail_)
            tail_ = curr->prev;
        delete curr;
    }
    size_--;
}

// REVERSE
template <typename T>
void CircularList<T>::reverse()
{
    if (!head_ || size_ == 1)
        return;
    Node *curr = head_;
    for (int i = 0; i < size_; ++i)
    {
        std::swap(curr->next, curr->prev);
        curr = curr->prev;
    }
    std::swap(head_, tail_);
}

// ROTATE
template <typename T>
void CircularList<T>::rotate(int k)
{
    if (!head_ || k == 0)
        return;
    if (k > 0)
    {
        while (k--)
        {
            head_ = head_->next;
            tail_ = tail_->next;
        }
    }
    else
    {
        while (k++)
        {
            head_ = head_->prev;
            tail_ = tail_->prev;
        }
    }
}

// ITERATORS
template <typename T>
typename CircularList<T>::iterator CircularList<T>::begin() const
{
    return head_ ? iterator(head_, head_) : end();
}

template <typename T>
typename CircularList<T>::iterator CircularList<T>::end() const
{
    return iterator(nullptr, nullptr);
}

template <typename T>
typename CircularList<T>::iterator CircularList<T>::cycle_begin() const
{
    return head_ ? iterator(head_, head_, true) : end();
}

template <typename T>
typename CircularList<T>::iterator CircularList<T>::at(int index) const
{
    if (index < 0 || index >= size_)
        throw std::out_of_range("Index out of range");
    Node *curr = head_;
    for (int i = 0; i < index; ++i)
        curr = curr->next;
    return iterator(curr, curr); // anchor at the node itself
}

// SORT
// Most optimal: recursive merge sort for doubly linked list
// O(n log n) time, O(log n) stack
// Handles circularity
template <typename T>
void CircularList<T>::sort()
{
    if (size_ < 2)
        return;
    // Break circularity
    head_->prev->next = nullptr;
    head_->prev = nullptr;
    // Sort
    Node *sorted = mergeSort(head_, size_, [](const T &a, const T &b)
                             { return a < b; });
    // Restore circularity and prev pointers
    Node *last = sorted;
    for (int i = 1; i < size_; ++i)
        last = last->next;
    sorted->prev = last;
    last->next = sorted;
    head_ = sorted;
    tail_ = last;
}

#endif

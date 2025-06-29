See `oops_demo.cpp` for code examples demonstrating all major OOPs concepts in C++.

## OOPS Concepts: Structure & File Links

1. **Class and Object**  
   [OOPS/class_and_object.cpp](OOPS/class_and_object.cpp)
2. **Access Modifiers**  
   [OOPS/access_modifiers.cpp](OOPS/access_modifiers.cpp)
3. **Constructors**  
   [OOPS/constructors.cpp](OOPS/constructors.cpp)
4. **Destructor**  
   [OOPS/destructor.cpp](OOPS/destructor.cpp)
5. **Static Data Members and Methods**  
   [OOPS/static_example.cpp](OOPS/static_example.cpp)
6. **Important C++ Keywords**  
   [OOPS/cpp_keywords.cpp](OOPS/cpp_keywords.cpp)
7. **Inheritance**  
   [OOPS/inheritance.cpp](OOPS/inheritance.cpp)
8. **Function Overloading**  
   [OOPS/function_overloading.cpp](OOPS/function_overloading.cpp)
9. **Function Overriding**  
   [OOPS/function_overriding.cpp](OOPS/function_overriding.cpp)
10. **Polymorphism**  
    [OOPS/polymorphism.cpp](OOPS/polymorphism.cpp)
11. **Encapsulation**  
    [OOPS/encapsulation.cpp](OOPS/encapsulation.cpp)
12. **Abstraction**  
    [OOPS/abstraction.cpp](OOPS/abstraction.cpp)
13. **Dynamic Instance Creation**  
    [OOPS/dynamic_instance.cpp](OOPS/dynamic_instance.cpp)
14. **Deep vs Shallow Copy**  
    [OOPS/deep_vs_shallow_copy.cpp](OOPS/deep_vs_shallow_copy.cpp)
15. **Padding and Alignment**  
    [OOPS/padding_and_alignment.cpp](OOPS/padding_and_alignment.cpp)

# Object Oriented Programming (OOPs) in C++

## What is OOPs?

Object Oriented Programming (OOPs) is a programming paradigm based on the concept of objects, which can contain data and code: data in the form of fields (attributes/properties), and code in the form of procedures (methods/functions). OOPs helps in organizing complex programs, promoting code reuse, and modeling real-world entities.

## Key Concepts of OOPs

### 1. Class and Object

- **Class**: Blueprint for creating objects. Defines attributes and behaviors.
- **Object**: Instance of a class. Has its own state and behavior.

# 📘 Access Modifiers and Inheritance in C++ (OOP)

This project demonstrates the use of access modifiers (`public`, `protected`, `private`) in C++ and how they behave in inheritance.

---

## 🔒 Access Modifiers Overview

### 1. `private`

- Default for class members
- Accessible only within the same class
- ❌ Not accessible from derived classes or outside

### 2. `protected`

- Accessible within the class and its derived classes
- ❌ Not accessible from outside

### 3. `public`

- Accessible from anywhere (class, derived class, outside code)

---

## 👨‍👧 Inheritance Access

When a class inherits another class, the access modifier used for inheritance affects how base class members are treated in the derived class.

| Inheritance Type     | Public in Base → | Protected in Base → | Private in Base → |
| -------------------- | ---------------- | ------------------- | ----------------- |
| `public` inheritance | public           | protected           | not inherited     |
| `protected`          | protected        | protected           | not inherited     |
| `private`            | private          | private             | not inherited     |

---

## 📄 Code Example

````cpp
class Base {
public:
    void show() {}         // ✅ Accessible everywhere
protected:
    int data;              // ✅ Accessible in derived class
private:
    int secret;            // ❌ Not accessible in derived class
};

class Derived : public Base {
    void test() {
        show();   // ✅ OK - inherited as public
        data = 5; // ✅ OK - inherited as protected
        // secret = 10; ❌ ERROR - not inherited
    }
};


**Example:**

```cpp
class Student {
public:
    string name;
    int roll;
    void display() { cout << name << " (" << roll << ")" << endl; }
};
Student s;
s.name = "Amit";
s.roll = 101;
s.display(); // Output: Amit (101)
````

### 2. Inheritance

- Mechanism by which one class (child/derived) acquires properties and behaviors of another class (parent/base).
- Promotes code reuse and hierarchical relationships.

**Example:**

```cpp
class Animal {
public:
    void eat() { cout << "Eating..." << endl; }
};
class Dog : public Animal {
public:
    void bark() { cout << "Barking..." << endl; }
};
Dog d;
d.eat(); // Output: Eating...
d.bark(); // Output: Barking...
```

### 3. Polymorphism

- Ability of different objects to respond in their own way to the same message (function call).
- Types:
  - Compile-time (Function Overloading)
  - Run-time (Function Overriding via virtual functions)

**Example:**

```cpp
class Shape {
public:
    virtual void draw() { cout << "Drawing shape" << endl; }
};
class Circle : public Shape {
public:
    void draw() override { cout << "Drawing circle" << endl; }
};
Shape* s = new Circle();
s->draw(); // Output: Drawing circle
```

### 4. Encapsulation

- Wrapping data (attributes) and code (methods) together as a single unit (class).
- Restricts direct access to some of the object's components (using private/protected).

**Example:**

```cpp
class Account {
private:
    double balance;
public:
    void deposit(double amt) { balance += amt; }
    double getBalance() { return balance; }
};
Account acc;
acc.deposit(1000);
cout << acc.getBalance(); // Output: 1000
```

### 5. Abstraction

- Hiding complex implementation details and showing only the necessary features of an object.
- Achieved using abstract classes and interfaces (pure virtual functions in C++).

**Example:**

```cpp
class Vehicle {
public:
    virtual void start() = 0; // Pure virtual function
};
class Car : public Vehicle {
public:
    void start() override { cout << "Car started" << endl; }
};
Car c;
c.start(); // Output: Car started
```

## Benefits of OOPs

- Modularity
- Code Reusability
- Scalability
- Maintainability
- Real-world Modeling

## Importance of OOPs in DSA

- **Data Abstraction:** OOPs allows you to model data structures (like Linked List, Stack, Queue, Tree, Graph) as classes, encapsulating data and operations together.
- **Reusability:** Once a data structure class is written, it can be reused and extended for other problems (e.g., a generic Stack class for DFS, expression evaluation, etc.).
- **Modularity:** Each data structure or algorithm can be implemented as a separate class/module, making code easier to debug and maintain.
- **Inheritance:** You can create specialized data structures by inheriting from base classes (e.g., PriorityQueue from Queue).
- **Polymorphism:** Enables writing generic algorithms that work with different data structures via base class pointers (e.g., traversing different types of trees).
- **Encapsulation:** Protects the internal state of data structures, exposing only necessary operations (e.g., push/pop for Stack).

**Example in DSA:**

```cpp
// Linked List Node as a class
class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
// Linked List class encapsulating operations
class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}
    void insert(int val) {
        Node* n = new Node(val);
        n->next = head;
        head = n;
    }
    void print() {
        Node* temp = head;
        while(temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
LinkedList ll;
ll.insert(10);
ll.insert(20);
ll.print(); // Output: 20 10
```

OOPs makes it easier to implement, extend, and maintain complex data structures and algorithms, which is essential for mastering DSA.

## Real-World Examples

- **Bank Account**: Encapsulates balance, allows deposit/withdraw, hides internal state.
- **Animal Hierarchy**: Dog inherits from Animal, overrides speak method.
- **Shape Interface**: Circle implements area calculation, demonstrating abstraction.

## See Also

- [C++ OOPs Documentation](https://cplusplus.com/doc/tutorial/classes/)
- [GeeksforGeeks OOPs in C++](https://www.geeksforgeeks.org/object-oriented-programming-in-cpp/)

---

## LeetCode Problem: Add Digits ([leetcode_258.cpp](OOPS/leetcode_258.cpp))

- **Problem:** Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.
- **Link:** [LeetCode 258. Add Digits](https://leetcode.com/problems/add-digits/)

**Approaches:**

1. **Loop-based approach:**
   - Repeatedly sum the digits until a single digit remains.
   - Time complexity: O(log n)
   - See function: `addDigits(int num)`
2. **Optimal (Digital Root) approach:**
   - Uses the formula: `1 + (num - 1) % 9` (with special case for 0)
   - Time complexity: O(1)
   - See function: `addDigitsOptimal(int num)`

**See code and comments in:** [OOPS/leetcode_258.cpp](OOPS/leetcode_258.cpp)

---

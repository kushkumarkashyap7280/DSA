# Day 71: C++ OOPs Concepts & Practice

Welcome to Day 71! This folder contains comprehensive C++ Object-Oriented Programming (OOPs) learning materials, well-structured code examples, and today's solved LeetCode problems.

## 📂 OOPS II Folder Overview

The `OOPS II` folder contains beginner-friendly explanations and runnable code for all major OOPs concepts in C++:

| Concept      | File Name                                        | Description                                               |
| ------------ | ------------------------------------------------ | --------------------------------------------------------- |
| Inheritance  | [Inheritance.cpp](./OOPS%20II/Inheritance.cpp)   | Types of inheritance, ambiguity, diamond problem          |
| Polymorphism | [Polymorphism.cpp](./OOPS%20II/Polymorphism.cpp) | Compile-time & runtime polymorphism, operator overloading |
| Abstraction  | [Abstraction.cpp](./OOPS%20II/Abstraction.cpp)   | Abstract classes, pure virtual functions                  |
| Interface    | [Interface.cpp](./OOPS%20II/Interface.cpp)       | Interfaces in C++ using abstract classes                  |
| C++ Keywords | [cpp_keywords.cpp](./OOPS%20II/cpp_keywords.cpp) | Explanations and examples of important keywords           |

Each file contains:

- Clear theory and explanation
- Well-commented code examples
- Practical demonstrations

## 🔗 Quick Links

- [Inheritance.cpp](./OOPS%20II/Inheritance.cpp)
- [Polymorphism.cpp](./OOPS%20II/Polymorphism.cpp)
- [Abstraction.cpp](./OOPS%20II/Abstraction.cpp)
- [Interface.cpp](./OOPS%20II/Interface.cpp)
- [cpp_keywords.cpp](./OOPS%20II/cpp_keywords.cpp)

## 📝 LeetCode Problems Solved Today

### [LeetCode 6. Zigzag Conversion](https://leetcode.com/problems/zigzag-conversion/)

**Approach:**

- Use a vector of strings to simulate writing characters in a zigzag pattern row by row.
- Traverse the input string, appending each character to the appropriate row.
- Change direction (down/up) when reaching the first or last row.
- Concatenate all rows to get the final result.

**Time Complexity:** O(n), where n is the length of the string (each character is visited once).

**Space Complexity:** O(n), for storing the rows and the result string.

> _You can find the code for this problem in:_  
> [leetcode_6.cpp](./leetcode_6.cpp)

---

Feel free to explore the code files for hands-on learning and reference. If you have any questions or want to practice more, check out the other days' folders!

# Day 41: C++ Macros Deep Dive

## What are Macros?

Macros are preprocessor directives that allow you to define constants, functions, and code blocks that are processed before compilation. They are powerful tools for code generation and conditional compilation.

## Types of Macros

### 1. Object-like Macros

Simple constant definitions that are replaced during preprocessing.

```cpp
#define PI 3.14159
#define MAX_SIZE 100
#define NEWLINE '\n'
```

- Used for: Constants, magic numbers
- No storage space in memory
- Literal text replacement

### 2. Function-like Macros

Macros that work like functions but are expanded at compile time.

```cpp
#define SQUARE(x) ((x) * (x))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
```

- Parentheses important for precedence
- No function call overhead
- Inline expansion

### 3. Multi-line Macros

Macros that span multiple lines using line continuation (\\).

```cpp
#define PRINT_INFO(x) \
    cout << "Value: " << x << NEWLINE; \
    cout << "Square: " << SQUARE(x) << NEWLINE
```

- Use backslash for continuation
- Each line must end with backslash
- Last line no backslash

### 4. Conditional Compilation Macros

Control code compilation based on conditions.

```cpp
#ifdef DEBUG
    #define LOG(x) cout << "Debug: " << x << endl
#else
    #define LOG(x)
#endif
```

Common Directives:

- `#ifdef`: If defined
- `#ifndef`: If not defined
- `#if`: Conditional compilation
- `#else`: Alternative code
- `#endif`: End condition

### 5. Stringizing Operator (#)

Converts macro parameters to string literals.

```cpp
#define STRINGIFY(x) #x
#define PRINT_VAR(var) cout << #var << " = " << var << endl
```

- `#x` converts x to string
- Useful for debugging
- Preserves variable names

### 6. Token Pasting Operator (##)

Concatenates two tokens during preprocessing.

```cpp
#define CONCAT(a, b) a##b
CONCAT(val, ue) // becomes "value"
```

- Joins tokens before expansion
- Creates new identifiers
- Useful for generic programming

### 7. Predefined Macros

Built-in macros provided by the compiler.

```cpp
__FILE__  // Current file name
__LINE__  // Current line number
__DATE__  // Compilation date
__TIME__  // Compilation time
__STDC__  // C standard compliance
```

## Best Practices

1. **Macro Names**

   - Use UPPERCASE for macros
   - Clear, descriptive names
   - Avoid common variable names

2. **Function-like Macros**

   - Always use parentheses
   - Protect all arguments
   - Consider inline functions instead

3. **Debugging**
   - Use conditional compilation
   - Include debugging information
   - Careful with stringizing

## Common Pitfalls

1. **Side Effects**

```cpp
#define SQUARE(x) x * x
int a = 5;
SQUARE(a++);  // Expands to: a++ * a++  (undefined behavior)
```

2. **Precedence Issues**

```cpp
#define MULTIPLY(x, y) x * y
MULTIPLY(3 + 4, 2)  // Expands to: 3 + 4 * 2 (wrong result)
```

3. **Multiple Evaluation**

```cpp
#define MAX(a,b) ((a) > (b) ? (a) : (b))
MAX(++a, b)  // a might be incremented twice
```

## When to Use Macros

1. **Use Macros For:**

   - Constants across multiple files
   - Conditional compilation
   - Debug/logging facilities
   - Header guards

2. **Prefer Alternatives When:**
   - Defining functions (use inline)
   - Type-safe constants (use const)
   - Complex operations (use functions)
   - Template metaprogramming

## Interview Tips

1. **Key Discussion Points**

   - Preprocessing vs compilation
   - Macro expansion process
   - Header guards implementation
   - Debug vs release builds

2. **Common Questions**
   - Difference between #define and const
   - Macro vs inline function
   - Header guard implementation
   - Conditional compilation usage

# Variable Scope in C++

Variable scope defines where a variable can be accessed in a program. Understanding scope is crucial for writing maintainable and bug-free code.

## 1. Global Scope

Variables declared outside any function or class.

```cpp
int globalVar = 10;          // Global variable
const int MAX_VALUE = 100;   // Global constant
static int staticGlobal = 5; // Static global variable
```

- Accessible throughout the program
- Available to all functions
- Lifetime spans entire program execution
- Static globals limited to current file

## 2. Local Scope

Variables declared inside a function or block.

```cpp
void function() {
    int localVar = 20;       // Local variable
    static int counter = 0;  // Static local variable
    counter++;              // Retains value between calls
}
```

- Only accessible within declaring function/block
- Created on function entry, destroyed on exit
- Static locals retain value between calls

## 3. Block Scope

Variables declared inside a block (enclosed by curly braces).

```cpp
{
    int blockVar = 30;    // Block scope variable
    // blockVar only accessible here
}
// blockVar not accessible here
```

- Limited to the block they're declared in
- Includes loop and conditional blocks
- Destroyed when block execution ends

## 4. Parameter Scope

Function parameters are local to the function.

```cpp
void parameterScope(int paramVar) {
    // paramVar is local to this function
    cout << paramVar << endl;
}
```

- Parameters are local variables
- Accessible only within function
- New copy for each function call

## 5. Variable Shadowing

When a local variable has same name as a global variable.

```cpp
int globalVar = 10;        // Global variable

void function() {
    int globalVar = 1000;  // Shadows global variable
    cout << globalVar;     // Uses local variable (1000)
    cout << ::globalVar;   // Uses global variable (10)
}
```

- Local variable "hides" global variable
- Use scope resolution operator (::) to access global
- Generally considered poor practice

## 6. Class Member Scope

Variables declared within a class.

```cpp
class Example {
private:
    int memberVar;     // Class member variable
public:
    void method() {
        int localVar;  // Method local variable
    }
};
```

- Member variables accessible within class methods
- Lifetime depends on object lifetime
- Access controlled by public/private/protected

## Best Practices for Variable Scope

1. **Minimize Global Variables**

   - Use only when absolutely necessary
   - Consider making them const if possible
   - Use namespaces to organize globals

2. **Use Local Variables**

   - Keep variables in smallest needed scope
   - Initialize variables when declared
   - Use block scope to limit visibility

3. **Static Variables**

   - Use for persistent state within functions
   - Avoid static class members if possible
   - Initialize static variables

4. **Avoid Shadowing**
   - Use distinct names for variables
   - Don't reuse global names locally
   - Use clear, descriptive names

# Inline Functions vs Macros

Inline functions are a better alternative to function-like macros in many cases. They provide type safety and proper scope rules while maintaining performance benefits.

## Inline Functions

```cpp
inline int square(int x) {
    return x * x;
}
```

### Advantages over Macros:

1. **Type Safety**

   - Proper type checking at compile time
   - Function parameters properly evaluated
   - Return type checking

2. **Debugging**

   - Can be debugged like normal functions
   - Show up in debugger stack traces
   - Better error messages

3. **Scope Rules**
   - Follow proper C++ scope rules
   - No unexpected variable name conflicts
   - Proper name lookup

### When to Use Inline Functions:

1. **Simple Operations**

   - Small, frequently called functions
   - Performance-critical code
   - Simple mathematical operations

2. **Class Member Functions**
   - Small accessor methods
   - Simple setter methods
   - Short utility functions

```cpp
class Point {
    int x, y;
public:
    inline int getX() { return x; }  // Good inline candidate
    inline void setX(int val) { x = val; }
};
```

# Ternary Operator

The ternary operator `?:` is a concise way to write simple if-else conditions.

## Basic Syntax

```cpp
condition ? expression1 : expression2
```

- If condition is true, evaluates to expression1
- If condition is false, evaluates to expression2

## Examples

1. **Simple Assignment**

```cpp
int max = (a > b) ? a : b;  // Find maximum of two numbers
```

2. **Nested Ternary**

```cpp
string result = (score >= 90) ? "A" :
               (score >= 80) ? "B" :
               (score >= 70) ? "C" : "F";
```

3. **With Function Calls**

```cpp
void printStatus(int value) {
    cout << (value > 0 ? "Positive" : value < 0 ? "Negative" : "Zero");
}
```

## Best Practices

1. **Use for Simple Conditions**

   - Keep expressions simple
   - Avoid nested ternary when possible
   - Use for straightforward either/or choices

2. **Readability**

   - Add parentheses for clarity
   - Break long expressions into multiple lines
   - Consider using if-else for complex logic

3. **Common Use Cases**
   - Simple value selection
   - Quick null checks
   - Toggle between two values

```cpp
// Good uses
string status = isActive ? "ON" : "OFF";
int fee = isMember ? 100 : 200;

// Avoid complex nested operations
// Bad example:
int result = a > b ?
            x > y ? x : y :
            c > d ? c : d;  // Hard to read
```

# Default Arguments in C++

Default arguments allow you to specify default values for function parameters. If a caller doesn't provide these arguments, the default values are used.

## Basic Syntax

```cpp
return_type function_name(type1 param1, type2 param2 = default_value2) {
    // function body
}
```

## Rules and Best Practices

1. **Declaration Rules**
   - Default arguments must be rightmost parameters
   - Can't have a non-default argument after a default argument
   - Default value must be a constant or global variable

```cpp
// Correct way
void print(string text, int count = 1, bool newline = true);

// Wrong way
void print(int count = 1, string text);  // Error: default argument not at end
```

2. **Multiple Default Arguments**

```cpp
// All parameters with default values
void configure(string name = "default", int timeout = 30, bool debug = false) {
    // function body
}

// Usage
configure();                    // Uses all defaults
configure("custom");           // Uses default timeout and debug
configure("custom", 60);       // Uses default debug
configure("custom", 60, true); // Specifies all values
```

3. **Common Use Cases**

```cpp
// Constructor with default values
class Server {
public:
    Server(string host = "localhost",
           int port = 8080,
           bool secure = false) {
        // initialization
    }
};

// Function overloading alternative
void draw(int width = 100, int height = 100, string color = "black") {
    // drawing logic
}
```

## Best Practices

1. **Choose Meaningful Defaults**

   - Use commonly needed values
   - Make defaults safe and conservative
   - Document why defaults were chosen

2. **Consistency**

   - Keep default values consistent across related functions
   - Use same defaults in overloaded functions
   - Maintain backwards compatibility

3. **Avoid Complexity**

   ```cpp
   // Good: Simple, clear defaults
   void setTimer(int seconds = 60, bool repeat = false);

   // Bad: Complex expressions as defaults
   void setTimer(int seconds = 60 * 24, bool repeat = someGlobalVar);
   ```

## Common Pitfalls

1. **Changing Defaults**

```cpp
// Header file
void process(int value = 100);

// Source file - WRONG!
void process(int value = 200) { } // Different default value
```

2. **Dynamic Default Values**

```cpp
int currentValue = 42;

// WRONG: Non-constant default
void setValue(int value = currentValue); // Don't use variables

// Correct: Use constant
void setValue(int value = 42);
```

3. **Order Dependency**

```cpp
// WRONG: Parameters with defaults must be last
void configure(int timeout = 30, string name); // Error

// Correct order
void configure(string name, int timeout = 30);
```

# Constants in C++

Constants are variables whose values cannot be modified after initialization. C++ provides multiple ways to define constants.

## Types of Constants

### 1. const Keyword

```cpp
const int MAX_SIZE = 100;
const double PI = 3.14159;
const string APP_NAME = "MyApp";
```

- Value cannot be changed after initialization
- Must be initialized when declared
- Type-safe
- Scope rules apply normally

### 2. constexpr Keyword

Used for compile-time constants.

```cpp
constexpr int ARRAY_SIZE = 100;
constexpr double FACTOR = 2.5;
constexpr int square(int x) { return x * x; }
```

- Evaluated at compile time
- Improved performance
- Can be used with functions
- More restrictive than const

### 3. #define vs const

```cpp
// Macro constant (avoid this)
#define MAX_VALUE 100

// Better: const (use this)
const int MAX_VALUE = 100;
```

**Why prefer const over #define:**

- Type safety
- Scope control
- Debugging support
- No text substitution issues

## Common Use Cases

1. **Class Constants**

```cpp
class Circle {
    const double PI = 3.14159;  // Instance constant
    static const int MAX_RADIUS = 1000;  // Class constant

public:
    double getArea(double radius) const {  // Const member function
        return PI * radius * radius;
    }
};
```

2. **Const Parameters and Pointers**

```cpp
// Const parameter
void printValue(const int& value);

// Const pointer to non-const data
int* const ptr = &value;

// Pointer to const data
const int* ptr = &value;

// Const pointer to const data
const int* const ptr = &value;
```

3. **Const Member Functions**

```cpp
class Example {
    int value;
public:
    // Function promises not to modify object
    int getValue() const {
        return value;
    }
};
```

## Best Practices

1. **Use const Whenever Possible**

   ```cpp
   // Parameters
   void processData(const vector<int>& data);

   // Return values
   const string& getName() const;

   // Local variables
   const int daysInWeek = 7;
   ```

2. **Const Member Functions**

   - Mark all methods that don't modify object state
   - Enables use with const objects
   - Documents method behavior

3. **Const References**

   ```cpp
   // Efficient and safe
   void printUser(const User& user);

   // Avoid copying large objects
   const BigObject& getObject() const;
   ```

## Common Pitfalls

1. **Const Correctness**

```cpp
// WRONG: Forgetting const
string getName() { return name; }

// Correct: Use const when method doesn't modify state
string getName() const { return name; }
```

2. **Temporary Objects**

```cpp
// WRONG: Returning reference to temporary
const string& createMessage() {
    string msg = "Hello";
    return msg;  // Dangling reference!
}
```

3. **Const Cast**

```cpp
// Avoid const_cast if possible
const int value = 42;
int& nonConstRef = const_cast<int&>(value);  // Bad practice
```

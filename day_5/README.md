# Control Flow Statements in C++

## 1. if-else Statements

### Simple if-else

- Basic conditional execution
- Used for binary conditions
- Syntax:

```cpp
if (condition) {
    // true block
} else {
    // false block
}
```

### if-else Ladder

- Multiple conditions checked sequentially
- Used when multiple conditions need to be tested
- Only first true condition is executed

```cpp
if (condition1) {
    // block 1
} else if (condition2) {
    // block 2
} else {
    // default block
}
```

### Nested if-else

- if-else inside another if-else
- Used for complex conditions
- Can lead to deep nesting

```cpp
if (outer_condition) {
    if (inner_condition) {
        // nested block
    }
}
```

## 2. Switch Statement

### Basic Switch

- Alternative to if-else ladder
- Works with constants
- More efficient for multiple conditions

```cpp
switch (expression) {
    case constant1:
        // code block 1
        break;
    case constant2:
        // code block 2
        break;
    default:
        // default block
}
```

## Comparison Between if-else and switch

### if-else

- Advantages:
  - Can handle any type of condition
  - Suitable for boolean expressions
  - Can use relational operators
- Disadvantages:
  - Can become complex with multiple conditions
  - Less efficient for multiple equality checks

### Switch

- Advantages:
  - More readable for multiple conditions
  - Better performance for multiple equality checks
  - Good for menu-driven programs
- Disadvantages:
  - Only works with constants
  - Cannot use relational operators
  - Limited to equality checking

## Best Practices

1. Use if-else when:

   - Testing boolean conditions
   - Using relational operators
   - Having few conditions

2. Use switch when:
   - Comparing single variable with constants
   - Having many conditions
   - Need better performance

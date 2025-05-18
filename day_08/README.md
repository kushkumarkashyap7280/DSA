# Scope and Functions in C++

## Variable Scope Types

1. **Global Scope**

   - Variables declared outside all functions
   - Accessible throughout the program
   - Memory allocated for entire program runtime
   - Example: `int globalVar = 100;`

2. **Local Scope**

   - Variables declared inside a function
   - Only accessible within that function
   - Memory allocated when function is called
   - Example: `int localVar = 50;`

3. **Block Scope**
   - Variables declared inside a block {}
   - Only accessible within that block
   - Example: Variables in if, for, while blocks

## Function Types Demonstrated

1. **Area Calculator**

   - Pure functions with return values
   - Mathematical computations
   - Single responsibility principle

2. **Eligibility Checker**
   - Boolean functions
   - Decision making
   - Multiple condition checking

## Best Practices

1. Minimize global variables
2. Use meaningful function names
3. Keep functions focused on single task
4. Use appropriate return types
5. Validate input parameters

## Memory Management

- Global variables: Static memory
- Local variables: Stack memory
- Block variables: Stack memory with limited lifetime

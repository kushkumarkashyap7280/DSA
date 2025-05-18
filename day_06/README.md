# Loops in C++

## Types of Loops

### 1. For Loop

- **Syntax**: `for(initialization; condition; increment/decrement)`
- **Use Cases**:
  - Known number of iterations
  - Array traversal
  - Pattern printing
  - Counter-based iterations

### 2. While Loop

- **Syntax**: `while(condition)`
- **Use Cases**:
  - Unknown number of iterations
  - Menu-driven programs
  - Game loops
  - Input validation

### 3. Do-While Loop

- **Syntax**: `do { } while(condition);`
- **Use Cases**:
  - Menu systems
  - Input validation
  - When loop body must execute at least once

### 4. Range-based For Loop

- **Syntax**: `for(type variable : container)`
- **Use Cases**:
  - Container traversal
  - Array processing
  - Collection operations
  - Clean, readable iteration

## Loop Control Statements

### 1. break

- Exits the loop immediately
- Used in:
  - Search algorithms
  - Menu systems
  - Early termination

### 2. continue

- Skips rest of current iteration
- Used in:
  - Filtering
  - Skipping specific values
  - Conditional processing

## Common Loop Patterns

1. **Nested Loops**

   - Pattern printing
   - Matrix operations
   - Multi-dimensional array processing

2. **Infinite Loops**

   - Game loops
   - Server programs
   - Event handling
   - Continuous monitoring

3. **Loop with Multiple Variables**
   - Two-pointer techniques
   - Multiple counters
   - Complex iterations

## Best Practices

1. Use appropriate loop type for the task
2. Avoid infinite loops without exit conditions
3. Keep loop bodies simple and focused
4. Use meaningful iterator names
5. Consider performance implications

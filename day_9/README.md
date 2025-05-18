# Pattern Printing in C++

## Types of Patterns

1. **Square Patterns**

   - Solid Square: All positions filled
   - Hollow Square: Only boundary filled
   - Time Complexity: O(n²)
   - Space Complexity: O(1)

2. **Pyramid Patterns**

   - Regular Pyramid: Increasing stars
   - Inverted Pyramid: Decreasing stars
   - Time Complexity: O(n²)
   - Space Complexity: O(1)

3. **Diamond Pattern**
   - Combination of pyramids
   - Time Complexity: O(n²)
   - Space Complexity: O(1)

## Pattern Building Blocks

1. Outer loop: Controls rows
2. Inner loop(s):
   - Space printing
   - Star printing
3. Line break after each row

## Tips for Pattern Questions

1. Identify the number of rows
2. Find spaces and stars relationship
3. Look for symmetry
4. Break complex patterns into parts

## Common Pattern Types

```
Square:      Pyramid:      Diamond:
* * * * *    *          *
* * * * *   * *        * *
* * * * *  * * *      * * *
* * * * * * * * *    * * * *
* * * * *  * * *      * * *
           * *          * *
            *            *
```

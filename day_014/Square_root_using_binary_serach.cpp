// Problem statement
// You are given a positive integer ‘n’.



// Your task is to find and return its square root. If ‘n’ is not a perfect square, then return the floor value of sqrt(n).



// Example:
// Input: ‘n’ = 7

// Output: 2

// Explanation:
// The square root of the number 7 lies between 2 and 3, so the floor value is 2.




// int floorSqrt(int n)
// {
 

// method 1 :

   int i = 0, j = n, ans = 0;
    while (i <= j) {
        long long m = i + (j - i) / 2;
        long long square = m * m;

        if (square == n) return m;
        if (square < n) {
            ans = m;
            i = m + 1;
        } else {
            j = m - 1;
        }
    }
    return ans;

    // method 2 :

   int i = 0 , j = n;
   while( i <= j){
     int m = i + ( j -i)/2;
      int square = m * m;
      int next_square = (m +1)*(m +1);
      if(n == square) return m;
      if(n >= square && n < next_square){return m;}
      else if(n < square){
         j = m -1;
      }else{
         i = m +1;
      }

   }
   return j;

   // method 3 :

   if (n == 0 || n == 1) return n;

   for( int i = 1 ; i < (n/2) +1 ; i++ ){
       int k = i*i;
      if(k == n) return i;
      if(k > n) return (i-1);
   }
  // }

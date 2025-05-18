// here we going to learn how to find square root of a number with precision upto n decimal places;


#include <iostream>
using namespace std;

int floorSqrt(int n)
{
   int i = 0 , j = n;
   int ans = -1;

   while(i <= j){

      int m = i + (j -i)/2;
      long long  square = 1LL * m*m;
      if(n == square) { return m;}
      else if( n > square){
         ans = m;
         i = m + 1;
      }else{
         j = m -1;
      }


   }
   return ans;
}
double findSqrt(int n, int precision){

    double temp = floorSqrt(n);
    if(precision == 0){ 
        return (int) temp;
    }
    int temp_precision = 1;
   double base = 1;
    while(temp_precision <= precision){
        base /=10;
        while(((temp + base)* (temp + base)) < n){
            temp += base;
        }
        temp_precision ++;
    }
    
   return temp;
}

int main(){
    int n;
    cout << "Enter the number to find the square root: ";
    cin >> n;
    int precision;
    cout << "Enter the precision: ";
    cin >> precision;
    double ans = findSqrt(n, precision);
    cout << "The square root of " << n << " is: " << ans << endl;
    return 0;
}
// Problem statement
// Given an array/list of length ‘n’, where the array/list represents the boards and each element of the given array/list represents the length of each board. Some ‘k’ numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint.



// You are supposed to return the area of the minimum time to get this job done of painting all the ‘n’ boards under a constraint that any painter will only paint the continuous sections of boards.



// Example :
// Input: arr = [2, 1, 5, 6, 2, 3], k = 2

// Output: 11

// Explanation:
// First painter can paint boards 1 to 3 in 8 units of time and the second painter can paint boards 4-6 in 11 units of time. Thus both painters will paint all the boards in max(8,11) = 11 units of time. It can be shown that all the boards can't be painted in less than 11 units of time.


// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1 :
// 4 2
// 10 20 30 40


// Sample Output 1 :
// 60


// Explanation For Sample Input 1 :
// In this test case, we can divide the first 3 boards for one painter and the last board for the second painter.


// Sample Input 2 :
// 2 2
// 48 90


// Sample Output 2 :
// 90


// Expected Time Complexity:
// Try to do this in O(n*log(n)).


// Constraints :
// 1 <= n <= 10^5
// 1 <= k <= n
// 1 <= arr[i] <= 10^9

// Time Limit: 1 sec.

int isPossible(vector<int> &boards, int k, int m){
  int total_boards = boards.size();
  int total_painters =1;
  int total_time =0;
  for(int i = 0 ; i < total_boards ; i++){
      if(total_time + boards[i] <= m){
          total_time +=boards[i] ;
      }else{
          total_painters++;
          if(total_painters > k || total_time > m) return false;
          total_time = boards[i];
      }
  }
  return true;

}

int findLargestMinDistance(vector<int> &boards, int k)
{
 int ans = -1;
  int i = 0, j = 0;
  for (int p = 0; p < boards.size(); p++) {
      if (boards[p] > i) i = boards[p]; // max element
      j += boards[p]; // total sum
  }
 while(i <= j){
     int m = i +(j -i)/2;
     if(isPossible(boards , k , m)){
         ans = m;
         j = m -1;
     }else{
         i = m +1;
     }

 }
 return ans;
}
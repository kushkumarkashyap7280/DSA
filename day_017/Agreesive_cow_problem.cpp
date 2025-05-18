// link :  https://bit.ly/3dkuQ2B 



// Problem statement
// You are given an array 'arr' consisting of 'n' integers which denote the position of a stall.



// You are also given an integer 'k' which denotes the number of aggressive cows.



// You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.



// Print the maximum possible minimum distance.



// Example:
// Input: 'n' = 3, 'k' = 2 and 'arr' = {1, 2, 3}

// Output: 2

// Explanation: The maximum possible minimum distance will be 2 when 2 cows are placed at positions {1, 3}. Here distance between cows is 2.

// code begins here

bool isPossible(vector<int> &stalls, int k, int m) {
  int cows = 1;
  int last_position = stalls[0];
  int stalls_length = stalls.size();

  for (int i = 1; i < stalls_length; i++) {
      if (stalls[i] - last_position >= m) {
          cows++;
          last_position = stalls[i];
      }
      if (cows >= k) return true;
  }

  return false;
}


int aggressiveCows(vector<int> &stalls, int k)
{
  for (int i = 0; i < stalls.size(); i++) {
  for (int j = 0; j < stalls.size() - i - 1; j++) {
      if (stalls[j] > stalls[j + 1]) {
          int temp = stalls[j];
          stalls[j] = stalls[j + 1];
          stalls[j + 1] = temp;
      }
  }
}
 
    int ans = -1;
int i=1 , j;
int maxi = stalls[0] , mini = stalls[0] ;
for(int x : stalls){
    if(x > maxi){ maxi = x;}
    if( x < mini){ mini = x;}
}
j = maxi - mini;

while(i <=j){
    int m = i + (j - i)/2;
    if(isPossible(stalls , k , m)){
        ans = m;
        i = m +1;
    }else{
        j = m -1;
    }
}
  return ans;
}
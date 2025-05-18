// Prata spoj problem: https://bit.ly/3ExHXt5  

// Problem statement
// In Ninja Land, there is a famous restaurant named ‘CookingNinjas’. There are ‘N’ cooks in ‘CookingNinjas’ numbered from 0 to N-1. Each cook has rank ‘R’ (1 <= R <= 10).

// A cook with a rank ‘R’ can prepare 1 dish in the first ‘R’ minutes, 1 more dish in the next ‘2R’ minutes, 1 more dish in next ‘3R’ minutes, and so on (A cook can only make complete dishes) For example if a cook is ranked 2. He will prepare one dish in 2 minutes, one more dish in the next 4 mins and one more in the next 6 minutes hence in a total of 12 minutes he can make 3 dishes, Note, In 13 minutes also he can make only 3 dishes as he does not have enough time for the 4th dish).

// One day ‘CookingNinjas’ receive an order of ‘M’ dishes that they need to complete as early as possible. You are given an integer array ‘rank’ of size ‘N’ in which ‘rank[i]’ gives ‘rank’ of ith cook and an integer ‘M’, You need to find out the minimum times required to complete this order of ’M’ dishes.

// Note
// One dish can be prepared by only one cook, however, two or more cooks can simultaneously prepare different dishes.
// For Example
// Let ‘N’ = 4,  ‘ranks’ = [1, 2, 3, 4] and ‘M’ = 11.  Then the minimum time required to cook 11 dishes will be 12 minutes.  The cooks should prepare dishes in the following manner -:
// Cook-0 prepare 4 dishes in 10 minutes i.e (1 dish in 1 minute, 1 more dish in next 2 minutes, 1 more dish in next 3 minutes, 1 more dish in next 4 minutes).
// Cook-1 prepare 3 dishes in 12 minutes i.e (1 dish in 2 minutes, 1 more dish in 4 minutes, 1 more dish in 6 minutes).
// Cook-2 prepare 2 dishes in 9 minutes i.e (1 dish in 3 minutes, 1 more dish in the next 6 minutes).
// Cook-3 prepare 2 dishes in 12 minutes i.e (1 dish in 4 minutes, 1 more dish in the next 8 minutes).
// If all four cooks work simultaneously then they can prepare(4 + 3 + 2 + 2 = 11) dishes in 12 minutes. And it is the minimum possible time.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints
// 1 <= T <= 50
// 1 <= N <= 20
// 1 <= M <= 10^4
// 1 <= rank[i] <= 10

// Time Limit: 1 sec
// Sample Input 1
// 2
// 1 1
// 10
// 4 11
// 1 2 3 4
// Sample Output 1
// 10
// 12
// Explanation of Sample Input 1
// Test case 1:
// There is only one chef with rank 10, so he will cook one dish in 10 minutes.

// Test case 2
// See the problem statement for an explanation.
// Sample Input 2
// 2
// 4 10
// 1 2 3 4
// 8 8
// 1 1 1 1 1 1 1 1
// Sample Output 2
// 12
// 1

#include <iostream>
#include <vector>
using namespace std;


bool isPossible(vector<int> &rank, int m, int mid_time) {
    int total_dish = 0;
    for (int r : rank) {
        int time = 0, count = 0, i = 1;
        while (true) {
            time += r * i;
            if (time > mid_time) break;
            count++;
            i++;
        }
        total_dish += count;
        if (total_dish >= m) return true;  // Early exit
    }
    return false;
}

int minCookTime(vector<int> &rank, int m)
{    int ans = -1;
    int Slowest_cook = rank[0];
    for(int cook : rank){
        if(Slowest_cook < cook) Slowest_cook = cook;
    }
    int i = 0; //min time
    int j =  Slowest_cook * ((m*(m+1))/2); // max time
    while(i<=j){
        int mid_time = i + (j -i)/2;
        if(isPossible(rank , m , mid_time)){
            ans = mid_time;
            j = mid_time -1;
        }else{
            i = mid_time +1;
        }
    }
    return ans;
}
int main() {
    int n, m;
    cout << "Enter number of cooks and number of dishes: ";
    cin >> n >> m;
    vector<int> rank(n);
    cout << "Enter the rank of each cook: ";
    for (int i = 0; i < n; i++) {
        cin >> rank[i];
    }
    cout << "Minimum time to cook " << m << " dishes is: ";
    cout << minCookTime(rank, m) << endl;
    return 0;
}
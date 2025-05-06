// book allocation problem
// Problem statement
// Ayush is studying for ninjatest which will be held after 'N' days, And to score good marks he has to study 'M' chapters and the ith chapter requires TIME[i] seconds to study. The day in Ayush’s world has 100^100 seconds. There are some rules that are followed by Ayush while studying.

// 1. He reads the chapter in a sequential order, i.e. he studies i+1th chapter only after he studies ith chapter.

// 2. If he starts some chapter on a particular day he completes it that day itself.

// 3. He wants to distribute his workload over 'N' days, so he wants to minimize the maximum amount of time he studies in a day.

// Your task is to find out the minimal value of the maximum amount of time for which Ayush studies in a day, in order to complete all the 'M' chapters in no more than 'N' days.

// For example

// if Ayush want to study 6 chapters in 3 days and the time that each chapter requires is as follows:
// Chapter 1 = 30
// Chapter 2 = 20
// Chapter 3 = 10
// Chapter 4 = 40
// Chapter 5 = 5
// Chapter 6 = 45

// Then he will study the chapters in the following order 

// | day 1 : 1 , 2 | day 2 : 3 , 4 | day 3 : 5 , 6 |
// Here we can see that he study chapters in sequential order and the maximum time to study on a day is 50, which is the minimum possible in this case.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 1 <= T <= 10
// 1 <= N , M <= 10 ^ 4
// 1 <= TIME[i] <= 10 ^ 9 
// It is considered that there are infinite seconds in a day, on the planet where Ayush lives.

// Time limit: 1 sec.
// Sample Input 1:
// 1
// 3 5
// 1 2 2 3 1
// Sample Output 1:
// 4
// Explanation of sample input 1:
// The ayush will read the chapter as follows,
// Day 1 : 1 , 2         Time required : 3
// Day 2 : 3             Time required : 2
// Day 3 : 4 , 5         Time required : 4
// So the maximum time in a day is 4.
// Sample Input 2:
// 1
// 4 7
// 2 2 3 3 4 4 1 
// Sample Output 2:
// 6
// Explanation of sample input 2:
// The ayush will read the chapter as follows,
// Day 1 : 1 , 2          Time required : 4
// Day 2 : 3 , 4          Time required : 6
// Day 3 : 5              Time required : 4
// Day 4 : 6 , 7          Time required : 5
// So the maximum time in a day is 6.

#include <bits/stdc++.h> 
bool isPossible(int n, int m, vector<int> time, int mid) {
	int student_no = 1;
	int TotalPages = 0;

	for (int i = 0; i < m; i++) {
		if (TotalPages + time[i] <= mid) {
			TotalPages += time[i];
		} else {
			student_no++;
			if (student_no > n || time[i] > mid) {
				return false;
			}
			TotalPages = time[i];
		}
	}
	return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) {
	int ans = -1;
	int totalsum = 0, maxTime = 0;

	for (int i : time) {
		totalsum += i;
		maxTime = max(maxTime, i);
	}

	int low = maxTime, high = totalsum;

	while (low <= high) {
		int mid = low + (high - low) / 2;

		if (isPossible(n, m, time, mid)) {
			ans = mid;
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	return ans;
}

// answer second 

//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isPossible(vector<int> &arr, int k ,int mid){
        int students = 1;
        int total_books = arr.size();
        int pagesum = 0;
        for(int i = 0 ; i <  total_books ; i++){
            if(pagesum + arr[i] <= mid){
                pagesum += arr[i];
            }else{
                students++;
                if(students > k || pagesum > mid ){
                    return false;
                }
                pagesum = arr[i];
            }
        }
        
    return true;
        
    };
    int findPages(vector<int> &arr, int k) {
         int total_books = arr.size();
         if(k > total_books) return -1;
       int ans = -1;
   int i = *max_element(arr.begin(), arr.end());
        int j = accumulate(arr.begin(), arr.end(), 0);
    while(i <=j){
        int m = i + (j - i)/2;
        if(isPossible(arr ,k ,m)){
            ans = m;
            j = m -1;
            
        }else{
             i = m +1;
        }
        
     }
     return ans;
    
    };
};


// geeksforgeeks problem 

//{ Driver Code Starts.
//https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
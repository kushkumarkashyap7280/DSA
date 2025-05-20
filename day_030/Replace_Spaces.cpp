// Replace Spaces

//https://www.naukri.com/code360/problems/replace-spaces_1172172

// Problem statement
// You have been given a string 'STR' of words. You need to replace all the spaces between words with “@40”.

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 1 <= T <= 50
// 0 <= |STR| <= 100

// Where ‘|STR|’ is the length of a particular string including spaces.

// Time limit: 1 sec
// Sample Input 1:
// 2
// Coding Ninjas Is A Coding Platform
// Hello World
// Sample Output 1:
// Coding@40Ninjas@40Is@40A@40Coding@40Platform
// Hello@40World
// Explanation of Sample Output 1:
// In test case 1, After replacing the spaces with “@40” string is: 

// Coding@40Ninjas@40Is@40A@40Coding@40Platform

// In test case 2, After replacing the spaces with “@40” string is: 

// Hello@40World
// Sample Input 2:
// 3
// Hello
// I love coding
// Coding Ninjas India
// Sample Output 2:
// Hello
// I@40love@40coding
// Coding@40Ninjas@40India    
// Explanation for Sample Output 2:
// In test case 1, After replacing the spaces with “@40” string is: 

// Hello

// In test case 2, After replacing the spaces with “@40” string is: 

// I@40love@40coding

// In test case 3, After replacing the spaces with “@40” string is: 

// Coding@40Ninjas@40India

#include <iostream>
#include <string>
using namespace std;

// first approach , this is my first approach which is not optimised
// time complexity is O(n^2)
// space complexity is O(1)
// string replaceSpaces(string &str){
// 	string a ="@40";
// 	int i = 0;
// 	while(i < str.size()){
// 		if(str[i]== ' '){
// 			 str.erase(i, 1); 
// 			str.insert(i , a);
// 			i += 3;
// 		}else{
// 				i++;
// 		}

	
// 	}
// 	return str;
// }

// Optimised approach
// time complexity is O(n)
// space complexity is O(1)
string replaceSpaces(const string &str) {
    string result;

    for (char ch : str) {
        if (ch == ' ')
            result += "@40";  // add 3 characters
        else
            result += ch;     // add the original character
    }

    return result;
}

int main() {
  // example;
  string str = "Coding Ninjas Is A Coding Platform";
  cout << replaceSpaces(str) << endl;
  string str1= "Hello World";
  cout << replaceSpaces(str1) << endl;
return 0;
}
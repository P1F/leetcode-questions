#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
557. Reverse Words in a String III

Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
----------------------------------------------------------------------------------
Example 1:

Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"

Example 2:

Input: s = "God Ding"
Output: "doG gniD"
--------------------------------------------------------------------------------- 
Constraints:

1 <= s.length <= 5 * 104
s contains printable ASCII characters.
s does not contain any leading or trailing spaces.
There is at least one word in s.
All the words in s are separated by a single space.
*/

// MY FIRST SOLUTION
// ANALYSIS:
// Time complexity - O(n^2)
// Space complexity - O(1)
class Solution {
public:
    void reverseSubstring(string& s, int ini, int end){
        for (int i = ini, j = end; i <= ini + (end-ini)/2; i++, j--)
            swap(s[i], s[j]);
    }
    
    string reverseWords(string s) {
        for (int i = 0, j = 0; j < s.size(); j++){
            if (s[j] == ' ' && s[i] != ' '){
                reverseSubstring(s, i, j-1);
                i = j;
            } else if (s[j] != ' ' && s[i] == ' ')
                i = j;
            if (j == s.size()-1 && s[j] != ' ')
                reverseSubstring(s, i, j);
        }
        return s;
    }
};

// MY SECOND SOLUTION
// ANALYSIS:
// Time complexity - O(n)
// Space complexity - O(1)
class Solution {
public:
    void reverseSubstring(string& s, int ini, int end){
        for (int i = ini, j = end; i <= ini + (end-ini)/2; i++, j--)
            swap(s[i], s[j]);
    }
    
    string reverseWords(string s) {
        int i = 0, pos = 0;
        while(1){
            pos = s.find(" ", pos+1);
            if (pos == string::npos) pos = s.size();
            reverseSubstring(s, i, pos-1);
            if (pos == s.size()) break;
            i = pos+1;
        }
        return s;
    }
};

// LEETCODE SOLUTION
// ANALYSIS:
// Time complexity - O(n)
// Space complexity - O(1)
// https://leetcode.com/problems/reverse-words-in-a-string-iii/discuss/664562/Simple-and-Clean-C%2B%2B-solution-(in-place)
class Solution {
public:
    string reverseWords(string& s) {
        int i = 0;
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] == ' ') {
                reverse(s.begin() + i, s.begin() + j);
                i = j + 1;
            }
        }
        reverse(s.begin() + i, s.end());
        return s;
    }
};

int main(){
    string s1 = "Let's take LeetCode contest";
    string s2 = "s'teL ekat edoCteeL tsetnoc";

    cout << Solution().reverseWords(s1) << endl;
    cout << Solution().reverseWords(s2) << endl;

    return 0;
}
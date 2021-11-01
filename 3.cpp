#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
3. Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring without repeating characters.
----------------------------------------------------------------------------------
Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Example 4:

Input: s = ""
Output: 0
--------------------------------------------------------------------------------- 
Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/

// MY FIRST SOLUTION
// ANALYSIS:
// Time complexity - O(n)
// Space complexity - O(min(n,m)) -> m: alphabet size, n: string size
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        if (len == 0 || len == 1) return len;
        unordered_map<char, int> umap;
        int left = 1, right = 1;
        int res = right-left+1;
        for (; right <= len; right++){
            int aux = umap[s[right-1]];
            umap[s[right-1]] = right;
            
            if(left == right) continue;
            
            if (aux >= left){
                res = max(res, right-left);
                left = aux+1;
            }
        }
        res = max(res, right-left);
        
        return res;
    }
};

// SECOND SOLUTION - Sliding Window Optimized
// ANALYSIS:
// Time complexity - O(n)
// Space complexity - O(min(n,m)) -> m: alphabet size, n: string size
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> umap;
        int res = 0;
        for (int right = 1, left = 1; right <= s.size(); right++){
            if (umap[s[right-1]]) left = max(left, umap[s[right-1]]+1);
            res = max(res, right-left+1);
            umap[s[right-1]] = right;
        }
        return res;
    }
};

int main(){
    string s1 = "abcabcbb";
    string s2 = "bbbbb";
    string s3 = "pwwkew";
    string s4 = "";

    cout << Solution().lengthOfLongestSubstring(s1) << endl;
    cout << Solution().lengthOfLongestSubstring(s2) << endl;
    cout << Solution().lengthOfLongestSubstring(s3) << endl;
    cout << Solution().lengthOfLongestSubstring(s4) << endl;

    return 0;
}
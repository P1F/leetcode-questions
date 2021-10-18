#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

/*
Problem: 977. Squares of a Sorted Array

Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.
----------------------------------------------------------------------------------
Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].

Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
--------------------------------------------------------------------------------- 
Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in non-decreasing order.
---------------------------------------------------------------------------------
Follow up: Squaring each element and sorting the new array is very trivial, could you find an O(n) solution using a different approach?
*/

// MY SOLUTION
/*
    ANALYSIS:
    Time complexity: O(n)
    Space complexity: O(n)
*/
// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//         int l = nums.size();
        
//         vector<int> squaresSorted = {};
        
//         if (l == 0)
//             return squaresSorted;
        
//         int idxFirstPositive = -1;
//         for (int i = 0; i < l; i++) {
//             if (nums[i] >= 0){
//                 idxFirstPositive = i;
//                 break;
//             }
//         }
        
//         if (idxFirstPositive == 0){
//             for (int i = 0; i < l; i++)
//                 squaresSorted.push_back(pow(nums[i], 2));
//         } else if (idxFirstPositive == -1) {
//             for (int i = l - 1; i >= 0; i--)
//                 squaresSorted.push_back(pow(nums[i], 2));
//         } else {
//             int right = idxFirstPositive;
//             int left = right - 1;
            
//             while (left >= 0 && right < l) {
//                 if (abs(nums[left]) < nums[right]){
//                     squaresSorted.push_back(pow(nums[left], 2));
//                     left--;
//                 } else {
//                     squaresSorted.push_back(pow(nums[right], 2));
//                     right++;
//                 }
//             }
            
//             if (left >= 0){
//                 for (int i = left; i >= 0; i--)
//                     squaresSorted.push_back(pow(nums[i], 2));
//             }
            
//             if (right < l){
//                 for (int i = right; i < l; i++)
//                     squaresSorted.push_back(pow(nums[i], 2));
//             }
//         }
        
//         return squaresSorted;
//     }
// };

// AWESOME SOLUTION (not mine)
// https://leetcode.com/problems/squares-of-a-sorted-array/discuss/495394/C%2B%2B%3A-Simplest-one-pass-two-pointers
/*
    ANALYSIS:
    Time complexity: O(n)
    Space complexity: O(n)
*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l = nums.size();
        vector<int> res(l);

        int left = 0;
        int right = l-1;
        for (int i = l-1; i >= 0; i--){
            if (abs(nums[right]) > abs(nums[left])){
                res[i] = pow(nums[right], 2);
                right--;
            } else {
                res[i] = pow(nums[left], 2);
                left++;
            }
        }
        return res;
    }
};

int main(){
    vector<int> nums1 = {-4,-1,0,3,10};
    vector<int> nums2 = {-7,-3,2,3,11};

    cout << "nums1: ";
    for (const auto& e : Solution().sortedSquares(nums1)) {
        cout << e << " ";
    }
    cout << endl << "nums2: ";
    for (const auto& e : Solution().sortedSquares(nums2)) {
        cout << e << " ";
    }
    cout << endl;

    return 0;
}
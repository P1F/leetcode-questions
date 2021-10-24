#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
1. Two Sum

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
----------------------------------------------------------------------------------
Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
--------------------------------------------------------------------------------- 
Constraints:

    2 <= nums.length <= 104
    -109 <= nums[i] <= 109
    -109 <= target <= 109
    Only one valid answer exists.
---------------------------------------------------------------------------------
Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
*/

// MY FIRST SOLUTION
// ANALYSIS:
//  Time complexity: O(n) -> average; O(n**2) -> worst
//  Space complexity: O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++)
            umap[nums[i]] = i;
        for (int i = 0; i < nums.size()-1; i++){
            int p = target - nums[i];
            if(umap.count(p) != 0 && umap[p] != i)
                return {i, umap[p]};
        }
        
        return {};
    }
};

// LEETCODE SOLUTION
// ANALYSIS:
//  Time complexity: O(n) -> average; O(n**2) -> worst
//  Space complexity: O(n)
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int, int> umap;
//         for (int i = 0; i < nums.size()-1; i++){
//             int p = target - nums[i];
//             if(umap.count(p))
//                 return {i, umap[p]};
//             umap[nums[i]] = i;
//         }
        
//         return {};
//     }
// };

int main(){
    vector<int> nums1 = {2,7,11,15};
    int target1 = 9;
    vector<int> nums2 = {3,2,4};
    int target2 = 6;
    vector<int> nums3 = {3,3};
    int target3 = 6;

    for (auto i : Solution().twoSum(nums1, target1))
        cout << i << " ";
    cout << endl;
    for (auto i : Solution().twoSum(nums2, target2))
        cout << i << " ";
    cout << endl;
    for (auto i : Solution().twoSum(nums3, target3))
        cout << i << " ";
    cout << endl;

    return 0;
}
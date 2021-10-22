#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/*
283. Move Zeroes

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.
----------------------------------------------------------------------------------
Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:

Input: nums = [0]
Output: [0]
--------------------------------------------------------------------------------- 
Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
---------------------------------------------------------------------------------
Follow up: Could you minimize the total number of operations done?
*/

// FIRST TRY
/*
    ANALYSIS:
    Time complexity: O(n)
    Space complexity: O(n)
*/
// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int l = nums.size();
//         if (l == 0 || l == 1) return;
        
//         queue<int> q;
//         for (int i = 0; i < l; i++){
//             if (nums[i] != 0 && !q.empty()){
//                 swap(nums[i], nums[q.front()]);
//                 q.pop();
//             }
//             if (nums[i] == 0)
//                 q.push(i);   
//         }
//     }
// };

// SECOND TRY
/*
    ANALYSIS:
    Time complexity: O(n)
    Space complexity: O(1)
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        int l = nums.size();
        for (int i = 0; i < l; i++){
            if (nums[i]){
                nums[j] = nums[i];
                j++;
            }
        }
    }
};

int main(){
    vector<int> nums1 = {0,1,0,3,12};
    vector<int> nums2 = {0};

    Solution().moveZeroes(nums1);
    Solution().moveZeroes(nums2);

    cout << "nums1: ";
    for (const auto& e : nums1) {
        cout << e << " ";
    }
    cout << endl << "nums2: ";
    for (const auto& e : nums2) {
        cout << e << " ";
    }
    cout << endl;

    return 0;
}
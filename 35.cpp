#include <iostream>
#include <vector>

using namespace std;

/*
Problem: 35. Search Insert Position

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.
----------------------------------------------------------------------------------
Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4
Example 4:

Input: nums = [1,3,5,6], target = 0
Output: 0
Example 5:

Input: nums = [1], target = 0
Output: 0
--------------------------------------------------------------------------------- 
Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104
*/

// [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 13, 14]

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ini = 0;
        int end = nums.size() - 1;
        int mid;
        while(end >= ini){
            mid = (end+ini)/2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                end = mid - 1;
            else
                ini = mid + 1;
        }
        if (nums[mid] > target)
            return mid;
        else
            return mid+1;
    }
};

int main(){
    vector<int> nums1 = {1,3,5,6};
    int target1 = 5;
    vector<int> nums2 = {1,3,5,6};
    int target2 = 2;
    vector<int> nums3 = {1,3,5,6};
    int target3 = 7;
    vector<int> nums4 = {1,3,5,6};
    int target4 = 0;
    vector<int> nums5 = {1};
    int target5 = 0;

    cout << Solution().searchInsert(nums1, target1) << endl;
    cout << Solution().searchInsert(nums2, target2) << endl;
    cout << Solution().searchInsert(nums3, target3) << endl;
    cout << Solution().searchInsert(nums4, target4) << endl;
    cout << Solution().searchInsert(nums5, target5) << endl;

    return 0;
}
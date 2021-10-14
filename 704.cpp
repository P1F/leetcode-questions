#include <iostream>
#include <vector>

using namespace std;

/*
Problem:

Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.
----------------------------------------------------------------------------------
/*Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

Example 2:

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
--------------------------------------------------------------------------------- 
Constraints:

1 <= nums.length <= 104
-104 < nums[i], target < 104
All the integers in nums are unique.
nums is sorted in ascending order.
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // [-1  0  3  5  8  12]  t = 9
        //   i     m        e    nums[mid] = 3 < t = 9 -> ini = mid
        //            i  m  e    nums[mid] = 8 < t = 9 -> ini = mid
        //            i  m  e    nums[mid] = 8 < t = 9 -> ini = mid
        //             i=m  e    
        int ini = 0;
        int end = nums.size()-1;
        int mid;
        while(end >= ini) {
            mid = (end+ini)/2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                end = mid-1;
            else
                ini = mid+1;
        }
        return -1;
    }
};

int main(){
    vector<int> nums1 = {-1,0,3,5,9,12};
    int target1 = 9;
    vector<int> nums2 = {1,0,3,5,9,12};
    int target2 = 2;

    cout << Solution().search(nums1, target1) << endl;
    cout << Solution().search(nums2, target2) << endl;

    return 0;
}
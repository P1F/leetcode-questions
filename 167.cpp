#include <iostream>
#include <vector>

using namespace std;

/*
167. Two Sum II - Input array is sorted

Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= first < second <= numbers.length.

Return the indices of the two numbers, index1 and index2, as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.
----------------------------------------------------------------------------------
Example 1:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.

Example 2:

Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3.

Example 3:

Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2.
--------------------------------------------------------------------------------- 
Constraints:

2 <= numbers.length <= 3 * 104
-1000 <= numbers[i] <= 1000
numbers is sorted in non-decreasing order.
-1000 <= target <= 1000
The tests are generated such that there is exactly one solution.
*/

// MY SOLUTION
// ANALYSIS:
// Time complexity - O(n)
// Space complexity - O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        while(l < r){
            if (numbers[l] + numbers[r] == target)
                return {l+1, r+1};
            else if (numbers[l] + numbers[r] > target)
                r--;
            else
                l++;
        }
        return {};
    }
};

int main(){
    vector<int> nums1 = {2,7,11,15};
    int target1 = 9;
    vector<int> nums2 = {2,3,4};
    int target2 = 6;
    vector<int> nums3 = {-1,0};
    int target3 = -1;

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
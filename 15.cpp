#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 15. 3Sum

// MY FIRST SOLUTION
/*
    ANALYSIS:
    Time complexity: O(n^2)
    Space complexity: O(n)
*/
class Solution
{
public:
    void twoSum(vector<int> &sortedNums, int targetIdx, int sz, vector<vector<int>> &res)
    {
        int l = targetIdx + 1;
        int b = sz - 1;

        while (l < b)
        {
            if ((l > targetIdx + 1 && sortedNums[l] == sortedNums[l - 1]))
            {
                l++;
                continue;
            }
            if ((b < sz - 1 && sortedNums[b] == sortedNums[b + 1]))
            {
                b--;
                continue;
            }
            if (sortedNums[l] + sortedNums[b] == -sortedNums[targetIdx])
            {
                res.push_back({sortedNums[targetIdx], sortedNums[l], sortedNums[b]});
                l++;
                b--;
            }
            else if (sortedNums[l] + sortedNums[b] < -sortedNums[targetIdx])
                l++;
            else
                b--;
        }
    }

    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int sz = nums.size();
        if (sz < 3)
            return {};
        vector<vector<int>> res = {};

        sort(nums.begin(), nums.end());

        for (int i = 0; i < sz; i++)
        {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            twoSum(nums, i, sz, res);
        }

        return res;
    }
};

// MY SECOND SOLUTION
/*
    ANALYSIS:
    Time complexity: O(n^2)
    Space complexity: O(n)
*/

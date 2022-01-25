#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
695. Max Area of Island

You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.
----------------------------------------------------------------------------------
Example 1:

Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.

Example 2:

Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0
--------------------------------------------------------------------------------- 
Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
grid[i][j] is either 0 or 1.
*/

// MY FIRST SOLUTION - Recursive mapping the visited (~40 ms & 38.8 MB)
// ANALYSIS:
// Time complexity - O(m*n)
// Space complexity - O(m*n)
class Solution {
private:
    unordered_map<int*, bool> visited;
public:
    int walk(vector<vector<int>>&grid, int row, int col){
        if (grid[row][col] == 0 || visited[&grid[row][col]]) return 0;
        visited[&grid[row][col]] = true;
        int left = (col == 0) ? 0 : walk(grid, row, col-1);
        int right = (col == grid[0].size() - 1) ? 0 : walk(grid, row, col+1);
        int up = (row == 0) ? 0 : walk(grid, row-1, col);
        int down = (row == grid.size() - 1) ? 0 : walk(grid, row+1, col);
        return 1 + left + right + up + down;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxSize = 0, size = 0;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (!visited[&grid[i][j]]){
                    size = walk(grid, i, j);
                    maxSize = max(maxSize, size);
                }
            }
        }
        return maxSize;
    }
};

// MY SECOND SOLUTION - Recursive without map and 'size' (~12 ms & 23.1 MB)
// ANALYSIS:
// Time complexity - O(m*n)
// Space complexity - O(m*n)
class Solution {
public:
    int walk(vector<vector<int>>&grid, int row, int col){
        if (!grid[row][col]) return 0;
        grid[row][col] = 0;
        int left = (col == 0) ? 0 : walk(grid, row, col-1);
        int right = (col == grid[0].size() - 1) ? 0 : walk(grid, row, col+1);
        int up = (row == 0) ? 0 : walk(grid, row-1, col);
        int down = (row == grid.size() - 1) ? 0 : walk(grid, row+1, col);
        return 1 + left + right + up + down;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxSize = 0;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j])
                    maxSize = max(maxSize, walk(grid, i, j));
            }
        }
        return maxSize;
    }
};

int main(){
    string s1 = "abcabcbb";
    string s2 = "bbbbb";
    string s3 = "pwwkew";
    string s4 = "";

    cout << Solution().islandPerimeter(s1) << endl;
    cout << Solution().islandPerimeter(s2) << endl;
    cout << Solution().islandPerimeter(s3) << endl;
    cout << Solution().islandPerimeter(s4) << endl;

    return 0;
}
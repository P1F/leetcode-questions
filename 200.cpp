#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
200. Number of Islands

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
----------------------------------------------------------------------------------
Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
--------------------------------------------------------------------------------- 
Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.
*/

// MY FIRST SOLUTION - Recursive
// ANALYSIS:
// Time complexity - O(m*n)
// Space complexity - O(m*n)
class Solution {
public:
    void visitIsland(vector<vector<char>>& grid, int row, int col){
        if (grid[row][col] == '0') return;
        grid[row][col] = '0';
        if (col != 0) visitIsland(grid, row, col-1);
        if (col != grid[0].size() - 1) visitIsland(grid, row, col+1);
        if (row != 0) visitIsland(grid, row-1, col);
        if (row != grid.size() - 1) visitIsland(grid, row+1, col);
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == '1'){
                    visitIsland(grid, i, j);
                    cnt++;
                }
            }
        }
        
        return cnt;
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
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
463. Island Perimeter

You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.
----------------------------------------------------------------------------------
Example 1:

Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image above.

Example 2:

Input: grid = [[1]]
Output: 4

Example 3:

Input: grid = [[1,0]]
Output: 4
--------------------------------------------------------------------------------- 
Constraints:

row == grid.length
col == grid[i].length
1 <= row, col <= 100
grid[i][j] is 0 or 1.
There is exactly one island in grid.
*/

// MY FIRST SOLUTION - Recursive
// ANALYSIS:
// Time complexity - O(m*n)
// Space complexity - O(m*n)
class Solution {
public:
    int walk(vector<vector<int>>& grid, int row, int col){
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || !grid[row][col]) return 1;
        if (grid[row][col] == -1) return 0;
        grid[row][col] = -1;
        return walk(grid, row+1, col) + walk(grid, row-1, col) + walk(grid, row, col+1) + walk(grid, row, col-1);
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = 0, col = 0;
        
        bool hasLand = false;
        for (int i = 0; i < grid.size() && !hasLand; i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j]){
                    row = i; col = j;
                    hasLand = true;
                }
            }
        }
        
        if (!hasLand) return 0;
        
        return walk(grid, row, col);
    }
};

// MY SECOND SOLUTION - Iterative
// ANALYSIS:
// Time complexity - O(m*n)
// Space complexity - O(1)
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j]){
                    if (i == grid.size() - 1 || !grid[i+1][j]) perimeter++;
                    if (i == 0 || !grid[i-1][j]) perimeter++;
                    if (j == grid[0].size() - 1 || !grid[i][j+1]) perimeter++;
                    if (j == 0 || !grid[i][j-1]) perimeter++;
                }
            }
        }
        return perimeter;
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
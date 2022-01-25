#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

/*
733. Flood Fill

An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and newColor. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with newColor.

Return the modified image after performing the flood fill.
----------------------------------------------------------------------------------
Example 1:

Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.

Example 2:

Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, newColor = 2
Output: [[2,2,2],[2,2,2]]
--------------------------------------------------------------------------------- 
Constraints:

m == image.length
n == image[i].length
1 <= m, n <= 50
0 <= image[i][j], newColor < 216
0 <= sr < m
0 <= sc < n
*/

// MY FIRST SOLUTION - Recursive
// ANALYSIS:
// Time complexity - O(m*n)
// Space complexity - O(m*n)
class Solution {
public:
    void fill(vector<vector<int>>& image, int sr, int sc, int newColor, int val){
        if (sr >= image.size() || sc >= image[0].size() || image[sr][sc] != val) return;
        image[sr][sc] = newColor;
        fill(image, sr+1, sc, newColor, val);
        fill(image, sr-1, sc, newColor, val);
        fill(image, sr, sc+1, newColor, val);
        fill(image, sr, sc-1, newColor, val);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] != newColor)
            fill(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }
};

// MY SECOND SOLUTION - Iterative
// ANALYSIS:
// Time complexity - O(m*n)
// Space complexity - O(m*n)
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] != newColor){
            int currentColor = image[sr][sc];
            stack<pair<int, int>> s;
            s.push(make_pair(sr, sc));
            while(!s.empty()){
                pair<int,int> pixel = s.top();
                sr = pixel.first; sc = pixel.second;
                s.pop();
                image[sr][sc] = newColor;
                if (sr+1 < image.size() && image[sr+1][sc] == currentColor) s.push(make_pair(sr+1, sc));
                if (sr-1 >= 0 && image[sr-1][sc] == currentColor) s.push(make_pair(sr-1, sc));
                if (sc+1 < image[0].size() && image[sr][sc+1] == currentColor) s.push(make_pair(sr, sc+1));
                if (sc-1 >= 0 && image[sr][sc-1] == currentColor) s.push(make_pair(sr, sc-1));
            }
        }
        return image;
    }
};

int main(){
    string s1 = "abcabcbb";
    string s2 = "bbbbb";
    string s3 = "pwwkew";
    string s4 = "";

    cout << Solution().floodFill(s1) << endl;
    cout << Solution().floodFill(s2) << endl;
    cout << Solution().floodFill(s3) << endl;
    cout << Solution().floodFill(s4) << endl;

    return 0;
}
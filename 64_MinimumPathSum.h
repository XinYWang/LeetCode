/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.
Example:
Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/
// Solution1: two-dimensional DP
/*class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty())
            return INT_MIN;
        int m = grid.size();
        int n = grid[0].size();
        int dp[m][n];
        dp[0][0] = grid[0][0];
        for(int i = 1; i < m; i++)
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        for(int j = 1; j < n; j++)
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        return dp[m - 1][n - 1];
    }
};*/

// Solution2: one-dimensional DP
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty())
            return INT_MIN;
        int m = grid.size();
        int n = grid[0].size();
        int dp[n];
        dp[0] = grid[0][0];
        for(int i = 1; i < n; i++)
            dp[i] = dp[i - 1] + grid[0][i];
        for(int i = 1; i < m; i++)
        {
            dp[0] += grid[i][0];
            for(int j = 1; j < n; j++)
            {
                dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
            }
        }
        return dp[n - 1];
    }
};

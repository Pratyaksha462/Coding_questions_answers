#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(vector<vector<int>> &grid, vector<vector<int>> &dp, int i,
              int j)
    {
        int m = grid.size();
        int n = grid[0].size();
        if ((i == m - 1 && j == n) || (i == m && j == n - 1))
            return 0;
        if (i == m || j == n)
            return INT_MAX;
        if (dp[i][j] != -1)
            return dp[i][j];
        int result = INT_MAX;

        result = min(solve(grid, dp, i + 1, j), solve(grid, dp, i, j + 1)) +
                 grid[i][j];

        return dp[i][j] = result;
    }
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int result = solve(grid, dp, 0, 0);
        return result;
    }
};
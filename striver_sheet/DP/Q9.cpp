#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<vector<int>> &triangle, int i, int j, int result, vector<vector<int>> &memo)
    {
        if (i >= triangle.size())
            return 0;
        if (memo[i][j] != -1)
            return memo[i][j];
        result += triangle[i][j] + min(solve(triangle, i + 1, j, result, memo),
                                       solve(triangle, i + 1, j + 1, result, memo));
        return memo[i][j] = result;
    }
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));

        int ans = solve(triangle, 0, 0, 0, memo);
        return ans;
    }
};
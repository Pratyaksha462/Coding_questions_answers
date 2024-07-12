#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int t[100][100];
    int solve(vector<vector<int>>& matrix, int row, int column) {
        int n = matrix.size() - 1;
        if (column < 0 || column > n)
            return INT_MAX;
        if (row == n)
            return matrix[row][column];
        if (t[row][column] != INT_MIN)
            return t[row][column];
        long long int a1 = solve(matrix, row + 1, column - 1);
        long long int a2 = solve(matrix, row + 1, column);
        long long int a3 = solve(matrix, row + 1, column + 1);
        return t[row][column] = matrix[row][column] + min({a1, a2, a3});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                t[i][j] = INT_MIN;
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            ans = min(ans, solve(matrix, 0, i));
        }
        return ans;
    }
};


#include <bits/stdc++.h>
using namespace std;

int maximumPoints(vector<vector<int>> &points, int n)
{
    // Code here
    vector<vector<int>> dp;
    for (int i = 0; i < n; i++)
    {
        vector<int> a;
        for (int j = 0; j < n; j++)
        {

            a.push_back(-1);
        }
        dp.push_back(a);
    }
    int maxinrow = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (points[i][j] >= maxinrow)
            {
                if (dp[i - 1][j] != -1 && i > 0)
                    continue;
                else
                {
                    maxinrow = points[i][j];
                    dp[i][j] = maxinrow;
                }
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dp[i][j] != -1)
            {
                sum += dp[i][j];
            }
        }
    }
    return sum;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> points;
    for (int i = 0; i < n; i++)
    {
        vector<int> a1;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            a1.push_back(x);
        }
        points.push_back(a1);
    }
    int ans = maximumPoints(points, n);
    cout << ans << endl;
    return 0;
}